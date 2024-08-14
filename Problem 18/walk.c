#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_COUNT 100 /*1000 would be better but it creates a mess in the terminal 
and 100 counts is enough to show to increase in the average stoplights.*/

int random_way();

int main(void){
    srand(time(0));
    for (int i = 0; i < 1000; i++){
        float average;
        int count = 0;
        for (int j = 0; j < SIMULATION_COUNT; j++){   
            int west = i, south = i;
            while (south != 0 && west != 0){
                if (random_way() == 0){
                    south--;
                }   else {
                    west--;
                    }
            }
            if (south == 0){
                count += west;
            } else if (west == 0) {
                count += south;
            }
        }
        average = ((float)count/(float)SIMULATION_COUNT)/2;
        printf("%f\n", average);
    }
    return 0;
}

int random_way(){
    return (rand() % 2);    /*0 if south 1 if west*/
}