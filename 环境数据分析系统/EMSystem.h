#pragma once
#include"Data.h"

class EMSystem
{
	friend ostream& operator<< (ostream& out, EMSystem& obj);//������Ԫ�������������Ϣ
public:
	EMSystem();
	void getPeriodData();//��ѯָ�����У�ָ��ʱ�����Ϣ
	void getMomData();//��ѯָ�����У�ָ��ʱ����Ϣ
	void JudMonth();//����ָ�����������õ��·�
	void JudCity();//���в�ͬ����ָ���·ݿ���������õĳ���
	void PrimePollution();//�ж�ָ�����У�ָ���·ݵ���Ҫ��Ⱦ������
	void GetStandard();//��ȡ�ض�������ֵ��Χ
	void SetStandard();//�޸���ֵ��Χ��ȡ�µı���
private:
	vector<CityData>System;//�洢������е�һ��ʱ�������
	int N;//�������и���
};

//EMSystem::EMSystem()
//{
//	cout << "��������Ҫ��������ĳ�����������:";
//	cin >> N;
//	string cityname, filename;
//	for (int i = 0; i < N; i++)
//	{
//		cout << "��������Ҫ������е�����,�Լ���Ҫ�򿪵Ĵ������ݵ��ļ����ƣ�";
//		cin >> cityname >> filename;
//		CityData* temp = new CityData(cityname,filename);
//		System.push_back(*temp);//������н��
//		delete temp;//ɾ��temp;
//	}
//}

EMSystem::EMSystem()
{
	char n[10];
	ifstream infile;
	infile.open("�����ļ�.txt");
	infile.getline(n,10,'\n');//��ȡ��һλ
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
		System.push_back(*temp);//������н��
		delete temp;//ɾ��temp;
	}
}

//EMSystem::EMSystem()//����ʹ�ù��캯��
//{
//	N = 3;
//	string cityname1, filename1, cityname2, filename2, cityname3, filename3;
//	cityname1 = "����";
//	cityname2 = "�Ϻ�";
//	cityname3 = "�人";
//	filename1 = "�������������ձ�.txt";
//	filename2 = "�Ϻ����������ձ�.txt";
//	filename3 = "�人���������ձ�.txt";
//
//	CityData* temp1 = new CityData(cityname1, filename1);
//	CityData* temp2 = new CityData(cityname2, filename2);
//	CityData* temp3 = new CityData(cityname3, filename3);
//
//	System.push_back(*temp1);//������н��
//	System.push_back(*temp2);//������н��
//	System.push_back(*temp3);//������н��
//	delete temp1, temp2, temp3;//ɾ��temp;
//}



ostream& operator<< (ostream& out, EMSystem& obj)//�������ϵͳ��Ϣ
{
	cout << "�����и���ΪΪ��" <<obj.N<<endl;
	for (int i = 0; i < obj.N; i++)
		cout << obj.System[i];
	return out;
}

 void EMSystem::getPeriodData()//��ѯָ�����У�ָ��ʱ�����Ϣ
{
	 string cityname, startime, endtime;//��ȡ����������ֹʱ��
	 Date Start, End;//����������
	 cout << "������������ҵĳ��У���ʼʱ�䣬����ʱ�䣬����ʱ���ԣ�Year-Month-Day����ʽ����,������������߽�ʱ��" << endl;
	 cin >> cityname >> startime >> endtime;
	 Start = ToDate(startime);//���ú�������ת��Ϊdate��ʽ
	 End = ToDate(endtime);
	 int pos = -1;//�����������ڲ��ҳ��������±��
	 for (int i = 0; i < N; i++)
		 if (System[i].getname() == cityname)//��һ������
			 pos = i;
	 if (pos < 0) { cout << "������в�����" << endl; return; }
	 cout << cityname<<Start<<"��"<<End<<"�ļ���������£�" << endl;
	 for (int j = 0; j<System[pos].n; j++)
		 if(System[pos].City[j].date >= Start&& System[pos].City[j].date <= End)//��������ڷ�Χ��
			cout << System[pos].City[j];
}


