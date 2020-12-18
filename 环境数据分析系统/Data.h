#pragma once
#include"stdafx.h"
#include"Date.h"
vector<string> Spilt(string s, char ch);//字符串拆分函数



struct MonitorData//每一项监测数据类
{
	int Num=0;//编号
	string city;//城市
	int index=0;//AQI指数
	string Pollution;//首要污染物
	Date date;//日期
	string level;//空气质量级别
};

ostream& operator<< (ostream& out, MonitorData& obj)//重载输出监测数据
{
	cout << obj.Num << "	" << obj.city << "	" << obj.index << "	" <<setw(40)<< obj.Pollution << "	" << obj.date << "		" << obj.level << endl;
	return out;
}

class EMSystem;
class CityData//一个城市一段时间监测数据
{
	friend class EMSystem;
	friend ostream& operator<< (ostream& out, CityData& obj);
public:
	CityData(string cityname, string filename);//参数为打开文件名称,以及对应城市名称
	string getname() { return _cityname; }
	int getsize() {return n; }
	void CalavAQI();//计算每个月平均AQI
	void ShowavAQI();//输出每个月平均AQI
protected:
	string _cityname;//城市名
	vector<MonitorData> City;//存储检测数据的容器
	int n;//数据个数
	double averAQI[12];//记录每个月的平均AQI，数组中每个元素对应相应月份的平均AQI
	
};

CityData::CityData(string cityname,string filename)//构造函数
{
	CityData::n = 0;
	_cityname = cityname;
	if (filename.empty()) { cout << "打开文件名字非法" << endl; }//名字为空
	ifstream infile;
	infile.open(filename);//打开指定文件
	if (infile.fail())//文件打开失败
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}

	char* str = new char[200];
	infile.getline(str, 200, '\n');//读取一行数据
	delete []str;//目的在于第二行才是有效数据
	
	string date;//日期
	while (!infile.eof())//读取文件每一行
	{
		MonitorData* temp = new MonitorData;
		infile >> (temp->Num) >> (temp->city) >> (temp->index) >> (temp->Pollution) >> date >> (temp->level);
		//依次读取每一行的内容

		temp->date = ToDate(date);//调用函数将其转换为date型
		City.push_back(*temp);//插入到容器中
		(CityData::n)++;
		delete temp;//删除动态指针
	}
	infile.close();
	CalavAQI();//初始化平均API
}

void CityData::CalavAQI()//计算平均AQI
{
	double totalAPI[12];//同一个月份API的总和
	int nday[12];//计算每个月的天数
	for (int j = 0; j < 12; j++)//初始化为0
	{
		totalAPI[j] = 0.0;
		nday[j] = 0;
	}
	for (int i = 0; i < CityData::n; i++)
	{
		int nmonth = City[i].date.month;//获取此数据的月份
		totalAPI[nmonth-1] += City[i].index;//累计求和
		nday[nmonth-1]++;//对应记录天数加一
	}
	for (int t = 0; t < 12; t++)
		averAQI[t] = totalAPI[t] / nday[t];//总和除以天数
}

void CityData::ShowavAQI()
{
	for (int i = 0; i < 12; i++)
		cout <<_cityname<< "第" << i + 1 << "个月的平均AQI为：" << fixed << setprecision(1) << averAQI[i] << endl;
}


ostream& operator<< (ostream& out, CityData& obj)//重载输出每个城市一段时间的监测数据
{
	cout << "检测城市为：" << obj.getname() << '\t' << "获得的样本个数为：" << obj.getsize() << endl;
	for (int i = 0; i < obj.n; i++)
		cout << obj.City[i];
	return out;
}

