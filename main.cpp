#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct courses {
    string courseName;
    string professor;
    char grade;
    int hours;
};

struct student {
    string firstName;
    string lastName;
    string address;
    string advisor;
    string phoneNum;
    double gpa;
    int birthMonth;
    int birthDay;
    int birthYear;
    int studentId;
    int numCourses;
    courses course[5];
};

const int SIZE = 10;

void assignId(int counter, student *studentRecords);
int sampleData(int counter, student *studentRecords);
int addRecords(int counter, student *studentRecords);
void modifyRecords(int counter, student *studentRecords);
int removeRecords(int counter, student *studentRecords);
void viewRecords(int counter, student *studentRecords);
void addCourses(int counter, student *studentRecords);
void display(int counter, student *studentRecords);
void gpaCalc(int i, student *studentRecords);

void assignId(int counter, student *studentRecords){

    int i = SIZE;

    studentRecords[counter].studentId = rand() % 9000 + 1000;

    while(i--){
        if(studentRecords[counter].studentId==studentRecords[i].studentId){
            assignId(counter, studentRecords);
            i++;
        }
        else{
            break;
        }
    }
}

int sampleData(int counter, student *studentRecords){

    studentRecords[counter].firstName = "Sarah";
    studentRecords[counter].lastName = "Parrish";
    studentRecords[counter].address = "768 Annadale Rd. Baltimore, MD 21206";
    studentRecords[counter].advisor = "Jones";
    studentRecords[counter].phoneNum = "432-543-5735";
    studentRecords[counter].birthMonth = 10;
    studentRecords[counter].birthDay = 24;
    studentRecords[counter].birthYear = 1990;
    studentRecords[counter].numCourses = 2;
    studentRecords[counter].course[0].courseName = "Chemistry";
    studentRecords[counter].course[0].professor = "Lopez";
    studentRecords[counter].course[0].hours = 3;
    studentRecords[counter].course[0].grade = 'A';
    studentRecords[counter].course[1].courseName = "Algebra";
    studentRecords[counter].course[1].professor = "Williams";
    studentRecords[counter].course[1].hours = 3;
    studentRecords[counter].course[1].grade = 'C';

    assignId(counter, studentRecords);
    counter++;

    studentRecords[counter].firstName = "Ashley";
    studentRecords[counter].lastName = "Pope";
    studentRecords[counter].address = "633 N. Vine St. Norman, OK 73072";
    studentRecords[counter].advisor = "Miller";
    studentRecords[counter].phoneNum = "762-642-6432";
    studentRecords[counter].birthMonth = 06;
    studentRecords[counter].birthDay = 11;
    studentRecords[counter].birthYear = 1991;
    studentRecords[counter].numCourses = 2;
    studentRecords[counter].course[0].courseName = "History";
    studentRecords[counter].course[0].professor = "Garcia";
    studentRecords[counter].course[0].hours = 3;
    studentRecords[counter].course[0].grade = 'B';
    studentRecords[counter].course[1].courseName = "English";
    studentRecords[counter].course[1].professor = "Davis";
    studentRecords[counter].course[1].hours = 3;
    studentRecords[counter].course[1].grade = 'A';

    assignId(counter, studentRecords);
    counter++;

    studentRecords[counter].firstName = "Bryan";
    studentRecords[counter].lastName = "Vincent";
    studentRecords[counter].address = "50 Lkae Street Centreville, VA 20120";
    studentRecords[counter].advisor = "Jones";
    studentRecords[counter].phoneNum = "632-546-3425";
    studentRecords[counter].birthMonth = 11;
    studentRecords[counter].birthDay = 05;
    studentRecords[counter].birthYear = 1990;
    studentRecords[counter].numCourses = 1;
    studentRecords[counter].course[0].courseName = "Psychology";
    studentRecords[counter].course[0].professor = "Brown";
    studentRecords[counter].course[0].hours = 3;
    studentRecords[counter].course[0].grade = 'B';

    assignId(counter, studentRecords);
    counter++;

    studentRecords[counter].firstName = "Derek";
    studentRecords[counter].lastName = "Hobbs";
    studentRecords[counter].address = "9113 Gates Drive West Chicago, IL 60185";
    studentRecords[counter].advisor = "Miller";
    studentRecords[counter].phoneNum = "743-625-6345";
    studentRecords[counter].birthMonth = 04;
    studentRecords[counter].birthDay = 17;
    studentRecords[counter].birthYear = 1992;
    studentRecords[counter].numCourses = 1;
    studentRecords[counter].course[0].courseName = "Computer Science";
    studentRecords[counter].course[0].professor = "Clark";
    studentRecords[counter].course[0].hours = 3;
    studentRecords[counter].course[0].grade = 'A';

    assignId(counter, studentRecords);
    counter++;

    return counter;

}

