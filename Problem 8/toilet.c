#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUMBER_IN_ROLL 200
#define BIG_CHOOSER 0.5
#define SIMULATION_COUNT 100000

int random_number(void);
int random_person(void);

int main(void){
    srand(time(0));

    int sum = 0;
    for (int i = 0; i < SIMULATION_COUNT; i++){
        int roll1 = NUMBER_IN_ROLL;
        int roll2 = NUMBER_IN_ROLL;
        while(roll1 > 0 && roll2 > 0){
            if (random_person()){
                if (roll1 > roll2){
                    roll1--;
                }else if (roll2 > roll1) {
                    roll2--;
                }else{
                    int number = random_number();
                    if (number == 0) roll1--;
                    else roll2--;
                }
            } else {
                if (roll1 < roll2){
                    roll1--;
                }else if (roll2 < roll1) {
                    roll2--;
                }else{
                    int number = random_number();
                    if (number == 0) roll1--;
                    else roll2--;
            }
            }
             
        }
      sum += abs(roll1 - roll2);  
    }
    float average = (float)sum/(float)SIMULATION_COUNT;
    printf("In average %f toilet paper is left.\n", average);
    return 0;
}

int random_person(void){
    return ((((float)rand() / (float)RAND_MAX) < BIG_CHOOSER) ? 1 : 0);
}

int random_number(void){
    return rand() % 2;
}