#include <iostream>
using namespace std;
class circle
{
private:
    int r;

public:
    void set_radius(int radius)
    {
        r=radius;
    }
    void get_radius()
    {
        cout<<"Radius: "<<r<<endl;
    }
    float area()
    {
      return 3.14*r*r;
    }
    float circumference()
    {
        return 2*3.14*r;
    }
};
int main()
{
    circle c1;
    c1.set_radius(5);
    c1.get_radius();
    float area_of_circle=c1.area();
    cout<<"Area of Circle: "<<area_of_circle<<endl;;
    float circumference_of_circle=c1.circumference();
    cout<<"Circumference of Circle: "<<circumference_of_circle;
    return 0;
}
