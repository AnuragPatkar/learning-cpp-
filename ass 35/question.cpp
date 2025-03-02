
//! Assignment-35: operator overloading

/* //?1. Define a class Complex with appropriate instance variables and member functions.

//?Define following operators in the class:

//?1. +

//?2. -

//?3. *

//?4. ==
#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    Complex():a(0),b(0){}
    Complex(int x, int y) : a(x), b(y) {}
    void showdata();
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    bool operator==(Complex);
};
bool Complex::operator==(Complex C) {
    return (a == C.a && b == C.b);
}
Complex Complex::operator*(Complex C)
{
    Complex temp;
    temp.a=a * C.a - b * C.b;
    temp.b=a * C.b + b * C.a;
    return temp;
}
Complex Complex::operator-(Complex C)
{
    Complex temp;
    temp.a=a-C.a;
    temp.b=b-C.b;
    return temp;
}
Complex Complex::operator+(Complex C)
{
    Complex temp;
    temp.a = a + C.a;
    temp.b = b + C.b;
    return temp;
}
void Complex::showdata()
{
    cout << a << " + " << b << "i" << endl;
}

int main()
{
    Complex c1(5, 6), c2(4, 5),c3,c4,c5,c6;
    c1.showdata();
    c2.showdata();
    c3 = c1 + c2;
    c3.showdata();

    c4=c1-c2;
    c4.showdata();

    c5=c1.operator*(c2);//ese bhi likh skte h
    c5.showdata();

    if (c1 == c2)
        cout << "c1 and c2 are equal" << endl;
    else
        cout << "c1 and c2 are NOT equal" << endl;

    return 0;
} */

/* //? 2. Create a class Time which contains hour, min and second as fields. Overload greater than. (>) operator to compare two time objects.
#include <iostream>
using namespace std;
class Time
{
private:
    int hours, min, sec;

public:
    Time(int h, int m, int s) : hours(h), min(m), sec(s) {}
    void showdata();
    bool operator>(Time);
};
bool Time::operator>(Time t)
{
    return (hours * 3600) + (min * 60) + sec > (t.hours * 3600) + (t.min * 60) + t.sec;


}
void Time::showdata()
{
    cout << "Time: " << hours << ":" << min << ":" << sec << endl;
}
int main()
{
    Time t1(5, 30, 12), t2(8, 15, 29);
    t1.showdata();
    t2.showdata();

    if (t1 > t2)
        cout << "t1 is greater then t2" << endl;
    else
        cout << "t2 is greater then t1" << endl;

    return 0;
}  */

/* //? 3. In Question-2, overload pre-increment and post-increment operator to increment Time object value by one second.
#include <iostream>
using namespace std;

class Time
{
private:
    int hours, min, sec;

public:
    Time(int h, int m, int s) : hours(h), min(m), sec(s) {}

    void showdata();

    // Prefix Increment Overloading
    Time operator++()
    {
        sec++;  // 1 second badhao
        if (sec == 60)
        {
            sec = 0;
            min++;
        }
        if (min == 60)
        {
            min = 0;
            hours++;
        }
        return *this; // Modified object return karo
    }

    // Postfix Increment Overloading
    Time operator++(int)
    {
        Time temp = *this; // Purani value store karo
        ++(*this);         // Prefix operator call karke ek second badhao
        return temp;       // Purani value return karo
    }
};

void Time::showdata()
{
    cout << "Time: " << hours << ":" << min << ":" << sec << endl;
}

int main()
{
    Time t1(5, 59, 59);
    cout << "Before Increment:\n";
    t1.showdata();

    cout << "\nAfter Prefix Increment (++t1):\n";
    ++t1;
    t1.showdata();

    cout << "\nAfter Postfix Increment (t1++):\n";
    t1++;
    t1.showdata();

    return 0;
} */

/* //? 4. In Question-2, overload operator+ to add two Time objects.
#include <iostream>
using namespace std;
class Time
{
private:
    int hours, min, sec;

public:
    Time() : hours(0), min(0), sec(0) {}
    Time(int h, int m, int s) : hours(h), min(m), sec(s) {}
    void showdata();
    Time operator+(Time);
};
Time Time::operator+(Time T)
{
    Time temp;
    temp.sec = sec + T.sec;
    temp.min = min + T.min;
    temp.hours = hours + T.hours;
    if (temp.sec >= 60)
    {
        temp.sec -= 60;
        temp.min++;
    }

    if (temp.min >= 60)
    {
        temp.min -= 60;
        temp.hours++;
    }
    return temp;
}
void Time::showdata()
{
    cout << "Time: " << hours << ":" << min << ":" << sec << endl;
}
int main()
{
    Time t1(5, 55, 32), t2(8, 15, 29),t3;
    t1.showdata();
    t2.showdata();

    t3=t1+t2;
    t3.showdata();

    return 0;
} */

