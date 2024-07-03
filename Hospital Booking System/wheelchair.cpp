#include<iostream>
#include <iomanip>
#include<cstring>
#include <fstream>
using namespace std;

class Wheelchair
{
	protected:
		int days_rented;
		double price;
	public:
		// Default constructor
		Wheelchair() 
		{
	        days_rented = 0;
	        price = 0.00;
	    }
	    	
	    void set_days_rented (int d)
	    {
	    	days_rented = d;
		}
		
		void display()
		{
			cout<<"Price per day : RM "<<fixed<<setprecision(2)<<price<<endl;
		}
		
		double get_price()
		{
			return price;
		}
		
		int get_days_rented()
		{
			return days_rented;
		}
		
		double calcTotal()
		{
			return price * days_rented;
		}	
		
		int calcDuration()
		{
			return days_rented;
		}
};

class ManualWheelchair : public Wheelchair {
	public:
		//idk if this counts as constructor overloading
		ManualWheelchair()
		{
			days_rented = 0;
	        price = 15.00;
		}
};

class ElectricWheelchair : public Wheelchair {
	public:
		ElectricWheelchair()
		{
			days_rented = 0;
			price = 30.00;
		}
};

int main()
{
	string name, phone, chair_type;
	int days, age, duration;
	double total = 0.00;
	char choice, cont;
	
	cout << "-----------------------------------------------" << endl;
	cout << "         Four Corners Supply Store             " << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Choices Available:                        " << endl;
	cout << "[1] Rent a Manual Wheelchair (RM 15.00 per day)" << endl;
	cout << "[2] Rent an Electric Wheelchair (RM 30.00 per day)" << endl;
	cout << "-----------------------------------------------" << endl;
	
	cout << "                INFORMATION               " << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Enter your name : ";
	getline(cin,name);
	
	cout << "Enter your age : ";
	cin >> age;
	cin.ignore();
	
	cout << "Enter your phone number : ";
	getline(cin,phone);
	
	cout << "-----------------------------------------------" << endl;
	
	do {
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		
		switch (choice) {
			case '1': {
				ManualWheelchair M;
				M.display();
				cout << "Enter number of days to rent: ";
				cin >> days;
				M.set_days_rented(days);
				total += M.calcTotal();
				duration += M.calcDuration();
				chair_type ="Manual Wheelchair";
				break;
			}
			case '2': {
				ElectricWheelchair E;
				E.display();
				cout << "Enter number of days to rent: ";
				cin >> days;
				E.set_days_rented(days);
				total += E.calcTotal();
				duration += E.calcDuration();
				chair_type ="Electric Wheelchair";
				break;
			}
			default: 
				cout<<"Invalid Choice. Please try again."<<endl;
		}
		
		
		cout << "Do you wish to continue [Y-Yes] [N-No]: ";
		cin >> cont;
		cout << "-----------------------------------------------" << endl;
		
	} while (cont=='Y'||cont=='y');
	
	
	cout << "                  RECEIPT                   " << endl;
	cout << "-----------------------------------------------" << endl;
	    cout<< "Customer Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Days Rented: " << duration << endl;
        cout<< "Price: RM " << fixed << setprecision(2) << total << endl;
        
        
	ofstream receiptFile("receipts.txt", ios::app); // Ensure you include <fstream> for file operations
    if (receiptFile.is_open()) {
        receiptFile << endl;
        receiptFile << "------Rent A Wheelchair ------" << endl;
        receiptFile << "Wheelchair Type   : " << chair_type  << endl;
        receiptFile << "Days Rented       : " << duration << endl;
        receiptFile << "Price             : RM " << fixed << setprecision(2) << total << endl;
        receiptFile.close();
        cout << "Your data has been saved. Please go to the couter to get your receipt." << endl;
    } else {
        cout << "Unable to open receipts.txt for writing." << endl;
    }
    return 0;
}