int addRecords(int counter, student *studentRecords){
    
    string temp;
    int i = SIZE;

    cout << "  * Add new records *" << endl << endl;
    cout << "New student information" << endl;
    assignId(counter, studentRecords);
    
    cout << "Student ID: " << studentRecords[counter].studentId << endl;
    cout << "First Name: ";
    cin >> studentRecords[counter].firstName;
    cout << "Last Name: ";
    cin >> studentRecords[counter].lastName;
    cout << "Birthday (mm/dd/yy): ";
    cin.ignore();
    getline(cin, temp);
    studentRecords[counter].birthMonth = stoi(temp.substr(0, 2));
    studentRecords[counter].birthDay = stoi(temp.substr(3,5));
    studentRecords[counter].birthYear = stoi(temp.substr(6,10));
    cout << "Phone Number (555-555-5555): ";
    getline(cin, studentRecords[counter].phoneNum);
    while(studentRecords[counter].phoneNum.length()>12){
        cout << "Incorrect Input." << endl;
        cout << "Phone Number (555-555-5555): ";
        getline(cin, studentRecords[counter].phoneNum);
    }
    cout << "Address: ";
    cin.ignore();
    getline(cin, studentRecords[counter].address);
    cout << "Assigned Advisor: ";
    cin >> studentRecords[counter].advisor;
    studentRecords[counter].numCourses=0;
    studentRecords[counter].gpa=0;

    cout << endl << "New student record successfully created." << endl;
    counter++;

    return counter;

}

void modifyRecords(int counter, student *studentRecords){
    
    string temp;
    bool match = false;
    int tempId;
    int change;
    int i = SIZE;

    cout << "  * Modify Records *" << endl << endl;
    cout << "Enter the student's ID: ";
    cin >> tempId;
     
        while(i--){
            if(tempId==studentRecords[i].studentId){
                cout << "Match found!" << endl << endl;
                cout << studentRecords[i].firstName  << " " << studentRecords[i].lastName << endl;
                match = true;
                break;
            }
        }

        if(match){
            cout << endl;
            cout << "1. Name" << endl;
            cout << "2. Birthday" << endl;
            cout << "3. Phone Number" << endl;
            cout << "4. Address" << endl;
            cout << "5. Advisor" << endl << endl;
            cout << "Update: ";
            cin >> change;

            while (change > 5 || change < 0){
                cout << "Invalid Input." << endl;
                cout << "Update: ";
                cin >> change;
            }

            switch(change){
                case 1: 
                    cout << "First Name: ";
                    cin >> studentRecords[i].firstName;
                    cout << "Last Name: ";
                    cin >> studentRecords[i].lastName;
                    cout << endl << "Update has been successful." << endl;
                    return;
                case 2: 
                    cout << "Birthday (mm/dd/yy): "; 
                    cin.ignore();
                    getline(cin, temp);
                    studentRecords[i].birthMonth = stoi(temp.substr(0, 2));
                    studentRecords[i].birthDay = stoi(temp.substr(3,5));
                    studentRecords[i].birthYear = stoi(temp.substr(6,10)); 
                    cout << endl << "Update has been successful." << endl;
                    return;
                case 3: 
                    cout << "Phone Number (555-555-5555): ";
                    cin.ignore();
                    getline(cin, studentRecords[i].phoneNum);
                    while(studentRecords[i].phoneNum.length()>12){
                        cout << "Incorrect Input." << endl;
                        cout << "Phone Number (555-555-5555): ";
                        getline(cin, studentRecords[i].phoneNum);
                    }
                    cout << endl << "Update has been successful." << endl;
                    return;
                case 4: 
                    cout << "Address: ";
                    cin.ignore();
                    getline(cin, studentRecords[i].address);
                    cout << endl << "Update has been successful." << endl;
                    return;
                case 5:
                    cout << "Advisor: ";
                    cin >> studentRecords[i].advisor;
                    cout << endl << "Update has been successful." << endl;
                    return;  
                }
            }
            else{
                cout << endl << "No match found." << endl;
            }
}