//? 5. Define a class matrix to represent 3x3 matrix. Provide appropriate instance methods. Also define operator +, operator -, operator * to perform addition, subtraction and multiplication operations respectively.

//? 5. Consider following class Numbers

/* class Numbers

{
    int x, y, z;

public:
    // methods
}; */

//? Overload the operator unary minus(-) to negate the numbers.
/* #include <iostream>
using namespace std;
class Numbers
{
private:
    int x, y, z;

public:
    Numbers(int a, int b, int c) : x(a), y(b), z(c) {}
    void showdata();
    Numbers operator+(Numbers);
    Numbers operator-(Numbers);
    Numbers operator*(Numbers);
    Numbers operator-();
};
class Matrix
{
private:
    int mat[3][3];

public:
    Matrix()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    Matrix(int m[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = m[i][j];
            }
        }
    }
    void showMatrix();
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
};
Matrix Matrix::operator*(Matrix X)
{
    Matrix t;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t.mat[i][j] = (mat[i][0] * X.mat[0][j]) + (mat[i][1] * X.mat[1][j]) + (mat[i][2] * X.mat[2][j]);
        }
    }
    return t;
}
Matrix Matrix::operator-(Matrix X)
{
    Matrix t;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t.mat[i][j] = (mat[i][j] - X.mat[i][j]);
        }
    }
    return t;
}
Matrix Matrix::operator+(Matrix X)
{
    Matrix t;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t.mat[i][j] = (mat[i][j] + X.mat[i][j]);
        }
    }
    return t;
}
void Matrix::showMatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
Numbers Numbers::operator-()
{
    return Numbers(-x, -y, -z);
}
Numbers Numbers::operator-(Numbers A)
{
    return Numbers(x - A.x, y - A.y, z - A.z);
}
Numbers Numbers::operator*(Numbers A)
{
    return Numbers(x * A.x, y * A.y, z * A.z);
}
Numbers Numbers::operator+(Numbers A)
{
    return Numbers(x + A.x, y + A.y, z + A.z);
}
void Numbers::showdata()
{
    cout << "x=" << x << " y=" << y << " z=" << z << endl;
}
void Matrix_class()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix m1(a), m2(b);
    m1.showMatrix();
    m2.showMatrix();

    Matrix m3 = m1 + m2;
    m3.showMatrix();

    Matrix m4 = m1 - m2;
    m4.showMatrix();

    Matrix m5 = m1 * m2;
    m5.showMatrix();
}
void Numbers_class()
{
    Numbers n1(3, 4, 5), n2(5, 7, 7);
    n1.showdata();
    n2.showdata();

    Numbers n3 = n1 + n2;
    n3.showdata();

    Numbers n4 = n1 - n2;
    n4.showdata();

    Numbers n5 = n1 * n2;
    n5.showdata();

    Numbers n6 = -n1;
    n6.showdata();
}
int main()
{
    Matrix_class();
    Numbers_class();

    return 0;
}  */

//? 6. Define a C++ class fraction

/* class fraction

{

long numerator,

    long denominator,

    public :

    fraction(long n = 0, long d = 0);
}

Define an operator+ to add two fraction object. */
/* #include <iostream>
using namespace std;
class Fraction
{
private:
    long numerator;
    long denominator;
    // Function to calculate GCD (Greatest Common Divisor)
    long gcd(long a, long b)
    {
        while (b != 0)
        {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Constructor with validation and simplification
    Fraction(long n = 0, long d = 1)
    {
        if (d == 0)
        {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            d = 1;
        }

        long divisor = gcd(n, d);
        numerator = n / divisor;
        denominator = d / divisor;

        // Ensure denominator is always positive
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    void showdata();
    Fraction operator+(Fraction f);
};
Fraction Fraction:: operator+(Fraction f)
{
    long num=(numerator*f.denominator)+(f.numerator*denominator);
    long dem=denominator*f.denominator;
    return Fraction(num,dem);
}

void Fraction::showdata()
{
    if (numerator == 0)
            cout << "0" << endl;
        else if (denominator == 1)
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl;
}
int main()
{
    Fraction f1(4, 5),f2(4,5);
    f1.showdata();
    f2.showdata();

    Fraction f3=f1+f2;
    cout<<"Sum: ";
    f3.showdata();
    return 0;
}
 */

/* //? 7. In Question -6,define an operator<to compare two fraction objects.
#include <iostream>
using namespace std;
class Fraction
{
private:
    long numerator;
    long denominator;


public:
    Fraction(long n,long d):numerator(n),denominator(d){}
    void showdata();
    bool operator<(Fraction );
};
bool Fraction::operator<(Fraction f)
{
    return numerator * f.denominator < f.numerator * denominator;
}
void Fraction::showdata()
{
    if (numerator == 0)
        cout << "0" << endl;
    else if (denominator == 1)
        cout << numerator << endl;
    else
        cout << numerator << "/" << denominator << endl;
}
int main()
{
    Fraction f1(1, 5), f2(2, 5);
    f1.showdata();
    f2.showdata();

    if (f1 < f2)
        cout << "f1 is lesser then f2."<<endl;
    else
        cout << "f1 is greater than or equal to f2."<<endl;
    return 0;
} */

