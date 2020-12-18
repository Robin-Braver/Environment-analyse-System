#pragma once
struct Date//������
{
	//�ա��¡���
	int year = 0;
	int month = 0;
	int day = 0;
	bool operator<=(Date& obj);//�����ж�С��
	bool operator>=(Date& obj);//�����жϴ���
	bool operator==(Date& obj);//�����ж����
};

ostream& operator<< (ostream& out, Date& obj)//�����������
{
	cout << obj.year << '-';
	if (obj.month < 10)//���·�Ϊ��λ���������λ
		cout << '0';
	cout << obj.month << '-';
	if (obj.day < 10)//������Ϊ��λ���������λ
		cout << '0';
	cout << obj.day;
	return out;
}

bool Date::operator<=(Date& obj)//�����ж����ڴ�С
{
	if (year < obj.year)//���С
		return true;
	else if (year == obj.year)//������
	{
		if (month < obj.month)//�·�С
			return true;
		else if (month == obj.month)//�·����
			if (day <=obj.day)//���ڸ�С
				return true;
			else
				return false;
		else
			return false;
	}
	else
		return false;//����Ҫô���Ҫô��
}

inline bool Date::operator>=(Date& obj)//�����ж����ڴ�С
{
	if (year > obj.year)//��ݴ�
		return true;
	else if (year == obj.year)//������
	{
		if (month >obj.month)//�·ݴ�
			return true;
		else if (month == obj.month)//�·����
			if (day>= obj.day)//���ڸ���
				return true;
			else
				return false;
		else
			return false;
	}
	else
	return false;//����Ҫô���ҪôС
}

inline bool Date::operator==(Date& obj)
{
	if (year == obj.year && month == obj.month && day == obj.day)//������ȫ���
		return true;
	return false;
}


vector<string> Spilt(string s, char ch)//�ַ�����ֺ���
{
	s.push_back(ch);//���ַ���ĩ�˲���һ���ָ��� ������ʶ��
	int start = 0, end = 0, size = s.size();//�������Ӵ���ʼ�����λ��
	vector<string> vs;

	for (int i = 0; i < size; i++)
	{
		if (s[i] == ch)//�ҵ���ʶ��
		{
			end = i;
			string temp = s.substr(start, end - start);//��ȡ�Ӵ�
			start = i + 1;
			vs.push_back(temp);
		}
	}
	return vs;//�����Ӵ�����
}

Date ToDate(string date)//����year-month-day���͵��ַ�����ʽ����ת��ΪDate��������
{
	Date Dtemp;
	vector<string>stemp;//��ŷָ����ڵ�����
	stemp = Spilt(date, '-');//���ú��������ڵ������շָ�
	int ntemp[3] = { 0,0,0 };//�洢������������
	for (unsigned i = 0; i < stemp.size(); i++)
		ntemp[i] = atoi(stemp[i].c_str());
	Dtemp.year = ntemp[0];
	Dtemp.month = ntemp[1];
	Dtemp.day = ntemp[2];
	return Dtemp;
}