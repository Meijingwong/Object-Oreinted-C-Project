#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "C:\\Users\\amaizing\\Desktop\\textbook\\3.THIRD SEMESTER\\OBJECT ORIENTED PROGRAMMING\\Medicine\\receipts.txt";
    ifstream inFile(filename.c_str()); // Correct way to pass filename as const char*

    if (!inFile.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return 1;
    }

    cout << "---------------------------" << endl;
    cout << "         RECEIPT           " << endl;
    cout << "---------------------------" << endl;
   // cout << "Contents of " << filename << ":" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}

