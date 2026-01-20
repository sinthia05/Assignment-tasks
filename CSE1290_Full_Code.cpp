#include <iostream>
#include <string>
using namespace std;

const int MAX_TEACHERS = 5;
const int MAX_COURSES  = 5;
const int MAX_LOAD     = 2;

//Function Declaration

// Teacher - Done by Sumaiya(2396)
void Add_Teacher(string names[], string faculties[],
                 int availability[], int teacherLoad[],
                 int &teacherCount);

void Delete_Teacher(string names[], string faculties[],
                    int availability[], int teacherLoad[],
                    int &teacherCount);

void Display_Teachers(const string names[], const string faculties[],
                      const int availability[], const int teacherLoad[],
                      int teacherCount);



// Course - Done by Sumaiya(2396)
void Add_Course(string courseNames[], string courseFaculty[],
                int courseSlot[], int assignedTeacher[],
                int &courseCount);

void Delete_Course(string courseNames[], string courseFaculty[],
                   int courseSlot[], int assignedTeacher[],
                   int &courseCount);


void Display_Courses(const string courseNames[], const string courseFaculty[],
                     const int courseSlot[], const int assignedTeacher[],
                     const string teacherNames[], int courseCount);



// Search - Done by Sinthia(2240)
void Search_By_Name(const string names[], const string faculties[],
                    const int availability[], const int teacherLoad[],
                    int teacherCount);

void Search_By_Faculty(const string names[], const string faculties[],
                       const int availability[], int teacherCount);

void Search_By_Slot(const string names[], const string faculties[],
                    const int availability[], int teacherCount);

void Search_Assigned_Courses(const string teacherNames[],
                             const string courseNames[],
                             const int assignedTeacher[],
                             int teacherCount, int courseCount);



// Assignment - Done by Sinthia(2240)
void Assign_Teachers(const string teacherNames[], const string teacherFac[],
                     const int availability[], int teacherLoad[],
                     int teacherCount, const string courseNames[],
                     const string courseFac[], const int courseSlot[],
                     int assignedTeacher[], int courseCount);

void Display_Routine(const string courseNames[], const int courseSlot[],
                     const int assignedTeacher[], const string teacherNames[],
                     int courseCount);

int main() {

    string names[MAX_TEACHERS];
    string faculties[MAX_TEACHERS];
    int availability[MAX_TEACHERS];
    int teacherLoad[MAX_TEACHERS] = {0};
    int teacherCount = 0;

    string courseNames[MAX_COURSES];
    string courseFaculty[MAX_COURSES];
    int courseSlot[MAX_COURSES];
    int assignedTeacher[MAX_COURSES];
    int courseCount = 0;

    int choice;

    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Add Teacher\n";
        cout << "2. Delete Teacher\n";
        cout << "3. Display Teachers\n";
        cout << "4. Add Course\n";
        cout << "5. Delete Course\n";
        cout << "6. Display Courses\n";
        cout << "7. Search Teacher by Name\n";
        cout << "8. Search Teacher by Faculty\n";
        cout << "9. Search Teacher by Slot\n";
        cout << "10. Assign Teachers to Courses\n";
        cout << "11. Search Assigned Courses of a Teacher\n";
        cout << "12. Display Routine\n";
        cout << "13. Exit\n";
        cout << "Enter choice: ";


//FIX STARTS HERE ---------
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n";
            continue;
        }
        cin.ignore();
//FIX ENDS HERE ---------


        switch(choice) {
            case 1:
                Add_Teacher(names, faculties, availability,
                            teacherLoad, teacherCount);
                break;
            case 2:
                Delete_Teacher(names, faculties, availability,
                               teacherLoad, teacherCount);
                break;
            case 3:
                Display_Teachers(names, faculties,
                                 availability, teacherLoad,
                                 teacherCount);
                break;
            case 4:
                Add_Course(courseNames, courseFaculty,
                           courseSlot, assignedTeacher,
                           courseCount);
                break;
            case 5:
                Delete_Course(courseNames, courseFaculty,
                              courseSlot, assignedTeacher,
                              courseCount);
                break;
            case 6:
                Display_Courses(courseNames, courseFaculty,
                                courseSlot, assignedTeacher,
                                names, courseCount);
                break;
            case 7:
                Search_By_Name(names, faculties,
                               availability, teacherLoad,
                               teacherCount);
                break;
            case 8:
                Search_By_Faculty(names, faculties,
                                  availability, teacherCount);
                break;
            case 9:
                Search_By_Slot(names, faculties,
                               availability, teacherCount);
                break;
            case 10:
                Assign_Teachers(names, faculties, availability,
                                teacherLoad, teacherCount,
                                courseNames, courseFaculty,
                                courseSlot, assignedTeacher,
                                courseCount);
                break;
            case 11:
                Search_Assigned_Courses(names, courseNames,
                                        assignedTeacher,
                                        teacherCount, courseCount);
                break;
            case 12:
                Display_Routine(courseNames, courseSlot,
                                assignedTeacher, names,
                                courseCount);
                break;
            case 13:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 13);

    return 0;
}

