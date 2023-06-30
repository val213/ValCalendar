//bb2ba567128345c78cc550781471f903
#include "tsplan.h"
#include <QString>
WeatherWidget::WeatherWidget(QObject* parent)
	: QObject{ parent }
{
	// 创建一个网络管理器用来发送HTTP请求
	networkManager = new QNetworkAccessManager(this);

	// 创建一个定时器用来每隔10秒刷新一次天气数据
	timer = new QTimer(this);
	timer->setInterval(100000); // 100秒一次
	timer->start();

	// 连接定时器的超时信号和请求天气数据的槽函数
	connect(timer, &QTimer::timeout, this, &WeatherWidget::requestWeatherData);
	// 请求一次天气数据
	requestWeatherData();
}

void WeatherWidget::requestWeatherData()
{
	// 设置要查询天气的城市，这里用广州
	// 设置要请求的URL，这里使用和风天气的免费接口
	QString url = "https://devapi.qweather.com/v7/weather/now?location=101280101&key=bb2ba567128345c78cc550781471f903";

	// 发送GET请求
	networkManager->get(QNetworkRequest(QUrl(url)));

	// 连接网络管理器的响应完成信号和处理天气数据的槽函数
	connect(networkManager, &QNetworkAccessManager::finished, this, &WeatherWidget::handleWeatherData);
}

void WeatherWidget::handleWeatherData(QNetworkReply* reply)
{
	// 读取响应数据
	QByteArray data = reply->readAll();
	qDebug() << "data: " << data;
	// 解析JSON格式的数据
	QJsonDocument doc = QJsonDocument::fromJson(data);
	if (!doc.isNull())
	{
		QJsonObject obj = doc.object(); // 获取JSON对象
		if (obj.contains("now")) // 判断是否包含"now"键
		{
			QJsonValue val = obj.value("now"); // 获取"now"键对应的值
			if (val.isObject())
			{
				QJsonObject now = val.toObject(); // 将值转换为JSON对象
				QString temp = now.value("temp").toString(); // 获取温度
				QString text = now.value("text").toString(); // 获取天气状况
				QString windScale = now.value("windScale").toString();//获取风力等级
				QString humidity = now.value("humidity").toString();//获取相对湿度
				//根据不同的天气状况给用户出行建议notice
				if (text == "晴")
				{
					notice = "今天天气晴朗，出行请注意防晒";
				}
				else if (text == "多云")
				{
					notice = "今天天气多云，出行请注意防晒";
				}
				else if (text == "阴")
				{
					notice = "今天天气阴沉，出行请注意防晒";
				}
				else if (text == "小雨")
				{
					notice = "今天天气小雨，出行请注意带伞";
				}
				else if (text == "中雨")
				{
					notice = "今天天气中雨，出行请注意带伞";
				}
				else if (text == "大雨")
				{
					notice = "今天天气大雨，出行请注意带伞";
				}
				else if (text == "暴雨")
				{
					notice = "今天天气暴雨，出行请注意带伞";
				}
				else if (text == "大暴雨")
				{
					notice = "今天天气大暴雨，出行请注意带伞";
				}
				else if (text == "特大暴雨")
				{
					notice = "今天天气特大暴雨，出行请注意带伞";
				}
				else notice = "天气多变，出门前请做好规划！";

				// 返回天气信息
				weatherInfo = "当前温度：" + temp + "℃" + " " + "当前天气：" + text + "\n" + "风力等级：" + windScale + " " + "相对湿度：" + humidity + "\n" + notice;
				qDebug() << weatherInfo;
			}
		}
	}
	// 发送信号，通知另一个类数据已经准备好了
	emit dataReady();
}