	#include <stdio.h>
	#include <malloc.h>

	#define MOVE_ONTO 1
	#define MOVE_OVER 2
	#define PILE_ONTO 3
	#define PILE_OVER 4
	
	int world[25][25];
	int blocks;
	
	int main(){
		if ((blocks = getNumberOfBlocks()) == 0) return 0;
		initializeWorld();
		int params_read, a, b;
		char cmd[4], cmd2[4];
		int initial_r,initial_c;
		while ((params_read = scanf("%s %d %s %d\n",cmd,&a,cmd2,&b)) > 0){
			if (params_read == 1 && strcmp(cmd,"quit")) break;
			else if (a != b && !inSameStack(a,b)){ 
				int command = getCommand(cmd,cmd2);
				switch (command){
					case MOVE_ONTO:
						find(b,&initial_r,&initial_c);
						if (returnBlocks(a) != 0) return 1;
						if (returnBlocks(b) != 0) return 2;
						if (move(a,b,initial_r,initial_c) != 0) return 3;
						break;
					case MOVE_OVER:
						find(b,&initial_r,&initial_c);
						if (returnBlocks(a) != 0) return 1;
						if (move(a,b,initial_r,initial_c) != 0) return 3;
						break;
					case PILE_ONTO:
						find(b,&initial_r,&initial_c);
						if (returnBlocks(b) != 0) return 1;
						if (move(a,b,initial_r,initial_c) != 0) return 3;
						break;
					case PILE_OVER:
						find(b,&initial_r,&initial_c);
						if (move(a,b,initial_r,initial_c) != 0) return 3;
						break;
					default:
						break;
				}
			}
		}
		printWorld();
		return 0;
	}
	
	int getNumberOfBlocks(){
		int i;
		if (scanf("%d\n",&i)==1) return i;
		else return 0;
	}
	
	int initializeWorld(){
		int i = 0;
		for (i = 0; i < 25; i++){
			if (i < blocks) world[i][0] = i;
			else world[i][0] = -1;
			int j = 0;
			for (j = 1; j < 25; j++){
				world[i][j] = -1;
			}
		}
	}
	
	int printWorld(){
		int i = 0;
		for (i = 0; i < blocks; i++){
			printf("%d:",i);
			int j = 0;
			for (j = 0; j < blocks; j++){
				if (world[i][j] == -1) break;
				printf(" %d",world[i][j]);
			}
			printf("\n");
		}
	}
	
	int find(int val, int *row, int *col){
		int i,j;
		for (i = 0; i < blocks; i++){
			for (j = 0; j < blocks; j++){
				if (world[i][j] == -1) break;
				if (world[i][j] == val){
					*row = i; 
					*col = j;
					return 0;
				}
			}
		}
		return -1;
	}

	int getCommand(char c[4],char c2[4]){
		int command = 0;
		if (strcmp(c,"move")==0) command = 1;
		else if (strcmp(c,"pile")==0) command = 3;
		else return command;
		
		if (strcmp(c2,"over")==0) command++;
		else if (strcmp(c2,"onto")==0) {
			
		} else return 0;
		
		return command;
	}
	
	int returnBlocks(int blockNumber){
		int r,c;
		if (find(blockNumber,&r,&c) == 0){
			int i,j;
			for (i = c+1; i < blocks; i++){
				if (world[r][i] > -1){
					int valToMove = world[r][i];
					for (j = 0; j < blocks; j++){
						if (world[valToMove][j] == -1){
							world[valToMove][j] = valToMove;
							break;
						}
					}
					world[r][i] = -1;
				} else {
					break;
				}
			}
		}
		return 0;
	}
	
	int move(int a,int b,int initial_r,int initial_c){
		int new_r = initial_r,new_c = initial_c,old_r,old_c;
		new_c++;
		while(world[new_r][new_c] != -1 && new_c < blocks) new_c++;
		if (find(a,&old_r,&old_c) == 0 && new_r != old_r){
			int i;
			for (i = old_c; i < blocks; i++){
				if (world[old_r][i] == -1) break;
				world[new_r][new_c++] = world[old_r][i];
				world[old_r][i] = -1;
			}
		}
		return 0;
	}
	
	int inSameStack(int a, int b){
		int r1,r2,c;
		find(a,&r1,&c);
		find(b,&r2,&c);
		return r1==r2;
	}


