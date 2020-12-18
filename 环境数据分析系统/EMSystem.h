#pragma once
#include"Data.h"

class EMSystem
{
	friend ostream& operator<< (ostream& out, EMSystem& obj);//定义友元函数重载输出信息
public:
	EMSystem();
	void getPeriodData();//查询指定城市，指定时间段信息
	void getMomData();//查询指定城市，指定时间信息
	void JudMonth();//评判指定城市最差最好的月份
	void JudCity();//评判不同城市指定月份空气质量最好的城市
	void PrimePollution();//判断指定城市，指定月份的主要污染物类型
	void GetStandard();//获取特定城市阈值范围
	void SetStandard();//修改阈值范围获取新的报表
private:
	vector<CityData>System;//存储多个城市的一段时间的容器
	int N;//包含城市个数
};

//EMSystem::EMSystem()
//{
//	cout << "请输入需要分析处理的城市样本个数:";
//	cin >> N;
//	string cityname, filename;
//	for (int i = 0; i < N; i++)
//	{
//		cout << "请输入需要处理城市的名称,以及需要打开的处理数据的文件名称：";
//		cin >> cityname >> filename;
//		CityData* temp = new CityData(cityname,filename);
//		System.push_back(*temp);//插入城市结点
//		delete temp;//删除temp;
//	}
//}

EMSystem::EMSystem()
{
	char n[10];
	ifstream infile;
	infile.open("配置文件.txt");
	infile.getline(n,10,'\n');//获取第一位
	N= int(n[0] - 48);
	for (int i = 1; n[i]!='\0'; i++)
	{
		N = N * 10;
		N += (n[i] - 48);
	}
	string cityname, filename;
	while (!infile.eof())
	{
		infile >> cityname >> filename;
		CityData* temp = new CityData(cityname,filename);
		System.push_back(*temp);//插入城市结点
		delete temp;//删除temp;
	}
}

//EMSystem::EMSystem()//测试使用构造函数
//{
//	N = 3;
//	string cityname1, filename1, cityname2, filename2, cityname3, filename3;
//	cityname1 = "北京";
//	cityname2 = "上海";
//	cityname3 = "武汉";
//	filename1 = "北京空气质量日报.txt";
//	filename2 = "上海空气质量日报.txt";
//	filename3 = "武汉空气质量日报.txt";
//
//	CityData* temp1 = new CityData(cityname1, filename1);
//	CityData* temp2 = new CityData(cityname2, filename2);
//	CityData* temp3 = new CityData(cityname3, filename3);
//
//	System.push_back(*temp1);//插入城市结点
//	System.push_back(*temp2);//插入城市结点
//	System.push_back(*temp3);//插入城市结点
//	delete temp1, temp2, temp3;//删除temp;
//}



ostream& operator<< (ostream& out, EMSystem& obj)//重载输出系统信息
{
	cout << "检测城市个数为为：" <<obj.N<<endl;
	for (int i = 0; i < obj.N; i++)
		cout << obj.System[i];
	return out;
}

 void EMSystem::getPeriodData()//查询指定城市，指定时间段信息
{
	 string cityname, startime, endtime;//读取城市名，起止时间
	 Date Start, End;//定义日期类
	 cout << "请依次输入查找的城市，开始时间，结束时间，其中时间以（Year-Month-Day）形式输入,且输出不包括边界时间" << endl;
	 cin >> cityname >> startime >> endtime;
	 Start = ToDate(startime);//调用函数将其转化为date格式
	 End = ToDate(endtime);
	 int pos = -1;//辅助变量用于查找城市所在下标号
	 for (int i = 0; i < N; i++)
		 if (System[i].getname() == cityname)//是一个城市
			 pos = i;
	 if (pos < 0) { cout << "输入城市不存在" << endl; return; }
	 cout << cityname<<Start<<"到"<<End<<"的检测数据如下：" << endl;
	 for (int j = 0; j<System[pos].n; j++)
		 if(System[pos].City[j].date >= Start&& System[pos].City[j].date <= End)//如果在日期范围内
			cout << System[pos].City[j];
}


void EMSystem::getMomData()//查询指定城市，指定时间信息
 {
	string cityname,moment;//读取城市名，起止时间
	Date Moment;//定义日期类
	cout << "请依次输入查找的城市，查找时间，其中时间以（Year-Month-Day）形式输入" << endl;
	cin >> cityname >> moment;
	Moment = ToDate(moment);//调用函数将其转化为date格式
	int pos = -1;//辅助变量用于查找城市所在下标号
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cityname)//是一个城市
			pos = i;
	if (pos < 0) { cout << "输入城市不存在" << endl; return; }
	cout << cityname << Moment<< "的检测数据如下：" << endl;
	for (int j = 0; j < System[pos].n; j++)
		if (System[pos].City[j].date == Moment)//如果时间相等
		{
			cout << System[pos].City[j];
			break;
		}
 }

