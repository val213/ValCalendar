#pragma once
#include<QString>
struct EVENT
{
	int event_id;
	QString event_name;
	QString event_date;
	QString event_starttime;
	QString event_endtime;
	QString event_content;
	QString event_type;
	int urgentdegree;

	bool operator==(const EVENT& other) const
	{
		return (event_id == other.event_id &&
			event_name == other.event_name &&
			event_date == other.event_date &&
			event_starttime == other.event_starttime &&
			event_endtime == other.event_endtime &&
			event_content == other.event_content &&
			event_type == other.event_type &&
			urgentdegree == other.urgentdegree);
	}

};