#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Base class
class Appointment {
protected:
    double price, total;

public:
    Appointment() {
        price = 15.00; // Set the price for a general appointment as RM15
        total = 0.00;
    }

    void calcPrice() { //calculate the total price
        total += price;
    }

    double getPrice() { //return price value
        return price;
    }

    double getTotal() { //return total value
        return total;
    }

    void display() { //display each price for different appointment
        cout << "Price : RM" << fixed << setprecision(2) << total << endl;
    }
};

class Vaccine : public Appointment { //derived class for Vaccine
private:
    string vaccName;
    int choice;

public:
    void selectVaccineType() { //user input to select Vaccine Type
        cout << "\nSelect your vaccine :  \n[1] Covid-19 \n[2] Flu \n[3] Malaria\n";
        cin >> choice;

        switch (choice) { //swtich the choice as different choice has different price
        case 1:
            vaccName = "Covid-19";
            price = 20.00;
            break;
        case 2:
            vaccName = "Flu";
            price = 15.00;
            break;
        case 3:
            vaccName = "Malaria";
            price = 10.00;
            break;
        default:
            vaccName = "Please select a valid Vaccine.";
            price = 0.00;
            break;
        }
        calcPrice(); // Call base class method to calculate total
    }

    void display() {
        cout << "Vaccine Selected: " << vaccName << endl;
        Appointment::display(); // Call base class display method
    }
};

class Specialist : public Appointment { //derived class for specialist
private:
    string spec_type;
    int choice;

public:
    void selectSpec() { //user input to select speacialist type
        cout << "\nSelect your specialist : \n[1] Dermatologist \n[2] Cardiologist \n[3] Pediatrician\n";
        cin >> choice;

        switch (choice) {//swtich the choice as different choice has different price
        case 1:
            spec_type = "Dermatologist";
            price = 85.00;
            break;
        case 2:
            spec_type = "Cardiologist";
            price = 95.00;
            break;
        case 3:
            spec_type = "Pediatrician";
            price = 100.00;
            break;
        default:
            spec_type = "Please select a valid specialist.";
            price = 0.00;
            break;
        }
        calcPrice(); // Call base class method to calculate total
    }

    void display() {
        cout << "Specialist selected : " << spec_type << endl;
        Appointment::display(); // Call base class display method
    }
};

int main() {
    string name, phoneNo;
    int age, choice;
    char continueBooking;
    double total_fees = 0.00;
    string Type;

    do {
        cout << "\n------------------------------------------ " << endl;
        cout << "     FOUR CORNERS' APPOINTMENT BOOKING       " << endl;
        cout << "------------------------------------------ " << endl;

        //menu for user to choose appointment
        cout << "\nPlease select your type of appointment" << endl;
        cout << "[1] General " << endl;
        cout << "[2] Vaccine " << endl;
        cout << "[3] Specialist " << endl;
        cout << "Enter your choice : "; //user input
        cin >> choice;

        cin.ignore();

        cout << "Enter your name : ";
        getline(cin, name);
        cout << "Enter your phone number: ";
        getline(cin, phoneNo);
        cout << "Enter your age : ";
        cin >> age;

        // Handle different appointment types
        if (choice == 1) {
            Appointment G; //create obj
            G.calcPrice();//fx call using obj
            G.display();
            Type="General";
            total_fees += G.getTotal(); //calculate obj G's total price
        } else if (choice == 2) {
            Vaccine V;
            V.selectVaccineType();
            V.display();
            Type="Vaccine";
            total_fees += V.getTotal();//calculate obj V's total price
        } else if (choice == 3) {
            Specialist S;
            S.selectSpec();
            S.display();
            Type="Specialist";
            total_fees += S.getTotal();//calculate obj S's total price
        } else {
            cout << "\nInvalid choice, please select a valid booking option!" << endl;
        }

        cout << "\nDo you want to have another booking? [Y/N] : ";
        cin >> continueBooking;

    } while (continueBooking == 'Y' || continueBooking == 'y');

    cout<<endl;
    cout << "--------RECEIPT-------" << endl; //print receipt after the user choose not to continue
    cout << "Name: " << name << endl;
    cout << "Phone Number: " << phoneNo << endl;
    cout << "Age: " << age << endl;
    cout << "Total Price: RM" << fixed << setprecision(2) << total_fees << endl; //display the added up total

     ofstream receiptFile("receipts.txt", ios::app);
    if (receiptFile.is_open()) {
        receiptFile << "Patient Name       : " << name << endl;
        receiptFile << "Age                : " << age << endl;
        receiptFile << "Phone Number       : " << phoneNo << endl;
        receiptFile << "Appointment Type   : " << Type << endl;
        receiptFile << "Price              : RM" << fixed << setprecision(2) << total_fees << endl;
        receiptFile << "--------------------------" << endl;
        receiptFile.close();

    } else {
        cout << "Unable to open receipts.txt for writing." << endl;
    }
    cout << "\nThank you for booking with us, please proceed to the counter for payment." << endl;

    return 0;
}
