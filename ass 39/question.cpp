//! Assignment-39: File Handling

/* //? 1. Write a C++ program to copy content of file and store in other file.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string sourceFileName, destinationFileName;

    // Get the source and destination file names from the user
    cout << "Enter the source file name: ";
    cin >> sourceFileName;
    cout << "Enter the destination file name: ";
    cin >> destinationFileName;

    // Open the source file for reading
    ifstream sourceFile(sourceFileName);
    if (!sourceFile)
    {
        cerr << "Error: Unable to open the source file!" << endl;
        return 1;
    }

    // Open the destination file for writing
    ofstream destinationFile(destinationFileName);
    if (!destinationFile)
    {
        cerr << "Error: Unable to create or open the destination file!" << endl;
        sourceFile.close();
        return 1;
    }

    // Copy content from source file to destination file
    char ch;
    while (sourceFile.get(ch))
    {
        destinationFile.put(ch);
    }

    // Close the files
    sourceFile.close();
    destinationFile.close();

    cout << "File content copied successfully!" << endl;

    return 0;
} */

/* //? 2. Write a C++ program to search a word in a file.
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("file2.txt", ios::out);
    char str[] = "My name is anurag patkar";
    fout<<str;
    fout.close();

    char word[]="name";

    ifstream fin;
    fin.open("file2.txt",ios::in);
    if(!fin)
    {cout<<"file not opened.";
    return 1;}
    char ch;
    while(fin.get(ch))
    {
        if(ch==word[0])
        {
            int i=1;
            while(word[i]==fin.get())
            {
                i++;
            }
            if(word[i]=='\0')
            {
                cout<<"word found";
                break;
            }
        }
    }
    fin.close();

    return 0;
} */

/* //? 3. Define a class Employe with empid, name and salary as instance variables. Also provide instance methods to input and display Employee record.
#include<iostream>
using namespace std;
class Employee
{
private:
int empid;
string name;
float salary;
public:
void inputEmployee(int id,string n,float s)
{
    empid=id;
    name=n;
    salary=s;
}
void displayEmployee()
{
    cout<<"Employee details: "<<endl;
    cout<<"Employee id: "<<empid<<endl;
    cout<<"Employee name: "<<name<<endl;
    cout<<"Salary: "<<salary<<endl;
}
};
int main()
{
    Employee e1;
    e1.inputEmployee(101,"Anurag Patkar",20000.00);
    e1.displayEmployee();
    return 0;
} */

/* //? 4. In question 3, define a member function to store new employee record in a file.
#include <iostream>
#include <fstream>
using namespace std;
class Employee
{
private:
    int empid;
    string name;
    float salary;

public:
    void inputEmployee(int id, string n, float s)
    {
        empid = id;
        name = n;
        salary = s;
    }
    void displayEmployee()
    {
        cout << "Employee details: " << endl;
        cout << "Employee id: " << empid << endl;
        cout << "Employee name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
    void storeEmployee()
    {
        ofstream fout;
        fout.open("file4.txt", ios::app);
        if (!fout)
        {
            cout << "Error: Could not open file for writing!";
            return;
        }
        fout << empid << " " << name << " " << salary<<endl;
        fout.close();
        cout << "Employee data stored successfully";
    }
};

int main()
{
    Employee e1;
    e1.inputEmployee(101, "Anurag Patkar", 20000.00);
    e1.displayEmployee();
    e1.storeEmployee();
    return 0;
} */

/* //? 5. In question 3, define a member function to print all employee records stored in a file
#include <iostream>
#include <fstream>
using namespace std;
class Employee
{
private:
    int empid;
    string name;
    float salary;

public:
    void inputEmployee(int id, string n, float s)
    {
        empid = id;
        name = n;
        salary = s;
    }
    void displayEmployee()
    {
        cout << "Employee details: " << endl;
        cout << "Employee id: " << empid << endl;
        cout << "Employee name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
    void storeEmployee()
    {
        ofstream fout;
        fout.open("file4.txt", ios::app);
        if (!fout)
        {
            cout << "Error: Could not open file for writing!";
            return;
        }
        fout << empid << " " << name << " " << salary << endl;
        fout.close();
        cout << "Employee data stored successfully";
    }
    void displayAllEmployee()
    {
        ifstream fin;
        fin.open("file4.txt", ios::in);
        if (!fin)
        {
            cout << "Error: file not found.";
            return;
        }
        char ch;
        while(fin.get(ch))
        {
            cout<<ch;
        }
        fin.close();
    }
};

int main()
{
    Employee e1;
    // e1.inputEmployee(101, "Anurag Patkar", 20000.00);
    // e1.displayEmployee();
    // // e1.storeEmployee();
    e1.displayAllEmployee();
    return 0;
} */

/* //? 6. In question 3, define a member function to search an employee by his empid in file. Print his record if found, other wise display a message of search failed.
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Employee
{
private:
    int empid;
    string name;
    float salary;

public:
    void inputEmployee(int id, string n, float s)
    {
        empid = id;
        name = n;
        salary = s;
    }

    void displayEmployee()
    {
        cout << "\nEmployee Details:\n";
        cout << "Employee ID: " << empid << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    void storeEmployee()
    {
        ofstream fout("file6.txt", ios::app);
        if (!fout)
        {
            cout << "Error: Could not open file for writing!" << endl;
            return;
        }
        fout << empid << " " << name << " " << salary << endl;
        fout.close();
        cout << "✅ Employee data stored successfully: " << empid << " " << name << " " << salary << endl;
    }

    void displayAllEmployee()
    {
        ifstream fin("file6.txt");
        if (!fin)
        {
            cout << "Error: File not found." << endl;
            return;
        }

        cout << "\n📜 All Employee Records:\n";
        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }

        fin.close();
    }

    void searchbyEmpid()
    {
        int search_id;
        cout << "\nEnter Employee ID to Search: ";
        cin >> search_id;

        ifstream fin("file6.txt");
        if (!fin)
        {
            cout << "Error: File not found!" << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(fin, line))
        {
            stringstream ss(line);
            int id;
            string fullName;
            float sal;

            ss >> id; // Read employee ID

            ss.ignore();                 // Ignore space
            getline(ss, fullName, '\n'); // Read full line as name and salary

            size_t lastSpace = fullName.find_last_of(' '); // Find last space for salary extraction
            if (lastSpace != string::npos)
            {
                sal = stof(fullName.substr(lastSpace + 1)); // Extract salary
                fullName = fullName.substr(0, lastSpace);   // Extract name
            }

            if (id == search_id)
            {
                cout << "\nEmployee Found!\n";
                cout << "Employee ID: " << id << endl;
                cout << "Name: " << fullName << endl;
                cout << "Salary: " << sal << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Employee with ID " << search_id << " not found!" << endl;

        fin.close();
    }
};

int main()
{
    Employee e[5];

    e[0].inputEmployee(101, "Anurag Patkar", 20000.00);
    e[1].inputEmployee(102, "Bhanu Patkar", 25000.00);
    e[2].inputEmployee(103, "Akash Khare", 50000.00);
    e[3].inputEmployee(104, "Romil Sahu", 30000.00);
    e[4].inputEmployee(105, "Jaydeep Sahu", 65000.00);

    // Store employee data in file
    // for (int i = 0; i < 5; i++)
    // {
    //     e[i].storeEmployee();
    // }
    // Display all employees from file
    e[0].displayAllEmployee();

    // Search for an employee by ID
    e[0].searchbyEmpid();

    return 0;
} */

//? 7. In question 3, define a member function to edit employee data of given empid

//? 8. In question 3, define a member function to delete an employee record of given empid
