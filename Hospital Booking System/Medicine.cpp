#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Pharmacy {
private:
    string medname, patientName;
    int medID, age;
    double price;
    string phoneNumber, medcer;

public:
    Pharmacy() {
        medname = "";
        patientName = "";
        medID = 0;
        age = 0;
        price = 0.0;
        phoneNumber = "";
        medcer = "";
    }

    void setMedDetails(int id, const string& pname, int a, const string& phone, double p) {
        medID = id;
        patientName = pname;
        age = a;
        phoneNumber = phone;
        price = p;
    }

    string getMedName() {
        return medname;
    }

    string getPatientName() {
        return patientName;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    void setMedicalCertificate(const string& mc) {
        medcer = mc;
    }

    int getId() {
        return medID;
    }

    int getAge() {
        return age;
    }

    double getPrice() {
        return price;
    }

    string getNeedMC() {
        return medcer;
    }

    void display();
    ~Pharmacy() {
        cout << "Your data has been submitted. Please go to the counter to take your medicine." << endl;
    }

    friend class Medicine;
};

class Medicine {
private:
    int choice;
    char doct_ID;

public:
    Medicine() {
        choice = 0;
        doct_ID;
    }

    void setMedDetails(Pharmacy& pharmacy, int id, const string& pname, int a, const string& phone, double p, const string& mc) {
        pharmacy.medID = id;
        pharmacy.patientName = pname;
        pharmacy.age = a;
        pharmacy.phoneNumber = phone;
        pharmacy.price = p;
        pharmacy.medcer = mc;
    }

    void select_medicine(Pharmacy& pharmacy, char doctor[], int numberDoctor) {
        cout << "Select your medicine purchase type: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pharmacy.price = 20.00;
                pharmacy.medname = "Pain Relief and Fever";
                break;
            case 2:
                pharmacy.price = 15.50;
                pharmacy.medname = "Cold and Flu";
                break;
            case 3:
                pharmacy.price = 10.00;
                pharmacy.medname = "Vitamins and Supplements";
                break;
            case 4:
                cout << "Doctor who gave you the prescription [A]-Dr. Rona [B]-Dr.Madmud [C]-Dr.Danish: ";
                cin >> doct_ID;
                for (int i = 0; i < 3; i++) {
                    if (doct_ID == doctor[i]) {
                        pharmacy.price = 30.00;
                        pharmacy.medname = "Others with prescription";
                        break;
                    }
                }
                if (pharmacy.medname.empty()) {
                    cout << "Doctor not found. Please try again." << endl;
                    pharmacy.price = 0.00;
                    pharmacy.medname = "-";
                }
                break;
            default:
                cout << "Invalid choice. Exiting." << endl;
                return;
        }
        pharmacy.price++; // adding the price while choosing two or more medicine types
    }
};

void Pharmacy::display() {
    cout << "Enter your name: ";
    getline(cin, patientName);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your phone number: ";
    cin >> phoneNumber;
}

class Purchase {
private:
    double totalFees;

public:
    Purchase() {
        totalFees = 0.0;
    }

    void calc_fees(Pharmacy *py) {
        totalFees += py->getPrice();
        cout << "Medicine Type  : " << py->getMedName() << endl;
        cout << "Price          : RM" << fixed << setprecision(2) << py->getPrice() << endl;
    }

    void printReceipt(Pharmacy *py) {
        
            cout << "Patient Name       : " << py->getPatientName() << endl;
            cout << "Age                : " << py->getAge() << endl;
            cout << "Phone Number       : " << py->getPhoneNumber() << endl;
            cout << "Medicine Type      : " << py->getMedName() << endl;
            cout << "Medical Certificate: " << py->getNeedMC() << endl;
            cout << "Total Price        : RM" << fixed << setprecision(2) << totalFees << endl;
            cout << "--------------------------" << endl;
            
    }
    
    double getTotalFees() const {
        return totalFees;
    }
};

int main() {
    Pharmacy A;
    Purchase P;
    Medicine* H;  // Declare pointer to Medicine
    
    char doctor[] = {'A', 'B', 'C'};
    int numberDoctor = sizeof(doctor) / sizeof(doctor[0]);
    char exitOption;

    cout << "--------PHARMACY-----------" << endl;
    cout << "[1] Pain Relief and Fever " << endl;
    cout << "[2] Cold and Flu " << endl;
    cout << "[3] Vitamins and Supplements " << endl;
    cout << "[4] Others with doctor prescription" << endl;
    cout << "---------------------------" << endl;
    cout << "        INFORMATION        " << endl;
    cout << "---------------------------" << endl;

    A.display();
    cout << "---------------------------" << endl;

    do {
        H = new Medicine; // creating Medicine object dynamically
        H->select_medicine(A, doctor, numberDoctor); // Call method on dynamically allocated object
        P.calc_fees(&A);
        cout << endl;
        cout << "Do you want to make another purchase? Yes-Y No-N: ";
        cin >> exitOption;
        cout << "---------------------------" << endl;
        delete H; // Free allocated memory
    } while (exitOption == 'Y' || exitOption == 'y');

    cout << "---------------------------" << endl;
    char mc;
    cout << "Do you need a Medical Certificate (MC)? [Y]-Yes [N]-No: ";
    cin >> mc;
    if (mc == 'Y' || mc == 'y') {
        A.setMedicalCertificate("Need");
    } else {
        A.setMedicalCertificate("No need");
    }

    cout << endl;
    P.printReceipt(&A);
    
    ofstream receiptFile("receipts.txt", ios::app);
    if (receiptFile.is_open()) {
    	receiptFile << endl;
        receiptFile << "-------Medicine Purchase--------" << endl;
        receiptFile << "Medicine Type      : " << A.getMedName() << endl;
        receiptFile << "Medical Certificate: " << A.getNeedMC() << endl;
        receiptFile << "Price              : RM" << fixed << setprecision(2) << P.getTotalFees() << endl;
        receiptFile.close();
        
    } else {
        cout << "Unable to open 'receipts.txt' for writing." << endl;
    }
    
    
    return 0;
}

