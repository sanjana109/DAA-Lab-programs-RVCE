#include<stdio.h>
#include<stdlib.h>

void Prims(int n, int cost[10][10]){
    int i, j, u, v, min, mincost=0, visited[10], numEdges=1;
    for(i=1;i<=n;i++){
        visited[i]=0; //initially all vertices marked unvisited
    }
    printf("\nThe edges considered for MST are- \n");
    visited[1]=1; //starting from first vertex, first vertex is visited 
    while(numEdges<n){
        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    if(visited[i]==0) //no point of revisiting a node
                        continue;
                    else{
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0){     // if either end of the edge is unvisited
            printf("%d) Edge(%d-%d) = %d\n",numEdges++, u, v, min);
            mincost+=min;
            visited[v]=1;       // mark end vertex as visited
        }
        cost[u][v]=cost[v][u]=999;
    }
    printf("\n\nCost of constructing MST is %d",mincost);
}

int main(){
    int i, j, n, cost[10][10];
    printf("\nPRIMS ALGORITHM - FOR MINIMUM SPANNING TREE\n");
    printf("\nEnter the number of nodes - ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix- \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)       //if there is no edge from a->b, then the corresponding entry ab in table is infinity
                cost[i][j] = 999;
        }
    }
    Prims(n,cost);
    return 0;
}

/*
0 999 3 999 999
999 0 10 4 999
3 10 0 2 6
999 4 2 0 1
999 999 6 1 0
*/