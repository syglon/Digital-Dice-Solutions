#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N_VALUE 25
#define VOTE_FOR_THEMSELVES 1   /*1 if the voters can vote for themselves and 0 for not.*/
#define SUBSET_OF_N 3 /*Subset of N, 0 for all the voters.*/      
#define SIMULATION_COUNT 1000000

int random_vote();

int main(void){
    srand(time(0));
    int count = 0;
    int N = N_VALUE;
    int M = (int)round(((double)N * ((double)2/(double)3)));

    for (int j = 0; j <SIMULATION_COUNT; j++){
        int array[N_VALUE] = {0};
        for (int i = 0; i < N; i++){ 
            int random = random_vote();
            if (!VOTE_FOR_THEMSELVES){
                for(;;){
                    if(random_vote() == i){
                        random_vote();
                    }else break;
                }
            }
            array[random]++;
            if (array[random] >= M){
                count++;
                break;
            }
        }
    }
    printf("With probability of %f\n", (float)count/(float)SIMULATION_COUNT);
    return 0;
}

int random_vote(){
#if (SUBSET_OF_N == 0)
    int random = (rand() % N_VALUE) + 1;
#else 
    int random = (rand() % SUBSET_OF_N) + 1;
#endif
    return random;
}