void EMSystem::getMomData()//��ѯָ�����У�ָ��ʱ����Ϣ
 {
	string cityname,moment;//��ȡ����������ֹʱ��
	Date Moment;//����������
	cout << "������������ҵĳ��У�����ʱ�䣬����ʱ���ԣ�Year-Month-Day����ʽ����" << endl;
	cin >> cityname >> moment;
	Moment = ToDate(moment);//���ú�������ת��Ϊdate��ʽ
	int pos = -1;//�����������ڲ��ҳ��������±��
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cityname)//��һ������
			pos = i;
	if (pos < 0) { cout << "������в�����" << endl; return; }
	cout << cityname << Moment<< "�ļ���������£�" << endl;
	for (int j = 0; j < System[pos].n; j++)
		if (System[pos].City[j].date == Moment)//���ʱ�����
		{
			cout << System[pos].City[j];
			break;
		}
 }

void EMSystem::JudMonth()//����ָ�����������õ��·�
{
	string cname; 
	int MaxM = -1;//���AQI�·��±�
	int MinM = -1;//��СAQI�·��±�
	double Maxdex = -1;//����·�API
	double Mindex = 9999;//����·�API
	cout << "�������ѯ���е����֣�";
	cin >> cname;
	int pos = -1;//�����������ڲ��ҳ��������±��
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cname)//��һ������
			pos = i;
	for (int j = 0; j < 12; j++)//������������
	{
		if (System[pos].averAQI[j] < Mindex)//���Ի�ȡ����СapiС
		{
			MinM = j;//�����±�
			Mindex = System[pos].averAQI[j];//������СAPI
		}
		else if (System[pos].averAQI[j] >Maxdex)//���Ի�ȡ�����api��
		{
			MaxM = j;//�����±�
			Maxdex = System[pos].averAQI[j];//�������API
		}
	}
	cout << cname << "����������õ��·�Ϊ��" << MinM + 1 << "�£�" << "��ƽ��APIΪ��" << fixed << setprecision(1) << Mindex << endl;
	cout << cname << "�������������·�Ϊ��" << MaxM + 1 << "�£�" << "��ƽ��APIΪ��" << fixed << setprecision(1) << Maxdex << endl;
}

void EMSystem::JudCity()//��ȡָ���·ݿ���������õĳ���
{
	int mtemp;
	string nametemp;
	double Mindex = 9999;
	cout << "������Ҫ�Աȵ�ָ���·ݣ�";
	cin >> mtemp;
	mtemp--;//����ת��Ϊ�±�
	for(int i=0;i<N;i++)//��������
		if (System[i].averAQI[mtemp] < Mindex)//�ҵ���С�ĳ���
		{
			nametemp = System[i].getname();//���³�������
			Mindex = System[i].averAQI[mtemp];//����API
		}
	cout << mtemp + 1 << "�£�����������õĳ����ǣ�" << nametemp << "����ƽ��APIΪ��" << fixed << setprecision(1) << Mindex << endl;
}

