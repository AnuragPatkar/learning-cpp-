//! Assignment-37: Pointer, this, DMA

/* //? 1. Define a class Person with name and age as instance variables. Provide parameterised constructor with two formal arguments name & age, to initialise instance variables.
#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    void showdata();
};
void Person::showdata()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}
int main()
{
    string name;
    int age;
    printf("Enter name: ");
    cin >> name;
    printf("Enter age: ");
    cin >> age;
    Person *p1;
    p1 = new Person(name, age);
    if (!p1)
    {
        cout<<"Memory Allocation Failed."<<endl;
        return 0;
    }

    p1->showdata();
    delete p1;
    return 0;
} */

/* //? 2. Define a class Complex with instance variables a and b to store real and imaginary part of a complex number. Provide setData() method with formal arguments with the name a and b, to set the values of instance variables. Also define showData() method to display instance member variable values.
#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    void setdata(int a, int b)
    {
       this->a=a;
       this->b=b;
    }
    void showdata();
};
void Complex::showdata()
{
    cout << "Complex Number: " << a << "+" << b << "i" << endl;
}
int main()
{
    Complex *c1;
    c1=new Complex();
    if(!c1)
    {
        cout<<"Memory Allocation Failed."<<endl;
        return 0;
    }
    c1->setdata(5,6);
    c1->showdata();
    delete c1;
    return 0;
} */

/* //? 3. In question-2, write a non member function in which instantiate Complex class dynamically. Initialise instance variables and display their values.
#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    void setdata(int x, int y)
    {
        a = x;
        b = y;
    }
    void showdata();
};
void Complex::showdata()
{
    cout << "Complex Number: " << a << "+" << b << "i" << endl;
}
void processComplex(int x,int y)
{
    Complex *c=new Complex();
    c->setdata(x,y);
    c->showdata();
    delete c;
}
int main()
{
    processComplex(5,6);
    processComplex(7,8);


    return 0;
} */

/* //? 4. Define a class Distance with instance variables hr, min and sec. Provide instance methods setTime() and showTime(). setTime() method has formal arguments with the same name as instance variables. Also define setters and getters.
#include <iostream>
using namespace std;
class Distance
{
private:
    int hr, min, sec;

public:
    void setTime(int, int, int);
    void showTime();

    void setHr(int hr) { this->hr = hr; }
    void setMin(int min) { this->min = min; }
    void setSec(int sec) { this->sec = sec; }

    // Getter Methods
    int getHr() { return hr; }
    int getMin() { return min; }
    int getSec() { return sec; }
};
void Distance::showTime()
{
    cout << "Time: " << hr << ":" << min << ":" << sec << endl;
}
void Distance::setTime(int hr, int min, int sec)
{
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}

int main()
{
    Distance *t1;
    t1 = new Distance();
    t1->setTime(5, 12, 30);
    t1->showTime();
    delete t1;

    Distance t2;
    t2.setTime(1,20,25);
    t2.showTime();

    t2.setHr(2);
    t2.setMin(50);
    t2.setSec(50);
    t2.showTime();

    cout<<"Time: "<<t2.getHr()<<":"<<t2.getMin()<<":"<<t2.getSec()<<endl;
    return 0;
} */

/* //? 5. In question-4, define a method to dynamically create an array of Time objects with specified size (received through argument) and return array.
#include <iostream>
using namespace std;
class Time
{
private:
    int hr, min, sec;

public:
    void setTime(int, int, int);
    void showTime();

    void setHr(int hr) { this->hr = hr; }
    void setMin(int min) { this->min = min; }
    void setSec(int sec) { this->sec = sec; }

    // Getter Methods
    int getHr() { return hr; }
    int getMin() { return min; }
    int getSec() { return sec; }
};
void Time::showTime()
{
    cout << "Time: " << hr << ":" << min << ":" << sec << endl;
}
void Time::setTime(int hr, int min, int sec)
{
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}
Time *create_array(int s)
{
    Time *d = new Time[s];
    int i;
    for(i=0;i<s;i++)
    {
        d[i].setTime(i+1,20,30);
    }
    return d;
}
void display_array(Time *d,int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        d[i].showTime();
    }
}
int main()
{
    Time *t1;
    t1 = new Time();
    t1->setTime(5, 12, 30);
    t1->showTime();
    delete t1;

    Time t2;
    t2.setTime(1, 20, 25);
    t2.showTime();

    t2.setHr(2);
    t2.setMin(50);
    t2.setSec(50);
    t2.showTime();

    cout << "Time: " << t2.getHr() << ":" << t2.getMin() << ":" << t2.getSec() << endl;
    int size;
    cout << "Enter Size of array: " << endl;
    cin >> size;
    Time *t3 = create_array(size);
    display_array(t3,size);
    delete []t3;
    return 0;
} */

