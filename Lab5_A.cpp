// Lab5_A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std; 



class Paper
{
public: 
    Paper(string type = "no tipe", int quantity = 0):
        m_Type(type), m_Quantity(quantity)
    {}
    void virtual Show() const; 
private :
    string m_Type; 
    int m_Quantity;
};

void Paper::Show() const
{
    cout << "\nPaper - " << m_Type; 
    cout << "\nQuantity of paper -  " << m_Quantity; 
}

class Own
{
public: 
    Own(string name = "there is nothing", int price = 0) :
        m_Name(name), m_Price(price)
    {}
    void virtual Show() const;

private: 
    string m_Name; 
    int m_Price; 
};

void Own::Show() const
{
    cout << "\nName - " << m_Name; 
    cout << "\nPrice - " << m_Price;
}

class Shares : public Paper, Own 
{
public: 
    Shares(string name = "shares", string type ="non", int quantity = -1 , int price = 10): 
        Paper(type,quantity), Own(name, price)
    {}
    void virtual Show() const 
    {
        Own::Show();
        Paper::Show();
    }
};


int main()
{
    Paper paper1, paper2("aquarelic", 5); 
    paper1.Show(); cout << endl; 
    paper2.Show(); cout << endl; 
    Own own1, own2("house", 25000); 
    own1.Show(); cout << endl; 
    own2.Show(); cout << endl; 
    Shares sh1, sh2("academy", "electronic", 25, 3000); 
    sh1.Show();  cout << endl;
    sh2.Show();

   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
