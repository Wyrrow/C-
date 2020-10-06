// LaboratorPOO1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// lab1_CegleiAlexei_POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Student {
	char* Name;
	char* Major;
	int Year;
	float Mark;
};

Student* Students;
int arrLength = 0;

void CoutStudent(Student& student) 
{
	if (student.Name != nullptr) {

		cout << "\nName - " << student.Name;
		cout << "\nMajor - " << student.Major;
		cout << "\nYear - " << student.Year;
		cout << "\nMark - " << student.Mark;
	}
	else {
		cout << "\n Space is empty...\n";
	}
}



void CinStudent(Student& student) {
	student.Name = new char[30];
	student.Major = new char[30];
	cout << "\nEnter name -";
	cin >> student.Name;
	cout << "\nEnter  " << student.Name << "'s major -  ";
	cin >> student.Major;
	cout << "\nEnter    " << student.Name << "'s year - ";
	cin >> student.Year;
	cout << "\nEnter   " << student.Name << "'s mark - ";
	cin >> student.Mark;


}

void Editor() {
	if (arrLength > 0) {
		char* _tmpName = new char[50];
		cout << "\nEnter the name of student you want to edit: ";
		cin >> _tmpName;
		for (int i = 0; i < arrLength; i++) {
			if (strlen(_tmpName) == strlen(Students[i].Name)) {
				int equalsChars = 0;
				for (int j = 0; j < strlen(_tmpName); j++) {
					if (_tmpName[j] == Students[i].Name[j]) {
						equalsChars++;
					}
				}
				if (equalsChars == strlen(_tmpName)) {
					cout << "\nWe found this student:\n";
					CinStudent(Students[i]);
					return;
				}
			}
		}
		cout << endl;
	}
	else {
		cout << "\n Not found this student! \n";
	}
}



void Deleter(Student& student) {
	delete[]student.Name;
	delete[]student.Major;
	student.Name = nullptr;
	student.Major = nullptr;
	student.Year = NULL;
	student.Mark = NULL; 

}

void CreateArray() {
	cout << "Enter count of Students: "; cin >> arrLength;
	Students = new Student[arrLength];
	cout << "Plese write data:\n\n";
	for (int i = 0; i < arrLength; i++) {
		cout << (i+1) << " ' student: \n";
		CinStudent(Students[i]);
		cout << endl;
	}
}

void DeleteArray() {
	for (int i = 0; i < arrLength; i++) {
		Deleter(Students[i]);
	}
	delete[]Students;
	Students = nullptr;
	arrLength = 0;
}

void Sort() {
	if (arrLength > 0) {
		for (int i = arrLength - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (Students[j].Mark > Students[j + 1].Mark && Students[j].Major > Students[j + 1].Major) {
					Student tempStudent = Students[j];
					Students[j] = Students[j + 1];
					Students[j + 1] = tempStudent;
				}
			}
		}
	}
}

void ShowArray() {
	if (arrLength > 0) {
		cout << "There are: " << arrLength << " students in the university\n";
		for (int i = 0; i < arrLength; i++) {
			cout << i << " student: \n";
			CoutStudent(Students[i]);
			cout << endl;
		}
		cout << endl;
	}
	else {
		cout << "\n Your list is empty!\n";
	}
}




void Menu() {
	cout << "\n1) Create Array.\n";
	cout << "\n2) Show Array.\n";
	cout << "\n3) Sort array by major and marks.\n";
	cout << "\n4) Edit student.\n";
	cout << "\n5) Delete Array.\n";
	cout << "\n6) Exit.\n";
}

int main()
{

	bool _going = true;
	int _choice = 0;
	while (_going)
	{
		Menu();
		cout << "\nEnter your choice  -  ";
		cin >> _choice;
		switch (_choice)
		{
		case 1:
			CreateArray();
			break;
		case 2:
			ShowArray();
			break;
		case 3:
			Sort();
			break;

		case 4:
			Editor();
			break;
		case 5:
			DeleteArray();
			break;
		case 6:
			_going = false;
			break;
		default:
			break;
		}
	}

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
