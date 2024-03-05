#include <bits/stdc++.h>

using namespace std;

    struct Student {
    int id;
    string name;
    string username;
    string pass;
    string number;
    //int roll;
    string address;
    string fat_name;
    string mot_name;
    };

    map <int, Student> student_map;//globally declared so that anyone can access
    map <int, int> att_map;//global map to track attendance
    map <int, int> grade_map;//global map to track grade
    map <string, string>assin_map;//global map to track assignment(only last date and code no of assignment)
    map <string, string> notice_map;//map for storing announcmet(date of announcment and notice itself)

int invalid(){
    cout << "\nInvalid choice, please try again.";
    getchar();
    cin.clear(); //Clear the input buffer to restore cin to a usable state
    cin.ignore(INT_MAX, '\n'); //Ignore the wrong input
}

int delay()//done
{
    for(int i = 0; i<3; i ++)
    {
        cout<<"\n Saving Records ...";
        for(int i = 0; i<10000; i ++)
        {
            for(int i = 0; i<10000; i ++)
            { }
        }
    }

    cout<<"\n Exiting Now ...";
    for(int i = 0; i<3; i ++){
       for(int ii = 0; ii<10000; ii ++) {
         for(int iii = 0; iii<10000; iii ++)
         {}
        }
    }

    return 0;
}
//eikhan theke admin ar student er sob function add korte hbe
int new_student(){

    int i, st_n;

    string name, username, pass, fat, mot, address;

    cout << "Total students to add: ";
    cin >> st_n;
    cout<<endl;

    cout << "\t\tAdding information of students\n";

    for(i=1;i<=st_n;i++){
        //int id = i;
        int id;
        string name, username, pass, number, address, fat_name, mot_name;

        cout << "Id no: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> pass;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter cell number: ";
        cin >> number;
        cout << "Enter Father's name: ";
        cin >> fat_name;
        cout << "Enter Mother's name: ";
        cin >> mot_name;
        cout << endl;

        student_map[id] = Student{id, name, username, pass, number, address, fat_name, mot_name};
        att_map[id] = 0; // Initialize attendance for each student to 0
        grade_map[id] = 0; // Initialize Grade for each student to 0
        cout << endl;

    }

    cout<<"Press any key to return.."<<endl;
    getchar();getchar();
    return 0;

}

int checkall(){

    cout << "\t\t----------- List of all registed ID with User Name -----------\n";
    int i;
    for (auto const& i : student_map) {

            Student student = student_map[i.first];

            cout << "User id: "<<student.id<<endl;
            cout << "User name: "<<student.username<<endl;
            cout << endl;

    }

    cout<<"Press any key to return.."<<endl;
    getchar();getchar();

    return 0;

}

int check_by_id(){

    int student_id;
    cout <<"Enter id to search: ";
    cin >> student_id;

    cout <<endl<<endl;

// Check if the map contains the given ID
    if (student_map.count(student_id) == 0) {
    cout << "ID " << student_id << " not found. Please try again.\n" << endl;
    cout << "\nPress any key to return.." << endl;
    getchar();
    getchar();
    return 0;
  }

    if (student_map.count(student_id) > 0) {
        Student student = student_map[student_id];
        cout << "\t\t--------------information of id no "<< student_id << "--------------"<<endl<<endl;

        cout << "User name: "<<student.username<<endl;
        cout << "Password: "<<student.pass<<endl;
        cout << "Roll: "<<student.id<<endl;
        cout << "Address: "<<student.address<<endl;
        cout << "Cell number: "<<student.number<<endl;
        cout << "Father's name: "<<student.fat_name<<endl;
        cout << "Mother's name: "<<student.mot_name<<endl;
        cout << endl;

    }

    else {
        cout << "No student found with ID " << student_id << endl;
    }

    cout<<"Press any key to return.."<<endl;
    getchar();getchar();
    return 0;

}

