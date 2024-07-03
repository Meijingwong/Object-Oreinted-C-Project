#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

double stringToDouble(const string& str) {
    stringstream ss(str);
    double result;
    ss >> result;
    return result;
}

void readReceiptAndCalculateTotal(const string& filename) {
    ifstream inFile(filename.c_str()); // Use filename.c_str() to convert std::string to const char*

    if (!inFile.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    string line;
    double totalFees = 0.0;

   
    while (getline(inFile, line)) {
        if (line.find("Price") != string::npos) {
            // Find the position of ": RM"
            size_t pos = line.find(": RM");
            if (pos != string::npos) {
                // Extract the substring starting from pos + 4 to skip ": RM"
                string priceStr = line.substr(pos + 4);
                double price = stringToDouble(priceStr);
                totalFees += price;
            }
        }
    }
    inFile.close();

    // Display receipt contents
    inFile.open(filename.c_str()); // Reopen using filename.c_str()

    if (!inFile.is_open()) {
        cerr << "Unable to reopen file " << filename << endl;
        return;
    }

    cout << "---------------------------------------------" << endl;
    cout << "                    RECEIPT                  " << endl;
    cout << "---------------------------------------------" << endl;

    while (getline(inFile, line)) {
        cout << line << endl;
    }
    
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Total Fees that you need to pay in the counter: RM " << fixed << setprecision(2) << totalFees << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;

    inFile.close();
}

int main() {
    string filename = "receipts.txt";  // Use relative path for simplicity
    readReceiptAndCalculateTotal(filename);

    // Pause to keep the console window open
    cout << "Press Enter to continue...";
    cin.ignore();  // Wait for the user to press Enter
    return 0;
}

