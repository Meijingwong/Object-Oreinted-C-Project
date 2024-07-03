#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class BedBooking {
protected:
    int duration, patAge;
    double price_per_day, total, assistant_cost;
    string bedType, patName, phone_number;

public:
    BedBooking() {
        patAge = 0;
        patName = " ";
        duration = 0;
        price_per_day = 0.00;
        total = 0.00;
        bedType = " ";
        assistant_cost = 0.00;
    }

    void bed_Choice() {
        int bed;
        char assistant;
        cout << "\nEnter your name: ";
        getline(cin, patName);

        cout << "Enter your age: ";
        cin >> patAge;
        cin.ignore();

        cout << "Enter your phone number: ";
        getline(cin, phone_number);

        cout << "\n------------------------------------------ " << endl;
        cout << "    FOUR CORNERS' BED BOOKING SERVICE      " << endl;
        cout << "------------------------------------------ " << endl;
        cout << "Select choice of bed: " << endl;
        cout << "\n[1] General Ward       --> RM55/Day" << endl;
        cout << "[2] Semi-Private Room  --> RM105/Day" << endl;
        cout << "[3] Private Room       --> RM220/Day" << endl;
        cout << "------------------------------------------ " << endl;
        cout << "\nEnter your preferred bed type: ";
        cin >> bed;

        switch (bed) {
            case 1:
                bedType = "General Ward";
                price_per_day = 55;
                break;

            case 2:
                bedType = "Semi-Private Room";
                price_per_day = 105;
                break;

            case 3:
                bedType = "Private Room";
                price_per_day = 220;
                cout << "Would you like a Personal Care Assistant ? [Y]-Yes [N]-No --> RM 5/Day: ";
                cin >> assistant;
                if (assistant == 'Y' || assistant == 'y') {
                    assistant_cost = 5.0;
                }
                break;

            default:
                cout << "Invalid choice. Exiting System." << endl;
                return;
        }

        cin.ignore(); // Clear the input buffer

        cout << "Enter duration of stay (days): ";
        cin >> duration;

        // Calculate total cost of stay without additional services
        total = (price_per_day * duration) + (assistant_cost * duration);
    }

    void displayDetails() {
        cout << "\n\nPatient Name       : " << patName << endl;
        cout << "Age                : " << patAge << endl;
        cout << "Phone Number       : " << phone_number << endl;
        cout << "Bed Type           : " << bedType << endl;
        cout << "Duration of Stay   : " << duration << " day(s)" << endl;
        cout << "Personal Care Assistant Cost: RM " << fixed << setprecision(2) << (assistant_cost * duration) << endl;
    }

    // Getter functions for protected members
    int getPatAge() const { 
	      return patAge; 
	}
	
    string getPhoneNumber() const { 
	return phone_number; 
	}
    string getPatName() const { 
	return patName; 
	}
    string getBedType() const { 
	return bedType;
	 }
    int getDuration() const { 
	return duration; 
	}
    double getAssistantCost() const { 
	return assistant_cost;
	 }
    double getTotal() const { 
	return total; 
	}
};

class add_service : public BedBooking {
protected:
    double meal_price, locker_price, news_price, service_total;

public:
    add_service() : BedBooking() {
        meal_price = 0.00;
        locker_price = 0.00;
        news_price = 0.00;
        service_total = 0.00;
    }

    void select_add_services() {
        char meal;
        char locker;
        char newspaper;

        cout << "\nWould you like us to provide meals daily? [Y]-Yes [N]-No --> RM 20/Day: ";
        cin >> meal;
        if (meal == 'Y' || meal == 'y') {
            meal_price = 20.00;
        }

        cout << "Would you like to book a locker? [Y]-Yes [N]-No --> RM 40/Day: ";
        cin >> locker;
        if (locker == 'Y' || locker == 'y') {
            locker_price = 40.00;
        }

        cout << "Would you like daily newspaper services? [Y]-Yes [N]-No --> RM 3/Day: ";
        cin >> newspaper;
        if (newspaper == 'Y' || newspaper == 'y') {
            news_price = 3.00;
        }

        // Calculate additional services total cost
        service_total = (meal_price + locker_price + news_price) * duration;

        // Update total cost including additional services
        total += service_total;
    }

    void displayAdditionalDetails() {
    	displayDetails();
        cout << "Cost of Stay       : RM " << fixed << setprecision(2) << total << endl;
        cout << "------------------------------------------ " << endl;
        cout << "\nYour data has been submitted. Proceed to the counter for authorization. Thank You." << endl;
    }
};

int main() {
    add_service s;
    s.bed_Choice(); // Call the base class method
    s.displayDetails(); // Call the base class method to display basic details
    s.select_add_services();
    s.displayAdditionalDetails();
    
    ofstream receiptFile("receipts.txt", ios::app);
    if (receiptFile.is_open()) {
    	receiptFile << "-------Booking Bed--------" << endl;
        receiptFile << "Bed Type           : " << s.getBedType() << endl;
        receiptFile << "Duration of Stay   : " << s.getDuration() << " day(s)" << endl;
        receiptFile << "Price              : RM " << fixed << setprecision(2) << s.getTotal() << endl;
        receiptFile.close();
    } else {
        cerr << "Unable to open receipts.txt for writing." << endl;
    }

    // Pause to keep the console window open
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();

    return 0;
}

