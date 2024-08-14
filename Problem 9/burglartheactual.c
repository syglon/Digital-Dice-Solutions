#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_COUNT 10000000
#define K_TH_STEP 7

int array_check(int *arr, int n);
void array_update(int *arr, int n);
int random_step(void);

int main(void){
    srand(time(0));
    int counts[K_TH_STEP] = {0};
    int count = 0;
    int steps;
    
    for (int i = 0; i < SIMULATION_COUNT; i++){
        int abc = 1;
        int position = 100;
        int a[200] = {0};
        a[100] = 1;
        steps = 0;

        while (abc){
            steps++;
            position = position + random_step();
            if (array_check(a,position)){
                abc = 0;
                if (steps <= K_TH_STEP){
                    counts[steps - 1]++;
                }
                }else {
                array_update(a, position);
            }
        }
    }
    for (int i = 1; i <= K_TH_STEP; i++) {
        float probability = (float)counts[i - 1] / (float)SIMULATION_COUNT;
        printf("Probability of revisiting at step %d: %f\n", i, probability);
    }
    return 0;
}

int random_step(void){
    int step_options[4] = {-2, -1, 1, 2};
    return step_options[rand() % 4];
}

void array_update(int *arr, int n){
    arr[n] = 1;
}

int array_check(int *arr, int n){
    return arr[n];
}