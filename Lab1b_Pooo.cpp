

#include <iostream>

using namespace std;

struct MyVector
{
    long* Elements;
    int  Size;
};

void Create(MyVector& vector) 
{
    cout << "\nWhat size of the vector do you want?\nSize -  "; cin >> vector.Size;
    vector.Elements = new long[vector.Size];
    cout << "\nEnter " << vector.Size << " numbers into vector:\n";
    for (int i = 0; i < vector.Size; i++)
    {
        cin >> vector.Elements[i];
    }
    
}


void Delete(MyVector& vector)
{
    delete[] vector.Elements;
    vector.Elements = nullptr; 
    vector.Size = NULL;
}



void Show(MyVector& vector)
{
    if (vector.Size == 0)
    {
        cout << "\nThis vector is empty!I'm so ssory" << endl;
    }
    else
    {
        cout << "\nVector have " << vector.Size << " elements" << endl;
        for (int i = 0; i < vector.Size; i++)
        {
            cout << "[" << vector.Elements[i] << "]";
        }
    }
}


void Edit(MyVector& vector)
{
    int newSize;
    cout << "\nEnter new size of vector:"; cin >> newSize;
    if (vector.Size == newSize) {
        cout << " Nothing has changed" << endl;
        return;
    }

    MyVector tmp;
    tmp.Size = newSize;

    tmp.Elements = new long[newSize];


    if (vector.Size > tmp.Size) {
        for (int i = 0; i < tmp.Size; i++)
        {
            tmp.Elements[i] = vector.Elements[i];
        }
        cout << "\nThe new vector has" << (vector.Size - tmp.Size) << " elements less" << endl;
    }
    else {
        for (int i = 0; i < vector.Size; i++)
        {
            tmp.Elements[i] = vector.Elements[i];
        }
        for (int i = vector.Size; i < tmp.Size; i++)
        {
            tmp.Elements[i] = 0;
        }
        cout << "\nThe new vector has" << (tmp.Size - vector.Size) << " more elements" << endl;
    }
    vector.Size = tmp.Size;
    for (int i = 0; i < vector.Size; i++) {
        vector.Elements[i] = tmp.Elements[i];
    }

    Show(vector);
    Delete(tmp);

}


void SearchElement(MyVector const& vector)
{
    int item;
    cout << "\nEnter the number of the desired item. \nEnter: "; cin >> item;
    if (item > 0 && item < vector.Size)
    {
        cout << "\nYour element: " << vector.Elements[item] << endl;
    }
    else {
        cout << "\nElement with number " << item << " doesn't exist" << endl;

    }
}



void Sum(MyVector const& vector) {
    long summ = 0;
    for (int i = 0; i < vector.Size; i++)
    {
        if (vector.Elements[i] % 2 == 0)
        {
            summ = summ + vector.Elements[i];
        }
    }

    cout << "\nThe sum of even elements of the vector is -> " << summ << endl;
}


void SearchMaxElement(MyVector& vector)
{
    int max = INT_MIN;
    int pos;
    for (int i = 0; i < vector.Size; i++)
    {
        if (max < vector.Elements[i])
        {
            max = vector.Elements[i];
            pos = i;
        }
    }
  cout << "\nMaximum vector element: Element [" << pos << "] =" << max << endl;
}


int main()
{
    MyVector vector1;
    cout << "\nCreate vector!";
    Create(vector1);

    cout << "\nYour vector..";
    Show(vector1);

    cout << "\nEdit number of elements";
    Edit(vector1);

    cout << "\nSearch disired elemnt";
    SearchElement(vector1);

    cout << "\nSum of even elements";
    Sum(vector1);

    cout << "\nSearch max element";
    SearchMaxElement(vector1);

    cout << "\nDelete vector";
    Delete(vector1); 
    cout << "\nVector was deleted! Good buy! "; 
    Show(vector1); 

    return 0;



}


