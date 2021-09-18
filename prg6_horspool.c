#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256 // considereing all ASCII char,[only printable->128]
int Table[SIZE];

void shiftTable(char P[]){
    int i, m;
    m=strlen(P);
    for(i=0;i<SIZE;i++){
        Table[i]=m; //atmost the character can be shifted by the length of the pattern
    }
    for(i=0;i<=m-2;i++){ //last character is not considered for shift values
        Table[P[i]]=m-i-1;  //how far the character is from the last character -> shift value
    }
}

int Horspool(char T[100], char P[]){
    int m, n, i, k;
    
    m=strlen(P);
    n=strlen(T);
    i=m-1;  //always begin comparison from the last character of the pattern
    while(i<=n-1){  // go on till we reach the last index of the text
        k=0;
        while( (k<m) && (P[m-1-k]==T[i-k]) ){ //begin matching from the last char of the pattern
            k=k+1;
        }
        if(k==m)    //pattern found
            return(i-m+1);
        else
            i=i+Table[T[i]];    //shift based on value from shift table
    }
    return(-1); // control reaches only after traversing whole text and pattern was not found
}

int main(){
    char text[100],pattern[25];
    int result;
    printf("\nHORSPOOL STRING MATCHING ALGORITHM\n");
    printf("\nEnter the text- ");
    gets(text);
    printf("\nEnter the pattern - ");
    gets(pattern);
    shiftTable(pattern);
    result=Horspool(text,pattern);
    if(result==-1){
        printf("\nPattern is not found in the text!\n");
    }
    else{
        printf("\nPattern found at position %d\n",result+1);
    }
    return(0);
}









