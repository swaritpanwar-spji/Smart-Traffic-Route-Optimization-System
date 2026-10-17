
#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int traffic[MAX][MAX];
int vertices;

// Add a two-way road 
void addRoad(int source, int destination, int distance)
{
    graph[source][destination] = distance;
    graph[destination][source] = distance;
}

// Set traffic level 
void setTraffic(int source, int destination, int level)
{
    traffic[source][destination] = level;
    traffic[destination][source] = level;
}

// Display road network 
void displayGraph()
{
    int i, j;

    printf("\n  ROAD NETWORK  \n");

    for (i = 0; i < vertices; i++)
    {
        for (j = i + 1; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                printf("%c -> %c : %d km\n",
                       'A' + i, 'A' + j,
                       graph[i][j]);
            }
        }
    }
}

// Display traffic conditions 
void displayTraffic()
{
    int i, j;

    printf("\n  TRAFFIC CONDITIONS   \n");

    for (i = 0; i < vertices; i++)
    {
        for (j = i + 1; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                printf("%c -> %c : ",
                       'A' + i, 'A' + j);

                if (traffic[i][j] == 1)
                    printf("Low");
                else if (traffic[i][j] == 2)
                    printf("Medium");
                else
                    printf("High");

                printf("\n");
            }
        }
    }
}

// Calculate traffic-adjusted road cost 
int getCost(int source, int destination)
{
    int distance, level;

    distance = graph[source][destination];
    level = traffic[source][destination];

    if (level == 1)
        return distance;
    else if (level == 2)
        return distance + 2;
    else if (level == 3)
        return distance + 5;

    return distance;
}

int main()
{
    int i, j;
    char source, destination;

    printf("Enter number of locations (4 for this network): ");
    scanf("%d", &vertices);

    if (vertices != 4)
    {
        printf("Please enter 4 locations: A, B, C and D\n");
        return 0;
    }

    // Initialize matrices 
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
            traffic[i][j] = 0;
        }
    }

    // Add roads 
    addRoad(0, 1, 5);  // A-B 
    addRoad(0, 3, 3);  // A-D 
    addRoad(1, 2, 8);  // B-C 
    addRoad(3, 2, 4);  // D-C 
    addRoad(1, 3, 6);  // B-D 

    // Set traffic levels 
    setTraffic(0, 1, 1);  // A-B: Low 
    setTraffic(0, 3, 2);  // A-D: Medium 
    setTraffic(1, 2, 3);  // B-C: High 
    setTraffic(3, 2, 1);  // D-C: Low 
    setTraffic(1, 3, 2);  // B-D: Medium 

    // Display network information 
    displayGraph();
    displayTraffic();

    // Accept source and destination 
    printf("\n  ROUTE SEARCH  \n");

    printf("Enter source location (A-D): ");
    scanf(" %c", &source);

    printf("Enter destination location (A-D): ");
    scanf(" %c", &destination);

    // Validate locations 
    if (source < 'A' || source > 'D' ||
        destination < 'A' || destination > 'D')
    {
        printf("Invalid location\n");
        return 0;
    }

    if (graph[source - 'A'][destination - 'A'] == 0)
    {
        printf("No direct road exists between these locations\n");
        return 0;
    }

    printf("\nSource: %c\n", source);
    printf("Destination: %c\n", destination);

    printf("Direct road distance: %d km\n",
           graph[source - 'A'][destination - 'A']);

    printf("Traffic-adjusted road cost: %d\n",
           getCost(source - 'A', destination - 'A'));

    printf("\nFirst phase completed successfully\n");

    return 0;
}
