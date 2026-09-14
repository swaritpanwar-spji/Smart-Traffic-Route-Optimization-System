#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int vertices;

void addRoad(int source, int destination, int distance)
{
    graph[source][destination] = distance;
    graph[destination][source] = distance;
}

void displayGraph()
{
    int i, j;

    printf("\nRoad Network:\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j;

    printf("Enter number of locations: ");
    scanf("%d", &vertices);

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    addRoad(0, 1, 5);
    addRoad(0, 2, 2);
    addRoad(1, 3, 3);
    addRoad(2, 3, 4);

    displayGraph();

    return 0;
}
