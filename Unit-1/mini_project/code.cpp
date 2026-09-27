#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class for Smart Devices
class SmartDevice {
protected:
    string deviceID;
    string location;
    string status;
    string lastUpdated;
    bool power;

public:
    // Constructor
    SmartDevice(string id, string loc, string stat, string time)
    {
        deviceID = id;
        location = loc;
        status = stat;
        lastUpdated = time;
        power = false;
    }

    // Switch device ON
    void switchOn()
    {
        power = true;
        cout << deviceID << " is switched ON.\n";
    }

    // Switch device OFF
    void switchOff()
    {
        power = false;
        cout << deviceID << " is switched OFF.\n";
    }

    // Change device status
    void changeStatus(string newStatus)
    {
        status = newStatus;
        cout << "Status changed successfully.\n";
    }

    // Display device information
    void display()
    {
        cout << "\nDevice ID     : " << deviceID;
        cout << "\nLocation      : " << location;
        cout << "\nStatus        : " << status;
        cout << "\nPower         : " << (power ? "ON" : "OFF");
        cout << "\nLast Updated  : " << lastUpdated << endl;
    }

    // Getter for device ID
    string getDeviceID()
    {
        return deviceID;
    }
};


// Smart Home Manager class
class SmartHomeManager {
private:
    vector<SmartDevice> devices;

public:

    // Add a device
    void addDevice(SmartDevice device)
    {
        devices.push_back(device);
    }

    // Display all devices
    void displayDashboard()
    {
        cout << "\n====================================";
        cout << "\n       SMART HOME DASHBOARD";
        cout << "\n====================================";

        if (devices.empty())
        {
            cout << "\nNo devices available.\n";
            return;
        }

        for (int i = 0; i < devices.size(); i++)
        {
            cout << "\n\nDevice " << i + 1;
            devices[i].display();
        }
    }

    // Find device using ID
    int findDevice(string id)
    {
        for (int i = 0; i < devices.size(); i++)
        {
            if (devices[i].getDeviceID() == id)
                return i;
        }

        return -1;
    }

    // Switch device ON
    void turnOn(string id)
    {
        int index = findDevice(id);

        if (index != -1)
            devices[index].switchOn();
        else
            cout << "Device not found.\n";
    }

    // Switch device OFF
    void turnOff(string id)
    {
        int index = findDevice(id);

        if (index != -1)
            devices[index].switchOff();
        else
            cout << "Device not found.\n";
    }

    // Change status
    void updateStatus(string id, string newStatus)
    {
        int index = findDevice(id);

        if (index != -1)
            devices[index].changeStatus(newStatus);
        else
            cout << "Device not found.\n";
    }
};


// Main function
int main()
{
    SmartHomeManager home;

    // Creating smart devices
    SmartDevice light1(
        "L001",
        "Living Room",
        "Brightness 80%",
        "10:30 AM"
    );

    SmartDevice thermostat1(
        "T001",
        "Bedroom",
        "Temperature 24C",
        "10:35 AM"
    );

    SmartDevice camera1(
        "C001",
        "Main Door",
        "Monitoring",
        "10:40 AM"
    );

    SmartDevice lock1(
        "D001",
        "Main Door",
        "Locked",
        "10:45 AM"
    );

    // Adding devices
    home.addDevice(light1);
    home.addDevice(thermostat1);
    home.addDevice(camera1);
    home.addDevice(lock1);

    int choice;
    string id;
    string newStatus;

    do
    {
        cout << "\n\n========== SMART HOME MANAGER ==========";
        cout << "\n1. Display Home Dashboard";
        cout << "\n2. Switch Device ON";
        cout << "\n3. Switch Device OFF";
        cout << "\n4. Change Device Status";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                home.displayDashboard();
                break;

            case 2:
                cout << "Enter Device ID: ";
                cin >> id;
                home.turnOn(id);
                break;

            case 3:
                cout << "Enter Device ID: ";
                cin >> id;
                home.turnOff(id);
                break;

            case 4:
                cout << "Enter Device ID: ";
                cin >> id;

                cout << "Enter new status: ";
                cin.ignore();
                getline(cin, newStatus);

                home.updateStatus(id, newStatus);
                break;

            case 5:
                cout << "\nExiting Smart Home Manager...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 5);

    return 0;
}
