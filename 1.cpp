#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void line(int times, char c){
    for(int i = 0; i < times; i++)
        cout << c;
    cout << endl;
}

struct doctor {
    string name;
    string address;
    string contact;
    int age;
    string sex;
    string doctorID;
};

struct patient {
    string name;
    string address;
    string contact;
    int age;
    string sex;
    string blood_group;
    string had_diseases;
    string patientID;
    string date;
    doctor doctorofPatient;
    double billcost;
};

patient patients[50];
doctor doctors[10];
int patientcounter = 0;
int doctorcounter = 0;

void doctorinfo(doctor &doc);
void addDoctor();
void addpatient();
void Patientinfo(patient &p);
int getpatientByID(const string &Id);
void printpatientinfo();
void printpatientbill();
void printalldoctors();
void editpatientbill();
void editpatientdoctor();
doctor getdoctorByID(const string &ID, int count, doctor docs[]);


void doctorinfo(doctor &doc)
{
    cout << "please input the doctor name : ";
    getline(cin, doc.name);
    cout << "please input the doctor address : ";
    getline(cin, doc.address);
    cout << "please input the doctor contact number : ";
    getline(cin, doc.contact);
    cout << "please input the doctor age : ";
    cin >> doc.age;
    cin.ignore();
    cout << "please input the doctor sex : ";
    getline(cin, doc.sex);
    cout << "please input the doctor ID : ";
    getline(cin, doc.doctorID);
}

void addDoctor() {
    if (doctorcounter >= 10) { cout << "Doctor list full.\n"; return; }
    doctorinfo(doctors[doctorcounter]);
    doctorcounter++;
}

void Patientinfo(patient &p) {
    cout << "please input patient name: ";
    getline(cin, p.name);
    cout << "please input patient address: ";
    getline(cin, p.address);
    cout << "please input contact number: ";
    getline(cin, p.contact);
    cout << "please input age: ";
    cin >> p.age;
    cin.ignore();
    cout << "please input sex: ";
    getline(cin, p.sex);
    cout << "please input blood group: ";
    getline(cin, p.blood_group);
    cout << "please input earlier symptoms: ";
    getline(cin, p.had_diseases);
    cout << "please input patient ID: ";
    getline(cin, p.patientID);
    cout << "please input date: ";
    getline(cin, p.date);
    p.billcost = 0.0;
}

void addpatient() {
    if (patientcounter >= 50) { cout << "Patient list full.\n"; return; }
    Patientinfo(patients[patientcounter]);
    patientcounter++;
}

int getpatientByID(const string &Id) {
    for (int i = 0; i < patientcounter; ++i) if (patients[i].patientID == Id) return i;
    return 0;
}

doctor getdoctorByID(const string &ID, int count, doctor docs[]) {
    for (int i = 0; i < count; ++i) if (docs[i].doctorID == ID) return docs[i];
    return doctor();
}

void printpatientinfo() {
    string id;
    cout << "please input the id of the patient : ";
    cin >> id;
    cin.ignore();
    int idx = getpatientByID(id);
    line(70, '=');
    cout << "Name : " << patients[idx].name << endl;
    cout << "Address : " << patients[idx].address << endl;
    cout << "Contact number : " << patients[idx].contact << endl;
    cout << "Age : " << patients[idx].age << endl;
    cout << "Sex : " << patients[idx].sex << endl;
    cout << "Blood group : " << patients[idx].blood_group << endl;
    cout << "Diseases : " << patients[idx].had_diseases << endl;
    cout << "Patient ID : " << patients[idx].patientID << endl;
    cout << "Date : " << patients[idx].date << endl;
    line(70, '=');
}

void printpatientbill() {
    string id;
    cout << "please input the id of the patient : ";
    cin >> id;
    cin.ignore();
    int idx = getpatientByID(id);
    line(70, '=');
    cout << "Name : " << patients[idx].name << endl;
    cout << "Doctor : " << patients[idx].doctorofPatient.name << endl;
    cout << "Bill : " << patients[idx].billcost << endl;
    line(70, '=');
}

