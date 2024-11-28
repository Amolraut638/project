#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Event 
{
    int id;
    string name;
    string date;
    string venue;
    string organizer;

public:
    // Constructor to initialize member variables
    Event() : id(0), name(""), date(""), venue(""), organizer("") {}

    // Input function
    void input() 
    {
        cout << "Enter Event ID: ";
        cin >> id;
        cin.ignore(); // to clear the input buffer
        cout << "Enter Event Name: ";
        getline(cin, name);
        cout << "Enter Event Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter Venue: ";
        getline(cin, venue);
        cout << "Enter Organizer Name: ";
        getline(cin, organizer);
    }

    // Display function
    void display() const 
    {
       cout<<"Event ID: "<<id<<endl;
       cout<<"Event Name: "<<name<<endl;
       cout<<"Event Date: "<<date<<endl;
       cout<<"Venue: "<<venue<<endl;
       cout<<"Organizer: "<<organizer<<endl;
    }

    // Getters
    int getId() const 
    { 
        return id; 
    }

    string getName() const 
    { 
        return name; 
    }

    string getDate() const 
    { 
        return date; 
    }

};

class Participant 
{
    int id;
    string name;
    string contact;
    int eventId; // ID of the event the participant is registered for

public:
    // Constructor
    Participant() : id(0), name(""), contact(""), eventId(0) {}

    // Input function
    void input() {
        cout << "Enter Participant ID: ";
        cin >> id;
        cin.ignore(); // to clear the input buffer
        cout << "Enter Participant Name: ";
        getline(cin, name);
        cout << "Enter Contact Info: ";
        getline(cin, contact);
        cout << "Enter Event ID to Register: ";
        cin >> eventId;
    }

    // Display function
    void display() const 
    {
        cout<<"Participant ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Contact: "<<contact<<endl;
        cout<<"Event ID: "<<eventId<<endl;
    }

    // Getters
    int getId() const 
    { 
        return id; 
    }

    int getEventId() const 
    { 
        return eventId; 
    }
};

class Venue 
{
    int id;
    string name;
    string location;
    int capacity;

public:
    // Constructor
    Venue() : id(0), name(""), location(""), capacity(0) {}

    // Input function
    void input() 
    {
        cout<<"Enter Venue ID: ";
        cin>>id;
        cin.ignore(); // to clear the input buffer
        cout<<"Enter Venue Name: ";
        getline(cin, name);
        cout<<"Enter Location: ";
        getline(cin, location);
        cout<<"Enter Capacity: ";
        cin>>capacity;
    }

    // Display function
    void display() const 
    {
        cout<<"Venue ID: "<<id<<endl;
        cout<<"Venue Name: "<<name<<endl;
        cout<<"Location: "<<location<<endl;
        cout<<"Capacity: "<<capacity<<endl;
    }

    // Getters
    int getId() const 
    { 
        return id; 
    }
};

class Schedule 
{
    int eventId;
    string date;
    string timeSlot;
    int venueId;

public:
    // Constructor
    Schedule() : eventId(0), date(""), timeSlot(""), venueId(0) {}

    // Input function
    void input() 
    {
        cout<<"Enter Event ID: ";
        cin>>eventId;
        cin.ignore(); // to clear the input buffer
        cout<<"Enter Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout<<"Enter Time Slot (e.g., 10:00 AM - 12:00 PM): ";
        getline(cin, timeSlot);
        cout<<"Enter Venue ID: ";
        cin>>venueId;
    }

    // Display function
    void display() const 
    {
       
       cout<<"Event ID: "<<eventId<<endl;
       cout<<"Date: "<<date<<endl;
       cout<<"Time Slot: "<<timeSlot<<endl; 
       cout<<"Venue ID: "<<venueId<<endl;
    }

    // Getters
    int getEventId() const 
    { 
        return eventId; 
    }

    int getVenueId() const 
    { 
        return venueId; 
    }
};

int main() 
{
    //Vectors to store the objects
    vector<Event> events;
    vector<Participant> participants;
    vector<Venue> venues;
    vector<Schedule> schedules;

    int choice;
    while(1)
    {
       cout << "\nEvent Management System\n";
       cout << "1. Add Event\n";
       cout << "2. Add Participant\n";
       cout << "3. Add Venue\n";
       cout << "4. Add Schedule\n";
       cout << "5. View Events\n";
       cout << "6. View Participants\n";
       cout << "7. Exit\n"<<endl;
       cout << "Enter your choice: ";
       cin >> choice;

        switch (choice) 
        {
            case 1: {
                Event e;
                e.input();
                events.push_back(e);
                break;
            }

            case 2: {
                Participant p;
                p.input();
                participants.push_back(p);
                break;
            }

            case 3: {
                Venue v;
                v.input();
                venues.push_back(v);
                break;
            }

            case 4: {
                Schedule s;
                s.input();
                schedules.push_back(s);
                break;
            }

            case 5: {
                cout << "\nList of Events:\n";
                for (const auto& e : events) {
                    e.display();
                }
                break;
            }

            case 6: {
                cout << "\nList of Participants:\n";
                for (const auto& p : participants) {
                    p.display();
                }
                break;
            }

            case 7: {
                cout << "Exiting...\n";
                break;
            }

            default:
                cout <<"Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
