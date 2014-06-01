#include <stdio.h>
#include <string.h>

#define NORTHWEST  world[i-1][j-1]
#define NORTH  world[i-1][j]
#define NORTHEAST  world[i-1][j+1]
#define WEST  world[i][j-1]
#define EAST  world[i][j+1]
#define SOUTHWEST  world[i+1][j-1]
#define SOUTH  world[i+1][j]
#define SOUTHEAST  world[i+1][j+1]

int world[100][100];

void addMine(int l, int c, int i, int j);

int main(int argc, char* argv){
	int i,j,lines,columns,trash, curr, field = 0;
	char c;
	trash = scanf("%d %d\n",&lines,&columns);
	while (lines > 0 || columns > 0){
		memset(world,0,sizeof(world));
		if (field > 0) printf("\n");
		printf("Field #%d:\n",++field);
		curr = 0;
		for (i = 0; i < lines; i++){
			for (j = 0; j < columns; j++){
				c = getchar();
				if (c == '*') addMine(lines,columns,i,j);
				if (i > 1){
					if (world[curr][j] > -1) printf("%d",world[curr][j]);
					else printf("*");
				}
			}
			if (i > 1){
				printf("\n");
				curr++;
			}
			trash = scanf("\n");
		}
		for (; curr < lines; curr++){
			for (j = 0; j < columns; j++) {
				if (world[curr][j] > -1) printf("%d",world[curr][j]);
				else printf("*");
			}
			printf("\n");
		}
		trash = scanf("%d %d\n",&lines,&columns);
	}
	return 0;
}

void addMine(int l, int c, int i, int j){
	world[i][j] = -1;
	
	if (i > 0 && j > 0 && NORTHWEST >= 0) NORTHWEST++;
	if (i > 0 && NORTH >= 0) NORTH++;
	if (i > 0 && j+1 < c && NORTHEAST >= 0) NORTHEAST++;
	if (j > 0 && WEST >= 0) WEST++;
	if (j+1 < c && EAST >= 0) EAST++;
	if (i+1 < l && j > 0 && SOUTHWEST >= 0) SOUTHWEST++;
	if (i+1 < l && SOUTH >= 0) SOUTH++;
	if (i+1 < l && j+1 < c && SOUTHEAST >= 0) SOUTHEAST++;
	
	return;
}