void EMSystem::JudMonth()//评判指定城市最差最好的月份
{
	string cname; 
	int MaxM = -1;//最大AQI月份下标
	int MinM = -1;//最小AQI月份下标
	double Maxdex = -1;//最差月份API
	double Mindex = 9999;//最好月份API
	cout << "请输入查询城市的名字：";
	cin >> cname;
	int pos = -1;//辅助变量用于查找城市所在下标号
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cname)//是一个城市
			pos = i;
	for (int j = 0; j < 12; j++)//遍历整个数组
	{
		if (System[pos].averAQI[j] < Mindex)//比以获取的最小api小
		{
			MinM = j;//更新下标
			Mindex = System[pos].averAQI[j];//更新最小API
		}
		else if (System[pos].averAQI[j] >Maxdex)//比以获取的最大api大
		{
			MaxM = j;//更新下标
			Maxdex = System[pos].averAQI[j];//更新最大API
		}
	}
	cout << cname << "空气质量最好的月份为：" << MinM + 1 << "月，" << "其平均API为：" << fixed << setprecision(1) << Mindex << endl;
	cout << cname << "空气质量最差的月份为：" << MaxM + 1 << "月，" << "其平均API为：" << fixed << setprecision(1) << Maxdex << endl;
}

void EMSystem::JudCity()//获取指定月份空气质量最好的城市
{
	int mtemp;
	string nametemp;
	double Mindex = 9999;
	cout << "请输入要对比的指定月份：";
	cin >> mtemp;
	mtemp--;//将其转化为下标
	for(int i=0;i<N;i++)//遍历数组
		if (System[i].averAQI[mtemp] < Mindex)//找到更小的城市
		{
			nametemp = System[i].getname();//更新城市名称
			Mindex = System[i].averAQI[mtemp];//更新API
		}
	cout << mtemp + 1 << "月，空气质量最好的城市是：" << nametemp << "，其平均API为：" << fixed << setprecision(1) << Mindex << endl;
}

void EMSystem::PrimePollution()//判断指定城市，指定月份的主要污染物类型
{
	int montemp;
	string cname;
	string pollution1 = "细颗粒物(PM2.5)";
	string pollution2 = "二氧化氮";
	string pollution3 = "颗粒物(PM10)";
	string pollution4 = "臭氧8小时";
	int maxdex = -1;//辅助下标
	int Maxpollution = 0;
	int pos = -1;//辅助变量用于查找城市所在下标号
	int PollutionNum[4] = { 0,0,0,0 };//记录每种污染物种类的数量
	//其中：0：细颗粒物(PM2.5)；	1：二氧化氮;		2:颗粒物;		3:臭氧8小时
	cout<< "请依次输入查找的城市，查找月份" << endl;
	cin >> cname >> montemp;
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cname)//是一个城市
			pos = i;
	for (int i = 0; i < System[pos].n; i++)//遍历着一个城市的数据
	{
		if (System[pos].City[i].date.month == montemp)//是目的月份
		{
			string temp;
			temp = System[pos].City[i].Pollution;
			if (temp == "细颗粒物(PM2.5)" || temp.find(pollution1) != string::npos)//是该污染物或者包含该污染物
				PollutionNum[0]++;
			else if (temp == "二氧化氮" || temp.find(pollution2) != string::npos)//是该污染物或者包含该污染物
				PollutionNum[1]++;
			else if (temp == "颗粒物(PM10)" || temp.find(pollution3) != string::npos)//是该污染物或者包含该污染物
				PollutionNum[2]++;
			else if (temp == "臭氧8小时" || temp.find(pollution3) != string::npos)//是该污染物或者包含该污染物
				PollutionNum[2]++;
		}
	}

	for (int t = 0; t < 4; t++)//找最主要污染物，即数组内最大元素值
	{
		if (Maxpollution < PollutionNum[t])
		{
			Maxpollution = PollutionNum[t];
			maxdex = t;
		}
	}
	if (maxdex == 0)
		cout << cname << montemp << "月主要的污染物类型为：细颗粒物(PM2.5)，被困扰天数为：" << Maxpollution << "天" << endl;
	else if (maxdex == 1)
		cout << cname << montemp << "月主要的污染物类型为：二氧化氮，被困扰天数为：" << Maxpollution << "天" << endl;
	else if (maxdex == 2)
		cout << cname << montemp << "月主要的污染物类型为：颗粒物(PM10)，被困扰天数为：" << Maxpollution << "天" << endl;
	else if (maxdex == 3)
		cout << cname << montemp << "月主要的污染物类型为：臭氧8小时，被困扰天数为：" << Maxpollution << "天" << endl;
}

