#include <iostream>
#include <fstream> // Include fstream for file operations
using namespace std;

int main() {
    int select;
    cout << "-------------------------------------------" << endl;
    cout << "           HOSPITAL BOOKING SYSTEM         " << endl;
    cout << "-------------------------------------------" << endl;
    cout << "[1] Booking Appointment " << endl;
    cout << "[2] Booking Bed " << endl;
    cout << "[3] Rent a Wheelchair " << endl;
    cout << "[4] Medicine Purchase" << endl;
    cout << "[5] Sign Out" << endl;
    cout << "Please select a service: ";
    cin >> select;
    
    if (select == 4) {
        // Opening Medicine.cpp file in write mode
        ofstream my_file("Medicine.cpp");

        if (my_file.is_open()) {
            // File opened successfully
            cout << "Medicine.cpp opened successfully. You can now write to it." << endl;
            
            // Example: Write data to the file
            my_file << "#include <iostream>" << endl;
            my_file << "#include <string>" << endl;
            my_file << "using namespace std;" << endl;
            my_file << endl;
            my_file << "int main() {" << endl;
            my_file << "    cout << \"Hello from Medicine.cpp\" << endl;" << endl;
            my_file << "    return 0;" << endl;
            my_file << "}" << endl;
            
            // Close the file after writing
            my_file.close();
        } else {
            // Unable to open file
            cerr << "Unable to open Medicine.cpp file." << endl;
        }
    }
    
    return 0;
}

