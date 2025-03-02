#include <iostream>
#include <string.h>
using namespace std;
class Customer
{
private:
    int cust_id;
    char name[20];
    char email[20];
    char mobile[10];

public:
    Customer()
    {
        cust_id = 0;
        strcpy(name, "no name");
        strcpy(email, "no email");
        strcpy(mobile, "no mobile number");
    }
    Customer(int x)
    {
        cust_id = x;
        strcpy(name, "no name");
        strcpy(email, "no email");
        strcpy(mobile, "no mobile number");
    }
    Customer(int x, const char *a, const char *b)
    {
        cust_id = x;
        strcpy(name, a);
        strcpy(email, b);
        strcpy(mobile, "no mobile number");
    }
    Customer(int x, const char *a, const char *b, const char *c)
    {
        cust_id = x;
        strcpy(name, a);
        strcpy(email, b);
        strcpy(mobile, c);
    }

    void showdata();
};
void Customer::showdata()
{
    cout << "customer id :" << cust_id << endl;
    cout << "customer name :" << name << endl;
    cout << "Email Id:" << email << endl;
    cout << "Mobile Number: " << mobile << endl;
}
int main()
{
    Customer c1, c2(101), c3(102, "Anurag", "A@gmail.com"), c4(105, "bhanu", "anurag@gmail.com", "9098906256");
    c1.showdata();
    c2.showdata();
    c3.showdata();
    c4.showdata();
    return 0;
}
