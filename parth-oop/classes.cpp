#include <iostream>
#include <string>
using namespace std;

class Road
{
private:
    string source;
    string destination;
    int distance;

public:
    Road(string s, string d, int dis)
    {
        source = s;
        destination = d;
        distance = dis;
    }

    void displayRoad()
    {
        cout << "Road: " << source << " -> "
             << destination << endl;

        cout << "Distance: "
             << distance << " km" << endl;
    }
};

class Traffic
{
private:
    int trafficLevel;

public:
    Traffic(int level)
    {
        trafficLevel = level;
    }

    void displayTraffic()
    {
        cout << "Traffic: ";

        if (trafficLevel == 1)
            cout << "Low";
        else if (trafficLevel == 2)
            cout << "Medium";
        else
            cout << "High";

        cout << endl;
    }
};

class Route
{
private:
    string source;
    string destination;

public:
    Route(string s, string d)
    {
        source = s;
        destination = d;
    }

    void displayRoute()
    {
        cout << "Route: "
             << source << " -> "
             << destination << endl;
    }
};

int main()
{
    cout << "===== OOP MODULE =====\n\n";

    Road road1("A", "B", 5);
    Traffic traffic1(1);
    Route route1("A", "C");

    road1.displayRoad();
    traffic1.displayTraffic();

    cout << endl;

    route1.displayRoute();

    return 0;
}
