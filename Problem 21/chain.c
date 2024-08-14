#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_COUNT 1000000
#define DESIRED_MALES 6 /*Desired males in the second generation.*/
#define GENERATION 3

int random_sons();
int main(void) {
    srand(time(0));
    int count = 0;
    int generation = GENERATION;
    for(int i = 0; i < SIMULATION_COUNT; i++){
        int son_count = random_sons();
        if(son_count == 0){
            continue;
        }
        int second_generation = 0;
        for (int j = 0; j < son_count; j++){
            second_generation += random_sons();
            }

#if (GENERATION == 2)
        if (second_generation == DESIRED_MALES){
        count++;
        }
    }
    
    
#elif (GENERATION == 3)
        int third_generation = 0;
        for (int k = 0; k < second_generation; k++){
            third_generation += random_sons();
        }
        if (third_generation == DESIRED_MALES){
            count++;
        }}
#endif

    float average = (float)count/(float)SIMULATION_COUNT;
    printf("There is %f probability of getting %d male offsprings in %d generations\n", average, DESIRED_MALES, GENERATION);
    return 0;
}

int random_sons(){
    int sons;
    float p_0 = 0.4825;
    float p_1 = 0.2126;
    float p_2 = p_1 * 0.5893;
    float p_3 = p_2 * 0.5893;
    float p_4 = p_3 * 0.5893;
    float p_5 = p_4 * 0.5893;
    float p_6 = p_5 * 0.5893;

    float random = ((float)rand() / (float)RAND_MAX);

    if (random < p_0) {
        sons = 0;
    } else if (random < p_0 + p_1){
        sons = 1;
    } else if (random < p_0 + p_1 + p_2){
        sons = 2;
    } else if (random < p_0 + p_1 + p_2 + p_3){
        sons = 3;
    } else if (random < p_0 + p_1 + p_2 + p_3 + p_4){
        sons = 4;
    } else if (random < p_0 + p_1 + p_2 + p_3 + p_4 + p_5){
        sons = 5;
    } else if (random < p_0 + p_1 + p_2 + p_3 + p_4 + p_5 + p_6){
        sons = 6;
    } else {
        sons = 7;
    }
    return sons;
}