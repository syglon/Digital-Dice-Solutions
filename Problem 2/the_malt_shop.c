#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_COUNT 10000000
#define BILL 7
#define LILY 5

int random_minute(void);

int main(void){
    srand(time(0));
    int count = 0;
    
    for ( int i = 0; i < SIMULATION_COUNT; i++){
        int lily_arrives = random_minute();
        int bill_arrives = random_minute();
        if (lily_arrives < bill_arrives){
            if (bill_arrives <= (lily_arrives + LILY)){
                count++;
            }
        }else if  (bill_arrives < lily_arrives){
            if (lily_arrives <= (bill_arrives + BILL)){
                count++;
            }
        }
    }
    float probability = (float)count/(float)SIMULATION_COUNT;
    printf("They will meet with the probability of %f between 03.30pm and 04.00pm.\n ", probability);
    return 0;
}

int random_minute(void){                /*Returns a random minute in the half-hour period*/
    return ((rand() % 30) + 1);
}