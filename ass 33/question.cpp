// TODO: C++ Assignment 5

// TODO: Assignment-33: Member function, static

/* //! 1. Define a class Complex to represent a complex number with instance variables a and b to store real and imaginary parts. Also define following member functions
//! 1. void setData(int, int)
//! 2. void showData()
//! 3. Complex add(Complex)
//! 4. Complex subtract(Complex)
//! 5. Complex multiply(Complex)
#include <iostream>
using namespace std;
class complex
{
private:
    int a, b;

public:
    void setData(int, int);
    void showData();
    complex add(complex);
    complex subtract(complex);
    complex multiply(complex);
};
void complex::setData(int x, int y)
{
    a = x;
    b = y;
}
void complex::showData()
{
    cout << a;
    if (b >= 0) {
        cout << " + " << b << "i" << endl;
    } else {
        cout << " - " << -b << "i" << endl;
    }
}
complex complex::add(complex C)
{
    complex temp;
    temp.a = a + C.a;
    temp.b = b + C.b;
    return temp;
}
complex complex::subtract(complex C)
{
    complex temp;
    temp.a = a - C.a;
    temp.b = b - C.b;
    return temp;
}
complex complex::multiply(complex C)
{
    complex temp;
    temp.a = a * C.a - b * C.b;  // (ac - bd)
    temp.b = a * C.b + b * C.a;  // (ad + bc)
    return temp;
}
int main()
{
    complex c1, c2, c3;
    c1.setData(4, 5);
    c2.setData(6, 7);
    c1.showData();
    c2.showData();
    c3 = c1.add(c2);
    c3.showData();
    c3 = c1.subtract(c2);
    c3.showData();
    c3 = c1.multiply(c2);
    c3.showData();
    return 0;
} */

/* //! 2. Define a class Time to represent a time with instance variables him and sec to store hour, minute, and second. Also define following member functions
//! 1. void setTime(int, int, int)
//! 2. void showTime()
//! 3. void normalize()
//! 4. Time add(Time)
//! 5. bool isGreater(Time)
#include <iostream>
using namespace std;
class Time
{
private:
    int h, m, s;

public:
    void setTime(int, int, int);
    void showTime();
    void normalize();
    Time add(Time);
    bool isGreater(Time);
};
bool Time::isGreater(Time T)
{
    if (h > T.h)
        return true;
    else if (h == T.h)
    {
        if (m > T.m)
            return true;
        else if (m == T.m)
        {
            if (s > T.s)
                return true;
        }
    }
    return false;
}
void Time::normalize()
{
    if (s >= 60)
    {
        s %= 60;
        m++;
    }
    if (m >= 60)
    {
        m %= 60;
        h++;
    }
}
void Time::setTime(int hours, int minute, int second)
{

    h = hours;
    m = minute;
    s = second;
    normalize();
}
void Time::showTime()
{
    normalize();
    cout << "Time(HH:MM:SS): " << h << ":" << m << ":" << s << endl;
}
Time Time::add(Time T)
{
    Time temp;
    temp.h = h + T.h;
    temp.m = m + T.m;
    temp.s = s + T.s;
    return temp;
}
int main()
{
    Time t1, t2, t3;
    t1.setTime(3, 15, 20);
    t1.showTime();
    t2.setTime(4, 50, 50);
    t2.showTime();

    t3 = t1.add(t2);
    t3.showTime();

    if (t1.isGreater(t2))
    {
        cout << "Time 1 is greater than Time 2." << endl;
    }
    else
    {
        cout << "Time 1 is not greater than Time 2." << endl;
    }
    return 0;
} */

/* //! 3. Define a class TestResult with properties roll_no, right, wrong, net_score. Also define class properties right_weightage, wrong_weightage. Provide methods to set and get all the properties.
#include <iostream>
using namespace std;
class TestResult
{
private:
    int roll_no, right, wrong;
    int right_weightage = 2, wrong_weightage = -1;

public:
    void setRollNo(int r)
    {
        roll_no = r;
    }
    void setRight(int r){right=r;}
    void setleft(int w){wrong=w;}
    void setdata(int, int, int);
    int getRollNo(){return roll_no;}
    int getRight(){return right;}
    int getWrong(){return wrong;}
    void showdata();
    int net_score();
};
int TestResult::net_score()
{
    return (right * right_weightage) + (wrong * wrong_weightage);
}
void TestResult::setdata(int roll_num, int r, int w)
{
    roll_no = roll_num;
    right = r;
    wrong = w;
}
void TestResult::showdata()
{
    cout << "Roll Number: " << roll_no << endl;
    cout << "Right Answer: " << right << endl;
    cout << "Wrong Number: " << wrong << endl;
    cout << "Net Score: " << net_score() << endl;
}
int main()
{
    TestResult t1, t2;
    t1.setdata(101, 20, 5);
    t1.showdata();

    return 0;
} */

