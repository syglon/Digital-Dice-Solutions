#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_COUNT 1000000
#define HAYSTACK 10

void shuffle(int *array, size_t n);

int main(void){
    srand(time(0));
    int a[HAYSTACK];
    float prob[HAYSTACK];

    for (int j = 0; j < HAYSTACK; j++){    // For Samples
        int count = 0;    
        for (int iterate = 0; iterate < SIMULATION_COUNT; iterate++){
            for (int i = 0; i < HAYSTACK; i++){  // Declaring random array.
                a[i] = (i + 1);
            }
            shuffle(a, HAYSTACK);      
            if (j == 0) {
                if (a[0] == HAYSTACK){
                    count++;
                }
            } else {
                int max_value = a[0];
                for (int t = 1; t < j; t++){
                    if (a[t] > max_value){
                        max_value = a[t];
                }
            }
                for (int o = j; o < HAYSTACK; o++){
                    if (a[o] > max_value){
                        if (a[o] == HAYSTACK){
                            count++;
                        }
                        break;                    
                    }
                }
            } 
        }
        prob[j] = (float)count / (float)SIMULATION_COUNT;
        printf("Probability for j=%d: %.5f\n", j, prob[j]);
    }
    return 0;
}

void shuffle(int *array, size_t n){    //Shuffling function.
    size_t i;
    for (i = 0; i < n - 1; i++){
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}