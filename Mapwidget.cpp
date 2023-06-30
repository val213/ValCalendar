//MapWidget.cpp
#include"Mapwidget.h"
#include"ui_Mapwidget.h"
MapWidget::MapWidget(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("选择地点");
	JSBridge = new bridge(ui.webEngineView, this);
	QWebChannel* channel = new QWebChannel(this);
	channel->registerObject("bridge", JSBridge); // 将对象名称改为"bridge"
	ui.webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
	ui.webEngineView->settings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);
	// 将 QWebChannel 对象绑定到 view 的 profile 中
	ui.webEngineView->show();
	ui.webEngineView->load(QUrl("qrc:/calendar/Baidu_JS/BDmap.html"));
	ui.webEngineView->page()->setDevToolsPage(ui.webEngineView->page());
	connect(ui.webEngineView, &QWebEngineView::loadFinished, [](bool ok) {
		if (ok) {
			// 页面加载完成后执行的操作
			qDebug() << "Page loaded successfully";
		}
		else {
			// 页面加载失败时执行的操作
			qDebug() << "Page failed to load";
		}
		});

	connect(JSBridge, &bridge::distanceAndTimeCalculated, this, &MapWidget::onDistanceAndTimeCalculated);
	ui.webEngineView->page()->setWebChannel(channel);
	connect(ui.calculateButton, &QPushButton::clicked, this, &MapWidget::onCalculateButtonClicked);
}

MapWidget::~MapWidget()
{
}
void MapWidget::onCalculateButtonClicked()
{
	// 获取起点和终点输入框的文本
	QString start = ui.startInput->text();
	QString end = ui.endInput->text();

	// 调用JSBridge的槽函数，将起点和终点传递给JS文件
	JSBridge->setStartAndEnd(start, end);
}

// 槽函数，用于接收计算结果并更新QT中的文本框
void MapWidget::onDistanceAndTimeCalculated(const QString& duration, const QString& distance)
{
	// 更新文本框显示计算结果
	ui.distanceOutput->setText(duration);
	ui.durationOutput->setText(distance);
}
void MapWidget::handleWebPageLoadFinished(bool success)
{
	if (success) {
		ui.webEngineView->page()->runJavaScript("console.log = function(message) {"
			"    window.qwebchannel.javascriptConsoleMessage(message);"
			"};");
	}
	else {
		qDebug() << "Web page load failed!";
	}
}

void MapWidget::handleJavaScriptConsoleMessage(const QString& message)
{
	qDebug() << "JavaScript Console Message:" << message;
}

//ui.webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
//ui.webEngineView->setGeometry(QRect(10, 30, 581, 341));// 设置锚点与大小
//ui.webEngineView->load(QUrl("C:\\Users\\yangluwei\\source\\repos\\calendar\\calendar\\Baidu_JS\\BDmap.html"));
//QString path = QApplication::applicationDirPath() + "/BDmap.html";  //将html文件放入debug目录下
//qDebug() << __FUNCTION__ << path;

//ui.webEngineView->load(QUrl::fromLocalFile(path));

//ui.webEngineView->load(QUrl(u8"https://www.ditu6.com/walk/"));  // 加载目标网页

//ui.webEngineView->setZoomFactor(1.2);  // 调整缩放因子以适应页面大小

// ui.webEngineView->page()->setWebChannel(channel);

 /*
 QString htmlPath = QCoreApplication::applicationDirPath() + "Baidu_JS/BDmap.html";//从此html文件中读取内容后写入webview
 QUrl baseUrl = QCoreApplication::applicationDirPath() + "/Baidu_JS/";//外部对象，包括以下CSS和js文件
 QFile file(htmlPath);
 if (!file.open(QIODevice::ReadOnly))
 {
	 return;
 }
 QString htmlData = file.readAll().constData();
 file.close();
 ui.webEngineView->setHtml(htmlData, baseUrl);
 */

 //ui.webEngineView->show();

// connect(ui.webEngineView, &QWebEngineView::loadFinished,this, &TODOwidget::handleWebPageLoadFinished);
// connect(JSBridge, &bridge::DisplayPoint, this, &TODOwidget::DisplaySlot);