void printalldoctors() {
    if (doctorcounter == 0) { cout << "There is no data to show\n"; return; }
    line(60, '=');
    for (int i = 0; i < doctorcounter; i++) {
        cout << "Doctor name : " << doctors[i].name << endl;
        cout << "Doctor address : " << doctors[i].address << endl;
        cout << "Doctor age : " << doctors[i].age << endl;
        cout << "Doctor contact : " << doctors[i].contact << endl;
        cout << "Doctor sex : " << doctors[i].sex << endl;
        cout << "Doctor ID : " << doctors[i].doctorID << endl;
        line(30, '-');
    }
}

void editpatientbill() {
    string id;
    cout << "please input patient ID to edit bill: ";
    cin >> id;
    cin.ignore();
    int idx = getpatientByID(id);
    cout << "enter new bill amount: ";
    cin >> patients[idx].billcost;
    cin.ignore();
}

void editpatientdoctor() {
    string pid, did;
    cout << "patient ID: ";
    cin >> pid;
    cin.ignore();
    cout << "doctor ID: ";
    getline(cin, did);
    int pidx = getpatientByID(pid);
    for (int i = 0; i < doctorcounter; ++i) {
        if (doctors[i].doctorID == did) { patients[pidx].doctorofPatient = doctors[i]; return; }
    }
    cout << "Doctor not found." << endl;
}

int main() {
    patientcounter = 0;
    doctorcounter = 0;
    int choice = 0;
    while (choice != 8) {
        cout << "1- add a new doctor\n";
        cout << "2- add a new patient\n";
        cout << "3- edit the patient bill\n";
        cout << "4- edit the patient doctor\n";
        cout << "5- print patient info\n";
        cout << "6- print patient bill\n";
        cout << "7- print doctors record\n";
        cout << "8- exit program\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) addDoctor();
        else if (choice == 2) addpatient();
        else if (choice == 3) editpatientbill();
        else if (choice == 4) editpatientdoctor();
        else if (choice == 5) printpatientinfo();
        else if (choice == 6) printpatientbill();
        else if (choice == 7) printalldoctors();
        else if (choice == 8) 
        break;
    }
    _getche();
    return 0;
}

// ----------------- Additional utilities -----------------

void saveToFile(const string &filename) {
    ofstream out(filename);
    if (!out) { cout << "Failed to open file for writing\n"; return; }
    out << patientcounter << "\n" << doctorcounter << "\n";
    for (int i = 0; i < patientcounter; ++i) {
        auto &p = patients[i];
        out << p.name << "\n" << p.address << "\n" << p.contact << "\n" << p.age << "\n" << p.sex << "\n";
        out << p.blood_group << "\n" << p.had_diseases << "\n" << p.patientID << "\n" << p.date << "\n" << p.billcost << "\n";
        out << p.doctorofPatient.doctorID << "\n"; // store link to doctor by ID
    }
    for (int i = 0; i < doctorcounter; ++i) {
        auto &d = doctors[i];
        out << d.name << "\n" << d.address << "\n" << d.contact << "\n" << d.age << "\n" << d.sex << "\n" << d.doctorID << "\n";
    }
    out.close();
    cout << "Saved to " << filename << "\n";
}

void loadFromFile(const string &filename) {
    ifstream in(filename);
    if (!in) { cout << "Failed to open file for reading\n"; return; }
    int pc, dc;
    if (!(in >> pc)) { cout << "Invalid file\n"; return; }
    in >> dc;
    string tmp;
    getline(in, tmp); // consume endline
    patientcounter = 0; doctorcounter = 0;
    for (int i = 0; i < pc; ++i) {
        patient p;
        getline(in, p.name);
        getline(in, p.address);
        getline(in, p.contact);
        in >> p.age; in.ignore();
        getline(in, p.sex);
        getline(in, p.blood_group);
        getline(in, p.had_diseases);
        getline(in, p.patientID);
        getline(in, p.date);
        in >> p.billcost; in.ignore();
        string docid; getline(in, docid);
        // attach empty doctor with ID; will resolve after reading doctors
        p.doctorofPatient.doctorID = docid;
        patients[patientcounter++] = p;
    }
    for (int i = 0; i < dc; ++i) {
        doctor d;
        getline(in, d.name);
        getline(in, d.address);
        getline(in, d.contact);
        in >> d.age; in.ignore();
        getline(in, d.sex);
        getline(in, d.doctorID);
        doctors[doctorcounter++] = d;
    }
    // resolve doctor links for patients
    for (int i = 0; i < patientcounter; ++i) {
        string id = patients[i].doctorofPatient.doctorID;
        for (int j = 0; j < doctorcounter; ++j) if (doctors[j].doctorID == id) { patients[i].doctorofPatient = doctors[j]; break; }
    }
    in.close();
    cout << "Loaded from " << filename << "\n";
}

