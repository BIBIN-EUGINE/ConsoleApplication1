// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class book declaration
class booking;

//Person class
class person {
private:
    string name;
    string address;
    int tel;
    string email;
public:
    person(string name = "nil", string address = "nil", int tel = 0, string email = "nil") {
        this->name = name;
        this->address = address;
        this->tel = tel;
        this->email = email;
    }

    virtual void set() {
        cout << "Enter your name" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter your address" << endl;
        getline(cin, address);
        cout << "Enter your telephone" << endl;
        cin >> tel;
        cout << "Enter your email" << endl;
        cin >> email;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Tele: " << tel << endl;
        cout << "Email: " << email << endl;
    }
    ~person() = default;
};

//passenger class
class passenger : public person {
private:
    string passport;
public:
    passenger(string passport = "nil") {
        this->passport = passport;
    };
    void set() {
        person::set();
        cout << "Enter the passport number:" << endl;
        //getline(cin,passport);
        cin >> this->passport;
    }
    string get_passport() {
        return passport;
    }
    void display() {
        person::display();
        cout << "Passport: " << passport << endl;
    }
};

//employee class
class employee : public person {
private:
    string title;
    int flightno;
public:
    void set() {
        person::set();
        cout << "Enter the title" << endl;
        cin >> this->title;
        cout << "enter the flight number" << endl;
        cin >> flightno;
    }
    void display() {
        person::display();
        cout << "title: " << title << endl;
        cout << "Flightno: " << flightno << endl;
    }
    string get_title() {
        return  title;
    }
    int get_flightno() {
        return flightno;
    }
};

//Booking class
class booking {
    int seatnumber = 0;
public:
    booking(int seatnumber = 0) {
        this->seatnumber = seatnumber;
    }
    void set_seatnumber() {
        seatnumber++;
    }
    void display() {
        cout << "Seat Number" << seatnumber << endl;
    }
    passenger p;
    ~booking() = default;
};

//Class Airports
class airport {
private:
    string s_airport_name, d_airport_name;
    float takeoff, landing;
public:
    class cities {
    private:
        string source_city, destination_city;
    public:
        void get_source_city() {
            cout << "Enter the source city" << endl;
            cin >> source_city;
        }
        void get_destination_city() {
            cout << "Enter the destination city" << endl;
            cin >> destination_city;
        }
        void display_city() {
            cout << "Source City: " << source_city << endl;
            cout << "Destination City: " << destination_city << endl;
        }
    };
    cities c;
    void set_source_airport_city() {
        cout << "Enter the source airport name" << endl;
        cin >> s_airport_name;
        c.get_source_city();
    }
    void set_destination_airport_city() {
        cout << "Enter the destination airport name" << endl;
        cin >> d_airport_name;
        c.get_destination_city();
    }
    void display_air_city() {
        cout << "Source Airport: " << s_airport_name << endl;
        cout << "Destination Airport: " << d_airport_name << endl;
        c.display_city();
    }
    void get_delay_time() {
        cout << "Enter the takeoff delay" << endl;
        cin >> takeoff;
        cout << "Enter the Landing delay" << endl;
        cin >> landing;
    }
    float get_takeoff() {
        return takeoff;
    }
    float get_landing() {
        return landing;
    }
};

// Flight class
class flight {
private:
    int FlightNumber;
    string DepartureDate;
    float DepartureTime;
    string ArrivalDate;
    float ArrivalTime;
    float duration;
    float expe_dep_time;
    float expe_arr_time;
    vector<booking> b;
    vector<employee> e;
    employee e1;
    airport air;
public:
    flight(int flightno = 0, string depdate = "nil", float deptime = 0.00,
        string arrivaldate = "nil", float arrivaltime = 0.00,
        float duration = 0.0) {
        this->FlightNumber = flightno;
        this->DepartureDate = depdate;
        this->DepartureTime = deptime;
        this->ArrivalDate = arrivaldate;
        this->ArrivalTime = arrivaltime;
        this->duration = duration;
    }
    void delay();
    void set_flight() {
        cout << "Enter the flight number" << endl;
        cin.ignore();
        cin >> FlightNumber;
        cout << "Enter the departure date DD/MM/YYYY";
        cin.ignore();
        getline(cin, DepartureDate);
        cout << "Enter the departure time" << endl;
        cin >> DepartureTime;
        cout << "Enter the arrival date DD/MM/YYYY" << endl;
        cin.ignore();
        getline(cin, ArrivalDate);
        cout << "Enter the arrival time" << endl;
        cin >> ArrivalTime;
        cout << "Enter the duration" << endl;
        cin >> duration;
        air.set_source_airport_city();
        air.set_destination_airport_city();
        expe_arr_time = ArrivalTime;
        expe_dep_time = DepartureTime;
    }
    int get_flightno();
    void display_flight();
    void add_employee();
    void display_employee();
    void add(booking);
    void cancel(string);
    void CancelAllBookings();
    void display_bookings();
};

