/*
You are required to implement a simplified hospital management system in C++ to manage patients, doctors, 
and their appointments. The system should allow adding new patients and doctors, scheduling appointments, 
and viewing the details of patients doctors, and scheduled appointments.

1. Add Patient -> Name, Age, Gender, ID -> because the name can be indentical

2. Add Doctor ->> Name, Age, Gender, ID -> because the name can be indentical

3. Schedule Appointment -> Patiend ID, Doctor ID, DATE

4. View Patients -> Print all the Patients -> store them

5. View Doctors -->Print all the Doctors -> store them

6. View Appointments ->Print all the Appointments -> store them

0. Exit
*/


#include<bits/stdc++.h>
using namespace std;
int pid,did;
class patient{
public :
    string name;
    int age;
    string gender;
    int ID;
    patient(string n,int a,string g ){
        ID=pid;
        pid++;
        name=n;
        age=a;
        gender=g;
    }
};


class Doctor{
public :
    string name;
    int age;
    string gender;
    int ID;
    Doctor(string n,int a,string g ){
        ID=did;
        did++;
        name=n;
        age=a;
        gender=g;
    }
};


class Appointment{
public :
    int patientid;
    int Doctorid;
    string Date;
     Appointment(int p,int d,string date) {
        patientid=p;
        Doctorid=d;
        Date=date;
    }

};
vector<patient>allpatients;
vector<Doctor>allDoctors;
vector<Appointment>allAppointment;

bool ispatientPresent(int id){
    for(int i=0;i<allpatients.size();i++){
        if(id==allpatients[i].ID) return true;
    }
    return false;
}

bool isDoctorPresent(int id){
    for(int i=0;i<allDoctors.size();i++){
        if(id==allDoctors[i].ID) return true;
    }
    return false;
}

void addpatient(){
    string n,g;
    int a;
    cout<<"Give the patient Name : ";
    cin>>n;
    cout<<"\nGive the patient age : "; cin>>a;
    cout<<"\nGive the patient gender : "; cin>>g;
    patient temp(n,a,g);
    allpatients.push_back(temp);
}
void addDoctor(){
    string n,g;
    int a;
    cout<<"Give the Doctor Name : ";
    cin>>n;
    cout<<"\nGive the Doctor age : "; cin>>a;
    cout<<"\nGive the Doctor gender : "; cin>>g;
    Doctor temp(n,a,g);
    allDoctors.push_back(temp);
}
void ScheduleAppointment(){
    int patientid;
    int Doctorid;
    string Date;
    cout << "\nGive the patient ID: ";
    cin >> patientid;
    cout << "Give the Doctor ID: ";
    cin >> Doctorid;
    cout << "Enter the appointment date (e.g., 2025-01-15): ";
    cin >> Date;
    if(ispatientPresent(patientid)==false || isDoctorPresent(Doctorid)==false ){
        cout<<"Invalid patient ID or Doctor ID"<<endl;
        cout<<"Appointment Schedule unsuccessfull"<<endl;
        return;
    } 
    Appointment temp(patientid,Doctorid ,Date);
    allAppointment.push_back(temp);
}
void viewPatients(){
    for(int i=0;i<allpatients.size();i++){
        cout<<"patient Name : "<< allpatients[i].name<<endl;
    }
    cout<<"\n\n";
}
void viewDoctors(){
    for(int i=0;i<allDoctors.size();i++){
        cout<<"Doctor Name : "<< allDoctors[i].name<<endl;
    }
    cout<<"\n\n";
}
void viewAppointments(){
    for(int i=0;i<allAppointment.size();i++){
        cout<<"patient ID : "<< allAppointment[i].patientid<<"  has appointment with Doctor ID : "<< allAppointment[i].Doctorid<<"   Date : "<< allAppointment[i].Date<<endl;
    }
    cout<<"\n\n";
}

int main(){
    pid=1;
    did=1;
    int choice;

    do{
        cout<<"1.Add Patient\n2. Add Doctor\n3. Schedule Appointment \n4. View Patients \n5. View Doctors \n6. View Appointments \n0. Exit \n";
        cout<<"Give your choice :";
        cin>>choice;

        switch (choice){
        case 1 :
            addpatient();
            break;
        case 2 :
            addDoctor();
            break;
        case 3 :
            ScheduleAppointment(); 
            break;
        case 4 :
            viewPatients();
            break;
        case 5 :
            viewDoctors();
            break;
        case 6 :
            viewAppointments();
            break;
        default:
            cout<<"Invalid Choice";
            exit;
            break;
        }

    }while(choice!=0);
    
}