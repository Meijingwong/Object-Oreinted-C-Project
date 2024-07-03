#include <iostream>
#include <cstdlib> // For system()
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


int main() {
    int select;

    do {
        cout << "-------------------------------------------" << endl;
        cout << "           HOSPITAL BOOKING SYSTEM         " << endl;
        cout << "-------------------------------------------" << endl;
        cout << "[1] Booking Appointment " << endl;
        cout << "[2] Booking Bed " << endl;
        cout << "[3] Rent a Wheelchair " << endl;
        cout << "[4] Medicine Purchase" << endl;
        cout << "[5] Receipt" << endl;
        cout << "[0] Exit" << endl;
        cout << endl;
        cout << "Please select a service (0-5): ";
        cin >> select;

        if (select == 1) {
            int result = system("start Appointment.exe");
            if (result != 0) {
                cout << "Failed to start Appointment.exe" << endl;
            }
        } else if (select == 2) {
            int result = system("start Bed.exe");
            if (result != 0) {
                cout << "Failed to start Bed.exe" << endl;
            }
        } else if (select == 3) {
            int result = system("start wheelchair.exe");
            if (result != 0) {
                cout << "Failed to start wheelchair.exe" << endl;
            }
        } else if (select == 4) {
            int result = system("start Medicine.exe");
            if (result != 0) {
                cout << "Failed to start Medicine.exe" << endl;
            }
        } else if (select == 5) {
           int result = system("start receipt.exe");
            if (result != 0) {
                cout << "Failed to start receipt.exe" << endl;
            }
        } else if (select != 0) {
            cout << "Invalid selection. Please choose a number from 0 to 5." << endl;
        }

    } while (select != 0);

    return 0;
}