void flight::delay() {
    air.get_delay_time();
    float temp;
    temp = (ArrivalTime + air.get_landing()) - (int)((ArrivalTime + air.get_landing()));
    expe_arr_time = (int(ArrivalTime + air.get_landing())) % 24 + temp;
    temp = (DepartureTime + air.get_takeoff()) - (int)(DepartureTime + air.get_takeoff());
    expe_dep_time = (int(DepartureTime + air.get_takeoff())) % 24 + temp;
}

int flight::get_flightno() {
    return FlightNumber;
}

void flight::display_flight() {
    cout << "Flight Number: " << FlightNumber << endl;
    cout << "Departure Date: " << DepartureDate << endl;
    cout << "Departure Time: " << DepartureTime << endl;
    cout << "Expected Departure Time: " << expe_dep_time << endl;
    cout << "Arrival Date: " << ArrivalDate << endl;
    cout << "Arrival Time: " << ArrivalTime << endl;
    cout << "Expected Arrival Time: " << expe_arr_time << endl;
    cout << "Duration: " << duration << endl;
    air.display_air_city();
}

void flight::display_bookings() {
    vector<booking>::iterator it;
    booking temp;
    for (auto i = b.begin(); i != b.end(); i++) {
        temp = *i;
        temp.display();
        temp.p.display();
        cout << "*******" << endl << endl;
    }
}

void flight::cancel(string p) {
    vector<booking>::iterator it;
    booking temp;
    for (auto it = b.begin(); it != b.end(); it++) {
        temp = *it;
        if (temp.p.get_passport() == p) {
            b.erase(it);
        }
    }
    for (auto i = b.begin(); i != b.end(); i++) {
        temp = *i;
        temp.display();
        temp.p.display();
    }
}

void flight::CancelAllBookings() {
    b.clear();
    booking temp;
    for (auto i = b.begin(); i != b.end(); i++) {
        temp = *i;
        temp.display();
        temp.p.display();
    }
}

void flight::add(booking b1) {
    booking temp;
    int count = 0;
    for (auto i = b.begin(); i != b.end(); i++) {
        temp = *i;
        if (temp.p.get_passport() == b1.p.get_passport())
            count = 1;
    }
    if (count == 0)
        b.push_back(b1);
    else
        cout << "You cannot book more than one ticket for the same flight" << endl;
}

void flight::add_employee() {
    e1.set();
    employee temp;
    int count = 0;
    if (e1.get_title() == "Manager") {
        for (auto i = e.begin(); i != e.end(); i++) {
            temp = *i;
            if (temp.get_title() == "Manager") {
                count = 1;
            }
        }
    }
    if (count == 0 && (e1.get_flightno() == FlightNumber)) {
        e.push_back(e1);
    }
    else {
        cout << "Cannot assign more than one manager to a flight/ Wrong flight no " << endl;
    }
}

void flight::display_employee() {
    employee temp;
    for (auto i = e.begin(); i != e.end(); i++) {
        temp = *i;
        temp.display();
        cout << "*******" << endl << endl;
    }
}

class airline {
public:
    flight f[5];
};

