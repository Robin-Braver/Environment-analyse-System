#include"EMSystem.h"



int main()
{
	cout << "*********************************************************" << endl;
	cout << "*                                                       *" << endl;
	cout << "*" << "\t" << "\t" << "��ӭʹ��STAR�������ݷ���ϵͳ" << "\t" << "\t" << "*" << endl;
	cout << "*                                                       *" << endl;
	cout << "*" << "\t" << "\t" << "     " << " ���ڿ�ʼ��������" << "\t" << "\t" << "\t" << "*" << endl;
	cout << "*                                                       *" << endl;
	cout << "*********************************************************" << endl;
	EMSystem controler;//��������
	cout << "�ļ�����ɹ�������" << endl;
	while (1)
	{
		//������
		cout << "*********************************************************" << endl;
		cout << "*                                                       *" << endl;
		cout << "*" << "\t" << "\t" << "��ӭʹ��STAR�������ݷ���ϵͳ" << "\t" << "\t" << "*" << endl;
		cout << "*                                                       *" << endl;
		cout << "*" << "\t" << "\t" << "     " << " 1��ʹ����ع���" << "\t" << "\t" << "\t" << "*" << endl;
		cout << "*" << "\t" << "\t" << "    " << "  0���˳�ϵͳ" << "\t" << "\t" << "\t" << "*" << endl;
		cout << "*                                                       *" << endl;
		cout << "*********************************************************" << endl;
		cout << "��ѡ��Ȩ��ģʽ��";

		int choice1;//ѡ��Ȩ��
		cin >> choice1;
		
		if (choice1 == 1)
		{
			int flag = 1;
			while (flag == 1)
			{
				system("cls");
				cout << "*********************************************************************************" << endl;
				cout << "*                                                                               *" << endl;
				cout << "*" << "\t" << "\t" << "��ӭʹ��STAR�������ݷ���ϵͳ" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t" << "    " << "��ǰ״̬��ʹ��ϵͳ״̬" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*                                                                               *" << endl;
				cout << "*" << "\t" << "\t" << "1����ȡָ�����С�ָ��ʱ�����Ϣ" << "\t" << "\t" << "\t"<<  "\t" << "\t""*" << endl;
				cout << "*" << "\t" << "\t" << "2����ȡָ�����С�ָ��ʱ����Ϣ	" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "3����ȡָ����������Լ������·ݼ���AQI" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t" << "4���Ա�ָ���·ݿ���������õĳ���" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "5���ж�ָ�����С�ָ���·ݵ���Ҫ��Ⱦ������" << "\t" << "\t"  << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "6����ȡָ������AQI��ֵ" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "7��Ϊָ����������µ���ֵ�����ĳ���·ݵ�����" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t" << "0������" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*                                                                               *" << endl;
				cout << "*********************************************************************************" << endl;

				int choice2;
				cout << "��ѡ����Ҫʹ�õķ���";
				cin >> choice2;
				system("cls");
				switch (choice2)
				{
				case 0:
					flag = 0;
					break;
				case 1:
					controler.getPeriodData();
					cout << "��ѡ��������Ĳ���:" << endl;
					cout << "1���������в���" << endl;
					cout << "0��������һ��" << endl;
					cin >> flag;
					system("cls");
					break;
				case 2:
					controler.getMomData();
					cout << "��ѡ��������Ĳ���:" << endl;
					cout << "1���������в���" << endl;
					cout << "0��������һ��" << endl;
					cin >> flag;
					system("cls");
					break;
				case 3:
					controler.JudMonth();//����ָ�����������õ��·�
					cout << "��ѡ��������Ĳ���:" << endl;
					cout << "1���������в���" << endl;
					cout << "0��������һ��" << endl;
					cin >> flag;
					system("cls");
					break;
				case 4:
					controler.JudCity();///���в�ͬ����ָ���·ݿ���������õĳ���
					cout << "��ѡ��������Ĳ���:" << endl;
					cout << "1���������в���" << endl;
					cout << "0��������һ��" << endl;
					cin >> flag;
					system("cls");
					break;
				case 5:
					controler.PrimePollution();//�ж���Ҫ��Ⱦ��();
					cout << "��ѡ��������Ĳ���:" << endl;
					cout << "1���������в���" << endl;
					cout << "0��������һ��" << endl;
					cin >> flag;
					system("cls");
					break;
				case 6:
					controler.GetStandard(); //��ȡ�ض�������ֵ��Χ
					cout << "��ѡ��������Ĳ���:" << endl;
					cout << "1���������в���" << endl;
					cout << "0��������һ��" << endl;
					cin >> flag;
					system("cls");
					break;
				case 7:
					controler.SetStandard();//������ֵ��Χ
					cout << "��ѡ��������Ĳ���:" << endl;
					cout << "1���������в���" << endl;
					cout << "0��������һ��" << endl;
					cin >> flag;
					system("cls");
					break;
				}
			}
		}
		else if (choice1 == 0)
		{
			cout << "�˳��ɹ����ڴ��ٴ�ʹ�ã�" << endl;
			return 0;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
}