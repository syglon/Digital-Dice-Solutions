#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************************************************************
 * FOR THE SECOND PART OF THE QUESTION, FUNCTION IN THE 20TH LINE NEEDS TO BE *
 *        CHANGED WITH JUDGE_A AND 24TH LINE NEEDS TO BE COMMENTED OUT        *
 ******************************************************************************/

#define SIMULATION_COUNT 1000000

void judge(float probability, int *count);
void judge_A(float probability, int *count);

int main(void){
    srand(time(0));
    int sum = 0;
    for(int i = 0; i < SIMULATION_COUNT; i++){
        int count = 0;
        judge(0.95, &count);
        judge(0.95, &count);                
        judge(0.90, &count);                   
        judge(0.90, &count);
        judge(0.80, &count); 
        if (count >= 3){
            sum++;
        }

    }
    float average = (float)sum/(float)SIMULATION_COUNT;
    printf("Average: %c%f\n", 37, 100 * average);
    return 0;
}

void judge(float probability, int *count){
    if (((float)rand()/(float)RAND_MAX)>probability) (*count)++;
}

void judge_A(float probability, int *count){
    if (((float)rand()/(float)RAND_MAX)>probability) ((*count) = (*count) + 2);
}