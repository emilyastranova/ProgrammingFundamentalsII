#include<iostream>
#include<string>

using namespace std;

class personType
{
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name
public:

    void print() const{cout << firstName << " " << lastName << endl;}
       //Function to output the first name and last name
       //in the form firstName lastName.
  
    void setName(string first, string last){firstName = first; lastName = last;}
       //Function to set firstName and lastName according 
       //to the parameters.
       //Postcondition: firstName = first; lastName = last

    string getName(){return firstName + " " + lastName;}
       //Function to set firstName and lastName according 
       //to the parameters.
       //Postcondition: firstName = first; lastName = last

    string getFirstName() const{return firstName;}
       //Function to return the first name.
       //Postcondition: The value of the firstName is returned.
    
    void setFirstName(string firstName){this->firstName = firstName;}

    string getLastName() const{return lastName;}
       //Function to return the last name.
       //Postcondition: The value of the lastName is returned.
    
    void setLastName(string lastName){this->lastName = lastName;}

    personType(string first = "", string last = ""){firstName = first; lastName = last;}
       //constructor
       //Sets firstName and lastName according to the parameters.
       //The default values of the parameters are empty strings.
       //Postcondition: firstName = first; lastName = last  

};

class doctorType : public personType
{
    string specialty = "Unspecifed"; // Kept private because no need to access directly without getter and setter
    public:
        doctorType(){} // Default constructor
        doctorType(string firstName, string lastName, string specialty) // Constructor that sets specialty
        {
            setFirstName(firstName);
            setLastName(lastName);
            this->specialty = specialty;
        } 
        
        string getSpecialty(){return specialty;}
        void print()
        {
            cout << "Doctor: " << getName() << endl;
            cout << "Specialty: " << specialty << endl;
        }
};

class billType
{
    int patientID; 
    double pharmacyCharges; 
    double medicineCharges; 
    double doctorsFee; 
    double roomCharges;
    double totalHospitalCharges;

    public:
        billType(){} // Default constructor
        billType(double patientID, double pharmacyCharges, double medicineCharges, double doctorsFee, double roomCharges, double totalHospitalCharges)
        {
            this->patientID = patientID,  this->pharmacyCharges = pharmacyCharges, this->medicineCharges = medicineCharges,  
            this->doctorsFee = doctorsFee,  this->roomCharges = roomCharges, this->totalHospitalCharges = totalHospitalCharges;
        } // Constuctor that sets all values

        int getPatientID() {return this->patientID;}
        void setPatientID(int patientID) {this->patientID = patientID;}

        double getPharmacyCharges() {return this->pharmacyCharges;}
        void setPharmacyCharges(double pharmacyCharges) {this->pharmacyCharges = pharmacyCharges;}

        double getMedicineCharges() {return this->medicineCharges;}
        void setMedicineCharges(double medicineCharges) {this->medicineCharges = medicineCharges;}

        double getDoctorsFee() {return this->doctorsFee;}
        void setDoctorsFee(double doctorsFee) {this->doctorsFee = doctorsFee;}

        double getRoomCharges() {return this->roomCharges;}
        void setRoomCharges(double roomCharges) {this->roomCharges = roomCharges;}

        double getTotalHospitalCharges() {return this->totalHospitalCharges;}
        void setTotalHospitalCharges(double totalHospitalCharges) {this->totalHospitalCharges = totalHospitalCharges;}

        void calculateTotalCharges(){totalHospitalCharges = pharmacyCharges + medicineCharges+ doctorsFee + roomCharges;}

        void print()
        {
            cout << "Pharmacy Charges: $" << pharmacyCharges << endl;
            cout << "Medicine Charges: $" << medicineCharges << endl;
            cout << "Doctors Fee: $" << doctorsFee << endl;
            cout << "Room Charges: $" << roomCharges << endl;
            cout << "Total Charges: $" << totalHospitalCharges << endl;
        }

};

class patientType : public personType
{
    int patientID; 
    int age; 
    string dateOfBirth; 
    string physicianName; 
    string admissionDate; 
    string dischargeDate;

    public:
        patientType(){} // Default constructor
        patientType(string firstName, string lastName, int patientID, int age, string dateOfBirth, string physicianName, string admissionDate, string dischargeDate)
        {
            this->patientID = patientID; this->age = age; // Set all local variables inside of patientType, kept private
            this->dateOfBirth = dateOfBirth; this->physicianName = physicianName; 
            this->admissionDate = admissionDate; this->dischargeDate = dischargeDate;
            setFirstName(firstName);
            setLastName(lastName);
        }
        int getPatientID() {return this->patientID;}
        void setPatientID(int patientID) {this->patientID = patientID;}

        int getAge() {return this->age;}
        void setAge(int age) {this->age = age;}

        string getDateOfBirth() {return this->dateOfBirth;}
        void setDateOfBirth(string dateOfBirth) {this->dateOfBirth = dateOfBirth;}

        string getPhysicianName() {return this->physicianName;}
        void setPhysicianName(string physicianName) {this->physicianName = physicianName;}

        string getAdmissionDate() {return this->admissionDate;}
        void setAdmissionDate(string admissionDate) {this->admissionDate = admissionDate;}

        string getDischargeDate() {return this->dischargeDate;}
        void setDischargeDate(string dischargeDate) {this->dischargeDate = dischargeDate;}

        void print()
        {
            cout << "Patient: " << getName() << endl;
            cout << "Date Of Birth: " << dateOfBirth << endl;
            cout << "Physician Name: " << physicianName << endl;
            cout << "Admission Date: " << admissionDate << endl;
            cout << "Discharge Date: " << dischargeDate << endl;
        }
};

int main()
{
    doctorType doctorRoss = doctorType("Tyler", "Ross", "Phsyician");
    doctorRoss.setFirstName("Salvador"); // Changes the name that was in the constructor
    doctorRoss.print();
    cout << "--------------------------" << endl << endl;

    string physicianName = doctorRoss.getName();
    patientType patient1 = patientType("Emily", "Higgins", 10, 10, "April 26th, 2000", physicianName, "January 1st, 2020", "Februrary 2nd, 2020");
    patient1.setAge(12); // Modify age just as proof-of-concept
    patient1.print();
    cout << "--------------------------" << endl << endl;

    billType bill1 = billType(12345, 1.25, 1.26, 1.27, 1.28, 1.29);
    bill1.calculateTotalCharges();
    bill1.print();
    
    return 0;
}