int cheeck_all_att(){

    //to show list of students with there attendane
    for(auto const& i : att_map)
        cout << "ID: "<<i.first<<" Attendance: "<<i.second<<endl;

    cout<<"Press any key to continue.."<<endl;
    getchar();getchar();

    return 0;

}
//to find attendance by id
int check_att_by_id(){

    int i;
    cout<<"Enter your id: ";
    cin >> i;

    auto it = att_map.find(i);//finding the place in att_map
    int att = it->second;//to store value of att_map
        cout << "ID: "<<i<<" Attendance: "<<att<<endl;

    cout<<"Press any key to return.."<<endl;
    getchar();getchar();
    return 0;

}
//notice board
int sh_ann(){
    int i;
    cout<<"\n\t\t------ showing all announcement ------\n";
    for(auto const& i : notice_map)
        cout << "Date of Announcement: "<<i.first<<endl<<"Announcement: "<<i.second<<endl;

    cout<<"\nPress any key to continue.."<<endl;
    getchar();getchar();

    return 0;

}
//creat announcment
int cr_ann(){

    int st_n, i;

    cout << "Total announcement you want to make: ";
    cin >> st_n;
    cout << endl;

    string date, note;

//creating a new announcement
    for (i = 1; i <= st_n; i++) {

        cout<<"Date of announcement: ";
        cin >> date;
        cin.ignore(); // Ignore the newline character in the input buffer
        cout << "Announcement: ";
        getline(cin, note); // Read the entire sentence
        notice_map[date] = note;
    }

//showing all announcement
    cout<<"\t\t------ showing all announcement ------\n";
    for(auto const& i : notice_map)
        cout << "Date of announcement: "<<i.first<<endl<<"Announcement: "<<i.second<<endl;

    cout<<"\nPress any key to continue.."<<endl;
    getchar();getchar();

    return 0;

}
//showing assignment
int sh_assi(){

    int i;

    // Check if the map is empty
    if (assin_map.empty()) {
    cout << "\t\t-----------No assignments found-----------\n";
    cout << "\nPress any key to continue.." << endl;
    getchar();getchar();

    return 0;
  }

    //showing all assignment
    cout << "\t\t-----------showing all assignments and due date-----------\n";
    for(auto const& i : assin_map)
        cout << "Last Date of assignment no "<<i.first<<" is "<<i.second<<endl;

    cout<<"\nPress any key to continue.."<<endl;
    getchar();getchar();

    return 0;

}
//create assignment
int cr_assi(){

    int i, st_n;

    cout << "Total Student: ";
    cin >> st_n;
    cout << endl;

    string code, due;

//creating a new assginment and due date
    for (i = 1; i <= st_n; i++) {

        cout<<"Last Date of Submission: ";
        cin >> due;
        cin.ignore(); // Ignore the newline character in the input buffer
        cout << "Assignment code: ";
        cin>>code;
        assin_map[code] = due;
    }

    sh_assi();

}
//add mark for assignment by admin
int mark_assi(){

    int i, mark;
    cout<<"Enter ID to add mark: ";
    cin>>i;
    cout<<"Enter total mark to add: ";
    cin >> mark;

    grade_map[i] += mark;

    cout<<"\nMarked succefully!"<<endl;
    getchar();getchar();

    return 0;
}
//to check grade by admin
int check_grade_by_id(){

    int i;

    cout<<"Enter Roll to see mark: ";
    cin >>i;

    // Check if the map is empty
    if (grade_map.empty()) {
    cout << "Sorry. No grades found.\n" << endl;
    cout << "\nPress any key to return.." << endl;
    getchar();getchar();

    return 0;
    }

    int att = grade_map[i];//to store value of att_map
        cout << "ID: "<<i<<" Grade: "<<att<<endl;

    cout<<"\nPress any key to return.."<<endl;
    getchar();getchar();

    return 0;

}
//to check all grade by admin
int check_all_grade(){

    if (grade_map.empty()) {
    cout << "No grades found.\n" << endl;
    cout << "\nPress any key to return.." << endl;
    getchar();getchar();

    return 0;
  }

    cout << "\t\t-----------Grade List-----------\n";
    for (auto const& entry : grade_map) {
    int id = entry.first;
    int grade = entry.second;
    cout << "ID: " << id << " Total Grade: " << grade << endl;
  }

  cout << "\nPress any key to return.." << endl;
  getchar();
  getchar();

  return 0;
}
//delete account by id for student
int del_id(){
    int id;

    cout<< "id to delete: ";
    cin >> id;

    auto it = student_map.erase(id);

    cout<<"Delete successfull!\n";
    cout<<"\nPress any key to return..";
    getchar();getchar();

    return 0;

}
//delete all student by admin
int del_all(){

    student_map.clear();

    cout<<"Database delete successfull!\n";
    cout<<"\nPress any key to return..";
    getchar();getchar();

    return 0;
}
//show information of student by admin
int sh_pro(int enteredId){

// Check if the map contains the given ID
    if (student_map.count(enteredId) == 0) {
    cout << "ID " << enteredId << " not found. Please try again.\n" << endl;
    cout << "\nPress any key to return.." << endl;
    getchar();
    getchar();
    return 0;
  }

    if (student_map.count(enteredId) > 0) {
        Student student = student_map[enteredId];
        cout << "\t\t--------------  Your information --------------"<<endl<<endl;

        cout << "User name: "<<student.username<<endl;
        cout << "Address: "<<student.address<<endl;
        cout << "Cell number: "<<student.number<<endl;
        cout << "Father's name: "<<student.fat_name<<endl;
        cout << "Mother's name: "<<student.mot_name<<endl;
        cout << endl;

    }

    else {
        cout << "No student found with ID " << enteredId << endl;
    }

    cout<<"Press any key to return.."<<endl;
    getchar();getchar();
    return 0;

}
//check attendance by students
int mark_my_att(int enteredId){

    auto it = att_map.find(enteredId);

    if (it != att_map.end())
        ++it->second;

    cout << "You have attended " << it->second << " days\n";

    cout<<"Press any key to return..\n";
    getchar();getchar();

    return 0;

}
//mark present at class by students
int count_my_att(int enteredId){

    int att;

    auto it = att_map.find(enteredId);
    if (it != att_map.end()) {
        att = it->second;
        cout << "You have attended " << att << " days.\n\n";
    }
    else {
        cout << "Student not found.\n";
        return 0;
    }

    cout<<"\nPress any key to return.."<<endl;
    getchar();getchar();
    return 0;

}
//check grade by STUDENT 
int check_my_grade(int enteredId){

    int itt = grade_map[enteredId];//to store value of att_map
        cout << "You have got "<<itt<<" marks in total"<<endl;

    cout<<"\nPress any key to return.."<<endl;
    getchar();getchar();

    return 0;

}





