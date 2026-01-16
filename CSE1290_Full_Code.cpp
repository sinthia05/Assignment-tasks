#include <iostream>
#include <string>
using namespace std;

const int MAX_TEACHERS = 5;
const int MAX_COURSES = 5;

// Functions
void Add_Teacher(string names[], string faculties[], int &teacherCount);
void Delete_Teacher(string names[], string faculties[], int &teacherCount);
void Display_Teachers(const string names[], const string faculties[], int teacherCount);

void Add_Course(string courseNames[], string courseFaculty[], int courseSlot[],
                int assignedTeacher[], int &courseCount);
void Display_Courses(const string courseNames[], const string courseFaculty[],
                     const int courseSlot[], const int assignedTeacher[],
                     const string teacherNames[], int courseCount);
void Assign_Teachers(const string teacherNames[], const string teacherFac[],
                     int teacherCount, const string courseNames[],
                     const string courseFac[], const int courseSlot[],
                     int assignedTeacher[], int courseCount);

int main() {
    string names[MAX_TEACHERS];
    string faculties[MAX_TEACHERS];
    int teacherCount = 0;

    string courseNames[MAX_COURSES];
    string courseFaculty[MAX_COURSES];
    int courseSlot[MAX_COURSES];
    int assignedTeacher[MAX_COURSES];

    int courseCount = 0;
    int choice;

    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Add Teacher\n";
        cout << "2. Delete Teacher\n";
        cout << "3. Display Teachers\n";
        cout << "4. Add Course\n";
        cout << "5. Display Courses\n";
        cout << "6. Assign Teachers to Courses\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        // FIX
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore();
        // FIX

        switch(choice) {
            case 1:
                Add_Teacher(names, faculties, teacherCount);
                break;
            case 2:
                Delete_Teacher(names, faculties, teacherCount);
                break;
            case 3:
                Display_Teachers(names, faculties, teacherCount);
                break;
            case 4:
                Add_Course(courseNames, courseFaculty, courseSlot,
                           assignedTeacher, courseCount);
                break;
            case 5:
                Display_Courses(courseNames, courseFaculty, courseSlot,
                                assignedTeacher, names, courseCount);
                break;
            case 6:
                Assign_Teachers(names, faculties, teacherCount,
                                courseNames, courseFaculty, courseSlot,
                                assignedTeacher, courseCount);
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 7);

    return 0;
}

// Teacher Function

void Add_Teacher(string names[], string faculties[], int &teacherCount) {
    if (teacherCount >= MAX_TEACHERS) {
        cout << "Teacher limit reached.\n";
        return;
    }

    cout << "Enter Teacher Name: ";
    getline(cin, names[teacherCount]);
    cout << "Enter Faculty: ";
    getline(cin, faculties[teacherCount]);

    teacherCount++;
    cout << "Teacher added successfully!\n";
}

void Delete_Teacher(string names[], string faculties[], int &teacherCount) {
    if (teacherCount == 0) {
        cout << "No teachers to delete.\n";
        return;
    }

    string delName;
    cout << "Enter teacher name to delete: ";
    getline(cin, delName);

    for (int i = 0; i < teacherCount; i++) {
        if (names[i] == delName) {
            for (int j = i; j < teacherCount - 1; j++) {
                names[j] = names[j + 1];
                faculties[j] = faculties[j + 1];
            }
            teacherCount--;
            cout << "Teacher deleted.\n";
            return;
        }
    }
    cout << "Teacher not found.\n";
}

void Display_Teachers(const string names[], const string faculties[], int teacherCount) {
    if (teacherCount == 0) {
        cout << "No teachers available.\n";
        return;
    }

    cout << "\nTeachers:\n";
    for (int i = 0; i < teacherCount; i++) {
        cout << i + 1 << ". " << names[i]
             << " (" << faculties[i] << ")\n";
    }
}

// Course Function

void Add_Course(string courseNames[], string courseFaculty[],
                int courseSlot[], int assignedTeacher[],
                int &courseCount) {

    if (courseCount >= MAX_COURSES) {
        cout << "Course limit reached.\n";
        return;
    }

    cout << "Enter Course Name: ";
    getline(cin, courseNames[courseCount]);
    cout << "Enter Required Faculty: ";
    getline(cin, courseFaculty[courseCount]);
    cout << "Enter Time Slot (1-5): ";
    cin >> courseSlot[courseCount];
    cin.ignore();

    assignedTeacher[courseCount] = -1;
    courseCount++;

    cout << "Course added successfully!\n";
}

void Display_Courses(const string courseNames[], const string courseFaculty[],
                     const int courseSlot[], const int assignedTeacher[],
                     const string teacherNames[], int courseCount) {

    if (courseCount == 0) {
        cout << "No courses available.\n";
        return;
    }

    cout << "\nCourses:\n";
    for (int i = 0; i < courseCount; i++) {
        cout << i + 1 << ". " << courseNames[i]
             << " | Faculty: " << courseFaculty[i]
             << " | Slot: " << courseSlot[i];

        if (assignedTeacher[i] != -1)
            cout << " | Teacher: " << teacherNames[assignedTeacher[i]];
        else
            cout << " | Teacher: Not Assigned";

        cout << endl;
    }
}

// Assignment With Conflict Detection 

void Assign_Teachers(const string teacherNames[], const string teacherFac[],
                     int teacherCount, const string courseNames[],
                     const string courseFac[], const int courseSlot[],
                     int assignedTeacher[], int courseCount) {

    if (teacherCount == 0 || courseCount == 0) {
        cout << "Add teachers and courses first.\n";
        return;
    }

    for (int i = 0; i < courseCount; i++) {

        if (assignedTeacher[i] != -1)
            continue;

        for (int j = 0; j < teacherCount; j++) {

            if (courseFac[i] == teacherFac[j]) {

                int conflict = 0;

                for (int k = 0; k < courseCount; k++) {
                    if (assignedTeacher[k] == j &&
                        courseSlot[k] == courseSlot[i]) {
                        conflict = 1;
                        break;
                    }
                }

                if (!conflict) {
                    assignedTeacher[i] = j;
                    break;
                }
            }
        }
    }

    cout << "Assignment process completed.\n";
}
