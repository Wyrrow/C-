#include <iostream>
#include <string>

using namespace std; 

class Procesor
{
	friend ostream& operator<<(ostream& os, Procesor& proc); 
public: 
	Procesor(string name= "no name",	int frequency = 0, string  production = "production", double memory = 1);
	Procesor(const Procesor& procesor); 
	void Write(); 

private: 
	string m_Name; 
	int m_Frequency; 
	string  m_Production;
	double m_Memory;

};

Procesor:: Procesor(string name , int frequency , string  production , double memory): 
	m_Name(name), m_Frequency(frequency), m_Production(production), m_Memory(memory)
{}

Procesor::Procesor(const Procesor& procesor)
{
	this->m_Name = procesor.m_Name; 
	this->m_Frequency = procesor.m_Frequency;
	this->m_Production = procesor.m_Production; 
	this->m_Memory = procesor.m_Memory; 
}

ostream& operator<<(ostream& os, Procesor& procesor)
{
	cout << "\nName of procesor is " << procesor.m_Name ; 
	cout << "\nIts frequency is " << procesor.m_Frequency << " Hz"; 
	cout << "\nthe production technology used is " << procesor.m_Production ; 
	cout << "\nits internal memory is " << procesor.m_Memory << endl; 

	return os;
}


int main()
{
	Procesor p1, p2("Intel core i7", 8, "7nnm tech proces", 16); 
	cout << p1 << p2; 

	return 0; 
}