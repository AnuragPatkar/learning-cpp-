//! Assignment-38: Inheritance

/* //? 1. Define a class Person with name and age as instance variables as private members. Provide setters and getters as protected methods. Derive a class Employee from Person class with private instance variable salary. Provide public methods setEmployee() and showEmployee().
#include <iostream>
#include <iomanip> // For setprecision
using namespace std;
class Person
{
private:
    string name;
    int age;

protected:
    void setname(string s)
    {
        name = s;
    }
    void setage(int a) { age = a; }
    string getname()
    {
        return name;
    }
    int getage() { return age; }

public:
    Person() {}
};
class Employee : public Person
{
private:
    float salary;

public:
    void setemployee(string s, int a, float p)
    {
        setname(s);
        setage(a);
        salary = p;
    }
    void getemployee()
    {
        cout << "Name: " << getname() << endl;
        cout << "Age: " << getage() << endl;
        cout << "Salary: " << fixed << setprecision(2) << salary << endl;
    }
};
int main()
{
    Employee e1;
    e1.setemployee("Anurag", 35, 12000.0);
    e1.getemployee();
    return 0;
} */

/* //? 2. Define a class Circle with radius as private Instance variable and setRadius(), getRadius(), getArea() as public instance methods. Define a class ThickCircle as a subclass of Circle with thickness as private instance variable and getThickness(). setThickness() as public instance methods. Provide an overridden method getArea() to calculate area of thick portion of circle.
#include <iostream>
using namespace std;
class Circle
{
private:
    float radius;

public:
    void setRadius(float r) { radius = r; }
    float getRadius() { return radius; }
    virtual float getArea() { return 3.14 * radius * radius; }
};
class ThickCircle : public Circle
{
private:
    float thickness;

public:
    void setThickness(float t)
    {
        thickness = t;
    }
    float getThickness() { return thickness; }
    float getArea()
    {
        float outerRadius = getRadius() + thickness;
        return 3.14 * (outerRadius * outerRadius - getRadius() * getRadius());
    }
};
int main()
{
    Circle c1;
    c1.setRadius(5);
    cout<<"Area of circle: "<<c1.getArea()<<endl;

    ThickCircle t1;
    t1.setRadius(5);
    t1.setThickness(2);
    cout<<"Area of circle after adding thickness: "<<t1.getArea()<<endl;
    return 0;
} */

/* //? 3. Define a class Coordinate with x and y as instance variables. Define overloaded versions of getDistance(), first with no argument calculating distance from origin, and second with one argument of Coordinate type to calculate distance between two coordinates. Also define other methods if required.
#include <iostream>
#include <math.h>
using namespace std;
class Coordinate
{
private:
    int x, y;

public:
    Coordinate(int x = 0, int y = 0) : x(x), y(y) {}
    void getDistance() const
    {
        double distance = sqrt(x * x + y * y);
        cout << "Distance from origin: " << distance << endl;
    }

    void getDistance(const Coordinate &c)
    {
        double distance = sqrt((c.x-x) * (c.x-x) + (c.y-y)*(c.y-y));
        cout << "Distance : " << distance << endl;
    }
};
int main()
{
    Coordinate c1(3,4),c2(5,6);
    c1.getDistance();
    c1.getDistance(c2);

    return 0;
} */

/* //? 4. Define a class Shape with shapeName as instance variable. Provide setter and getter.
#include <iostream>
using namespace std;
class Shape
{
private:
    string shapename;

public:
    void setShapename(string s)
    {
        shapename = s;
    }
    string getShapename()
    {
        return shapename;
    }
};
int main()
{
    Shape s1;
    s1.setShapename("anurag patkar");
    cout<<"Name:" <<s1.getShapename()<<endl;
    return 0;
} */

/* //? 5. In question 3 & 4, derive a class StraightLine from Shape with two Coordinate type objects as instance members. Provide methods to setLine(), getDistance() and showLine()
#include <iostream>
#include <math.h>
using namespace std;
class Shape
{
private:
    string shapename;

public:
    void setShapename(string s)
    {
        shapename = s;
    }
    string getShapename()
    {
        return shapename;
    }
};
class Coordinate
{
private:
    int x, y;

public:
    Coordinate(int x = 0, int y = 0) : x(x), y(y) {}
    void setCoordinate(int a, int b)
    {
        x = a;
        y = b;
    }
    void showCoordinate()
    {
        cout << "x=" << x << " y=" << y << endl;
    }
    void getDistance() const
    {
        double distance = sqrt(x * x + y * y);
        cout << "Distance from origin: " << distance << endl;
    }

    void getDistance(const Coordinate &c)
    {
        double distance = sqrt((c.x - x) * (c.x - x) + (c.y - y) * (c.y - y));
        cout << "Distance : " << distance << endl;
    }
};
class StraightLine : public Shape
{
private:
    Coordinate c1, c2;

public:
    void setLine(int x1, int y1, int x2, int y2)
    {
        c1.setCoordinate(x1, y1);
        c2.setCoordinate(x2, y2);
    }
    void getDistance()
    {
        c1.getDistance(c2);
    }
    void showLine()
    {
        cout << "Line from ";
        c1.showCoordinate();
        cout << " to ";
        c2.showCoordinate();
        cout << endl;
    }
};
int main()
{
    StraightLine l1;
    l1.setShapename("My line");
    l1.setLine(3,4,5,6);

    cout<<"Shapename: "<<l1.getShapename()<<endl;
    l1.showLine();
    l1.getDistance();

    return 0;
} */