//? 8. Consider a class Distance

/* class Distance

{

    int km, m, cm;

public:
    // methods,
};

Overload the operator+ to add two distance objects. */
/* #include <iostream>
using namespace std;
class Distance
{
private:
    int km, m, cm;

public:
    Distance(int km = 0, int m = 0, int cm = 0) : km(km), m(m), cm(cm) {}
    void showdata();
    Distance operator+(Distance);
};
Distance Distance::operator+(Distance T)
{
    Distance temp;
    temp.km = km + T.km;
    temp.m = m + T.m;
    temp.cm = cm + T.cm;

    if (temp.cm >= 100)
    {
        temp.m += temp.cm / 100;
        temp.cm %= 100;
    }

    if (temp.m >= 1000)
    {
        temp.km += temp.m / 1000;
        temp.m %= 1000;
    }

    return temp;
}
void Distance::showdata()
{
    cout << "Distance: " << km << "km," << m << "m," << cm << "cm" << endl;
}
int main()
{
    Distance d1(5, 55, 32), d2(20, 999, 99), d3;
    d1.showdata();
    d2.showdata();

    d3 = d1 + d2;
    d3.showdata();

    return 0;
} */

/* //? 9. In Question - 8, define operator pre decrement and post decrement to decrease distance by 1 cm.
#include <iostream>
using namespace std;
class Distance
{
private:
    int km, m, cm;

public:
    Distance(int km = 0, int m = 0, int cm = 0) : km(km), m(m), cm(cm) {}
    void showdata();
    Distance operator+(Distance);
    Distance operator++();
    Distance operator++(int);
    Distance operator--();
    Distance operator--(int);
};
Distance Distance::operator++()
{
    cm++;
    if (cm >= 100)
    {
        cm %= 100;
        m++;
    }
    if (m >= 1000)
    {
        m %= 1000;
        km++;
    }
    return *this;
}
Distance Distance::operator++(int)
{
    Distance temp = *this; // Purani value store karo
    ++(*this);         // Prefix operator call karke ek second badhao
    return temp;       // Purani value return karo
}
Distance Distance::operator--()
{
    cm--;
    if (cm < 0)
    {
        cm += 100;
        m--;
    }
    if (m < 0)
    {
        m += 1000;
        km--;
    }
    return *this;
}
Distance Distance::operator--(int)
{
    Distance temp = *this; // Purani value store karo
    --(*this);         // Prefix operator call karke ek second badhao
    return temp;       // Purani value return karo
}
Distance Distance::operator+(Distance T)
{
    Distance temp;
    temp.km = km + T.km;
    temp.m = m + T.m;
    temp.cm = cm + T.cm;

    if (temp.cm >= 100)
    {
        temp.m += temp.cm / 100;
        temp.cm %= 100;
    }

    if (temp.m >= 1000)
    {
        temp.km += temp.m / 1000;
        temp.m %= 1000;
    }

    return temp;
}
void Distance::showdata()
{
    cout << "Distance: " << km << "km," << m << "m," << cm << "cm" << endl;
}
int main()
{
    Distance d1(5, 999, 99), d2(20, 999, 99), d3;
    d1.showdata();
    d2.showdata();

    d3 = d1 + d2;
    d3.showdata();

    ++d1;
    d1.showdata();

    d1++;
    d1.showdata();

    return 0;
}  */

//? 10. Consider the following class Array

/* class Array
{
    int *p;

    int size;

public:
    // methods
};

Define constructor to allocate an array of given size(size is given through parameter).

Define a subscript operator to access element at given Index.Define destructor to deallocates the memory of array.
*/
/* #include <iostream>
#include <iostream>
using namespace std;

class Array
{
private:
    int *p;
    int size;

public:
    // Constructor to allocate memory
    Array(int s) : size(s)
    {
        p = new int[size]; // ✅ Memory allocate ki
    }

    // Constructor to initialize from another array
    Array(int *a, int s) : size(s)
    {
        p = new int[size]; 
        for (int i = 0; i < size; i++)
        {
            p[i] = a[i];
        }
    }

    // Subscript Operator Overloading
    int &operator[](int index)
    {
        if (index < 0 || index >= size) // ✅ Out-of-bounds checking
        {
            cout << "Array index out of bounds!" << endl;
            exit(1); 
        }
        return p[index];
    }

    void showdata()
    {
        for (int i = 0; i < size; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~Array()
    {
        delete[] p; // ✅ Avoid memory leak
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Array a(arr, 5);

    a.showdata();

    // Accessing elements using subscript operator
    cout << "Element at index 2: " << a[3] << endl;

    // Modifying an element using subscript operator
    a[2] = 50;
    a.showdata();

    return 0;
} */
 