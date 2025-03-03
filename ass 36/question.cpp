//! Assignment-36: Operator Overloading, friend operator

/* //?1. Define a class Complex and overload following operators as a friend,

// 1. +

// 2. -

// 3. *

#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    math(int x = 0, int y = 0) : a(x), b(y) {}
    void showdata();
    friend math operator+(math, math);
    friend math operator-(math, math);
    friend math operator*(math, math);
};
math operator*(math m1, math m2)
{
    return math(m1.a * m2.a - m1.b * m2.b, m1.a * m2.b + m1.b * m2.a);
}
math operator-(math m1, math m2)
{
    return math(m1.a - m2.a, m1.b - m2.b);
}
math operator+(math m1, math m2)
{
    return math(m1.a + m2.a, m1.b + m2.b);
}
void math::showdata()
{
    cout << "a:" << a << " b:" << b << endl;
}
int main()
{
    math m1(3, 4), m2(5, 6), m3;
    m1.showdata();
    m2.showdata();

    m3 = m1 + m2;
    m3.showdata();

    m3=m1-m2;
    m3.showdata();

    m3=m1*m2;
    m3.showdata();
    return 0;
} */

/* //?2. Define a class Time with appropriate instance variables and member functions.

// Overload following operators

// 1. << insertion operator

// 2. >> extraction operator
#include <iostream>
using namespace std;
class Time
{
private:
    int hour, min, sec;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}
    void showdata();
    friend istream &operator>>(istream &, Time &);
    friend ostream &operator<<(ostream &, Time &);
};
istream &operator>>(istream &in, Time &t)
{
    in >> t.hour >> t.min >> t.sec;
    return in;
}
ostream &operator<<(ostream &out, Time &t)
{
    out << "Time:" << t.hour << ":" << t.min << ":" << t.sec;
    return out;
}
void Time::showdata()
{
    cout << "Time:" << hour << ":" << min << ":" << sec << endl;
}
int main()
{
    Time t1, t2;
    // t1.showdata();
    // t2.showdata();

    cout << "Enter Time:";
    cin >> t1;
    cout << t1;
    cout << endl;

    return 0;
} */

/* //?3. In Question-2, over load operator= to perform copy of Time object.
#include <iostream>
using namespace std;
class Time
{
private:
    int hour, min, sec;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}
    Time(const Time &t)
    {
        hour = t.hour;
        min = t.min;
        sec = t.sec;
    }
    void showdata();
    friend istream &operator>>(istream &, Time &);
    friend ostream &operator<<(ostream &, Time &);
    Time& operator=(const Time &t);
};
Time& Time::operator=(const Time &t)
{
    if (this != &t) // Check for self-assignment
    {
        hour = t.hour;
        min = t.min;
        sec = t.sec;
    }
    return *this;
}

istream &operator>>(istream &in, Time &t)
{
    in >> t.hour >> t.min >> t.sec;
    return in;
}
ostream &operator<<(ostream &out, Time &t)
{
    out << "Time:" << t.hour << ":" << t.min << ":" << t.sec;
    return out;
}
void Time::showdata()
{
    cout << "Time:" << hour << ":" << min << ":" << sec << endl;
}
int main()
{
    Time t1;
    // t1.showdata();
    // t2.showdata();

    cout << "Enter Time:";
    cin >> t1;
    cout << t1;
    cout << endl;

    Time t2 = t1;
    t2.showdata();

    return 0;
} */

//?4. Consider the following class Array

