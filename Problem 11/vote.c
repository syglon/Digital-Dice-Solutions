#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*%2.5 error caused by not treating the senators individually, going to be fixed in further commits*/

#define AGAINST_VOTES 49
#define ABSENT 5
#define SIMULATION_COUNT 1000000

int random_number();

int main(void){
    srand(time(0));
    int sum = 0;
    for (int i = 0; i < SIMULATION_COUNT; i++){
        int A = AGAINST_VOTES;
        int M = ABSENT;
        int F = 100 - AGAINST_VOTES; /*For votes*/
        for (int j = 0; j < ABSENT; j++){
            if (random_number() == 0){
                A--;
            } else {
                F--;
            }
        }
        if (A > F){
            sum++;
        }
    } 
    float average = (float)sum/(float)SIMULATION_COUNT;
    printf("Average probability: %f\n", (average));
    return 0;
}

int random_number(){
    return rand() % 2;
}