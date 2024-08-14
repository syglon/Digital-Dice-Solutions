#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIMULATION_COUNT 100000
#define CAR_COUNT 5
#define LENGTH 1.0

void random_generator(float *array);
void sort_array(float *array);
float nearest_distance(float *array, int i);
float mutual_nearest(float *array);
float probability(void);

int main(void) {
    srand(time(0));
    printf("The probability of a randomly selected car being one of a nearest neighbor pair equals %f for %d cars.\n", probability(), CAR_COUNT);
    return 0;
}

void random_generator(float *array){
    for (int i = 0; i < CAR_COUNT; i++) {
        array[i] = (float)(rand())/(float)RAND_MAX;
}
}

void sort_array(float *array){
    for (int i = 0; i < CAR_COUNT - 1; i++){
        for (int j = 0; j < CAR_COUNT - i - 1; j++) {
            if (array[j] > array[j+1]) {
                float tmp;
                tmp = array[j+1];
                array[j+1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

float nearest_distance(float *array, int i) {
    float front_distance = 0, back_distance = 0;

    if (i == 0) {
        front_distance = array[i + 1] - array[i];
        return front_distance;
    } else if (i == CAR_COUNT - 1) {
        back_distance = array[i] - array[i - 1];
        return back_distance;
    } else {
        front_distance = array[i + 1] - array[i];
        back_distance = array[i] - array[i - 1];
        return (front_distance < back_distance) ? front_distance : back_distance;
    }
}

float mutual_nearest(float *array) {
    int mutual_nearest = 0;
    for (int i = 0; i < CAR_COUNT; i++){
        if (nearest_distance(array, i) == nearest_distance(array, i+1)){
            mutual_nearest++;
        }
    }
    return (float)(mutual_nearest * 2) / (float)CAR_COUNT;
}

float probability(void) {
    float sum = 0;
    float a[CAR_COUNT];
    for (int i = 0; i < SIMULATION_COUNT; i++) {
        random_generator(a);
        sort_array(a);
        sum = sum + (float)mutual_nearest(a);
    }
    return (float)sum/(float)SIMULATION_COUNT;
}