int adminView()
    {
    int goBack = 0;
    while(1)
    {
    system("cls");
    cout<<"Organizing sector:";
    cout<<"\n 1 Register a Student";
    cout<<"\n 2 Check List of Student registered by userame";
    cout<<"\n 3 See information of any student by ID";
    cout<<"\n 4 Get List of student with their attendance count";
    cout<<"\n 5 Check presense count of any student by ID No";
    cout<<"\n 6 Delete student by ID";
    cout<<"\n 7 Delete All students name registered";

    cout<<"\nNotice Board";
    cout<<"\n 8 Create an announcment";
    cout<<"\n 9 Show all announcments";

    cout<<"\nAssignment and Grading sector:";
    cout<<"\n 10 Add a new Assignment";
    cout<<"\n 11 Show all Assignment";
    cout<<"\n 12 Evaluate Assignment";
    cout<<"\n 13 Check Grade of any student by ID";
    cout<<"\n 14 Check all students Grade";
    cout<<"\n 0. Go Back <- \n";
    int choice;

    cout<<"\n Enter you choice: ";
    cin>>choice;

     switch(choice)
     {
           case 1: new_student();break;
           case 2: checkall(); break;
           case 3: check_by_id(); break;
           case 4: cheeck_all_att(); break;
           case 5: check_att_by_id(); break;
           case 6: del_id(); break;
           case 7: del_all(); break;

           case 8: cr_ann(); break;
           case 9: sh_ann(); break;
           
           case 10: cr_assi(); break;
           case 11: sh_assi(); break;
           case 12: mark_assi(); break;
           case 13: check_grade_by_id(); break;
           case 14: check_all_grade(); break;
           case 0: goBack = 1; break;
           default: invalid(); break;
     }

    if(goBack == 1)
        break; //break the loop
    }

    return 0;
    }
