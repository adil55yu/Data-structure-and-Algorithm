#include <iostream>
using namespace std;

struct Student {
    int rollNo;
    string name;
    int marks;
};

int countStudents(Student s[], int n) {
    if(n == 0)
        return 0;

    if(s[n-1].marks >= 50)
        return 1 + countStudents(s, n-1);

    return countStudents(s, n-1);
}

void sortStudents(Student s[], int n) {
    if(n == 1)
        return;

    for(int i = 0; i < n-1; i++) {
        if(s[i].marks > s[i+1].marks) {
            Student temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
    }

    sortStudents(s, n-1);
}

int main() {
    Student s[5] = {
        {1, "Ali", 75},
        {2, "Ahmed", 40},
        {3, "Sara", 85},
        {4, "Hina", 35},
        {5, "Usman", 60}
    };

    cout << "Students with 50 or more marks: ";
    cout << countStudents(s, 5) << endl;

    sortStudents(s, 5);

    cout << "\nStudents sorted by marks:\n";

    for(int i = 0; i < 5; i++) {
        cout << s[i].rollNo << " "
             << s[i].name << " "
             << s[i].marks << endl;
    }

    return 0;
}