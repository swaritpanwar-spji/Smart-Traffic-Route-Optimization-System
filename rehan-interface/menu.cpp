#include <iostream>
using namespace std;

void showMenu()
{
    cout << "\n========================================\n";
    cout << "   SMART TRAFFIC ROUTE OPTIMIZATION\n";
    cout << "========================================\n";

    cout << "1. View Road Network\n";
    cout << "2. View Traffic\n";
    cout << "3. Update Traffic\n";
    cout << "4. Find Best Route\n";
    cout << "5. Exit\n";

    cout << "Enter choice: ";
}

int main()
{
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nRoad Network module will be connected here.\n";
        }
        else if (choice == 2)
        {
            cout << "\nTraffic module will be connected here.\n";
        }
        else if (choice == 3)
        {
            cout << "\nTraffic update module will be connected here.\n";
        }
        else if (choice == 4)
        {
            cout << "\nRoute calculation module will be connected here.\n";
        }
        else if (choice == 5)
        {
            cout << "\nThank you for using Smart Traffic System!\n";
        }
        else
        {
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
