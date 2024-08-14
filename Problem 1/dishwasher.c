#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIMULATION_COUNT 1000000

float counts(int number);

int main(void) {
    srand(time(NULL));
    printf("The probability of the clumsy dishwasher breaking 4 or 5 plates is %f. \n",counts(SIMULATION_COUNT));
    return 0;
}

float counts(int number) {
    int count = 0;
    for (int p = 0; p < number; p++){
        int i = 0;
        for (int t = 0; t < 5; t++) {
            int random = (rand() % 5) + 1;
            if (random == 4) {  /*4 can be any number between 1 and 5. It represents the "clumsy" dishwasher.*/
                i++;
            } 
        }
        if (i>=4) count++;
    }
    return (float)count/(float)number;
}

