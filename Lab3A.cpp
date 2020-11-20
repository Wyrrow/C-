// Lab3A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std; 

class Time
{
	friend Time* operator+(Time& aTime, Time& bTime);
	friend Time* operator-(Time& aTime, Time& bTime);
public:
	Time& operator++();
	Time& operator--();
	Time& operator++( int n);
	Time& operator--(int n );
	Time();
	Time(int hour = 0, int minute = 0, int second = 0);
	void Check(); 
	void Write();
	void Show(); 
private:
	int m_Hour; 
	int m_Minute; 
	int m_Second;

};

Time::Time()
{}

Time::Time(int hour, int minute, int second):
	m_Hour(hour), m_Minute(minute),m_Second(second)
	{}

void Time::Check()
{
	if (m_Second >= 60 )
	{
		abs(m_Second);
		m_Second %= 60;
		m_Minute++;
		
	}

	if (m_Minute >= 60 )
	{
		abs(m_Minute);
		m_Minute %= 60;
		m_Hour++;
		
	}
	if (m_Hour >24 )
	{
		abs(m_Hour);
		m_Hour %= 24;
		
	}

	
}

void Time::Write()
{
	
	cout << "\nEnter hours: "; cin >> m_Hour; 
	cout << "\nEnter minutes: "; cin >> m_Minute; 
	cout << "\nEnter seconds: "; cin >> m_Second;
	
	Check(); 
}


void Time::Show()
{
	cout << "\nYour time: " << m_Hour << " hours, " << m_Minute << " minutes, " << m_Second << " seconds." << endl; 
}

Time* operator+( Time& aTime, Time& bTime)
{

	Time* tmp = new Time(0,0,0);
	tmp->m_Hour = aTime.m_Hour + bTime.m_Hour; 
	tmp->m_Minute = aTime.m_Minute + bTime.m_Minute;
	tmp->m_Second = aTime.m_Second + bTime.m_Second;
	tmp->Check();
	tmp->Show(); 
	return tmp; 
}
Time*  operator-(Time& aTime, Time& bTime)
{
	Time* tmp = new Time(0, 0, 0);
	tmp->m_Hour = abs(aTime.m_Hour - bTime.m_Hour);
	tmp->m_Minute = abs(aTime.m_Minute - bTime.m_Minute);
	tmp->m_Second = abs(aTime.m_Second - bTime.m_Second);
	
	tmp->Check();
	tmp->Show();
	return tmp;
}

Time& Time:: operator++()
{
	this->m_Hour++; this->m_Minute++; this->m_Second++; 
	this->Check(); 
	this->Show(); 
	return *this; 
}

Time& Time:: operator--()
{
	this->m_Hour--; this->m_Minute--; this->m_Second--;
	this->Check();
	this->Show();
	return *this;

}

Time& Time:: operator++(int n)
{
	n = 1; 
	this->m_Hour+=n; this->m_Minute+=n; this->m_Second+=n;
	this->Check(); 
	this->Show();
	return *this; 
}

Time& Time:: operator--(int n)
{
	n = 1;
	this->m_Hour -= n; this->m_Minute -= n; this->m_Second -= n;
	this->Check();
	this->Show();
	return *this;
}

int main()
{
	Time time1(0,0,0), time2(0,0,0); 
	time1.Write();
	time1.Show();
	time2.Write();
	time2.Show();
	cout << "\n------------- Operator +: -------------\n";
	time1 + time2; 
	
	cout << "\n------------- Operator -: -------------\n";
	time1 - time2;

	cout << "\n------------- Operator ++time : -------------\n";
	++time1; 

	cout << "\n------------- Operator --time : -------------\n";
	--time1;

	cout << "\n------------- Operator time++ : -------------\n";
	time2++;

	cout << "\n------------- Operator time-- : -------------\n";
	time2--;
	

	return 0; 

   
}

