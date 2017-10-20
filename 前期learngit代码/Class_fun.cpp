#include<iostream>
#include<stdlib.h>

using namespace std;

class Time
{
public:
	Time(int hour = 0,int minute = 0,int second = 0)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 2017,int month = 2,int day = 18)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	~Date()
	{
		cout<<"已析构"<<endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	ostream& operator <<(ostream& _cout)
	{
		_cout<<_year<<' '<<_month<<' '<<_day<<endl;
		return _cout;
	}

	int Getdaysinmonth(int year,int month)
	{
		int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		if((((year%4 == 0)&&(year%100 != 0)) || (year%400 == 0))&&(month == 0))
		{
			days[month] = 29;
		}
		return days[month];
	}
    
	Date& operator = (const Date& c)
	{
		if(this != &c){
		   _year = c._year;
		   _month = c._month;
		   _day = c._day;
		}
		return *this;
	}

	Date& operator ++()
	{
		_day += 1;
		return *this;
	}
    
   	Date& operator --()
	{
		_day -= 1;
		return *this;
	}

	Date operator ++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	Date operator --(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}
    
	//Date operator - (int days)
	//{
	//	if(days < 0){
	//		days = 0 - days;
	//    }
	//	Date temp(*this);
	//	temp._day -= days;
	//	while(temp._day < 0){
	//		if(temp._month == 1){
	//			temp._day += 31;
	//		}
	//		else{
	//			--temp._month;
	//			temp._day += Getdaysinmonth(_year, temp._month);
	//		}
	//	}
	//	return temp;
	//}

    Date ToCorrect(Date &d)
	{
		if(d._day >  Getdaysinmonth(d._year, d._month))
		{
			while(d._day > Getdaysinmonth(d._year, d._month))
			{
				d._day -= Getdaysinmonth(d._year, d._month);
				if(12 == d._month){
					d._year++;
					d._month = 1;
				}
				else{
					++d._month;
				}
			}
		}
		else
		{
			while(d._day <= 0)
			{
				if(1 == d._month){
					d._year--;
					d._month = 12;
				}
				else{
					--d._month;
				}
				d._day += Getdaysinmonth(d._year, d._month);
			}
		}
		return d;
	}

	/*Date& operator +(int days)//此方法慎用 因为其将改变原本投入计算的日期
	{
		this->_day += days;
		ToCorrect(*this);
		return *this;
	}*/

	Date operator +(int days)
	{
		Date Temp(*this);
		Temp._day += days;
		ToCorrect(Temp);
		return Temp;
	}

	Date operator -(int days)
	{
		Date Temp(*this);
		Temp._day -= days;
		ToCorrect(Temp);
		return Temp;
	}

private:
    int _year;
    int _month;
	int _day;
    class Time;
};

void Funtest1()
{
  Date d1(2017,2,14);
  Date d2(d1);
  Date d3(1997,6,19);
  d3 = d1;
  ++d3;
  d3<<cout<<endl;
}

void Funtest2()
{
	Date d1(2017,2,20);
	Date d2(d1);
	Date d3;
	Date d4(d1);
	d4 = d2 + 50;
	d3 = d2 - 50;
    d3<<cout<<endl;
	d4<<cout<<endl;

}

int main()
{
    Funtest2(); 	
	system("pause");
	return 0;
}