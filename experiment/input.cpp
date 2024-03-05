#include<bits/stdc++.h>
#include<map>
#include<fstream>

using namespace std; 

struct Student 
{
    int id;
    string name;
    string username;
    string pass;
    string number;
    string address;
    string fat_name;
    string mot_name;

};

map<int, Student> student_map;


int new_student(){

    int i, st_n;

    string name, username, pass, fat, mot, address;

    cout << "Total students to add: ";
    cin >> st_n;
    cout<<endl;

    cout << "\t\tAdding information of students\n";

    for(i=1;i<=st_n;i++){
        
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

        student_map[id] = Student{id,name,username,pass,address,number,fat_name,mot_name};

        ofstream out("input.txt", ios::app);
        
        out << student_map[id].id << " " << student_map[id].name << " " << student_map[id].username << " "
            << student_map[id].pass << " " << student_map[id].number << " " << student_map[id].address << " "
            << student_map[id].fat_name << " " << student_map[id].mot_name << endl;

        out.close();
        cout << "Data saved successfully." << endl;
        
    }

    cout<<"Press any key to return.."<<endl;
    getchar();getchar();
    return 0;

}

int check_by_id() {
    int student_id;
    cout << "Enter ID to search: ";
    cin >> student_id;
    cout << endl << endl;

    ifstream in("input.txt"); // Open the file "input.txt" for reading

    if (in.is_open()) { // Check if the file is successfully opened
        string line;
        bool found = false;

        // Read the file line by line
        while (getline(in, line)) {
            // Create a stringstream to parse the line
            stringstream ss(line);

            // Read the ID from the line
            int id;
            ss >> id;

            if (id == student_id) { // If the ID matches the one we're searching for
                // Extract and print the student's information
                Student student;
                student.id = id;
                ss >> student.name >> student.username >> student.pass >> student.number >> student.address >> student.fat_name >> student.mot_name;

                cout << "\t\t-------------- Information of ID no " << student_id << " --------------" << endl << endl;
                cout << "Name: " << student.name << endl;
                cout << "User name: " << student.username << endl;
                cout << "Password: " << student.pass << endl;
                cout << "ID: " << student.id << endl;
                cout << "Address: " << student.address << endl;
                cout << "Cell number: " << student.number << endl;
                cout << "Father's name: " << student.fat_name << endl;
                cout << "Mother's name: " << student.mot_name << endl;
                cout << endl;

                found = true;
                break; // Exit the loop when the student is found
            }
        }

        if (!found) { // If the student is not found in the file
            cout << "Student with ID " << student_id << " not found." << endl;
        }

        in.close(); // Close the file
    } else {
        cout << "Failed" << endl;
    }

    cout << "Press any key to return.." << endl;
    getchar();
    getchar();
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
    // cout<<"\n 2 Check List of Students registered by userame";
    cout<<"\n 3 See information of any student by ID";
    // cout<<"\n 6 Delete student by ID";
    // cout<<"\n 0. Go Back <- \n";
    int choice;

    cout<<"\n Enter you choice: ";
    cin>>choice;

     switch(choice)
     {
           case 1: new_student();break;
        //    case 2: checkall(); break;
           case 3: check_by_id(); break;
        //    case 4: cheeck_all_att(); break;
        //    case 5: check_att_by_id(); break;
     }

    if(goBack == 1)
        break; //break the loop
    }

    return 0;
}

int main(){

        while(1)
    {
        system("cls");
        cout<<"\n Attendance Management System \n";
        cout<<"-------------------------------------\n\n";
        cout<<"0. Exit"<<endl;
        cout<<"1. Admin View\n";


        //this portion is provided for driver menu 
        //underdeveloped : 1. Add Student 

        int choice;

        cout<<"\n Enter you choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1: adminView(); break;
        // case 2: adminlogin(); break;
        // case 3: parent(); break;
        case 0:
                break;

        }
    }
}