#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*****************************************************************************
 * THERE IS A BUG SOMEWHERE BUT THE CODE SEEMS TO WORK FOR LARGE NUMBERS OF N *
 *****************************************************************************/

#define COUNT 1000
#define LENGTH 1.0

void random_generator(float *array);
void sort_array(float *array);
float nearest_distance(float *array, int i);
float mutual_nearest(float *array);
float probability(float *array);

int main(void) {
    float a[COUNT];
    random_generator(a);
    sort_array(a);
    printf("%f\n", probability(a));
    return 0;
}

void random_generator(float *array){
    srand(time(0));
    for (int i = 0; i < COUNT; i++) {
        array[i] = (float)(rand())/(float)RAND_MAX;
}
}

void sort_array(float *array){
    for (int i = 0; i < COUNT - 1; i++){
        for (int j = 0; j < COUNT - i - 1; j++) {
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
    } else if (i == COUNT - 1) {
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
    for (int i = 0; i < COUNT; i++){
        if (nearest_distance(array, i) == nearest_distance(array, i+1)){
            mutual_nearest++;
        }
    }
    return (float)(mutual_nearest*2)/(float)COUNT;
}

float probability(float *array) {
    float sum;
    for (int i = 0; i < 1000000; i++) {
        sum = sum + (float)mutual_nearest(array);
    }
    return (float)sum/(float)1000000;
}