int searchPatientByName(const string &name) {
    for (int i = 0; i < patientcounter; ++i) {
        string lowerA = patients[i].name;
        string lowerB = name;
        transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        if (lowerA.find(lowerB) != string::npos) return i;
    }
    return -1;
}

bool deletePatientByID(const string &Id) {
    int idx = -1;
    for (int i = 0; i < patientcounter; ++i) if (patients[i].patientID == Id) { idx = i; break; }
    if (idx == -1) return false;
    for (int i = idx; i + 1 < patientcounter; ++i) patients[i] = patients[i+1];
    --patientcounter;
    return true;
}

void addSampleData() {
    // add two doctors
    doctors[0].name = "Dr. Ahmed"; doctors[0].address = "Cairo"; doctors[0].contact = "0100000000"; doctors[0].age = 45; doctors[0].sex = "M"; doctors[0].doctorID = "D001";
    doctors[1].name = "Dr. Mona"; doctors[1].address = "Giza"; doctors[1].contact = "0101111111"; doctors[1].age = 39; doctors[1].sex = "F"; doctors[1].doctorID = "D002";
    doctorcounter = 2;
    // add three patients
    patients[0].name = "Ali Hassan"; patients[0].address = "Cairo"; patients[0].contact = "0122222222"; patients[0].age = 30; patients[0].sex = "M"; patients[0].blood_group = "A+"; patients[0].had_diseases = "None"; patients[0].patientID = "P001"; patients[0].date = "2025-12-22"; patients[0].doctorofPatient = doctors[0]; patients[0].billcost = 150.0;
    patients[1].name = "Sara Ali"; patients[1].address = "Alex"; patients[1].contact = "0123333333"; patients[1].age = 25; patients[1].sex = "F"; patients[1].blood_group = "B+"; patients[1].had_diseases = "Asthma"; patients[1].patientID = "P002"; patients[1].date = "2025-12-20"; patients[1].doctorofPatient = doctors[1]; patients[1].billcost = 200.0;
    patients[2].name = "Mohamed Omar"; patients[2].address = "Tanta"; patients[2].contact = "0124444444"; patients[2].age = 50; patients[2].sex = "M"; patients[2].blood_group = "O+"; patients[2].had_diseases = "Diabetes"; patients[2].patientID = "P003"; patients[2].date = "2025-11-10"; patients[2].doctorofPatient = doctors[0]; patients[2].billcost = 500.0;
    patientcounter = 3;
    cout << "Sample data added (" << patientcounter << " patients, " << doctorcounter << " doctors).\n";
}

void showStats() {
    int male = 0, female = 0;
    double totalBill = 0.0;
    for (int i = 0; i < patientcounter; ++i) {
        if (!patients[i].sex.empty() && (patients[i].sex[0] == 'M' || patients[i].sex[0] == 'm')) ++male;
        else ++female;
        totalBill += patients[i].billcost;
    }
    cout << "Patients: " << patientcounter << "  Doctors: " << doctorcounter << "\n";
    cout << "Male: " << male << "  Female: " << female << "\n";
    cout << "Total billed: " << totalBill << "  Average bill: ";
    if (patientcounter) cout << (totalBill / patientcounter) << '\n'; else cout << "0\n";
}
