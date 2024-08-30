#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string n, string d)
        : name_(n), dob_(d) {}

    string GetName() {
        return name_;
    }

    string GetDOB() {
        return dob_;
    }

private:
    string name_;
    string dob_;
};

int main() {
    const int maxPersons = 100;
    Person people[maxPersons] = {
        Person("Alice", "1990-05-15"),
        Person("Bob", "1985-08-20"),
        Person("Charlie", "1995-03-10")
    };

    cout << "Enter a date of birth (YYYY-MM-DD): ";
    string searchDOB;
    cin >> searchDOB;

    bool found = false;
    for (int i = 0; i < maxPersons; ++i) {
        if (people[i].GetDOB() == searchDOB) {
            cout << "Name: " << people[i].GetName() << endl;
            found = true;
            break; // Exit the loop once a match is found
        }
    }

    if (!found) {
        cout << "No persons found with the specified date of birth." << endl;
    }

    return 0;
}
