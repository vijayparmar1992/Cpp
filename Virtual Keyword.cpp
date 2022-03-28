#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person {
protected:
    string name;
    int age;

public:
    virtual void putdata() {};
    virtual void getdata() {};


};

class Professor :public Person
{
private:
    int publications;
    static int cur_id;
    int pcur_id = 0;
public:
    Professor()
    {
        cur_id = cur_id + 1;
        pcur_id = cur_id;
        //cout<<"pcur_id"<<pcur_id<<endl;
    }
    //The function getdata should get the input from the user : the name, age and publications of the professor
    void getdata()
    {
        cin >> name;
        cin >> age;
        cin >> publications;
    }
    //The function putdata should print the name, age, publications and the cur_id of the professor.
    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << pcur_id << endl;
    }
};

class Student :public Person
{
private:
    int marks[6];
    static int cur_id;
    int pcur_id = 0;
    int totalMarks;
    int getTotalMarks()
    {
        for (int i = 0; i < 6; i++)
        {
            totalMarks = totalMarks + marks[i];
        }
        return totalMarks;
    }
public:
    Student()
    {
        cur_id = cur_id + 1;
        pcur_id = cur_id;
        //cout<<"pcur_id"<<pcur_id<<endl;
    }

    // The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects.
    void getdata()
    {

        cin >> name;
        cin >> age;
        for (int i = 0; i < 6; i++)
        {
            cin >> marks[i];
        }
    }
    //The function putdata should print the name, age, sum of the marks and the cur_id of the student.
    void putdata()
    {
        cout << name << " " << age << " " << getTotalMarks() << " " << pcur_id << endl;
    }
};
int Student::cur_id = 0;
int Professor::cur_id = 0;


int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
