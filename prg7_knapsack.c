#include<stdio.h>
#include<stdlib.h>
int n, W, w[10], v[10], V[10][10], x[10];

int max(int a, int b){
    if(a>b)
        return a;
    else 
        return b;
}

void Knapsack(){
    int i, j;
    printf("\nKnapsack dynamic programming table-\n");
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n+1;j++){
            if(i==0 || j==0)
                V[i][j]=0;
            else if(j<w[i])
                V[i][j] = V[i-1][j];
            else{
                V[i][j] = max(V[i-1][j], V[i-1][j-w[i]]+v[i]);
            }
            printf("%d\t",V[i][j]);
        }
        printf("\n");
    }
}

void solution(){
    int i, j;
    i=n;
    j=W;
    while(i!=0 && j!=0){
        if(V[i][j]!=V[i-1][j]){
            x[i]=1;
            j= j-w[i];
        }
        i--;
    }
}

int main(){
    int i;
    printf("\nKNAPSACK PROBLEM\n");
    printf("\nEnter the number of objects- ");
    scanf("%d",&n);
    printf("\nRead the knapsack capcity- ");
    scanf("%d",&W);
    printf("\nEnter the weight of each object- ");
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    printf("\nEnter the profit of the objects- ");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    Knapsack();
    solution();  //this will tell which objects are there in the knapsack
    
    printf("\nObjects selected for maximal profit are- \n");
    printf("\nObject\tWeight\tProfit\n");

    for(i=1;i<=n;i++){
        if(x[i]==1){
            printf("%d\t%d\t%d\n",i,w[i],v[i]);
        }
    }
    printf("\nMax profit gained is Rs. %d\n",V[n][W]);
    return 0;
}