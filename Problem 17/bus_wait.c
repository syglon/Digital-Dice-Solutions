#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_COUNT 1000000
#define BUS_COUNT 2

void sort_array(float *arr);
float random_float();
float find_difference(float element, float array[]);

int main(void){
    srand(time(0));
    
    float sum = 0.0;

    for (int k = 0; k < SIMULATION_COUNT; k++){
        float a[BUS_COUNT + 1];
        a[0] = 60.0;
        float passenger = random_float()*60;
        
        for (int i = 1; i < BUS_COUNT; i++){
            a[i] = random_float()*60;
        }

        a[BUS_COUNT] = passenger;
        sort_array(a);
        sum += find_difference(passenger, a);
    }
    float average = (float)sum/(float)SIMULATION_COUNT;
    printf("In average the passenger needs to wait %f minutes for the bus.\n", average);
    return 0;
}

float random_float(){
    return ((float)rand() / (float)RAND_MAX);
}

void sort_array(float *arr){
    for (int i = 0; i < BUS_COUNT + 1; i++){
        for (int j = 0; j < BUS_COUNT - i; j++) {
            if (arr[j] > arr[j+1]) {
                float tmp;
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

float find_difference(float element, float array[]){
    for( int i = 0; i < BUS_COUNT + 1; i++){
        if (array[i] == element){
            return (array[i+1] - array[i]);
        }else continue;
    }
}