// LabPoo1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


using namespace std; 


class Student 
{
public: 
    Student();
    Student( int year, float mark,  char* name,  char spec );
    
    void CreateStudent(Student& stud); 
    
    void Print(Student stud);
    
private:
   
    char*m_Name;
    char m_Spec;
    int m_Year;
    float m_Mark;
    
    //Student* m_pNext;// Указатель на следующего студента в списке

};

Student::Student()
{}

Student::Student(int year, float mark,  char* name,  char spec) :
    m_Name(name), m_Spec(spec), m_Year(year), m_Mark(mark),
    m_pNext(0)
    {}
   

/*void Student ::  GetStudent(int& year, float& mark, const string& name , const string& spec ) const
{
    m_Name == name; 
    m_Spec == spec; 
    m_Year == year; 
    m_Mark == mark; 
} */

void Student::CreateStudent(Student& stud) 
{
    char t[30];
    cout << "\nPlease enter the name of the student: ";
    cin >> t;
    stud.m_Name = new char[strlen(t) + 1];
    strcpy(stud.m_Name, t);
    cout << "\nPlease enter the specialization  of the student: ";
    cin >> stud.m_Spec;
    cout << "\nPlease enter the year of the student: ";
    cin >> stud.m_Year;
    cout << "\nPlease enter the mark  of the student: ";
    cin >> stud.m_Mark;

   // cout << "\nPlease enter the name of the student: ";
    //showPerson(p1);
    //cout << "Adres p1 iz functii: " << &p1 << endl;
}


void Student::Print(Student stud)
{
}



class List : public Student
{
    friend ostream& operator<<(ostream& os, const List& alist);
public: 
    List();
    ~List();  
    int n = 0;
    void RemovePlayer();
    void CreateArr();
    void Clear();
private:
    // next student
    Student *arrStud;
    Student* m_pHead;

};


List:: List():
    m_pHead(0)
{}

List :: ~List()
{
    Clear();
}


//void List::CreateMem(float &mark , int &year, string &name, string &speac)
//{
//    Student* pNewPlayer = new Student(name);
//}

void List::CreateArr() {

   
    cout << "Write number of students: ";
    cin >> n;
    arrStud = new Student[n];
    for (int i = 0; i < n; i++) {
        cout << "Student number:  " << i << endl;
        CreateStudent(arrStud[i]);
    }
}
//void List::AddPlayer()
//{
//
//    Student st;
//    string name, spec;
//    int year;
//    float mark;
//    // создать нового игрока
//    cout << "\nPlease enter the name of the student: ";
//    cin >> name;
//    cout << "\nPlease enter the specialization of the student: ";
//    cin >> spec;
//    cout << "\nPlease enter the year of the student: ";
//    cin >> year;
//    cout << "\nPlease enter the mark of the student: ";
//    cin >> mark;
//    //Student* pNewPlayer = new Student (year, mark, name, spec); 
//    /*name = st.m_Name; 
//    spec = st.GetSpec(); 
//    year = st.GetYear();
//    mark = st.GetMark(); */    // если список пуст,поставить в его начало нового игрока
//    if (m_pHead == 0)
//    {
//        m_pHead = pNewPlayer;
//    }
//    //в противном случае найти конец списка и добавить игрока туда
//    else
//    {
//        Student* plter = m_pHead;
//        while (plter->GetNext() != 0)
//        {
//            plter = plter->GetNext();
//        }
//        plter->SetNext(pNewPlayer);
//    }
//}


void List::RemovePlayer()
{
    if (m_pHead == 0)
    {
        cout << "The list is empty. No one to remove !\n";
    }
    else
    {
        cout << "The list is empty. No one to remove !\n";
        Student* pTemp = m_pHead;
        m_pHead = m_pHead->GetNext();
        delete pTemp;

    }
}



void List :: Clear()
{
    while (m_pHead != 0)
    {
        RemovePlayer();
    }
}

ostream& operator<<(ostream& os, const Student& astud)
{
    List list;
    Student stud; 
    
    os << "\nHere's who's in the list:\n";
    if (list.n == 0)
    {
        os << "The list is empty.\n";
    }
    else
    {
        for (int i = 0; i < list.n; i++) {
            cout << "Student number: " << i << ": ";
            os << "\nName: " << stud.m_Name << endl;
            os << "\nSpecialization: " << pIter->GetSpec() << endl;
            os << "\nYear: " << pIter->GetYear() << endl;
            os << "\nMark: " << pIter->GetMark() << endl;
        
        while (pIter != 0)
        {
           
            pIter = pIter->GetNext();
            return os;
        }
    }
}

   
  





int main()
{
    List myList;
    int choice;
    do
    {

        cout << myList;
        cout << "\nINSTRUCTION\n";
        cout << "0 - Exit the program. \n";
        cout << "1 - Add а student to the list.\n";
        cout << "2 - Remove а student from the list. \n";
        cout << "3 - Clear the  list. \n";
        cout << endl << "Enter choice ";
        cin >> choice;
        switch (choice)
        {
            
        case 0: cout << "Good-bye.\n"; break;
        case 1: myList.AddPlayer(); break;
        case 2: myList.RemovePlayer();  break;
        case 3: myList.Clear(); break;
        default: cout << "That was not а valid choice. \n";
         }
    }
        while (choice != 0);
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
