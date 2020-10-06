// Lab2A_POO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std; 

class Major
{
   // friend ostream operator<<(ostream& os,  Major& Major);
public: 
    Major(int credits = 0 ,const string& teacher= " ",const string& subject =" ", const string& exam =" ");
    Major(const Major& major);
    ~Major(); 
    Major& operator= ( Major& major); 
    void Write();
    void Show();
       
   
private: 
    string* m_pTeacher;
    string* m_pSubject; 
    string* m_pExam; 
    int m_Credits; 
};

Major::Major(int credits, const string& teacher, const string& subject, const string& exam):
    m_Credits(credits)
{
    m_pTeacher = new string(teacher); 
    m_pSubject = new string(subject); 
    m_pExam = new string(exam); 
}

Major::~Major()
{
    delete m_pTeacher; 
    delete m_pSubject; 
    delete m_pExam; 
    m_Credits = NULL; 
}


Major::Major(const Major& major)
{
    m_pTeacher = new string(*(major.m_pTeacher)); 
    m_pSubject = new string(*(major.m_pSubject)); 
    m_pExam = new string(*(major.m_pExam)); 
    m_Credits = major.m_Credits; 
}

Major& Major:: operator=(Major& major)
{
    cout << "\n--- Edit --- \n";

    delete m_pTeacher;
    m_pTeacher = new string(*(major.m_pTeacher));
    cout << "\nWrite new techaer: "; cin >> *(major.m_pTeacher);
    delete m_pSubject;
    m_pSubject = new string(*(major.m_pSubject));
    cout << "\nWrite new subject: "; cin >> *(major.m_pSubject);
    delete m_pExam;
    m_pExam = new string(*(major.m_pExam));
    cout << "\nWrite new tipe of exam: "; cin >> *(major.m_pExam);

    cout << "\nWrite new quantity of credits: "; cin >> major.m_Credits;

    return *this;

}

 void Major :: Write()
 {

    cout << "\nWritee please --- \nTeacher: "; cin>> *m_pTeacher;

    cout << "\nSubject:"; cin >> *m_pSubject; 

    cout << "\nExam:"; cin >> *m_pExam;

    cout << "\nCredits:"; cin >> m_Credits; 
 

 }

 void Major::Show()
 {

     cout << "\nYour major:";
     cout << "\nTeacher: " << *m_pTeacher; 
     cout << "\nSubject: " << *m_pSubject; 
     cout << "\nExam: " << *m_pExam; 
     cout << "\nCredits: " << m_Credits << endl; 
 }


int main()
{
    Major major1; 
    Major major2; 
    major1.Write(); 
    major1.Show(); 
    major2 = major1;
    major1.Show(); 
    return 0; 
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
