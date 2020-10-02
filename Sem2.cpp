// Sem2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std; 


class Matrix
{
public:
    Matrix(); 
    Matrix(int n, int m);
    Matrix(int n);
    void Create(bool keyb = false, float elem = 0);
    void Show(); 
    void setElem(int i, int j, float elem);
    int getElem(int i, int j);
    int getErr();
    Matrix Add(const Matrix& other); 
    Matrix Sub(const Matrix& other);
    Matrix Mult(Matrix const& right);
    Matrix MultNumber(int number);


private:
    int m_Rows;
    int m_Cols;
    float** m_pData;
    int err;

}; 


   Matrix::Matrix()
    {
        m_Rows = 0; 
        m_Cols = 0; 
        err = 0; 
        m_pData = NULL;
    }

   Matrix:: Matrix(int n, int m) :
        m_Rows(n), m_Cols(m)
    {
        err = 0; 
        m_pData = new float* [m_Rows]; 
        for (int i = 0; i < m_Rows; i++)
            m_pData[i] = new float[m_Cols];
    }

  Matrix::  Matrix(int n) : Matrix(n, n)
    {}

    //Matrix(const Matrix& matrix)
    //{
    //  
    //    
    //        data = new float*(*(matrix.data));
    //    
    //    rows = matrix.rows; 
    //    cols = matrix.cols;
    //}
   

    /*~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
            delete[] data; 

    }*/
    
    void Matrix:: Create(bool keyb, float elem)
    {
        if (keyb == false)
        {
            for (int i = 0; i < m_Rows; i++)
                for (int j = 0; j < m_Cols; j++)
                    m_pData[i][j] = elem;
        }
        else
            for (int i = 0; i < m_Rows; i++)
                for (int j = 0; j < m_Cols; j++)
                        cin >> m_pData[i][j]; 
    }
    void Matrix:: Show()
    {
        for (int i = 0; i < m_Rows; i++)
        {
            for (int j = 0; j < m_Cols; j++)
            {
                 cout << m_pData[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl; 
        
    }

    int Matrix:: getElem(int i, int j)
    {
        if (i < 0 || i >= m_Rows || j < 0 || j >= m_Cols)
        {
            err = 1; 
            cout << "Error = " << err << endl;
            return 0; 
        }
        else
        {
            cout << "Your element : " << m_pData[i][j];
            return m_pData[i][j];
        }
    }

    void Matrix:: setElem(int i, int j, float elem)
    {
        if (i < 0 || i >= m_Rows || j < 0 || j >= m_Cols)
        {
            
            err = 1;
            cout << "Error = " << err << endl;
        }
        else
        {
            m_pData[i][j] = elem;
           
        }
    }
    int Matrix:: getErr()
    {
        return err; 
    }

    Matrix Matrix :: Add(const Matrix& other)
    {
        Matrix temp(m_Rows, m_Cols); 
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols)
        {
            temp.Create(); 
            temp.err = 2; 
            cout << "Error = " << temp.err << endl;
        }
        else
        {
            for (int i = 0; i < m_Rows; i++)
                for (int j = 0; j < m_Cols; j++)
                    temp.m_pData[i][j] = m_pData[i][j] + other.m_pData[i][j]; 
        }
        return temp;
    }
     
    Matrix Matrix :: Sub(const Matrix& other)
    {
        Matrix temp(m_Rows, m_Cols);
        if (m_Rows != other.m_Rows || m_Cols != other.m_Cols)
        {
            temp.Create();
            temp.err = 2;
            cout << "Error = " << temp.err << endl;
        }
        else
        {
            for (int i = 0; i < m_Rows; i++)
                for (int j = 0; j < m_Cols; j++)
                    temp.m_pData[i][j] = m_pData[i][j] - other.m_pData[i][j];
        }
        return temp;

    }



    Matrix Matrix:: Mult(Matrix const& right)
    {
        if (m_Cols!= right.m_Rows)
        {
            Matrix temp; 
            temp.err = 1; 
            cout << "Error = " << temp.err << endl;
            return temp; 
        }
        Matrix temp(m_Rows, right.m_Cols); 
        temp.Create();
        for (int i = 0; i < temp.m_Rows; i++)
            for (int j = 0; j < temp.m_Cols; j++)
                for (int k = 0; k < m_Cols; k++)
                    temp.m_pData[i][j] += m_pData[i][k] *right.m_pData[k][j];

        return temp; 
    }

   Matrix Matrix:: MultNumber(int number)
   {
       Matrix temp(m_Rows,m_Cols);
       temp.Create();
       for (int i = 0; i < temp.m_Rows; i++)
           for (int j = 0; j < temp.m_Cols; j++)
               temp.m_pData[i][j] = m_pData[i][j] * number;

       return temp;


   }




int main()
{
    float elem; 
    int num, i, j;
    Matrix A(2, 3), B(3, 2), C(2, 3), D(2); 
    cout << "Write  6 elements: " << endl; 
    A.Create(true);
    A.Show();
    cout << "Write 6 elements again: " << endl; 
    B.Create(true);
    B.Show();
    cout << "Write 6 elements ... " << endl; 
    C.Create(true);
    C.Show();
    C = A.Add(C); 
    cout << "C = A + C:"<< endl; 
    C.Show();
    C = A.Sub(C);
    cout << "C = A - C:" << endl;
    C.Show();

    C = A.Add(B); 
    cout << "C = A + B:" << endl;
    C.Show();

    D = A.Mult( B); 
    cout << "D = A * B:" << endl; 
    D.Show();

    cout << "\nWrite number :";
    cin >> num; 
    cout << "\nD *" << num << " :" << endl; 
    D = D.MultNumber(num);
    D.Show();

    cout << "\nWhat element from A matrix you want to return? i ="; cin >> i; 
    cout << "j ="; cin >> j; 
    A.getElem(i, j);

    cout << "\nWhat element from B matrix you want to change? i = "; cin >> i; 
    cout << "j ="; cin >> j;
    cout << "\nWrite value of element: "; cin >> elem;
    B.setElem(i, j ,elem);
    B.Show();

   





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
