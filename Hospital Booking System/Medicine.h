#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Forward declaration of Pharmacy class
class Pharmacy;

// Declaration of Medicine class
class Medicine {
private:
    int choice;
    char doct_ID;

public:
    void setMedDetails(Pharmacy& pharmacy, int id, const string& pname, int a, const string& phone, double p, const string& mc);
    void select_medicine(Pharmacy& pharmacy, char doctor[], int numberDoctor);
};

#endif // MEDICINE_H

