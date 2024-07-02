#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Pharmacy {
protected:
    string medname, patientName;
    int medID, age;
    double price;
    string phoneNumber, medcer;

public:
    Pharmacy() { // default constructor
        medname = "";
        patientName = "";
        medID = 0;
        age = 0;
        price = 0.0;
        phoneNumber = "";
        medcer = " ";
    }

    void setMedDetails(int id, const string& pname, int a, const string& phone, double p) { // mutator function
        medID = id;
        patientName = pname;
        age = a;
        phoneNumber = phone;
        price = p;
    }

    string getMedName() { // accessor function
        return medname;
    }

    string getPatientName() {
        return patientName;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    void setMedicalCertificate(const string& mc) {   //passing by reference
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
    
    
};

class Medicine : public Pharmacy {
private:
    int choice;
    char doct_ID;

public:
    void setMedDetails(int id, const string& pname, int a, const string& phone, double p, const string& mc) {    
        medID = id;
        patientName = pname;
        age = a;
        phoneNumber = phone;
        price = p;
        medcer = mc;
    }

    void select_medicine(char doctor[], int numberDoctor) {
        cout << endl;
        cout << "Select your medicine purchase type: ";
        cin >> choice;

        switch (choice) {
            case 1:
                price = 20.00;
                medname = "Pain Relief and Fever";
                break;
            case 2:
                price = 15.50;
                medname = "Cold and Flu";
                break;
            case 3:
                price = 10.00;
                medname = "Vitamins and Supplements";
                break;
            case 4:
                cout << "Doctor who gave you the prescription [A]-Dr. Rona [B]-Dr.Madmud [C]-Dr.Danish: ";
                cin >> doct_ID;
                for (int i = 0; i < numberDoctor; i++) {
                    if (doct_ID == doctor[i]) {
                        price = 30.00;
                        medname = "Others with prescription";
                        break;
                    }
                }
                if (medname.empty()) {
                    cout << "Doctor not found. Please try again." << endl;
                    price = 0.00;
                    medname = "-";
                }
                break;

            default:
                cout << "Invalid choice. Exiting." << endl;
                return;
        }
    }

   
};

// Required user to key in their data
// define a member function outside the class
void Pharmacy::display() {
    cout << "Enter your name: ";
   
    getline(cin, patientName);
    
    if (patientName.size() > 20) {
        patientName = patientName.substr(0, 20); // Truncate to 20 characters
    }
    
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your phone number: ";
    cin >> phoneNumber;
    
     
}

// calculate the total fees for buying the medicines
class Purchase {
private:
    double totalFees;

public:
    Purchase() {
        totalFees = 0.0;
    }

    void calc_fees(Pharmacy* py) {
        totalFees += py->getPrice();
        cout << "Medicine Type  : " << py->getMedName() << endl;
        cout << "Price          : RM" << fixed << setprecision(2) << py->getPrice() << endl;
    }

    void display_fees() {
        cout << "Total Price        : RM" << fixed << setprecision(2) << totalFees << endl;
    }
 
    //set an object as pointer
    void printReceipt(Pharmacy* py) {
        cout << endl;
        cout << "Patient Name       : " << py->getPatientName() << endl;
        cout << "Age                : " << py->getAge() << endl;
        cout << "Phone Number       : " << py->getPhoneNumber() << endl;
        cout << "Medicine Type      : " << py->getMedName() << endl;
        cout << "Medical Certificate: " << py->getNeedMC() << endl;
    }
};

class Sign{
	private:
		int back;
		
	public:
		
		Sign(){
		    back = 1;
		}
		
		~Sign() {
        cout << "Your data has been submitted. Please go to the counter to take your medicine." << endl; // destructor
    }
    
    void gotoHomapage(){
    	cout<<"Do you want to return back to the Homepage. [1]-Yes [2]-No"<<endl;
    	cin>> back;
    	
    	if(back == 1){
    		system("start Homepage.exe");
		} 
	}
};

int main() {
    Pharmacy A;
    Purchase P;
    Medicine* H;
    Sign Q;

    char doctor[] = { 'A', 'B', 'C' }; // array for storing doctor_ID
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
        H = new Medicine; // creating object dynamically
        H->select_medicine(doctor, numberDoctor);
        P.calc_fees(H);
        cout << endl;
        cout << "Do you want to make another purchase? Yes-Y No-N: ";
        cin >> exitOption;
        cout << "---------------------------" << endl;
        delete H; // free out the allocated memory after use
    } while (exitOption == 'Y' || exitOption == 'y');

    cout << "---------------------------" << endl;
    char mc;
    cout << "Do you need a Medical Certificate (MC)? [Y]-Yes [N]-No: ";
    cin >> mc;
    if (mc == 'Y' || mc == 'y') {
        A.setMedicalCertificate("Need");
    }
    else {
        A.setMedicalCertificate("No need");
    }

    cout << "---------------------------" << endl;
    cout << "         RECEIPT           " << endl;
    cout << "---------------------------" << endl;
    P.printReceipt(&A);
    P.display_fees();
    cout << "--------------------------" << endl;
     

    Q.gotoHomapage();
    
    return 0;
}

