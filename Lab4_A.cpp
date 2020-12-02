
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std; 

class Press
{
	friend ostream& operator<<(ostream& os, Press& press);
	friend istream& operator>>(istream& is, Press& press); 

public:

	Press(string t = "nontitle", int c = 0, int idx = 00000, int freq = 0 ):
		title(t), circulation(c), index(idx), frequency(freq)
	{}

	Press(const Press& press)
	{
		this->title = press.title;
		this->circulation = press.circulation; 
		this->index = press.index; 
		this->frequency = press.frequency; 
	}
	

	Press& operator= (const Press& press)
	{
		if (this->title == press.title  && this->circulation==press.circulation && this->index == press.index && this->frequency==press.frequency)
		{
			return *this; 
		}
		else
		{
			this->title = press.title;
			this->circulation = press.circulation;
			this->index = press.index;
			this->frequency = press.frequency;
		}
	}
	

protected: 
	string title;
	int circulation;// тираж
	int index;
    int frequency;//переодичность издания 

};


ostream& operator<<(ostream& os, Press& press)
{
	cout << "\nTitle : " << press.title << endl;
	cout << "Circulation : " << press.circulation << endl;
	cout << "Index : " << press.index << endl;
	cout << "Frequency : " << press.frequency <<" times in the moth"<< endl;

	return os;
}

istream& operator>>(istream& is, Press& press)
{

	cout << "\nWrite a title: ";
	is >> press.title;
	cout << "\nWrite the circulation: ";
	is >> press.circulation;
	cout << "\nWrite the index: ";
	is >> press.index;
	cout << "\nWrite the frequency times in the month: ";
	is >> press.frequency;
	return is;
}

class Newspaper : public Press
{
	friend istream& operator>>(istream& is, Press& press); 
	friend ostream& operator<<(ostream& os, Press& press); 
public:
	Newspaper(string t = "newspaper", int c= 20, int idx=1000, int freq=2):
		Press(t,c,idx,freq)
	{}
	Newspaper(const Newspaper& news):
		Press(news)
	{}

};
class Magazine : public Press
{

	friend istream& operator>>(istream& is, Press& press);
	friend ostream& operator<<(ostream& os, Press& press);
public:
	Magazine(string t = "magazine", int c = 20, int idx = 1000, int freq = 2) :
		Press(t, c, idx, freq)
	{}
	Magazine(const Magazine& mag) :
		Press(mag)
	{}
};

class IntEdition : public Press
{
	friend istream& operator>>(istream& is, Press& press);
	friend ostream& operator<<(ostream& os, Press& press);
public:
	IntEdition(string t = "electronic magazine", int c = 20, int idx = 1000, int freq = 2) :
		Press(t, c, idx, freq)
	{}
	IntEdition(const IntEdition& internet) :
		Press(internet)
	{}
};



int main()
{
	Press p1("Poem", 200, 3462, 2), p2, p3; 
	cout << "\nPrint p1: \n"<<p1; 
	cin >> p2; 
	cout <<"\nPrint p2: \n"<< p2; 
	p3 = p2; 
	cout <<"\nPrint p3 = p2: \n"<< p3;
	Newspaper n1("Phisics", 4000, 19384, 3), n2;
	cout <<"\nPrint n1: \n"<< n1; 
	cin >> n2; 
	cout <<"\nPrint n2: \n"<< n2; 
	Magazine m1; 
	IntEdition e1; 
	cout <<" \nPrint magazine m1\n" <<m1<< "Print element e1: \n" <<e1; 


	return 0; 
}