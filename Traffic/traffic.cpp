#include <iostream>
#include <string>
using namespace std;

struct RoadTraffic
{
    string source;
    string destination;
    int trafficLevel;
};

void displayTraffic(RoadTraffic roads[], int n)
{
    cout << "\n===== TRAFFIC INFORMATION =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << roads[i].source << " -> "
             << roads[i].destination << " : ";

        if (roads[i].trafficLevel == 1)
            cout << "Low";
        else if (roads[i].trafficLevel == 2)
            cout << "Medium";
        else
            cout << "High";

        cout << "\n";
    }
}

void updateTraffic(RoadTraffic roads[], int n)
{
    string source, destination;
    int level;

    cout << "\nEnter source: ";
    cin >> source;

    cout << "Enter destination: ";
    cin >> destination;

    cout << "Enter traffic level:\n";
    cout << "1. Low\n";
    cout << "2. Medium\n";
    cout << "3. High\n";
    cout << "Enter choice: ";
    cin >> level;

    for (int i = 0; i < n; i++)
    {
        if (roads[i].source == source &&
            roads[i].destination == destination)
        {
            roads[i].trafficLevel = level;
            cout << "\nTraffic updated successfully!\n";
            return;
        }
    }

    cout << "\nRoad not found.\n";
}

int main()
{
    RoadTraffic roads[5] =
    {
        {"A", "B", 1},
        {"A", "D", 2},
        {"B", "C", 3},
        {"D", "C", 1},
        {"B", "D", 2}
    };

    int choice;

    do
    {
        cout << "\n===== TRAFFIC MODULE =====\n";
        cout << "1. View Traffic\n";
        cout << "2. Update Traffic\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            displayTraffic(roads, 5);
        else if (choice == 2)
            updateTraffic(roads, 5);
        else if (choice == 3)
            cout << "Exiting Traffic Module...\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 3);

    return 0;
}
