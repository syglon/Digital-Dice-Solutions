#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RIDER_COUNT 1  /*Steve is not included to the count.*/
#define FLOOR_COUNT 11
#define SIMULATION_COUNT 1000000

int arr_check(int *arr, int stop);
int random_number(void);

int main(void){
    srand(time(0));
    int total_stops = 0;
    for (int i = 0; i < SIMULATION_COUNT; i++){
    int stops = 1;
    int arr[FLOOR_COUNT] = {0};
        for (int j = 0; j<RIDER_COUNT; j++){
            int random = random_number();
            if (random < 9 && arr_check(arr, random)){
                stops++;
            }
        }
        total_stops += stops;
    }
    float average = (float)total_stops/(float)SIMULATION_COUNT;
    printf("Average number of stops: %f\n", average);
    return 0;
}

int random_number(void){
    return (rand() % 11) + 1;
}

int arr_check(int *arr, int stop){
    if (arr[stop -1] == 0){
        arr[stop - 1] = 1;
        return 1;
    } else if (arr[stop -1] == 1){
        return 0;
    }
}