//TEACHER FUNCTIONS

void Add_Teacher(string names[], string faculties[],
                 int availability[], int teacherLoad[],
                 int &teacherCount) {

    if (teacherCount >= MAX_TEACHERS) {
        cout << "Teacher limit reached.\n";
        return;
    }

    cout << "Enter Teacher Name: ";
    getline(cin, names[teacherCount]);

    cout << "Enter Faculty: ";
    getline(cin, faculties[teacherCount]);

    cout << "Enter Available Slot (1-5): ";
    cin >> availability[teacherCount];
    cin.ignore();

    teacherLoad[teacherCount] = 0;
    teacherCount++;

    cout << "Teacher added successfully.\n";
}

void Delete_Teacher(string names[], string faculties[],
                    int availability[], int teacherLoad[],
                    int &teacherCount) {

    string key;
    cout << "Enter teacher name to delete: ";
    getline(cin, key);

    for (int i = 0; i < teacherCount; i++) {
        if (names[i] == key) {
            for (int j = i; j < teacherCount - 1; j++) {
                names[j] = names[j + 1];
                faculties[j] = faculties[j + 1];
                availability[j] = availability[j + 1];
                teacherLoad[j] = teacherLoad[j + 1];
            }
            teacherCount--;
            cout << "Teacher deleted.\n";
            return;
        }
    }
    cout << "Teacher not found.\n";
}

void Display_Teachers(const string names[], const string faculties[],
                      const int availability[], const int teacherLoad[],
                      int teacherCount) {

    for (int i = 0; i < teacherCount; i++) {
        cout << i + 1 << ". " << names[i]
             << " | Faculty: " << faculties[i]
             << " | Slot: " << availability[i]
             << " | Load: " << teacherLoad[i] << endl;
    }
}


//COURSE FUNCTIONS

void Add_Course(string courseNames[], string courseFaculty[],
                int courseSlot[], int assignedTeacher[],
                int &courseCount) {

    cout << "Enter Course Name: ";
    getline(cin, courseNames[courseCount]);

    cout << "Enter Required Faculty: ";
    getline(cin, courseFaculty[courseCount]);

    cout << "Enter Slot (1-5): ";
    cin >> courseSlot[courseCount];
    cin.ignore();

    assignedTeacher[courseCount] = -1;
    courseCount++;
}

void Delete_Course(string courseNames[], string courseFaculty[],
                   int courseSlot[], int assignedTeacher[],
                   int &courseCount) {

    if (courseCount == 0) {
        cout << "No courses to delete.\n";
        return;
    }

    string delCourse;
    cout << "Enter course name to delete: ";
    getline(cin, delCourse);

    for (int i = 0; i < courseCount; i++) {
        if (courseNames[i] == delCourse) {

            for (int j = i; j < courseCount - 1; j++) {
                courseNames[j] = courseNames[j + 1];
                courseFaculty[j] = courseFaculty[j + 1];
                courseSlot[j] = courseSlot[j + 1];
                assignedTeacher[j] = assignedTeacher[j + 1];
            }

            courseCount--;
            cout << "Course deleted successfully.\n";
            return;
        }
    }

    cout << "Course not found.\n";
}


