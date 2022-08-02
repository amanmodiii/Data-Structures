#include<stdio.h>
#include<stdlib.h>
int v, e;
void adjMat(int arr[][v]){
    int i,x,y;
    printf("Enter the edges as (vertexBegin  vertexEnd) : \n");
    for(i=0 ; i<e ; i++)
    {
        scanf("%d %d",&x,&y);
        arr[x][y]++;
        arr[y][x]++;
    }
}

void printArray(int arr[][v]){
    printf("\n\n The Adjacency Matrix :   \n\n");
    int i,j;
    for(i=0; i<v; i++){
        for(j=0 ;j<v ;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the number of vertices and edges : ");
    scanf("%d %d", &v, &e);
    int i,j;
    int adjMatrix[v][v];
    for(i=0;i<v;i++){
        for(j=0;j<v;j++)
            adjMatrix[i][j]=0;
    }
    adjMat(adjMatrix);

    printArray(adjMatrix);

}