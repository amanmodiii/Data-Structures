#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int v, e;
void adjMat(int arr[][v])
{
    int i, x, y;
    printf("Enter the edges as (vertexBegin  vertexEnd) : \n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &x, &y);
        arr[x][y]++;
        arr[y][x]++;
    }
}

void printArray(int arr[][v])
{
    printf("\n\n The Adjacency Matrix :   \n\n");
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the number of vertices and edges : ");
    scanf("%d %d", &v, &e);
    int i, j;
    int adjMatrix[v][v];
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            adjMatrix[i][j] = 0;
    }
    adjMat(adjMatrix);

    printArray(adjMatrix);
    //prims algorithm begins...

    int no_edge = 0;
    int selected[v];
    memset(selected,0,sizeof(selected));

    int x,y;
    int T[v],c;
    selected[0]=1;
    while(no_edge < v-1){
        int min = 999999;       //a very large no.
        int i,j;
        x=0,y=0;
        for(i=0 ; i<v ;i++){
            if(selected[i]){
                for(j=0 ; j<v ; j++){
                    if(!selected[j] && adjMatrix[i][j]){
                        if(min>adjMatrix[i][j]){
                            min=adjMatrix[i][j];
                            x=i,y=j;
                        }
                    }
                }
            }
        }
        printf("%d  -   %d   :   %d\n",x,y,adjMatrix[x][y]);
        selected[y]=1;
        no_edge++;
    }


}