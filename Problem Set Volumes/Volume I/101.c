#include <stdio.h>
#include <malloc.h>

#define MOVE_ONTO 1
#define MOVE_OVER 2
#define PILE_ONTO 3
#define PILE_OVER 4

struct block 
{
  	int number;  //The number of the block
  	struct block * block_above;  // Pointer to the block above this
};

struct block * world;
int * block_indexes;
int blocks;
	
int getNumberOfBlocks()
{
	int i;
	if (scanf("%d\n",&i)==1)
	{ 
		return i;
    }
	else
	{
		return 0;
	}
}

int initialize_variables()
{
	world = (struct block *) malloc (blocks * sizeof (struct block));
	block_indexes = (int *) malloc (blocks * sizeof (int));
	int idx;
	for (idx = 0; idx < blocks; idx++)
	{
		struct block b = {.number = idx, .block_above = 0};
		world[idx] = b;
		block_indexes[idx] = idx;
	}
}

int writeOutput(int block_idx)
{
	struct block * next = &(world[block_idx]);
	while (next != 0)
	{
		printf(" %d",next->number);
		next = next->block_above;
	}
}

int getCommand(char c[4],char c2[4])
{
	int command = 0;
	if (strcmp(c,"move"))
	{
		command = 1;
	}
	else if (strcmp(c,"pile"))
	{
		command = 3;
	}
	else
	{
		return command;
	}
	if (strcmp(c2,"over"))
	{
		command++;
	}
	else if (strcmp(c2,"onto"))
	{
		//DO NOTHING
	}
	else
	{
		return 0;
	}
	return command;
}

int return_blocks(int index,int block_number)
{
	struct block * next = &(world[index]);
	while (next != 0)
	{
		if (next->number == block_number)
			break;
		next = next->block_above;
	}
	if (next == 0)
	{
		return 1;
	}
	struct block * pre = next;
	next = next->block_above;
	pre->block_above = 0;
	while  (next != 0)
	{
		world[next->number] = *next;
		block_indexes[next->number] = next->number;
		pre = next;
		next = next->block_above;
		pre->block_above = 0;
	}
	return 0;
} 

int move(int a,int b,int a_index, int b_index)
{
	struct block * pre = &(world[a_index]);
	if (pre == 0)
	{
		return 1;
	}
	struct block * next = pre->block_above;
	while (next != 0)
	{
		if (next->number == a)
			break;
		pre = next;
		next = next->block_above;
	}
	if (next == 0)
	{
		return 1;
	}
	pre = 0;
	struct block * next2 = &(world[b_index]);
	int founded = 0;
	while (next2 != 0)
	{
		if (next2->number == b)
			founded = 1;
		next2 = next2->block_above;
	}
	if (founded == 0)
	{
		return 1;
	}
	next2 = next;
	while (next2 != 0)
	{
		block_indexes[next2->number] = b_index;
		next2 = next2->block_above;
	}
}

int main()
{
	if ((blocks = getNumberOfBlocks()) == 0)
	{
		return 0;
	}
	initialize_variables();
	int params_read, a, b;
	char cmd[4], cmd2[4];
	while ((params_read = scanf("%s %d %s %d\n",cmd,&a,cmd2,&b)) > 0)
	{
		if (params_read == 1 && strcmp(cmd,"quit"))
		{
			break;
		}
		else if (a != b)
		{
			int command = getCommand(cmd,cmd2);
			switch (command)
			{
				case MOVE_ONTO:
					if (return_blocks(block_indexes[a],a) != 0)
					{
						return 1;
					}
					if (return_blocks(block_indexes[b],b) != 0)
					{
						return 2;
					}
					if (move(a,b,block_indexes[a],block_indexes[b]) != 0)
					{
						return 3;
					}
					break;
				case MOVE_OVER:
					break;
				case PILE_ONTO:
					break;
				case PILE_OVER:
					break;
				default:
					break;
			}
		}
	}
	int i;
	for (i = 0; i < blocks; i++)
	{
		printf("%d:",i);
		writeOutput(i);
		printf("\n");
	}
	
}
