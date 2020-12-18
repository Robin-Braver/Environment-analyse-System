#pragma once
#include"stdafx.h"
#include"Date.h"
vector<string> Spilt(string s, char ch);//�ַ�����ֺ���



struct MonitorData//ÿһ����������
{
	int Num=0;//���
	string city;//����
	int index=0;//AQIָ��
	string Pollution;//��Ҫ��Ⱦ��
	Date date;//����
	string level;//������������
};

ostream& operator<< (ostream& out, MonitorData& obj)//��������������
{
	cout << obj.Num << "	" << obj.city << "	" << obj.index << "	" <<setw(40)<< obj.Pollution << "	" << obj.date << "		" << obj.level << endl;
	return out;
}

class EMSystem;
class CityData//һ������һ��ʱ��������
{
	friend class EMSystem;
	friend ostream& operator<< (ostream& out, CityData& obj);
public:
	CityData(string cityname, string filename);//����Ϊ���ļ�����,�Լ���Ӧ��������
	string getname() { return _cityname; }
	int getsize() {return n; }
	void CalavAQI();//����ÿ����ƽ��AQI
	void ShowavAQI();//���ÿ����ƽ��AQI
protected:
	string _cityname;//������
	vector<MonitorData> City;//�洢������ݵ�����
	int n;//���ݸ���
	double averAQI[12];//��¼ÿ���µ�ƽ��AQI��������ÿ��Ԫ�ض�Ӧ��Ӧ�·ݵ�ƽ��AQI
	
};

CityData::CityData(string cityname,string filename)//���캯��
{
	CityData::n = 0;
	_cityname = cityname;
	if (filename.empty()) { cout << "���ļ����ַǷ�" << endl; }//����Ϊ��
	ifstream infile;
	infile.open(filename);//��ָ���ļ�
	if (infile.fail())//�ļ���ʧ��
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(1);
	}

	char* str = new char[200];
	infile.getline(str, 200, '\n');//��ȡһ������
	delete []str;//Ŀ�����ڵڶ��в�����Ч����
	
	string date;//����
	while (!infile.eof())//��ȡ�ļ�ÿһ��
	{
		MonitorData* temp = new MonitorData;
		infile >> (temp->Num) >> (temp->city) >> (temp->index) >> (temp->Pollution) >> date >> (temp->level);
		//���ζ�ȡÿһ�е�����

		temp->date = ToDate(date);//���ú�������ת��Ϊdate��
		City.push_back(*temp);//���뵽������
		(CityData::n)++;
		delete temp;//ɾ����ָ̬��
	}
	infile.close();
	CalavAQI();//��ʼ��ƽ��API
}

void CityData::CalavAQI()//����ƽ��AQI
{
	double totalAPI[12];//ͬһ���·�API���ܺ�
	int nday[12];//����ÿ���µ�����
	for (int j = 0; j < 12; j++)//��ʼ��Ϊ0
	{
		totalAPI[j] = 0.0;
		nday[j] = 0;
	}
	for (int i = 0; i < CityData::n; i++)
	{
		int nmonth = City[i].date.month;//��ȡ�����ݵ��·�
		totalAPI[nmonth-1] += City[i].index;//�ۼ����
		nday[nmonth-1]++;//��Ӧ��¼������һ
	}
	for (int t = 0; t < 12; t++)
		averAQI[t] = totalAPI[t] / nday[t];//�ܺͳ�������
}

void CityData::ShowavAQI()
{
	for (int i = 0; i < 12; i++)
		cout <<_cityname<< "��" << i + 1 << "���µ�ƽ��AQIΪ��" << fixed << setprecision(1) << averAQI[i] << endl;
}


ostream& operator<< (ostream& out, CityData& obj)//�������ÿ������һ��ʱ��ļ������
{
	cout << "������Ϊ��" << obj.getname() << '\t' << "��õ���������Ϊ��" << obj.getsize() << endl;
	for (int i = 0; i < obj.n; i++)
		cout << obj.City[i];
	return out;
}

