#include <stdio.h>
#include <time.h>
#include <stdlib.h>



float counts(int number) {
    srand(time(NULL));
    int count = 0;
    
    for (int p = 0; p < number; p++){
    int i = 0;
    for (int t = 0; t < 5; t++) {
        int random = (rand() % 5) + 1;
        if (random == 4) i++;  /*4 can be any number between 1 and 5. It represents the "clumsy" dishwasher.*/
        }
    if (i>=4) count++;
    }
    return (float)count/(float)number;
    }

int main(void) {
    printf("%f",counts(1000000));
    return 0;
}