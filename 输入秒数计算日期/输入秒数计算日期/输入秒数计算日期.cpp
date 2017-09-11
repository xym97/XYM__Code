#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>

using namespace std;

string CalculationDate(long long s)
{
	long long year = 1970, month = 1, day = 1, minnate = 0, hour = 0, second = 0;
	second += s;
	while (second >= 60){
		second -= 60;
		minnate += 1;
		if (minnate >= 60){
		minnate -= 60;
		hour++;
		if (hour >= 24){
		hour -= 24;
		day++;
		if (day > 30){
		day -= 30;
		month++;
		if (month > 12){
		month -= 12;
		year++;
		}
		}
		}
		}
		}
	/*minnate = second / 60;
	hour = minnate / 60;
	day = hour / 24;
	month = day / 30;
	year = month / 12;
	while (month > 12){
		month -= 12;
		year++;
		if (day > 30){
			day -= 30;
			month++;
			if (hour > 24){
				hour -= 24;
				day++;
				if (minnate > 60){
					minnate -= 60;
					hour++;
					if (second > 60){
						second -= 60;
						minnate++;
					}
				}
			}
					
		}
	}*/
 
	
	char buff[100];// 
	//char date[100];
	//char date[] = "1970/01/01 00:00:00";
	string date;
	date += _itoa(year, buff, 10);//十代表十进制。
	date += '/';
	if (month < 10) date += '0';
	date += _itoa(month, buff, 10);
	date += '/';
	if (day < 10) date += '0';
	date += _itoa(day, buff, 10);
	date += ' ';
	if (hour < 10) date += '0';
	date += _itoa(hour, buff, 10);
	date += ':';
	if (minnate < 10) date += '0';
	date += _itoa(minnate, buff, 10);
	date += ':';
	if (second < 10) date += '0';
	date += _itoa(second, buff, 10);

	//sprintf(date, "%d/%02d/%02d %02d:%02d:%02d", year, month, day, hour, minnate, second);
	//这里sprintf()函数中的‘0’表示字符不够时用‘0’来填满 零后面的‘2’表示这一段长度为‘2’
	
	return date;

}

int main()
{
	long long second = 0;
	cout << " 输入秒数:" << endl;
	scanf("%d", &second);
	string ret = CalculationDate(second);
	cout << ret.c_str() << endl;
	system("pause");
	return 0;
}