#include <stdio.h>
#define INF 99
int V;
void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
	int i, j, k;
	for (k = 0; k < V; k++)
	{

		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	printf(
		"The following matrix shows the shortest distances"
		" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

// driver's code
int main()
{
	printf("Enter the number of vertices\n");
	scanf("%d", &V);
	int graph[V][V];
	printf("give 99999 for infinty\n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	// Function call
	floydWarshall(graph);
	return 0;
}