void EMSystem::PrimePollution()//�ж�ָ�����У�ָ���·ݵ���Ҫ��Ⱦ������
{
	int montemp;
	string cname;
	string pollution1 = "ϸ������(PM2.5)";
	string pollution2 = "��������";
	string pollution3 = "������(PM10)";
	string pollution4 = "����8Сʱ";
	int maxdex = -1;//�����±�
	int Maxpollution = 0;
	int pos = -1;//�����������ڲ��ҳ��������±��
	int PollutionNum[4] = { 0,0,0,0 };//��¼ÿ����Ⱦ�����������
	//���У�0��ϸ������(PM2.5)��	1����������;		2:������;		3:����8Сʱ
	cout<< "������������ҵĳ��У������·�" << endl;
	cin >> cname >> montemp;
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cname)//��һ������
			pos = i;
	for (int i = 0; i < System[pos].n; i++)//������һ�����е�����
	{
		if (System[pos].City[i].date.month == montemp)//��Ŀ���·�
		{
			string temp;
			temp = System[pos].City[i].Pollution;
			if (temp == "ϸ������(PM2.5)" || temp.find(pollution1) != string::npos)//�Ǹ���Ⱦ����߰�������Ⱦ��
				PollutionNum[0]++;
			else if (temp == "��������" || temp.find(pollution2) != string::npos)//�Ǹ���Ⱦ����߰�������Ⱦ��
				PollutionNum[1]++;
			else if (temp == "������(PM10)" || temp.find(pollution3) != string::npos)//�Ǹ���Ⱦ����߰�������Ⱦ��
				PollutionNum[2]++;
			else if (temp == "����8Сʱ" || temp.find(pollution3) != string::npos)//�Ǹ���Ⱦ����߰�������Ⱦ��
				PollutionNum[2]++;
		}
	}

	for (int t = 0; t < 4; t++)//������Ҫ��Ⱦ������������Ԫ��ֵ
	{
		if (Maxpollution < PollutionNum[t])
		{
			Maxpollution = PollutionNum[t];
			maxdex = t;
		}
	}
	if (maxdex == 0)
		cout << cname << montemp << "����Ҫ����Ⱦ������Ϊ��ϸ������(PM2.5)������������Ϊ��" << Maxpollution << "��" << endl;
	else if (maxdex == 1)
		cout << cname << montemp << "����Ҫ����Ⱦ������Ϊ����������������������Ϊ��" << Maxpollution << "��" << endl;
	else if (maxdex == 2)
		cout << cname << montemp << "����Ҫ����Ⱦ������Ϊ��������(PM10)������������Ϊ��" << Maxpollution << "��" << endl;
	else if (maxdex == 3)
		cout << cname << montemp << "����Ҫ����Ⱦ������Ϊ������8Сʱ������������Ϊ��" << Maxpollution << "��" << endl;
}

void EMSystem::GetStandard()//��ȡ�ض�������ֵ��Χ
{
	string cname;
	int pos = -1;
	double MaxLevel[5] = { 0,0,0,0,0 };//ÿһ��������������ֵAQI
	double MinLevel[5] = { 999,999,999,999,999 };// ÿһ�������������СֵAQI
	//�����±��У�0���ţ�1������2�������Ⱦ��3���ж���Ⱦ��4���ض���Ⱦ
	cout << "������Ҫ��ȡ��ֵ��Χ�ĳ������ƣ�";
	cin >> cname;
	for (int i = 0; i < N; i++)
		if (System[i].getname() == cname)//��һ������
			pos = i;

	for (int j = 0; j < System[pos].n; j++)//����
	{
		if (System[pos].City[j].level == "��")//�������
		{
			if (System[pos].City[j].index > MaxLevel[0])//�������ֵ
				MaxLevel[0]=System[pos].City[j].index ;
			if (System[pos].City[j].index < MinLevel[0])//������Сֵ
				MinLevel[0] = System[pos].City[j].index;
		}

		if (System[pos].City[j].level == "��")//�������
		{
			if (System[pos].City[j].index > MaxLevel[1])//�������ֵ
				MaxLevel[1] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[1])//������Сֵ
				MinLevel[1] = System[pos].City[j].index;
		}
		
		if (System[pos].City[j].level == "�����Ⱦ")//����������Ⱦ
		{
			if (System[pos].City[j].index > MaxLevel[2])//�������ֵ
				MaxLevel[2] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[2])//������Сֵ
				MinLevel[2] = System[pos].City[j].index;
		}
		if (System[pos].City[j].level == "�ж���Ⱦ")//������ж���Ⱦ
		{
			if (System[pos].City[j].index > MaxLevel[3])//�������ֵ
				MaxLevel[3] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[3])//������Сֵ
				MinLevel[3] = System[pos].City[j].index;
		}

		if (System[pos].City[j].level == "�ض���Ⱦ")//������ض���Ⱦ
		{
			if (System[pos].City[j].index > MaxLevel[4])//�������ֵ
				MaxLevel[4] = System[pos].City[j].index;
			if (System[pos].City[j].index < MinLevel[4])//������Сֵ
				MinLevel[4] = System[pos].City[j].index;
		}
	}
	cout <<setiosflags(ios::left)<<setw(40)<< "��������Ϊ���š�����ֵ��Χ��" << MinLevel[0] << '~' << MaxLevel[0] << endl;
	cout << setiosflags(ios::left) << setw(40) << "��������Ϊ����������ֵ��Χ��" << MinLevel[1] << '~' << MaxLevel[1] << endl;
	cout << setiosflags(ios::left) << setw(40) << "��������Ϊ�������Ⱦ������ֵ��Χ��" << MinLevel[2] << '~' << MaxLevel[2] << endl;
	cout << setiosflags(ios::left) << setw(40) << "��������Ϊ���ж���Ⱦ������ֵ��Χ��" << MinLevel[3] << '~' << MaxLevel[3] << endl;
	cout << setiosflags(ios::left) << setw(40) << "��������Ϊ���ض���Ⱦ������ֵ��Χ��" << MinLevel[4] << '~' << MaxLevel[4] << endl;
}