void EMSystem::GetStandard()//获取特定城市阈值范围
{
	string cname;
	int pos = -1;
	double MaxLevel[5] = { 0,0,0,0,0 };//每一项空气质量的最大值AQI
	double MinLevel[5] = { 999,999,999,999,999 };// 每一项空气质量的最小值AQI
	//其中下标中：0：优；1：良；2：轻度污染；3：中度污染；4：重度污染
	cout << "请输入要获取阈值范围的城市名称：";
	cin >> cname;
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cname)//是一个城市
			pos = i;

	for (int j = 0; j < System[pos].n; j++)//遍历
	{
		if (System[pos].City[j].level == "优")//如果是优
		{
			if (System[pos].City[j].index > MaxLevel[0])//更新最大值
				MaxLevel[0]=System[pos].City[j].index ;
			if (System[pos].City[j].index < MinLevel[0])//更新最小值
				MinLevel[0] = System[pos].City[j].index;
		}

		if (System[pos].City[j].level == "良")//如果是良
		{
			if (System[pos].City[j].index > MaxLevel[1])//更新最大值
				MaxLevel[1] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[1])//更新最小值
				MinLevel[1] = System[pos].City[j].index;
		}
		
		if (System[pos].City[j].level == "轻度污染")//如果是轻度污染
		{
			if (System[pos].City[j].index > MaxLevel[2])//更新最大值
				MaxLevel[2] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[2])//更新最小值
				MinLevel[2] = System[pos].City[j].index;
		}
		if (System[pos].City[j].level == "中度污染")//如果是中度污染
		{
			if (System[pos].City[j].index > MaxLevel[3])//更新最大值
				MaxLevel[3] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[3])//更新最小值
				MinLevel[3] = System[pos].City[j].index;
		}

		if (System[pos].City[j].level == "重度污染")//如果是重度污染
		{
			if (System[pos].City[j].index > MaxLevel[4])//更新最大值
				MaxLevel[4] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[4])//更新最小值
				MinLevel[4] = System[pos].City[j].index;
		}
	}
	cout <<setiosflags(ios::left)<<setw(40)<< "空气质量为“优”的阈值范围：" << MinLevel[0] << '~' << MaxLevel[0] << endl;
	cout << setiosflags(ios::left) << setw(40) << "空气质量为“良”的阈值范围：" << MinLevel[1] << '~' << MaxLevel[1] << endl;
	cout << setiosflags(ios::left) << setw(40) << "空气质量为“轻度污染”的阈值范围：" << MinLevel[2] << '~' << MaxLevel[2] << endl;
	cout << setiosflags(ios::left) << setw(40) << "空气质量为“中度污染”的阈值范围：" << MinLevel[3] << '~' << MaxLevel[3] << endl;
	cout << setiosflags(ios::left) << setw(40) << "空气质量为“重度污染”的阈值范围：" << MinLevel[4] << '~' << MaxLevel[4] << endl;
}

void EMSystem::SetStandard()//设置阈值范围
{
	int a1, b1, a2, b2, a3, b3, a4, b4, a5, b5;//新的阈值范围
	string cname; int nmonth = -1;
	int pos = -1;
	cout << "请依次输入新的阈值范围" << endl;
	cout << "请输入“优”的阈值范围(PS:先输入下限再输入上限）：";
	cin >> a1 >> b1;
	cout << "请输入“良”的阈值范围(PS:先输入下限再输入上限）：";
	cin >> a2 >> b2;
	cout << "请输入“轻度污染”的阈值范围(PS:先输入下限再输入上限）：";
	cin >> a3 >> b3;
	cout << "请输入“中度污染”的阈值范围(PS:先输入下限再输入上限）：";
	cin >> a4 >> b4;
	cout << "请输入“重度污染”的阈值范围(PS:先输入下限再输入上限）：";
	cin >> a5 >> b5;

	cout << "请输入要修改的城市以及月份：";
	cin >> cname >> nmonth;
	for (int i = 0; i < N; i++)//查找目的城市
		if (System[i].getname() == cname)//是一个城市
			pos = i;

	ofstream outfile;
	outfile.open(cname.c_str(), ios::out);
	outfile<<"编号"<<'\t' <<"城市" << '\t' << "AQI指数" << '\t' << "首要污染物" << '\t' << "日期" << '\t' << "空气质量级别" << endl;
	for (int j = 0; j < System[pos].n; j++)//查找目的月份
	{
		if (System[pos].City[j].date.month == nmonth)//是目的月份
		{
			MonitorData data = System[pos].City[j];
			int AQItemp = System[pos].City[j].index;
			if (a1 <= AQItemp&& AQItemp <= b1)//在新的“优”范围
				data.level = "优";
			if (a2 <= AQItemp && AQItemp <= b2)//在新的“良”范围
				data.level = "良";
			if (a3 <= AQItemp && AQItemp <= b3)//在新的“轻度污染”范围
				data.level = "轻度污染";
			if (a4 <= AQItemp && AQItemp <= b4)//在新的“中度污染”范围
				data.level = "中度污染";
			if (a5 <= AQItemp && AQItemp <= b5)//在新的“重度污染”范围
				data.level = "重度污染";
			outfile << data.Num << '\t' << data.city << '\t' << data.index << '\t' << data.Pollution << '\t';
			outfile << data.date.year << '-';
			if (data.date.month < 10)//当月分为个位数是输出两位
				outfile << '0';
			outfile << data.date.month << '-';
			if (data.date.day < 10)//当日期为个位数是输出两位
				outfile << '0';
			outfile << data.date.day << '\t';
				outfile<< data.level << endl;
		}
		
	}
	cout << "输出成功！请到“cpp文件所在文件夹找到名为" << cname << "的文件" << endl;
}