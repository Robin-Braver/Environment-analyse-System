#include"EMSystem.h"



int main()
{
	cout << "*********************************************************" << endl;
	cout << "*                                                       *" << endl;
	cout << "*" << "\t" << "\t" << "欢迎使用STAR环境数据分析系统" << "\t" << "\t" << "*" << endl;
	cout << "*                                                       *" << endl;
	cout << "*" << "\t" << "\t" << "     " << " 现在开始导入数据" << "\t" << "\t" << "\t" << "*" << endl;
	cout << "*                                                       *" << endl;
	cout << "*********************************************************" << endl;
	EMSystem controler;//建立对象
	cout << "文件导入成功！！！" << endl;
	while (1)
	{
		//功能区
		cout << "*********************************************************" << endl;
		cout << "*                                                       *" << endl;
		cout << "*" << "\t" << "\t" << "欢迎使用STAR环境数据分析系统" << "\t" << "\t" << "*" << endl;
		cout << "*                                                       *" << endl;
		cout << "*" << "\t" << "\t" << "     " << " 1：使用相关功能" << "\t" << "\t" << "\t" << "*" << endl;
		cout << "*" << "\t" << "\t" << "    " << "  0：退出系统" << "\t" << "\t" << "\t" << "*" << endl;
		cout << "*                                                       *" << endl;
		cout << "*********************************************************" << endl;
		cout << "请选择权限模式：";

		int choice1;//选择权限
		cin >> choice1;
		
		if (choice1 == 1)
		{
			int flag = 1;
			while (flag == 1)
			{
				system("cls");
				cout << "*********************************************************************************" << endl;
				cout << "*                                                                               *" << endl;
				cout << "*" << "\t" << "\t" << "欢迎使用STAR环境数据分析系统" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t" << "    " << "当前状态：使用系统状态" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*                                                                               *" << endl;
				cout << "*" << "\t" << "\t" << "1：读取指定城市、指定时间段信息" << "\t" << "\t" << "\t"<<  "\t" << "\t""*" << endl;
				cout << "*" << "\t" << "\t" << "2：读取指定城市、指定时间信息	" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "3：获取指定城市最好以及最差的月份及其AQI" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t" << "4：对比指定月份空气质量最好的城市" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "5：判断指定城市、指定月份的主要污染物类型" << "\t" << "\t"  << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "6：获取指定城市AQI阈值" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t"  << "7：为指定城市输出新的阈值并输出某个月份的数据" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*" << "\t" << "\t" << "0：返回" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "*" << endl;
				cout << "*                                                                               *" << endl;
				cout << "*********************************************************************************" << endl;

				int choice2;
				cout << "请选择你要使用的服务：";
				cin >> choice2;
				system("cls");
				switch (choice2)
				{
				case 0:
					flag = 0;
					break;
				case 1:
					controler.getPeriodData();
					cout << "请选择接下来的操作:" << endl;
					cout << "1：继续进行操作" << endl;
					cout << "0：返回上一级" << endl;
					cin >> flag;
					system("cls");
					break;
				case 2:
					controler.getMomData();
					cout << "请选择接下来的操作:" << endl;
					cout << "1：继续进行操作" << endl;
					cout << "0：返回上一级" << endl;
					cin >> flag;
					system("cls");
					break;
				case 3:
					controler.JudMonth();//评判指定城市最差最好的月份
					cout << "请选择接下来的操作:" << endl;
					cout << "1：继续进行操作" << endl;
					cout << "0：返回上一级" << endl;
					cin >> flag;
					system("cls");
					break;
				case 4:
					controler.JudCity();///评判不同城市指定月份空气质量最好的城市
					cout << "请选择接下来的操作:" << endl;
					cout << "1：继续进行操作" << endl;
					cout << "0：返回上一级" << endl;
					cin >> flag;
					system("cls");
					break;
				case 5:
					controler.PrimePollution();//判断主要污染物();
					cout << "请选择接下来的操作:" << endl;
					cout << "1：继续进行操作" << endl;
					cout << "0：返回上一级" << endl;
					cin >> flag;
					system("cls");
					break;
				case 6:
					controler.GetStandard(); //获取特定城市阈值范围
					cout << "请选择接下来的操作:" << endl;
					cout << "1：继续进行操作" << endl;
					cout << "0：返回上一级" << endl;
					cin >> flag;
					system("cls");
					break;
				case 7:
					controler.SetStandard();//设置阈值范围
					cout << "请选择接下来的操作:" << endl;
					cout << "1：继续进行操作" << endl;
					cout << "0：返回上一级" << endl;
					cin >> flag;
					system("cls");
					break;
				}
			}
		}
		else if (choice1 == 0)
		{
			cout << "退出成功！期待再次使用！" << endl;
			return 0;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}
}