/* class Array
{
int *p;

int size;

public:

// methods
}
Define operator = to perform deep copy of Array objects. */
/* #include <iostream>
using namespace std;
class Array
{
private:
    int *p;
    int size;

public:
    Array()
    {
        size = 0;
        p = new int[1];
        p[0] = 0;
    }
    Array(int s)
    {
        size = s;
        p = new int[s];
        cout << "Enter " << s << " numbers: ";
        for (int i = 0; i < size; i++)
        {
            cin >> p[i];
        }
    }
    ~Array()
    {
        delete[] p;
    }
    void display()
    {
        int i;
        cout << "Array Elements: " << endl;
        for (i = 0; i < size; i++)
        {
            cout << p[i] << " ";
        }
        cout<<endl;
    }
    Array &operator=(const Array &arr)
    {
        if (this != &arr) // Self-assignment check
        {
            delete[] p; // Purani memory free karo

            size = arr.size;
            p = new int[size];

            for (int i = 0; i < size; i++)
            {
                p[i] = arr.p[i]; // Copy elements
            }
        }
        return *this;
    }
};

int main()
{
    int n;
    cout << "Enter number of element:";
    cin >> n;
    Array *arr1 = new Array(n);
    arr1->display();

    Array arr2;
    arr2 = *arr1;
    arr2.display();

    delete arr1;

    return 0;
} */

/* //?5. In Question 4, define a friend operator to concatenate two Array objects.
#include <iostream>
using namespace std;
class Array
{
private:
    int *p;
    int size;

public:
    Array()
    {
        size = 0;
        p = new int[1];
        p[0] = 0;
    }
    Array(int s)
    {
        size = s;
        p = new int[s];
        cout << "Enter " << s << " numbers: ";
        for (int i = 0; i < size; i++)
        {
            cin >> p[i];
        }
    }
    Array(const Array &arr)
    {
        size = arr.size;
        p = new int[size];  // Deep Copy
        for (int i = 0; i < size; i++)
        {
            p[i] = arr.p[i];
        }
    }
    ~Array()
    {
        delete[] p;
    }
    void display()
    {
        int i;
        cout << "Array Elements: " << endl;
        for (i = 0; i < size; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    friend Array operator+(const Array &arr1, const Array &arr2);
};
Array operator+(const Array &arr1, const Array &arr2)
{
    Array result; // Use default constructor
    result.size = arr1.size + arr2.size; // Set the size of the result array
    result.p = new int[result.size]; // Allocate memory for the result array

    // Copy elements from arr1
    for (int i = 0; i < arr1.size; i++)
    {
        result.p[i] = arr1.p[i];
    }

    // Copy elements from arr2
    for (int i = 0; i < arr2.size; i++)
    {
        result.p[arr1.size + i] = arr2.p[i];
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter number of element:";
    cin >> n;
    Array *arr1 = new Array(n);
    Array *arr2 = new Array(n);

    arr1->display();
    arr2->display();

    Array arr3 = *arr1 + *arr2;
    cout << "Concatenate Array: " << endl;
    arr3.display();
    delete arr1;
    delete arr2;

    return 0;
} */

/* //?6. In Question-1, provide a unary friend operator to negate the real and imaginary part of a complex number.
#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    Complex(int x = 0, int y = 0) : a(x), b(y) {}
    void showdata();
    friend Complex operator+(Complex, Complex);
    friend Complex operator-(Complex, Complex);
    friend Complex operator*(Complex, Complex);
    friend Complex operator-(Complex);
};
Complex operator-(Complex m1)
{
    m1.a = -m1.a;
    m1.b = -m1.b;
    return m1;
}
Complex operator*(Complex m1, Complex m2)
{
    return Complex(m1.a * m2.a - m1.b * m2.b, m1.a * m2.b + m1.b * m2.a);
}
Complex operator-(Complex m1, Complex m2)
{
    return Complex(m1.a - m2.a, m1.b - m2.b);
}
Complex operator+(Complex m1, Complex m2)
{
    return Complex(m1.a + m2.a, m1.b + m2.b);
}
void Complex::showdata()
{
    cout << "a:" << a << " b:" << b << endl;
}
int main()
{
    Complex m1(3, 4), m2(5, 6), m3;
    m1.showdata();
    m2.showdata();

    m3 = m1 + m2;
    m3.showdata();

    m3 = m1 - m2;
    m3.showdata();

    m3 = m1 * m2;
    m3.showdata();

    m3=-m1;
    m3.showdata();
    return 0;
} */