/* //? 6. In question-4, define a method to sort Time object array.
#include <iostream>
using namespace std;
class Time
{
private:
    int hr, min, sec;

public:
    void setTime(int, int, int);
    void showTime();
    int total_sec()
    {
        return hr * 3600 + min * 60 + sec;
    }

    void setHr(int hr) { this->hr = hr; }
    void setMin(int min) { this->min = min; }
    void setSec(int sec) { this->sec = sec; }

    // Getter Methods
    int getHr() { return hr; }
    int getMin() { return min; }
    int getSec() { return sec; }
};
void Time::showTime()
{
    cout << "Time: " << hr << ":" << min << ":" << sec << endl;
}
void Time::setTime(int hr, int min, int sec)
{
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}
Time *create_array(int s)
{
    Time *d = new Time[s];
    int i,h,m,sec;
    for (i = 0; i < s; i++)
    {
        cout<<"Enter Time: ";
        cin>>h>>m>>sec;
        d[i].setTime(h, m, sec);
    }
    return d;
}
void display_array(Time *d, int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        d[i].showTime();
    }
}

void sort(Time *d, int s)
{
    Time temp;
    int i, j;
    for (i = 0; i < s; i++)
    {
        for (j = i + 1; j < s; j++)
        {
            if (d[i].total_sec() > d[j].total_sec())
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}
int main()
{
    Time *t1;
    t1 = new Time();
    t1->setTime(5, 12, 30);
    t1->showTime();
    delete t1;

    Time t2;
    t2.setTime(1, 20, 25);
    t2.showTime();

    t2.setHr(2);
    t2.setMin(50);
    t2.setSec(50);
    t2.showTime();

    cout << "Time: " << t2.getHr() << ":" << t2.getMin() << ":" << t2.getSec() << endl;
    int size;
    cout << "Enter Size of array: " << endl;
    cin >> size;
    Time *t3 = create_array(size);
    cout<<"Before sorting: "<<endl;
    display_array(t3, size);

    sort(t3, size);
    cout<<"After sorting: "<<endl;
    display_array(t3, size);
    delete[] t3;
    return 0;
} */

/* //? 7. In question-4, define a method to display Time object array values. Array is received through argument.
#include <iostream>
using namespace std;
class Time
{
private:
    int hr, min, sec;

public:
    void setTime(int, int, int);
    void showTime();
    int total_sec()
    {
        return hr * 3600 + min * 60 + sec;
    }

    void setHr(int hr) { this->hr = hr; }
    void setMin(int min) { this->min = min; }
    void setSec(int sec) { this->sec = sec; }

    // Getter Methods
    int getHr() { return hr; }
    int getMin() { return min; }
    int getSec() { return sec; }
};
void Time::showTime()
{
    cout << "Time: " << hr << ":" << min << ":" << sec << endl;
}
void Time::setTime(int hr, int min, int sec)
{
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}
Time *create_array(int s)
{
    Time *d = new Time[s];
    int i,h,m,sec;
    for (i = 0; i < s; i++)
    {
        cout<<"Enter Time: ";
        cin>>h>>m>>sec;
        d[i].setTime(h, m, sec);
    }
    return d;
}
void display_array(Time *d, int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        d[i].showTime();
    }
}

void sort(Time *d, int s)
{
    Time temp;
    int i, j;
    for (i = 0; i < s; i++)
    {
        for (j = i + 1; j < s; j++)
        {
            if (d[i].total_sec() > d[j].total_sec())
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}
int main()
{
    Time *t1;
    t1 = new Time();
    t1->setTime(5, 12, 30);
    t1->showTime();
    delete t1;

    Time t2;
    t2.setTime(1, 20, 25);
    t2.showTime();

    t2.setHr(2);
    t2.setMin(50);
    t2.setSec(50);
    t2.showTime();

    cout << "Time: " << t2.getHr() << ":" << t2.getMin() << ":" << t2.getSec() << endl;
    int size;
    cout << "Enter Size of array: " << endl;
    cin >> size;
    Time *t3 = create_array(size);
    cout<<"Before sorting: "<<endl;
    display_array(t3, size);

    sort(t3, size);
    cout<<"After sorting: "<<endl;
    display_array(t3, size);
    delete[] t3;
    return 0;
} */