int removeRecords(int counter, student *studentRecords){
    
    int tempId;
    cout << "  * Remove Records *" << endl << endl;
    cout << "Enter the student's ID: ";
    cin >> tempId;

    int i = SIZE;
    char choice;
    bool match = false;
     
     while(i--){
        if(tempId==studentRecords[i].studentId){
            cout << "Match found!" << endl << endl;
            cout << studentRecords[i].firstName  << " " << studentRecords[i].lastName << endl;
            match = true;
            cout << endl << "Are you sure you want to delete this record? (y/n): " << endl;
            cin >> choice;

            while(choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')
            {
                cout << endl << "Incorrect Input." << endl;
                cout << "Are you sure you want to delete this record? (y/n): " << endl;
                cin >> choice;

                if(choice == 'Y' || choice == 'y'){
                    for (int n=i; n<counter; n++)
                    {
                        studentRecords[n].studentId = studentRecords[n+1].studentId;
                        studentRecords[n].firstName = studentRecords[n+1].firstName;
                        studentRecords[n].lastName = studentRecords[n+1].lastName;
                        studentRecords[n].address = studentRecords[n+1].address;
                        studentRecords[n].advisor = studentRecords[n+1].advisor;
                        studentRecords[n].phoneNum = studentRecords[n+1].phoneNum;
                        studentRecords[n].gpa = studentRecords[n+1].gpa;
                        studentRecords[n].birthMonth = studentRecords[n+1].birthMonth;
                        studentRecords[n].birthDay = studentRecords[n+1].birthDay;
                        studentRecords[n].birthYear = studentRecords[n+1].birthYear;
                    }
                    counter = counter -1;
                    cout << endl << "Student Record has been successfully deleted." << endl;
                    break;
                }
                else if (choice == 'N' || choice == 'n')
                {
                    break;
                }
            }
        }    
    }

    if (!match){
        cout << endl << "No match found." << endl;
    }

    return counter;

}

void viewRecords(int counter, student *studentRecords){
        
    cout << "  * View Records *" << endl;

    if(counter==0){
        cout << endl << "No records found." << endl;
    }
    else
    {
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

        for(int i=0; i<counter; i++){
            cout << endl << "Student ID: " << studentRecords[i].studentId << endl;
            cout << "First Name: " << studentRecords[i].firstName << endl;
            cout << "Last Name: " << studentRecords[i].lastName << endl;
            cout << "Birthday: " << studentRecords[i].birthMonth << "/" 
                                 << studentRecords[i].birthDay << "/"
                                 << studentRecords[i].birthYear << endl;
            cout << "Phone Number: " << studentRecords[i].phoneNum << endl;
            cout << "Address: " << studentRecords[i].address << endl;
            cout << "Advisor: " << studentRecords[i].advisor << endl;
            gpaCalc(i, studentRecords);
            cout << fixed << showpoint << setprecision(2) << "GPA: " << studentRecords[i].gpa << endl;
            cout << endl << "Classes: " << endl;
                
                for (int n=0; n<studentRecords[i].numCourses; n++)
                {
                    cout << left << setw(15) << studentRecords[i].course[n].courseName << "     ";
                    cout << left << setw(10) << studentRecords[i].course[n].professor << "      ";
                    cout << left << setw(10) << studentRecords[i].course[n].hours << "      ";
                    cout << left << setw(10) << studentRecords[i].course[n].grade << endl;
 
                }            
                
            cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
        }
    }
}

void display(int counter, student *studentRecords){
    
    int choice=0;

    while (choice!=6) {
        cout << endl << "STUDENT MANAGMENT SYSTEM" << endl;
        cout << "------------------------" << endl << endl;
        cout << "1. Add new records" << endl;
        cout << "2. Modify records" << endl;
        cout << "3. Remove records" << endl;
        cout << "4. view records" << endl;
        cout << "5. Add courses" << endl;
        cout << "6. Exit" << endl;
        cout << endl << "Enter Choice: ";
        cin >> choice;
        
        while (choice > 6 || choice < 0){
            cout << "Invalid Input." << endl;
            cout << "Enter Choice: ";
            cin >> choice;
        }

        cout << endl << "------------------------" << endl << endl;

        if (choice == 1) {
            counter = addRecords(counter, studentRecords);
        }
        else if (choice == 2) {
            modifyRecords(counter, studentRecords);
        }
        else if (choice == 3) {
            counter = removeRecords(counter, studentRecords);
        }
        else if (choice == 4) {
            viewRecords(counter, studentRecords);
        }
        else if (choice == 5){
            addCourses(counter, studentRecords);
        }
        else
        {
            break;
        }
    }
}

void addCourses(int counter, student *studentRecords){
    
    cout << "  * Add Course *" << endl << endl;
    int i = SIZE;
    int n;
    int tempId;
    bool match = false;

    cout << "Enter the student's ID: ";
    cin >> tempId;

    while(i--){
            if(tempId==studentRecords[i].studentId){
                cout << "Match found!" << endl << endl;
                cout << studentRecords[i].firstName  << " " << studentRecords[i].lastName << endl << endl;
                n = studentRecords[i].numCourses;
                match = true;
                break;
            }
        }

    if(match){
        if (n<5){
            cout << "Class Name: ";
            cin >> studentRecords[i].course[n].courseName;
            cout << "Professor: ";
            cin >> studentRecords[i].course[n].professor;
            cout << "Hours: ";
            cin >> studentRecords[i].course[n].hours;
            while (studentRecords[i].course[n].hours < 0 || studentRecords[i].course[n].hours > 4)
            {
                cout << "Incorrect Input." << endl;
                cout << "Hours: ";
                cin >> studentRecords[i].course[n].hours;
            }
            cout << "Grade: "; 
            cin >> studentRecords[i].course[n].grade;
            while (studentRecords[i].course[n].grade!='A' && studentRecords[i].course[n].grade!='B' && studentRecords[i].course[n].grade!='C'
            && studentRecords[i].course[n].grade!='D' && studentRecords[i].course[n].grade!='F' && studentRecords[i].course[n].grade!='I')
            {
                cout << "Incorrect Input." << endl; 
                cout << "Grade: "; 
                cin >> studentRecords[i].course[n].grade;
            }

            studentRecords[i].numCourses++;

            cout << endl << "Course successfully added." << endl << endl;
        }
        else
        {
            cout << endl << "The max number of courses has been reached." << endl << endl;
        }
    }
    else
    {
        cout << endl << "No match found." << endl;
    }

}

void gpaCalc(int i, student *studentRecords){
    
    int totalCredits=0;
    int numCourses = studentRecords[i].numCourses;
    double tempGPA=0;
    double gpa=0;

    for (int n=0; n<numCourses; n++){
        if (studentRecords[i].course[n].grade == 'A')
        {
            tempGPA = 4.0 * studentRecords[i].course[n].hours;
        }
        else if (studentRecords[i].course[n].grade == 'B'){
            tempGPA = 3.0 * studentRecords[i].course[n].hours;
        }
        else if (studentRecords[i].course[n].grade == 'C')
        {
            tempGPA = 2.0 * studentRecords[i].course[n].hours;
        }
        else if (studentRecords[i].course[n].grade == 'D'){
            tempGPA = 1.0 * studentRecords[i].course[n].hours;
        }
        else
        {
            tempGPA = 0 * studentRecords[i].course[n].hours;
        }

        totalCredits+=studentRecords[i].course[n].hours;
        gpa=gpa+tempGPA;
    }
    
    gpa = gpa/totalCredits;
    studentRecords[i].gpa = gpa;

}

int main() {
    
    int counter = 0;

    student studentRecords[SIZE];

    counter = sampleData(counter, studentRecords);
    display(counter, studentRecords);

    cout << "Thank you for using the Student Management System." << endl << endl;

    return 0;
}