#include <stdio.h>

unsigned int i = 0;
unsigned int j = 0;

int readStandardInput()
{
	char line[1024], *p, *e;
	long v;
	//printf("Starting reading from standard input...\n");
	if (scanf("%d %d\n",&i,&j)==2)
	{ 
		return 0;
    }
	else
	{
		//printf("Finshed reading from standard input\n");
		return 1;
	}
}

int getCycleLength(int nmb)
{
	int cclLng = 0;
	while (1)
	{
		cclLng++;
		if (nmb == 1)
			break;
		if (nmb % 2 != 0)
			nmb = 3 * nmb + 1;
		else
			nmb = nmb / 2;
	}
	return cclLng;
}

int main()
{
	//printf("Starting program execution...\n");
	int curr_i, curr_j;
	while (readStandardInput() == 0)
	{
		if (i < j)
		{
			curr_i= i;
			curr_j = j;
		}
		else
		{
			curr_i= j;
			curr_j = i;
		}
		//printf("From %u to %u\n",curr_i, curr_j);
		int ctr;
		int maxCycleLength = 1;
		for (ctr = curr_i; ctr <= curr_j; ctr++)
		{
			int currCycleLength = getCycleLength(ctr);
			if (currCycleLength > maxCycleLength)
				maxCycleLength = currCycleLength;
		}
		printf("%d %d %d\n",i,j,maxCycleLength);
	}
	return 0;
}