void Display_Courses(const string courseNames[], const string courseFaculty[],
                     const int courseSlot[], const int assignedTeacher[],
                     const string teacherNames[], int courseCount) {

    for (int i = 0; i < courseCount; i++) {
        cout << courseNames[i]
             << " | Faculty: " << courseFaculty[i]
             << " | Slot: " << courseSlot[i];

        if (assignedTeacher[i] != -1)
            cout << " | Teacher: " << teacherNames[assignedTeacher[i]];
        else
            cout << " | Teacher: Not Assigned";

        cout << endl;
    }
}



//SEARCH FUNCTIONS

void Search_By_Name(const string names[], const string faculties[],
                    const int availability[], const int teacherLoad[],
                    int teacherCount) {

    string key;
    cout << "Enter name: ";
    getline(cin, key);

    for (int i = 0; i < teacherCount; i++) {
        if (names[i] == key) {
            cout << "Found: " << names[i]
                 << " | Faculty: " << faculties[i]
                 << " | Slot: " << availability[i]
                 << " | Load: " << teacherLoad[i] << endl;
            return;
        }
    }
    cout << "Teacher not found.\n";
}

void Search_By_Faculty(const string names[], const string faculties[],
                       const int availability[], int teacherCount) {

    string key;
    cout << "Enter faculty: ";
    getline(cin, key);

    for (int i = 0; i < teacherCount; i++) {
        if (faculties[i] == key) {
            cout << names[i]
                 << " | Slot: " << availability[i] << endl;
        }
    }
}

void Search_By_Slot(const string names[], const string faculties[],
                    const int availability[], int teacherCount) {

    int slot;
    cout << "Enter slot: ";
    cin >> slot;
    cin.ignore();

    for (int i = 0; i < teacherCount; i++) {
        if (availability[i] == slot) {
            cout << names[i]
                 << " | Faculty: " << faculties[i] << endl;
        }
    }
}

void Search_Assigned_Courses(const string teacherNames[],
                             const string courseNames[],
                             const int assignedTeacher[],
                             int teacherCount, int courseCount) {

    string key;
    cout << "Enter teacher name: ";
    getline(cin, key);

    int index = -1;
    for (int i = 0; i < teacherCount; i++) {
        if (teacherNames[i] == key) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Teacher not found.\n";
        return;
    }

    cout << "Courses taught by " << key << ":\n";
    for (int i = 0; i < courseCount; i++) {
        if (assignedTeacher[i] == index) {
            cout << "- " << courseNames[i] << endl;
        }
    }
}



//ASSIGNMENT

void Assign_Teachers(const string teacherNames[], const string teacherFac[],
                     const int availability[], int teacherLoad[],
                     int teacherCount, const string courseNames[],
                     const string courseFac[], const int courseSlot[],
                     int assignedTeacher[], int courseCount) {

    for (int i = 0; i < courseCount; i++) {

        int best = -1;
        int minLoad = 999;

        for (int j = 0; j < teacherCount; j++) {
            if (courseFac[i] == teacherFac[j] &&
                courseSlot[i] == availability[j] &&
                teacherLoad[j] < MAX_LOAD) {

                int conflict = 0;
                for (int k = 0; k < courseCount; k++) {
                    if (assignedTeacher[k] == j &&
                        courseSlot[k] == courseSlot[i]) {
                        conflict = 1;
                        break;
                    }
                }

                if (!conflict && teacherLoad[j] < minLoad) {
                    minLoad = teacherLoad[j];
                    best = j;
                }
            }
        }

        if (best != -1) {
            assignedTeacher[i] = best;
            teacherLoad[best]++;
        }
    }

    cout << "Assignment completed.\n";
}

//FULL DISPLAY
void Display_Routine(const string courseNames[], const int courseSlot[],
                     const int assignedTeacher[], const string teacherNames[],
                     int courseCount) {

    if (courseCount == 0) {
        cout << "No routine available.\n";
        return;
    }

    cout << "\n===== FULL CLASS ROUTINE =====\n";

    for (int slot = 1; slot <= 5; slot++) {
        cout << "Time Slot " << slot << ":\n";

        bool found = false;
        for (int i = 0; i < courseCount; i++) {
            if (courseSlot[i] == slot) {
                cout << "  " << courseNames[i] << " - ";

                if (assignedTeacher[i] != -1)
                    cout << teacherNames[assignedTeacher[i]];
                else
                    cout << "Not Assigned";

                cout << endl;
                found = true;
            }
        }

        if (!found)
            cout << "  No class\n";
    }
}


