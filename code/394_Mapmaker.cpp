#include <iostream>
#include <cstdio>

typedef struct ArrayDimension {
    unsigned long lowerBound;
    unsigned long upperBound;
} ArrayDimension;

typedef struct Array {
    char name[10];
    unsigned long baseAddress;
    unsigned long size;
    int dimensionCount;
    ArrayDimension * dimensions;
} Array;

void initArrays(Array * arrays, int N){
    int i,j,trash;
    for (i = 0; i < N; i++){
        bool newLineConsummed = getArrayName(arrays[i].name);
        trash = scanf("%lu %lu %d ",&(arrays[i].baseAddress),&(arrays[i].size),&(arrays[i].dimensionCount));
        arrays[i].dimensions = (ArrayDimension*) malloc(sizeof(ArrayDimension)*arrays[i].dimensionCount);
        for (j = 0; j < arrays[i].dimensionCount; j++){
            trash = scanf("%lu %lu",&(arrays[i].dimensions[j].lowerBound),&(arrays[i].dimensions[j].upperBound));
        }
        if (!newLineConsummed) flushInput();
    }
}

int main(){
    int N, R;
    
    int n = scanf("%d %d\n",&N,&R);

    Array* arrays = (Array *) malloc(sizeof(Array)*N);

    initArrays(arrays,N);


    /*char buf[1000];
    int n, t = 0, curr_t;
    int hh, mm, ss, curr_speed = 0, new_speed;
    double distance = 0;
    while (std::cin.getline(buf, sizeof(buf))){
        n = sscanf(buf, "%d:%d:%d %d", &hh, &mm, &ss, &new_speed);
        curr_t = hh * 3600 + mm * 60 + ss;
        distance += (curr_t - t) * curr_speed;
        t = curr_t;
        if (n == 3)
            printf("%02d:%02d:%02d %.2lf km\n", hh, mm, ss, distance/3600);
        else if (n == 4)
            curr_speed = new_speed;
    }*/
    return 0;
}