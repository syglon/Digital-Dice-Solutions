#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 24


int count = 0;

float counts(int number_of_simulation) {
    srand(time(0));
    for (int p = 0; p < number_of_simulation; p++) {
    int a[N], b[N];

    for (int i = 0; i < 24; i++) { /*Array of 1-24*/
        a[i] = i + 1;
    }

    for (int j = 0; j < 24; j++) { /*Random number array*/
        b[j] = (rand() % 24) + 1;
    }

    for (int k = 0; k < 24; k++) {   /*Comparison of indexes in both arrays*/
        if (a[k] == b[k]) count++;
    }
    }
    return (float)count/(float)number_of_simulation; /*Average number of correct guesses.*/
}


int main(void) {
    /*printf("Average correct guesses in 100 simulations. %f\n", counts(100));
    printf("Average correct guesses in 100 thousand simulations. %f\n", counts(100000));
    printf("Average correct guesses in 10 million simulations. %f\n", counts(10000000));*/
    printf("Average correct guesses in 100 million simulations. %f\n", counts(100000000));
    return 0;
}