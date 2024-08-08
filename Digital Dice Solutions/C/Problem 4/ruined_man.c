#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*********************************************************************
 * PARAMETERS OF L, M, N AND P CAN BE ADJUSTED FROM THE MACROS BELOW *
 *********************************************************************/

#define L_VALUE 1
#define M_VALUE 2
#define N_VALUE 3
#define COUNT 1000000
#define HEADS_PROBABILITY 0.5

void coin_flip(int *Man_1, int *Man_2, int *Man_3);
int compare(int Man_1, int Man_2, int Man_3);
float monte_carlo(int Man_1, int Man_2, int Man_3);
float random_float();

int main(void){
    srand(time(0));
    int Man_1, Man_2, Man_3;
    
    float sum = 0;
    printf("Average: %f\n", monte_carlo(Man_1, Man_2, Man_3));
    return 0;
}


void coin_flip(int *Man_1, int *Man_2, int *Man_3){  /*Heads or tails generator including the heads probability.*/
    *Man_1 = ((random_float() > HEADS_PROBABILITY) ? 1 : 2);
    *Man_2 = ((random_float() > HEADS_PROBABILITY) ? 1 : 2);
    *Man_3 = ((random_float() > HEADS_PROBABILITY) ? 1 : 2);
}

int compare(int Man_1, int Man_2, int Man_3){
    int count = 0;
    int L = L_VALUE, M = M_VALUE, N = N_VALUE;
    while (L > 0 && M > 0 && N > 0) {
        coin_flip(&Man_1, &Man_2, &Man_3);
    if (Man_1 == Man_2 && Man_1 != Man_3){
        L--;
        M--;
        N += 2;
    }
    else if (Man_2 == Man_3 && Man_2 != Man_1){
        N--;
        M--;
        L += 2;
    }
    else if (Man_1 == Man_3 && Man_1 != Man_2){
        L--;
        N--;
        M += 2;
    }
    count++;
    }
    return count;
}

float monte_carlo(int Man_1, int Man_2, int Man_3){
    float sum = 0;
    
    for (int i = 0; i < COUNT; i++) {
        sum += (float)compare(Man_1, Man_2, Man_3);
    }
    return (float)sum/(float)COUNT;
}

float random_float(){
    return (float)rand()/(float)RAND_MAX;
}