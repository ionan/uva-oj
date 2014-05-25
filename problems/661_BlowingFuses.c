#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

typedef struct Device {
	bool on;
	unsigned long consumption;
} Device;

int main(int argc, char *argv){
	unsigned long n,m,c;
	int sequence = 0;
	Device * devices;
	while(scanf("%lu %lu %lu\n",&n,&m,&c) != EOF){
		if (n == 0 && m == 0 && c == 0) break;

		sequence++;
		int i, maxConsumption = 0;

		devices = (Device *) malloc(sizeof(Device)* n);
		for (i = 0; i < n; i++){
			unsigned long consumption;
			int trash = scanf("%lu\n",&consumption);
			devices[i].on = FALSE;
			devices[i].consumption = consumption;
		}

		int capacityLeft = c;
		bool blown = FALSE;
		for (i = 0; i < m; i++){
			int deviceIndex;
			int trash = scanf("%d\n",&deviceIndex);
			deviceIndex -= 1;
			if (!blown){
				if (devices[deviceIndex].on) {
					capacityLeft += devices[deviceIndex].consumption;
					devices[deviceIndex].on = FALSE;
				} else {
					capacityLeft -= devices[deviceIndex].consumption;
					devices[deviceIndex].on = TRUE;
					if (capacityLeft < 0){
						blown = TRUE;
					}
				}
				maxConsumption = (maxConsumption < (c - capacityLeft)) ? (c - capacityLeft) : maxConsumption; 
			}
		}

		printf("Sequence %d\n",sequence);
		if (capacityLeft < 0) {
			printf("Fuse was blown.\n");
		} else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n",maxConsumption);
		}
		printf("\n");

		free(devices);
	}
	return 0;
}
