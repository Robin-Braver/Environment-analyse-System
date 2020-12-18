#pragma once
struct Date//日期类
{
	//日、月、年
	int year = 0;
	int month = 0;
	int day = 0;
	bool operator<=(Date& obj);//重载判断小于
	bool operator>=(Date& obj);//重载判断大于
	bool operator==(Date& obj);//重载判断相等
};

ostream& operator<< (ostream& out, Date& obj)//重载输出日期
{
	cout << obj.year << '-';
	if (obj.month < 10)//当月分为个位数是输出两位
		cout << '0';
	cout << obj.month << '-';
	if (obj.day < 10)//当日期为个位数是输出两位
		cout << '0';
	cout << obj.day;
	return out;
}

bool Date::operator<=(Date& obj)//重载判断日期大小
{
	if (year < obj.year)//年份小
		return true;
	else if (year == obj.year)//年份相等
	{
		if (month < obj.month)//月份小
			return true;
		else if (month == obj.month)//月份相等
			if (day <=obj.day)//日期更小
				return true;
			else
				return false;
		else
			return false;
	}
	else
		return false;//否则要么相等要么大
}

inline bool Date::operator>=(Date& obj)//重载判断日期大小
{
	if (year > obj.year)//年份大
		return true;
	else if (year == obj.year)//年份相等
	{
		if (month >obj.month)//月份大
			return true;
		else if (month == obj.month)//月份相等
			if (day>= obj.day)//日期更大
				return true;
			else
				return false;
		else
			return false;
	}
	else
	return false;//否则要么相等要么小
}

inline bool Date::operator==(Date& obj)
{
	if (year == obj.year && month == obj.month && day == obj.day)//年月日全相等
		return true;
	return false;
}


vector<string> Spilt(string s, char ch)//字符串拆分函数
{
	s.push_back(ch);//在字符串末端插入一个分隔符 方便拆分识别
	int start = 0, end = 0, size = s.size();//定义拆分子串起始与结束位置
	vector<string> vs;

	for (int i = 0; i < size; i++)
	{
		if (s[i] == ch)//找到标识符
		{
			end = i;
			string temp = s.substr(start, end - start);//获取子串
			start = i + 1;
			vs.push_back(temp);
		}
	}
	return vs;//返回子串数组
}

Date ToDate(string date)//将（year-month-day）型的字符串格式日期转化为Date类型日期
{
	Date Dtemp;
	vector<string>stemp;//存放分隔日期的数组
	stemp = Spilt(date, '-');//调用函数将日期的年月日分隔
	int ntemp[3] = { 0,0,0 };//存储整形日期数组
	for (unsigned i = 0; i < stemp.size(); i++)
		ntemp[i] = atoi(stemp[i].c_str());
	Dtemp.year = ntemp[0];
	Dtemp.month = ntemp[1];
	Dtemp.day = ntemp[2];
	return Dtemp;
}