void EMSystem::SetStandard()//������ֵ��Χ
{
	int a1, b1, a2, b2, a3, b3, a4, b4, a5, b5;//�µ���ֵ��Χ
	string cname; int nmonth = -1;
	int pos = -1;
	cout << "�����������µ���ֵ��Χ" << endl;
	cout << "�����롰�š�����ֵ��Χ(PS:�������������������ޣ���";
	cin >> a1 >> b1;
	cout << "�����롰��������ֵ��Χ(PS:�������������������ޣ���";
	cin >> a2 >> b2;
	cout << "�����롰�����Ⱦ������ֵ��Χ(PS:�������������������ޣ���";
	cin >> a3 >> b3;
	cout << "�����롰�ж���Ⱦ������ֵ��Χ(PS:�������������������ޣ���";
	cin >> a4 >> b4;
	cout << "�����롰�ض���Ⱦ������ֵ��Χ(PS:�������������������ޣ���";
	cin >> a5 >> b5;

	cout << "������Ҫ�޸ĵĳ����Լ��·ݣ�";
	cin >> cname >> nmonth;
	for (int i = 0; i < N; i++)//����Ŀ�ĳ���
		if (System[i].getname() == cname)//��һ������
			pos = i;

	ofstream outfile;
	outfile.open(cname.c_str(), ios::out);
	outfile<<"���"<<'\t' <<"����" << '\t' << "AQIָ��" << '\t' << "��Ҫ��Ⱦ��" << '\t' << "����" << '\t' << "������������" << endl;
	for (int j = 0; j < System[pos].n; j++)//����Ŀ���·�
	{
		if (System[pos].City[j].date.month == nmonth)//��Ŀ���·�
		{
			MonitorData data = System[pos].City[j];
			int AQItemp = System[pos].City[j].index;
			if (a1 <= AQItemp&& AQItemp <= b1)//���µġ��š���Χ
				data.level = "��";
			if (a2 <= AQItemp && AQItemp <= b2)//���µġ�������Χ
				data.level = "��";
			if (a3 <= AQItemp && AQItemp <= b3)//���µġ������Ⱦ����Χ
				data.level = "�����Ⱦ";
			if (a4 <= AQItemp && AQItemp <= b4)//���µġ��ж���Ⱦ����Χ
				data.level = "�ж���Ⱦ";
			if (a5 <= AQItemp && AQItemp <= b5)//���µġ��ض���Ⱦ����Χ
				data.level = "�ض���Ⱦ";
			outfile << data.Num << '\t' << data.city << '\t' << data.index << '\t' << data.Pollution << '\t';
			outfile << data.date.year << '-';
			if (data.date.month < 10)//���·�Ϊ��λ���������λ
				outfile << '0';
			outfile << data.date.month << '-';
			if (data.date.day < 10)//������Ϊ��λ���������λ
				outfile << '0';
			outfile << data.date.day << '\t';
				outfile<< data.level << endl;
		}
		
	}
	cout << "����ɹ����뵽��cpp�ļ������ļ����ҵ���Ϊ" << cname << "���ļ�" << endl;
}