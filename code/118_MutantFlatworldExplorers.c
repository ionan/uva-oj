#include <stdio.h>
#include <string.h>

#define MAX_COORD 51

typedef int bool;
#define true 1
#define false 0

int world[MAX_COORD][MAX_COORD];
int maxX, maxY, x, y, rNum;
char orientation;

bool validPosition(int x, int y){
	if (x > maxX || x < 0){
		return false;
	}
	if (y > maxY || y < 0){
		return false;
	}
	return true;
}

char getNewOrientation(bool left){
	char orient = orientation;
	switch (orientation){
		case 'N':
			orient = left ? 'W' : 'E';
			break;
		case 'E':
			orient = left ? 'N' : 'S';
			break;
		case 'S':
			orient = left ? 'E' : 'W';
			break;
		case 'W':
			orient = left ? 'S' : 'N';
			break;
		default:
			orient = orientation;
	}
	return orient;
}

void move(){
	switch (orientation){
		case 'N':
			y++;
			break;
		case 'E':
			x++;
			break;
		case 'S':
			y--;
			break;
		case 'W':
			x--;
			break;
	}
}

bool existsHint(int x, int y){
	return (world[x][y] > 0 && world[x][y] < rNum);
}

bool performAction(char code){
	printf("\tPerforming action %c on %d,%d %c\n",code,x,y,orientation);
	if (code == 'L' || code == 'R'){
		orientation = getNewOrientation(code == 'L');
		printf("\t\tChanging orientation to %c\n", orientation);
		return true;
	} else if (code == 'F') {
		int oldX = x;
		int oldY = y;
		move();
		if (validPosition(x,y)){
			printf("\t\tMoving to %d, %d\n", x,y);
			world[x][y] = rNum;
			return true;
		} else if (existsHint(oldX, oldY)){
			printf("\t\tIgnoring order to move to %d,%d\n", x,y);
			int x = oldX;
			int y = oldY;
			return true;
		} else {
			printf("\t\tRobot lost in position %d,%d\n", x,y);
			return false;
		}
	} else {
		world[x][y] = rNum;
		printf("\t\tStay in %d, %d\n", x,y);
		return true;
	}
}

void printWorld(){
	int i,j;
	for (j = 0; j <= maxY; j++){
		for (i = 0;i <= maxX; i++){
			printf("%d ",world[i][j]);
		}
		printf("\n");
	}
}

void flushLine(){
	char c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
}

int main(int argc, char* argv){
	memset(world,0,sizeof(world));
	int i;
	char c;
	rNum = 0;
	int trash = scanf("%d %d\n",&maxX,&maxY);
	while ((trash = scanf("%d %d %c\n", &x, &y, &orientation)) != -1){
		rNum++;
		bool result = performAction(orientation);
		c = getchar();
		while (c != '\n' && c != EOF && result){
			result = performAction(c);
			c = getchar();
		}
		if (c != '\n' && c != EOF)
			flushLine();
		if (!result){
			printf("%d %d %c LOST\n",x,y, orientation);
		} else {
			printf("%d %d %c\n",x,y,orientation);
		}
	}
	printWorld();
	return 0;
}