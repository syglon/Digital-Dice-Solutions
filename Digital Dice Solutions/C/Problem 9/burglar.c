#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STEP_COUNT 100

int random_step(void); /*Generates a number between -2 and 2*/
int array_check(int *arr, int location);

int main(void){
    int array[200] = {0, [100] = 1};
    
    for (int i = 0; i < STEP_COUNT; i++){
        int step = random_step();
        int location = 100 + step;
        printf ("%d", array_check(array, location));
        //array_check(array, location, &count);
    }
    return 0;
}

int random_step(void){
    int step = (rand() % 5 - 2);
    return step;
}

int array_check(int *arr, int step){
    int count = 0;
    if (arr[step] == 1) {
        return count;
    } else {
        arr[step] = 1;
        count++;}
        return count;
}