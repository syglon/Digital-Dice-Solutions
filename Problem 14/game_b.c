#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********************************************************
 * THIS SIMULATION SHOWS THE AVERAGE COUNT OF THE GAMES *
 *   THAT TAKES PLACE TO MAKE A GIVEN INITIAL MONEY 0   *
 ********************************************************/

#define epsilon 0.005
#define STARTING_MONEY 10
#define SIMULATION_COUNT 100000

void coin1(int *capital);
void coin2(int *capital);

int main(void){
    srand(time(0));
    
    int sum = 0;
    for (int i = 0; i < SIMULATION_COUNT; i++){
        int capital = STARTING_MONEY;
        int count = 0;
        while(capital != 0){
            if ((capital % 3) == 0){
                coin1(&capital);
            }else {
                coin2(&capital);
            }
            count++;
            if (capital == 0) break;
        }
    sum += count;
    }
    
    float average = (float)sum/(float)SIMULATION_COUNT;
    printf("%d coins becomes zero in average of %f games.\n", STARTING_MONEY, average);
    return 0;
}

void coin1(int *capital){
    if (((float)rand()/(float)RAND_MAX) < ((0.10)-epsilon)){
        (*capital)++;
    } else {
        (*capital)--;
    }
}

void coin2(int *capital){
    if (((float)rand()/(float)RAND_MAX) < ((0.75)-epsilon)){
        (*capital)++;
    } else {
        (*capital)--;
    }
}