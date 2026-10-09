#include <stdio.h>

#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int traffic[MAX][MAX];
int vertices;

/* Add a two-way road */
void addRoad(int source, int destination, int distance)
{
    graph[source][destination] = distance;
    graph[destination][source] = distance;
}

/* Set traffic level for a road
   1 = Low
   2 = Medium
   3 = High
*/
void setTraffic(int source, int destination, int level)
{
    traffic[source][destination] = level;
    traffic[destination][source] = level;
}

/* Display road network */
void displayGraph()
{
    int i, j;

    printf("\n===== ROAD NETWORK =====\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = i + 1; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                printf("%c -> %c : %d km\n",
                       'A' + i,
                       'A' + j,
                       graph[i][j]);
            }
        }
    }
}

/* Display traffic conditions */
void displayTraffic()
{
    int i, j;

    printf("\n===== TRAFFIC CONDITIONS =====\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = i + 1; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                printf("%c -> %c : ",
                       'A' + i,
                       'A' + j);

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

/* Calculate effective road cost using traffic */
int getCost(int source, int destination)
{
    int distance;
    int level;

    distance = graph[source][destination];
    level = traffic[source][destination];

    if (level == 1)
        return distance;

    if (level == 2)
        return distance + 2;

    if (level == 3)
        return distance + 5;

    return distance;
}

/* Find vertex with minimum distance */
int findMinimum(int distance[], int visited[])
{
    int i;
    int minimum;
    int position;

    minimum = INF;
    position = -1;

    for (i = 0; i < vertices; i++)
    {
        if (visited[i] == 0 && distance[i] < minimum)
        {
            minimum = distance[i];
            position = i;
        }
    }

    return position;
}

/* Find best route using Dijkstra's algorithm */
void findBestRoute(int source, int destination)
{
    int distance[MAX];
    int previous[MAX];
    int visited[MAX];
    int i, count;
    int current;
    int next;
    int path[MAX];
    int pathCount;

    for (i = 0; i < vertices; i++)
    {
        distance[i] = INF;
        previous[i] = -1;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (count = 0; count < vertices; count++)
    {
        current = findMinimum(distance, visited);

        if (current == -1)
            break;

        visited[current] = 1;

        for (next = 0; next < vertices; next++)
        {
            if (graph[current][next] != 0 &&
                visited[next] == 0)
            {
                int newDistance;

                newDistance =
                    distance[current] +
                    getCost(current, next);

                if (newDistance < distance[next])
                {
                    distance[next] = newDistance;
                    previous[next] = current;
                }
            }
        }
    }

    if (distance[destination] == INF)
    {
        printf("\nNo route found.\n");
        return;
    }

    pathCount = 0;
    current = destination;

    while (current != -1)
    {
        path[pathCount] = current;
        pathCount++;
        current = previous[current];
    }

    printf("\n===== BEST ROUTE =====\n");

    for (i = pathCount - 1; i >= 0; i--)
    {
        printf("%c", 'A' + path[i]);

        if (i != 0)
            printf(" -> ");
    }

    printf("\n");

    printf("Total Route Cost: %d\n", distance[destination]);
}

/* Main function */
int main()
{
    int i, j;
    int source;
    int destination;

    printf("Enter number of locations (maximum 10): ");
    scanf("%d", &vertices);

    /* Initialize matrices */
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
            traffic[i][j] = 0;
        }
    }

    /*
       Road Network

       A -> B = 5 km
       A -> D = 3 km
       B -> C = 8 km
       D -> C = 4 km
       B -> D = 6 km
    */

    addRoad(0, 1, 5);
    addRoad(0, 3, 3);
    addRoad(1, 2, 8);
    addRoad(3, 2, 4);
    addRoad(1, 3, 6);

    /*
       Traffic

       1 = Low
       2 = Medium
       3 = High
    */

    setTraffic(0, 1, 1);  /* A-B Low */
    setTraffic(0, 3, 2);  /* A-D Medium */
    setTraffic(1, 2, 3);  /* B-C High */
    setTraffic(3, 2, 1);  /* D-C Low */
    setTraffic(1, 3, 2);  /* B-D Medium */

    displayGraph();

    displayTraffic();

    printf("\n===== ROUTE SEARCH =====\n");

    printf("Enter source location (A-D): ");
    scanf(" %c", &source);

    printf("Enter destination location (A-D): ");
    scanf(" %c", &destination);

    source = source - 'A';
    destination = destination - 'A';

    if (source < 0 || source >= vertices ||
        destination < 0 || destination >= vertices)
    {
        printf("\nInvalid location.\n");
        return 0;
    }

    findBestRoute(source, destination);

    return 0;
}
