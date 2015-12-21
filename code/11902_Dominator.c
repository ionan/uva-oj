#include <stdio.h>

#define MAX_VERT 100
#define UNVISITED 0
#define VISITED 1

int adjMatrix[MAX_VERT][MAX_VERT];
int dfs_info[MAX_VERT];

void resetDFSInfo(){
    int i;
    for (i = 0; i < MAX_VERT; i++){
        dfs_info[i] = UNVISITED;
    }
}

void resetMatrix(){
    int i,j;
    for (i = 0; i < MAX_VERT; i++){
        for (j = 0; j < MAX_VERT; j++){
            adjMatrix[i][j] = 0;
        }
    }
}

void printMatrix(int vn){
    int i,j;
    printf("Matrix\n***********************************\n");
    for (i = 0; i < vn; i++){
        for (j = 0; j < vn; j++){
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("***********************************\n");
}

void printDFSInfo(int vn, int j, int k){
    int i;
    printf("DFS (%d, %d)\n***********************************\n",j,k);
    for (i = 0; i < vn; i++){
        printf("%d ",dfs_info[i]);
    }
    printf("\n");
    printf("***********************************\n");
}

void readMatrix(int vertN){
    int j,k, trash;
    for (j = 0; j < vertN; j++){
        trash = scanf("%d",&(adjMatrix[j][0]));
        for (k = 1; k < vertN; k++){
            trash = scanf(" %d",&(adjMatrix[j][k]));
        }
        trash = scanf("\n");
    } 
}

void dfs(int start, int vertN){
    dfs_info[start] = VISITED;
    int i;
    for (i = 0; i < vertN; i++){
        int val = adjMatrix[start][i];
        if (val > 0 && dfs_info[i] == UNVISITED){
            dfs(i,vertN);
        }
    }
}

int main(int argc, char *argv){
    int test_cases, i, vertN, j, k;
    int trash = scanf("%d\n",&test_cases);
    for (i = 1; i <= test_cases; i++){
        trash = scanf("%d\n",&vertN);
        readMatrix(vertN);
        printMatrix(vertN);
        resetDFSInfo();
        dfs(0,vertN);
        printDFSInfo(vertN,-1,-1);
        for (j = 0; j < vertN; j++){
            for (k = 0; k < vertN; k++){
                resetDFSInfo();
                if (j != k){
                    dfs(0,vertN);
                }
                printDFSInfo(vertN,j,k);
            }
        }
    }
    return 0;
}