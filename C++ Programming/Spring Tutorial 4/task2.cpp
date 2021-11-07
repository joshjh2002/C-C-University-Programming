#include <iostream>
#include <string>
#include <vector>
// compile with g++ student-main.cpp -o main

using namespace std;

class person
{
public:
    person(string full_name, int nhs_number) : name(full_name), nhs(nhs_number)
    {
        
        // empty constructor, for now...
        p.push_back(this);
    }
    virtual ~person(){
        int i = 0;
        while (p[i] != NULL)
        {
            if (p[i] == this)
            {
                break;
            }
            i++;
        }
        p.erase(p.begin() + i);
    };

    string getName()
    {
        return name;
    }

    virtual void print()
    {
        cout << "Person \"" << name << "\", " << nhs << endl;
    }

    static vector<person *> &allPeople()
    {
        // implement this function and everything needed to track the available people
        return p;
    }

protected:
    static vector<person*> p;
    static int hasInitialised;
    string name;
    int nhs;
};
vector<person*> person::p;
class student : public person
{
public:
    student(string full_name, int nhs_number, int student_id) : student_id(student_id), person(full_name, nhs_number) // call constructor of parent class person
    {
    }

    int getStudentID()
    {
        return student_id;
    }

    virtual void print()
    {
        cout << "Student \"" << name << "\", " << nhs << ", " << student_id << endl;
    }

protected:
    int student_id;
};

void add_dummy()
{
    person someone("someone", 223);
}

int main()
{
    student max("Max Mustermann", 4712, 83000303);
    person john("B. Johnson", 222);

    // this case should work too, but what happens if the person is destroyed?
    // first solve it by commenting out this code:
    // add_dummy();
    // add_dummy();

    cout << "Registered People:" << endl;
    for (auto &p : student::allPeople())
    {
        p->print();
    }

    return 0;
}
