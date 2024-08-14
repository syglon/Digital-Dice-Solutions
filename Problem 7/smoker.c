#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATCH_COUNT 40
#define SIMULATION_COUNT 1000000

int matches(int a, int b);
float average(int a, int b);

int main(void){
    srand(time(0));
    int a = MATCH_COUNT;
    int b = MATCH_COUNT;
    printf("Average match count until one of them is empty: %f\n", average(a,b));
    return 0;
}

int matches(int a, int b){  
    int count = 0;
    while (a != 0 && b != 0){
        int random = (rand() % 2) + 1;
        if (random == 1) b--;
        else if (random == 2) a--;
        count++;     
    }
    return count;
}

float average(int a, int b){
    int sum = 0;
    for (int i = 0; i < SIMULATION_COUNT; i++){
        sum += matches(a,b);
    }
    return (float)sum/(float)SIMULATION_COUNT;
}