/* //? 6. Define a class Game with an array of 5 int variables as instance member to store the score of each of 5 rounds. Provide method to setScore(int round, int score). Also provide method getScore(int round).
#include <iostream>
using namespace std;
class Game
{
private:
    int arr[5];

public:
    Game()
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    void setScore(int round, int score)
    {
        if (round >= 1 && round <= 5)
            arr[round - 1] = score;
        else
            cout << "Invalid input." << endl;
    }
    int getScore(int round)
    {
        if (round >= 1 && round <= 5)
            return arr[round - 1];
        else
        {
            cout << "Invalid input." << endl;
            return -1;
        }
    }
};
int main()
{
    Game g1;
    g1.setScore(1, 2);
    g1.setScore(2, 4);
    g1.setScore(3, 5);
    g1.setScore(4, 6);
    g1.setScore(5, 8);

    cout << "Score: " << g1.getScore(8);
    return 0;
} */

/* //? 7. In question 6, derive a class GameResult with an array of 5 int type variables to store the result in each round. Result value is 2 for win, 0 for loose and 1 for draw. Provide methods to set Result and getResult. Write method to calculate final result of the game.
#include <iostream>
using namespace std;
class Game
{
private:
    int arr[5];

public:
    Game()
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    void setScore(int round, int score)
    {
        if (round >= 1 && round <= 5)
            arr[round - 1] = score;
        else
            cout << "Invalid input." << endl;
    }
    int getScore(int round)
    {
        if (round >= 1 && round <= 5)
            return arr[round - 1];
        else
        {
            cout << "Invalid input." << endl;
            return -1;
        }
    }
    void displayScore()
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
class GameResult : public Game
{
private:
    int result[5];

public:
    GameResult()
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            result[i] = -1;
        }
    }
    void setResult(int round, int res)
    {
        if (round >= 1 && round <= 5)
        {
            if (res == 2 || res == 1 || res == 0)
                result[round - 1] = res;
            else
                cout << "Invalid result value. Use 2 for win, 1 for draw, or 0 for loss." << endl;
        }
        else
            cout << "Invalid round number." << endl;
    }
    void getResult()
    {
        int i;
        cout << "Results(Win=2,Draw=1,Loss=0):" << endl;
        for (i = 0; i < 5; i++)
        {
            cout << result[i] << " ";
        }
    }
    int final_result()
    {
        int final=0;
        int i;
        for(i=0;i<5;i++)
        {
            final+=result[i];
        }
        return final;
    }
};
int main()
{

    GameResult r1;
    r1.setResult(1, 2); // Win in round 1
    r1.setResult(2, 0); // Loss in round 2
    r1.setResult(3, 1); // Draw in round 3
    r1.setResult(4, 2); // Win in round 4
    r1.setResult(5, 0); // Loss in round 5

    r1.getResult();
    cout<<endl;
    cout<<"Final Result: "<<r1.final_result()<<endl;
    return 0;
} */

/* //? 8. Define a class Actor with name, age as instance variables and setter, getters as instance methods. Define a class TVActor as a derived class of Actor with instance variable to store number of TV projects done or running and define setter, getter. Also define setTVActor() and showTVActor(). Define a class MovieActor as a derived class of Actor with instance variable to store number of movies doe or running and define setter, getter. Also define setMovieActor() and showMovie Actor().
//? Derive a class AllScreenActor from TVActor and MovieActor. Define a method to setActorData() and showActorData().
#include <iostream>
using namespace std;
class Actor
{
private:
    string name;
    int age;

public:
    void setName(string s) { name = s; }
    void setAge(int a) { age = a; }
    string getName() { return name; }
    int getAge() { return age; }
};
class TVActor : virtual public Actor
{
private:
    int num_of_TV_projects;

public:
    void setTVActorprojects(int tvp)
    {
        num_of_TV_projects = tvp;
    }
    int getTVActorprojects()
    {
        return num_of_TV_projects;
    }

    void setTVActor(string name, int age, int tvp)
    {
        setName(name);
        setAge(age);
        num_of_TV_projects = tvp;
    }
    void showTVActor()
    {
        cout << "TV Actor: " << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "TV Shows: " << num_of_TV_projects << endl;
    }
};
class MovieActor : virtual public Actor
{
private:
    int num_of_movies;

public:
    void setMovieActorprojects(int Movies)
    {
        num_of_movies = Movies;
    }
    int getMovieprojects()
    {
        return num_of_movies;
    }
    void setMovieActor(string name, int age, int Movies)
    {
        setName(name);
        setAge(age);
        num_of_movies = Movies;
    }
    void showMovieActor()
    {
        cout << "Movie Actor: " << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Movies : " << num_of_movies << endl;
    }
};
class AllScreenActor : public TVActor, public MovieActor
{
public:
    void setActorData(string name, int age, int tvp, int Movies)
    {
        setName(name);
        setAge(age);
        setTVActorprojects(tvp);
        setMovieActorprojects(Movies);
    }
    void ShowActorData()
    {
        cout << "Actor data: " << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Tv shows: " << getTVActorprojects() << endl;
        cout << "Movies : " << getMovieprojects() << endl;
    }
};
int main()
{
    AllScreenActor as1;
    as1.setActorData("Anurag",25,30,12);
    as1.ShowActorData();

    return 0;
} */