/* //? 8. Define a class String with char pointer and length of the string as instance member variables. Define a method to dynamically create an array of char type and hold the input string in such a way that the array length is just enough to accommodate the input string.
#include <iostream>
#include<string.h>
using namespace std;
class String
{
private:
    char *str;
    int l;

public:
    String()
    {
        l = 0;
        str = new char[1];
        str[0] = '\0';
    }
    String(const char *s)
    {
        l = strlen(s);
        str = new char[l + 1];
        strcpy(str, s);
    }
    String(const String &s)
    {
        l = s.l;
        str = new char[l + 1];
        strcpy(str, s.str);
    }

    void display()
    {
        cout<<str<<endl;
    }
    ~String()
    {
        delete[] str;
    }
};
int main()
{
    String s1("Anurag"),s2;
    s1.display();
    s2.display();
    String s3=s1;
    s3.display();
    return 0;
} */

/* //? 9. In question-8, define methods to convert string into uppercase, lowercase.
#include <iostream>
#include <string.h>
using namespace std;
class String
{
private:
    char *str;
    int l;

public:
    String()
    {
        l = 0;
        str = new char[1];
        str[0] = '\0';
    }
    String(const char *s)
    {
        l = strlen(s);
        str = new char[l + 1];
        strcpy(str, s);
    }
    String(const String &s)
    {
        l = s.l;
        str = new char[l + 1];
        strcpy(str, s.str);
    }
    void uppercase()
    {
        int i, j;
        for (i = 0; i < l; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
        }
    }
    void lowercase()
    {
        int i, j;
        for (i = 0; i < l; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
        }
    }
    void display()
    {
        cout << str << endl;
    }
    ~String()
    {
        delete[] str;
    }
};
int main()
{
    String s1("Anurag");
    s1.display();
    String s3 = s1;
    s3.display();

    s3.uppercase();
    cout << "Uppercase: ";
    s3.display();

    s3.lowercase();
    cout << "lowercase: ";
    s3.display();
    return 0;
} */

/* //? 10. In question-8, define methods to print string, return string, return length of string.
#include <iostream>
#include <string.h>
using namespace std;
class String
{
private:
    char *str;
    int l;

public:
    String()
    {
        l = 0;
        str = new char[1];
        str[0] = '\0';
    }
    String(const char *s)
    {
        l = strlen(s);
        str = new char[l + 1];
        strcpy(str, s);
    }
    String(const String &s)
    {
        l = s.l;
        str = new char[l + 1];
        strcpy(str, s.str);
    }
    void uppercase()
    {
        int i, j;
        for (i = 0; i < l; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
        }
    }
    void lowercase()
    {
        int i, j;
        for (i = 0; i < l; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
        }
    }
    void display()
    {
        cout << str << endl;
    }
    int get_length()
    {
        return l;
    }
    char* getstring()
    {
        return str;
    }
    ~String()
    {
        delete[] str;
    }
};
int main()
{
    String s1("Anurag");
    s1.display();
    String s3 = s1;
    s3.display();

    s3.uppercase();
    cout << "Uppercase: ";
    s3.display();

    s3.lowercase();
    cout << "lowercase: ";
    s3.display();

    cout<<"String: "<<s3.getstring()<<endl;
    cout<<"Length:"<<s3.get_length()<<endl;
    s3.display();
    return 0;
} */