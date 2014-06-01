#include <stdio.h>

#define bool int
#define TRUE 1
#define FALSE 0

char grid[3][3];

int main(int argc, char const *argv[]){
	int testCases, i, j, k;
	int trash = scanf("%d",&testCases);
	for (i = 0; i < testCases; i++){
		bool valid = TRUE;
		trash = scanf("\n%c%c%c\n%c%c%c\n%c%c%c\n", &(grid[0][0]), &(grid[0][1]), 
					&(grid[0][2]), &(grid[1][0]), &(grid[1][1]), &(grid[1][2]), 
					&(grid[2][0]), &(grid[2][1]), &(grid[2][2]));
		int x = 0, o = 0, endMovesO = 0, endMovesX = 0;
		for (j = 0; j < 3; j++){
			for (k = 0; k < 3; k++){
				if (grid[j][k] == 'X') x++;
				else if (grid[j][k] == 'O') o++;
			}
		}

		if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) 
			if (grid[0][0] == 'X') endMovesX++; 
			else if (grid[0][0] == 'O') endMovesO++;
		if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) 
			if (grid[0][0] == 'X') endMovesX++; 
			else if (grid[0][0] == 'O') endMovesO++;
		if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) 
			if (grid[2][0] == 'X') endMovesX++; 
			else if (grid[2][0] == 'O') endMovesO++;

		if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) 
			if (grid[0][0] == 'X') endMovesX++; 
			else if (grid[0][0] == 'O') endMovesO++;
		if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) 
			if (grid[0][1] == 'X') endMovesX++; 
			else if (grid[0][1] == 'O') endMovesO++;
		if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) 
			if (grid[0][2] == 'X') endMovesX++; 
			else if (grid[0][2] == 'O') endMovesO++;

		if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) 
			if (grid[0][0] == 'X') endMovesX++; 
			else if (grid[0][0] == 'O') endMovesO++;
		if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) 
			if (grid[0][2] == 'X') endMovesX++; 
			else if (grid[0][2] == 'O') endMovesO++;

		valid = ((x == o || x == o + 1) && ((endMovesO == 0 && endMovesX <= 1) || 
			(endMovesO <= 1 && endMovesX == 0 && x == o)));

		printf("%d) ",(i+1));
		if (valid) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}