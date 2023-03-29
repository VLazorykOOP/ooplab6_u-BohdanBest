#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int age;
public:
    Student(const string& name, int age) : name(name), age(age) {}
    virtual ~Student() {}

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Student name: " << student.name << endl << "age: " << student.age << endl;
        return os;
    }
};

class FamilyFather {
protected:
    string familyName;
    int childrenCount;
    int age2;
public:
    FamilyFather(const string& familyName, int childrenCount, int age2) : familyName(familyName), childrenCount(childrenCount), age2(age2){}
    virtual ~FamilyFather() {}

    friend ostream& operator<<(ostream& os, const FamilyFather& father) {
        os << "Family father name: " << father.familyName << endl << "age: " << father.age2 << endl << "children count: " << father.childrenCount << endl;
        return os;
    }
};

class StudentFamilyFather : public Student, public FamilyFather {
public:
    StudentFamilyFather(const string& name, int age, const string& familyName, int childrenCount, int age2)
        : Student(name, age), FamilyFather(familyName, childrenCount, age2) {}

    ~StudentFamilyFather() {}

    friend ostream& operator<<(ostream& os, const StudentFamilyFather& studentFather) {
        os << static_cast<const Student&>(studentFather) << static_cast<const FamilyFather&>(studentFather);
        return os;
    }
};

int main() {
    StudentFamilyFather sf("Bohdan", 18, "Bestanchuk", 2, 50);
    cout << sf << endl;

    return 0;
}