/* //! 4. Write a driver function main() to use TestResult class (Question 3). Create an array of 5 TestResult objects, set values to all the objects and display the results in sorted order (by net_score).
#include <iostream>
using namespace std;
class TestResult
{
private:
    int roll_no, right, wrong;
    int right_weightage = 2, wrong_weightage = -1;

public:
    void setdata(int, int, int);
    void showdata();
    int net_score();
};
int TestResult::net_score()
{
    return (right * right_weightage) + (wrong * wrong_weightage);
}
void TestResult::setdata(int roll_num, int r, int w)
{
    roll_no = roll_num;
    right = r;
    wrong = w;
}
void TestResult::showdata()
{
    cout << "Roll Number: " << roll_no << endl;
    cout << "Right Answer: " << right << endl;
    cout << "Wrong Number: " << wrong << endl;
    cout << "Net Score: " << net_score() << endl;
}
int main()
{
    TestResult a[5];
    a[0].setdata(101, 20, 5);
    a[1].setdata(102, 15, 10);
    a[2].setdata(103, 22, 3);
    a[3].setdata(104, 18, 7);
    a[4].setdata(105, 10, 15);

    // Bubble Sort Logic to sort TestResult objects based on net_score
    for (int i = 0; i < 4; i++) // Outer loop
    {
        for (int j = 0; j < 4 - i; j++) // Inner loop
        {
            if (a[j].net_score() < a[j + 1].net_score()) // Compare net_scores of adjacent objects
            {
                // Swap the objects if they are in wrong order
                TestResult temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        a[i].showdata();
    }

    return 0;
} */

/* //! 5. Define a class Matrix to represent a 3x3 order matrix. Provide appropriate methods and properties to the class. Also define following methods in the class:
//! 1. Matrix add(Matrix)
//! 2. Matrix sub(Matrix)
//! 3. Matrix multiply(Matrix)
//! 4. Matrix transpose()
//! 5. bool is_singular()
#include <iostream>
using namespace std;
class Matrix
{
private:
    int mat[3][3];

public:
    void setdata(int a[3][3]);
    void showdata();
    Matrix add(Matrix);
    Matrix sub(Matrix);
    Matrix multiply(Matrix);
    Matrix transpose();
    bool is_singular();
};
bool Matrix::is_singular()
{
    int det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
              mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
              mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

    if (det == 0)
        return true;
    else
        return false;
}
Matrix Matrix::transpose()
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = mat[j][i];
        }
    }
    return temp;
}
Matrix Matrix::multiply(Matrix m)
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = (mat[i][0] * m.mat[0][j]) + (mat[i][1] * m.mat[1][j]) + (mat[i][2] * m.mat[2][j]);
        }
    }
    return temp;
}
Matrix Matrix::sub(Matrix m)
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = mat[i][j] - m.mat[i][j];
        }
    }
    return temp;
}
Matrix Matrix::add(Matrix m)
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = mat[i][j] + m.mat[i][j];
        }
    }
    return temp;
}
void Matrix::setdata(int a[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat[i][j] = a[i][j];
        }
    }
}
void Matrix::showdata()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Matrix m1, m2, m3;
    int a1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int a2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    m1.setdata(a1);
    m2.setdata(a2);
    cout << "Matrix 1:" << endl;
    m1.showdata();
    cout << "Matrix 2:" << endl;
    m2.showdata();
    cout << "add:" << endl;
    m3 = m1.add(m2);
    m3.showdata();
    cout << "Sub:" << endl;
    m3 = m1.sub(m2);
    m3.showdata();
    cout << "Multiply:" << endl;
    m3 = m1.multiply(m2);
    m3.showdata();
    cout << "Transpose:" << endl;
    m3 = m1.transpose();
    m3.showdata();
    cout << "Is singular:" << endl;
    if (m1.is_singular())
        cout << "This Matrix is singular.";
    else
        cout << "This Matrix is not singular.";

    return 0;
} */