//login for admin
int adminlogin(){

    system("cls");
    adminView();
    getchar();
    delay();

    // cout<<"\n --------- Admin Login --------";

    // string admin_username;
    // string admin_password;

    // cout<<"\n Enter username : ";
    // cin>>admin_username;
    // cout<<"\n Enter password : ";
    // cin>>admin_password;

    // if(admin_username=="admin" && admin_password=="admin")
    // {
    //     adminView();
    //     getchar();
    //     delay();
    // }
    // else
    // {
    //     cout<<"\n Wrong username or password. Please try again..";
    //     cout<<"\n Press any key for main menu ";
    //     getchar();getchar();
    // }

    return 0;





}

int studentView(int enteredId)
{
    int goBack = 0;
    while(1)
    {
        system("cls");

        cout<<"\n 1 Show my profile";
        cout<<"\n 2 Mark Attendance for Today";
        cout<<"\n 3 Count my Attendance";
        cout<<"\n 4 See assignments and due dates";
        cout<<"\n 5 See my total grade";
        cout<<"\n 6 See Notice Board";
        cout<<"\n 0. Go Back <- \n";
        int choice;

        cout<<"\n Enter you choice: ";
        cin>>choice;

    switch(choice)
    {
           case 1: sh_pro(enteredId); break;
           case 2: mark_my_att(enteredId); break;
           case 3: count_my_att(enteredId); break;
           case 4: sh_assi(); break;
           case 5: check_my_grade(enteredId); break;
           case 6: sh_ann(); break;
           case 0: goBack = 1; break;
           default: invalid(); break;
     }

    if(goBack == 1)
        break; //break the loop
    }

    return 0;
}
 //login for student
 //student credential ei function er upore thakte hbe
int studentlogin() {
    system("cls");
    cout << "\n\t\t------- Student Login --------\n";

    int enteredId;
    string enteredUsername, enteredPassword;

    cout << "Enter your ID: ";
    cin >> enteredId;
    cout << "Enter your username: ";
    cin >> enteredUsername;
    cout << "Enter your password: ";
    cin >> enteredPassword;

    auto it = student_map.find(enteredId);

    if (it != student_map.end()) {
        const Student& student = it->second;
        if (student.username == enteredUsername && student.pass == enteredPassword) {
            cout << "Login successful!" << endl;
            studentView(enteredId);
            getchar();
            delay();
        }
        else {
            cout << "\n Wrong username or password. Please try again..";
            cout << "\n Press any key for the main menu ";
            getchar();
            getchar();
        }
    }

    else {
        cout << "\n ID not found. Please check your ID and Try Again.";
        cout << "\n Press any key for the main menu ";
        getchar();
        getchar();
    }

    return 0;
}

int parent(){

    label0:
    int goBack = 0;
    while(1)
    {
        system("cls");

        cout<<"\n 1 Show Attendance of your child";
        cout<<"\n 2 Show grade of your child";
        cout<<"\n 3 See Notice board";
        cout<<"\n 0. Go Back <- \n";
        int choice;

        cout<<"\n Enter you choice: ";
        cin>>choice;

    switch(choice)
    {
              case 1: check_att_by_id(); break;
              case 2: check_grade_by_id(); break;
              case 3: sh_ann(); break;
              case 0: goBack = 1; break;
              default: invalid(); break;
     }

    if(goBack == 1)
        break; //break the loop
    }
}

int main(){
//reload function eikhane hbe
        while(1)
    {
        system("cls");
        cout<<"\n Attendance Management System \n";
        cout<<"-------------------------------------\n\n";

        cout<<"1. Student Login\n";
        cout<<"2. Admin Login\n";
        cout<<"3. Partent Portal\n";

        cout<<"0. Exit\n";
        int choice;

        cout<<"\n Enter you choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1: studentlogin(); break;
        case 2: adminlogin(); break;
        case 3: parent(); break;
        case 0:
                while(1)
                {
                system("cls");
                cout<<"\n Are you sure, you want to exit? y | n \n";
                char ex;
                cin>>ex;
                if(ex == 'y' || ex == 'Y')//reload function ekhane hbe
                   exit(0);
                else if(ex == 'n' || ex == 'N')
                 {
                     break;
                 }
                 else
                 {
                    invalid();
                 }

               }
                break;

        default: invalid();break;
        }
    }
}
