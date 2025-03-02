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
}