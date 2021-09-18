#include <stdio.h>

#define INFINITY 999

//Function to implement dijkstra algorithm
void dijk(int cost[10][10],int n,int source,int v[10],int d[10])
{
	int least, i, j, u;

	//Mark source node as visited
	v[source] = 1;

	//From each node find shortest distance to nodes not visited
	for(i=1; i<=n; i++)
	{
		//Assume least as infinity
		least = INFINITY;

        //Find u and d(u) such that d(u) is minimum i.e., Find the next nearest node
		for(j=1; j<=n; j++)
		{
			if(v[j] == 0 && d[j] < least)
			{
				least = d[j];
				u = j;
			}
		}
		//Mark u as visited (mark nearest node as visited)
		v[u] = 1;

		//For remaining nodes, find shortest distance through u
		for(j=1; j<=n; j++)
		{
			if(v[j] == 0 && (d[j] > (d[u] + cost[u][j])) )
				d[j] = d[u] + cost[u][j];
		}
	}
}

int main()
{
	int n;					//no. of nodes
	int cost[10][10];		//Adjacency matrix of graph
	int source;				//source node
	int v[10];				//visited array. keeps track to nodes visited
	int d[10];				//distance array.shortest distance from source node
	int i, j;				//index variables

	//Read no. of nodes
	printf("\nDIJKSTRA's ALGORITHM\n");
	printf("\nEnter n: ");
	scanf("%d",&n);

	//Read cost adjacency matrix of graph
	printf("\nEnter  Cost matrix: \n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d",&cost[i][j]);

	//Read source
	printf("\nEnter the source:\n");
	scanf("%d",&source);

	//Initialise d[] to distance from source to each node
	//Initialise v[] to 0, indicating none of the nodes are visited
	for(i=1; i<=n; i++)
	{
		d[i] = cost[source][i];
		v[i] = 0;
	}

	//Call function to compute shortest distance
	dijk(cost, n, source, v, d);

	//Print Shortest distance from source to all other nodes
	printf("\nShortest distance from source %d\n\n",source);
	for(i=1; i<=n; i++)
		printf("%d ---> %d = %d\n\n",source,i,d[i]);

	return 0;
}


/*
Cost Matrix- 
0 4 2 999 999 999
4 0 1 5 999 999
2 1 0 8 10 999
999 5 8 0 2 6
999 999 10 2 0 3
999 999 999 6 3 0
*/