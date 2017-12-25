#include "bits/stdc++.h"
using namespace std;
#define V  4
#define INF 99999
void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
void floydWarshall(int graph[][V]){
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if(graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	printSolution(graph);
}
int main(int argc, char const *argv[])
{
	int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floydWarshall(graph);
	return 0;
}