/* //?7. Define a class Integer with instance variable of type int. Provide a friend logical operator not I. Also define a friend operator == to compare two Integer objects.
#include <iostream>
using namespace std;
class Integer
{
private:
    int a;

public:
    Integer(int x = 0) : a(x) {}
    void display();
    friend Integer operator!(Integer);
    friend bool operator==(Integer, Integer);
};
bool operator==(Integer i1, Integer i2)
{
    return i1.a == i2.a;
}
Integer operator!(Integer i)
{
    i.a = (i.a == 0) ? 1 : -i.a;
    return i;
}
void Integer ::display()
{
    cout << "Value of a: " << a << endl;
}
int main()
{
    Integer i1(5), i3(5);
    i1.display();
    Integer i2 = !i1;
    i2.display();
    if (i1 == i3)
        cout << "same" << endl;
    else
        cout << "not equal" << endl;
    return 0;
} */

/* //?8. Create a Coordinate class with 2 instance variables x and y. Overload comma operator such that when you write c3 = (c1, c2) then c2 is assigned to c3. Where c1, c2,and c3 are objects of 3D coordinate class.
#include <iostream>
using namespace std;
class Coordinate
{
private:
    int x, y;

public:
    Coordinate(int x = 0, int y = 0) : x(x), y(y) {}
    void display();
    Coordinate operator,(Coordinate);
};
Coordinate Coordinate:: operator,(Coordinate c)
{
    return Coordinate(c.x,c.y);

}
void Coordinate ::display()
{
    cout << "x: " << x << " y: " << y << endl;
}
int main()
{
    Coordinate c1(5, 6), c2(7, 8);
    c1.display();
    c2.display();
    Coordinate c3=(c1,c2);
    c3.display();
    return 0;
} */

/* //?9. In Question-8, provide overloaded insertion and extraction operators.
#include <iostream>
using namespace std;
class Coordinate
{
private:
    int x, y;

public:
    Coordinate(int x = 0, int y = 0) : x(x), y(y) {}
    void display();
    Coordinate operator,(Coordinate);
    friend istream &operator>>(istream &, Coordinate &);
    friend ostream &operator<<(ostream &, Coordinate &);
};
istream &operator>>(istream &in, Coordinate &c)
{
    in>>c.x>>c.y;
    return in;
}
ostream &operator<<(ostream &out, Coordinate &c)
{
    out << "x:" << c.x << " y:" << c.y << endl;
    return out;
}
Coordinate Coordinate::operator,(Coordinate c)
{
    return Coordinate(c.x, c.y);
}
void Coordinate ::display()
{
    cout << "x: " << x << " y: " << y << endl;
}
int main()
{
    Coordinate c1, c2;
    cin >> c1;
    cout<<c1;
    c1.display();
    c2.display();
    Coordinate c3 = (c1, c2);
    c3.display();
    return 0;
} */

/* //?10. Define a class Student with roll no, name and age as instance variables. Create setStudent() and showStudent() methods in the class. Overload operator == to compare two Student objects.
#include <iostream>
using namespace std;
class Student
{
private:
    int roll_no;
    string name;
    float age;

public:
    void setstudent(int r, string n, float a);
    void showstudent();
    bool operator==(Student);
};
bool Student::operator==(Student s)
{
    return roll_no == s.roll_no && name == s.name && age == s.age;
}
void Student::showstudent()
{
    cout << "Roll Number: " << roll_no << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}
void Student::setstudent(int r, string n, float a)
{
    roll_no = r;
    name = n;
    age = a;
}
int main()
{
    Student s1, s2;
    s1.setstudent(101, "Anurag", 15.4);
    s1.showstudent();

    s2.setstudent(101, "Anurag", 15);
    s2.showstudent();

    if(s1==s2)
    printf("s1 is equal too s2.");
    else
    printf("s1 is not equal to s2.");
    return 0;
} */



