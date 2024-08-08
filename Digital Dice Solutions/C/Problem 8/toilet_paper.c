#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_step(void); /*Generates a number between -2 and 2*/
int array_update(int step, int *arr);
int current_loc(int step, int loc);
int array_check(int *arr, int element_count, int loc);

int main(void){
    srand(time(0));
    int array[200] = {0};
    int element_count = sizeof(array)/sizeof(array[0]);
    printf("%d", array_check(array, element_count, 100));
    return 0;
}

int random_step(void){
    int step = (rand() % 5 - 2);
    return step;
}

int array_check(int *arr, int element_count, int loc){
    int count = 0;
    while (1){
    int step = random_step();
    loc = current_loc(step, loc);
    for (int i = 0; i < element_count; i++){
        if (arr[i] == loc){
            return count;
        } else count++;
    }
}
}

int current_loc(int step, int loc){
    loc += step;
    return loc;
}