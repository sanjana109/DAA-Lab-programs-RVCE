#include<stdio.h>
#include<stdlib.h>

int j=0,pop[10],v[10];

void topoVD(int a[][10], int in[], int n)
{
    int i, j, k, node, count=0;
	int v[10]={0};	
    for(k=1;k<=n;k++) 
	{
        for(i=1;i<=n;i++)	
		{
			//count++;
			if(in[i] == 0 && v[i] == 0)	//if the node's in-degree is 1 and its still not visited
			{
				node = i;
				printf("%5d",node);		//print the node in the topological order			
				v[node] = 1;			// the node is marked as visited
				break;
			}
		}
		
        for(i=1;i<=n;i++)				// once a node is visited, the in-degree of all the nodes attached to it must be subtracted by one
			if(a[node][i] == 1)			// if the node is attached to it
				in[i]--;				// decrement its in-degree
	}
	printf("\nComplexity - %d",count);
	printf("\n\n");
}

int main()
{
	int n;		     
	int a[10][10],b[10][10];		
	int i,j,k,node,choice;
	int in[10]={0};		
	
	printf("Enter n: ");
	scanf("%d",&n);// read the number of nodes

	printf("Enter Adj matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] == 1)//check if vertex has indegree               
				in[j]++;			
		}
	}
	printf("\nVertex Deletion Method topological order is- ");
    topoVD(a,in,n);	
}

/*
OUTPUT
nodes - 6
adjacnecy matrix- 
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 1 0 0 0 0
1 1 0 0 0 0
1 0 1 0 0 0

VD-  5 6 1 3 4 2
DFS- 6 4 5 3 2 1

*/

/*
void dfs(int source,int n,int a[10][10])
{
	int i,k,top=-1,stack[10];
	v[source]=1;
	stack[++top]= source+1;
	while(top!=-1)//check if stack is not empty
	{
		for(k=0;k<n;k++)
		{
			if( a[source][k] == 1 && v[k] == 1 )
			{
			  for(i=top;i>=0;i--)
			    if(stack[i] == k+1 )
				{
				  printf("\n Topological order not possible");
				   exit(0);
				}
			}
		     else
			{
			  if( a[source][k] == 1 && v[k] == 0)
			   {
				v[k]=1;
                stack[++top]= k+1;
				source = k;
				k=0;
			   }
			}
		  }
	   pop[j++]=source+1;
	   top--;
	   source=stack[top]-1;
    }
}

void topo(int n , int a[10][10])
{
    int i,k;
    for(i=0;i<n;i++)
        v[i]=0;
    for(k=0;k<n;k++)
		if(v[k]== 0)
			dfs(k,n,a);//dfs function call
}
*/