int main() {
    int k = 1, n, n_emp, flight_no, no_of_flights = 0;
    int temp = 0;
    string passport, airline_id = "air23", agent_id = "ag21", id;
    airline a;
    booking b;
    while (k) {
        n_emp = 0;
        temp = 0;
        cout << "Airline employee ID/ Agent ID" << endl;
        cin >> id;
        if (id == airline_id) {
            cout << "1. Flight information Add/View" << endl;
            cout << "2. Employee Add/view" << endl;
            cout << "3. Passenger information" << endl;
            cout << "4. exit" << endl;
            cin >> n;
            switch (n) {
            case 1:cout << "Press 1 for viewing current list of flight" << endl;
                cout << "press 2 for adding new flights" << endl;
                cout << "press 3 for airline delay" << endl;
                cin >> n_emp;
                if (n_emp == 2) {
                    cout << "Enter no of flights" << endl;
                    cin >> no_of_flights;
                    for (int i = 1; i <= no_of_flights; i++) {
                        cout << "Enter the details of flight: " << i << endl;
                        a.f[i].set_flight();
                    }
                }
                else if (n_emp == 1) {
                    for (int i = 1; i <= no_of_flights; i++) {
                        cout << "The details of flight: " << i << endl;
                        a.f[i].display_flight();
                        cout << "*********" << endl << endl;
                    }
                }
                else if (n_emp == 3) {
                    cout << "Enter the flight number " << endl;
                    cin >> flight_no;
                    for (int i = 1; i <= no_of_flights; i++) {
                        if (a.f[i].get_flightno() == flight_no) {
                            a.f[i].delay();
                            temp = 1;
                        }
                    }
                    if (temp == 0)
                        cout << "invalid" << endl;
                }
                else
                    cout << "Invalid" << endl;

                break;
            case 2:cout << "Press 1 for viewing current list of employees" << endl;
                cout << "press 2 for adding new employees";
                cin >> n_emp;
                if (n_emp == 1) {
                    cout << "Enter the flight number " << endl;
                    cin >> flight_no;
                    for (int i = 1; i <= no_of_flights; i++) {
                        if (a.f[i].get_flightno() == flight_no) {
                            a.f[i].display_employee();
                            cout << "********" << endl << endl;
                            temp = 1;
                        }
                    }
                    if (temp == 0)
                        cout << "invalid" << endl;
                }
                else if (n_emp == 2) {
                    cout << "Enter the flight number to which you need to assign" << endl;
                    cin >> flight_no;
                    for (int i = 1; i <= no_of_flights; i++) {
                        if (a.f[i].get_flightno() == flight_no) {
                            a.f[i].add_employee();
                            cout << "********" << endl << endl;
                            temp = 1;
                        }
                    }
                    if (temp == 0)
                        cout << "invalid" << endl;
                }
                else
                    cout << "Invalid" << endl;
                break;
            case 3:cout << "Enter the flight number" << endl;
                cin >> flight_no;
                for (int i = 1; i <= no_of_flights; i++) {
                    if (a.f[i].get_flightno() == flight_no) {
                        a.f[i].display_bookings();
                        cout << "********" << endl << endl;
                        temp = 1;
                    }
                }
                if (temp == 0)
                    cout << "invalid" << endl;
                break;
            case 4:break;
            default:break;
            }
        }
        else if (id == agent_id) {
            cout << "1. Book a flight" << endl;
            cout << "2. Cancel Booking" << endl;
            cout << "3. CancelALLbooking" << endl;
            cout << "4. exit" << endl;
            cin >> n;
            switch (n) {
            case 1:cout << "Enter the flight number" << endl;
                cin >> flight_no;
                b.set_seatnumber();
                b.p.set();
                for (int i = 1; i <= no_of_flights; i++) {
                    if (a.f[i].get_flightno() == flight_no) {
                        a.f[i].add(b);
                        cout << "********" << endl << endl;
                        temp = 1;
                    }
                }
                if (temp == 0)
                    cout << "invalid" << endl;
                break;
            case 2:cout << "Enter the passport number" << endl;
                cin >> passport;
                cout << "Enter the flight number" << endl;
                cin >> flight_no;
                for (int i = 1; i <= no_of_flights; i++) {
                    if (a.f[i].get_flightno() == flight_no) {
                        a.f[i].cancel(passport);
                        cout << "********" << endl << endl;
                        temp = 1;
                    }
                }
                if (temp == 0)
                    cout << "invalid" << endl;
                break;
            case 3:cout << "Enter the flight number" << endl;
                cin >> flight_no;
                for (int i = 1; i <= no_of_flights; i++) {
                    if (a.f[i].get_flightno() == flight_no) {
                        a.f[i].CancelAllBookings();
                        cout << "********" << endl << endl;
                        temp = 1;
                    }
                }
                if (temp == 0)
                    cout << "invalid" << endl;
                break;
            case 4:break;
            default:break;
            }
        }
        else
            cout << "Wrong id, please enter again" << endl;
    }
    return  0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
