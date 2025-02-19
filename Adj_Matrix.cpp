#include<bits/stdc++.h>
using namespace std;
#define max 20

int adj[max][max]; /*Adjacency matrix */
int n; /* Number of nodes in the graph */

void DFS(int start, int visited[]) {
    cout << start << " ";
    visited[start] = 1;

    for(int v = 1; v <= n; v++) {
        if(adj[start][v] == 1 && visited[v] == 0) {
            DFS(v, visited);
        }
    }
}

int main()
{
    int max_edges, i, j, origin, destin;
    char graph_type;

    printf( "Enter number of nodes : " );
    cin >> n;
    printf( "Enter type of graph, directed or undirected (d/u) : " );
    cin >> graph_type;

    if ( graph_type == 'u' )
        max_edges = n * ( n - 1 ) / 2;
    else
        max_edges = n * ( n - 1 );

    for ( i = 1;i <= max_edges;i++ )
        {
            printf( "Enter edge %d( 0 0 to quit ) : ", i );
            scanf( "%d %d", &origin, &destin );

            if ( ( origin == 0 ) && ( destin == 0 ) )
                break;

            if ( origin > n || destin > n || origin <= 0 || destin <= 0 )
                {
                    printf( "Invalid edge!\n" );
                    i--;
                }
            else
                {
                    adj[ origin ][ destin ] = 1;

                    if ( graph_type == 'u' )
                        adj[ destin ][ origin ] = 1;
                }
        }

    printf("Enter starting node for DFS: ");
    int start;
    cin >> start;

    int visited[max] = {}; /* Initialize visited array to 0 */
    printf("DFS traversal: ");
    DFS(start, visited);
    printf("\n");

    return 0;
}
