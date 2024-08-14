#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATION_COUNT 1000000
#define ELEVATOR_COUNT 2

float random_height();
int random_direction();
void sort_array(float *arr, int *indices);

int main(void){
    srand(time(0));
    struct Elevator {
        float height;
        float distance_gamow;
        int direction;             /*1 if up and 0 if down.*/
        int arrival_direction;     /*again 1 if upwards and 0 if downwards.*/
    };
    
    struct Elevator arr[ELEVATOR_COUNT];
    float gamows_height = 0.166667;           /*float equals 1/6 which is Gamow's height from the ground.*/
    float distances[ELEVATOR_COUNT];
    int indices[ELEVATOR_COUNT];
    int count = 0;

    for (int i = 0; i < SIMULATION_COUNT; i++){
        for (int j = 0; j<ELEVATOR_COUNT; j++){
            arr[j].height = random_height();
            arr[j].direction = random_direction();
            if (arr[j].height < gamows_height){     
                if (arr[j].direction == 1){
                    arr[j].distance_gamow = gamows_height - arr[j].height;
                    arr[j].arrival_direction = 1;
                } else {
                    arr[j].distance_gamow = gamows_height + arr[j].height;
                    arr[j].arrival_direction = 1;
                }
            }else if (arr[j].height > gamows_height) {
                if(arr[j].direction == 0){
                   arr[j].distance_gamow = arr[j].height - gamows_height;
                   arr[j].arrival_direction = 0; 
                } else {
                    arr[j].distance_gamow = 1.83 - arr[j].height;
                    arr[j].arrival_direction = 0;
                }
            }
            distances[j] = arr[j].distance_gamow;
            indices[j] = j;
        }

        sort_array(distances, indices);
        int closest_index = indices[0];

        int closest_arrival_direction = arr[closest_index].arrival_direction;
        if (closest_arrival_direction == 0){
            count++;
        }

    }
    float probability = ((float)count/(float)SIMULATION_COUNT);
    printf("The probability of the first coming elevator which goes downwards is %f\n", probability);
    return 0;
}

float random_height(){
    return ((float)rand() / RAND_MAX);
}

int random_direction(){
    return ((rand() % 2));
}

void sort_array(float *arr, int *indices){
    for (int i = 0; i < ELEVATOR_COUNT - 1; i++){
        for (int j = 0; j < ELEVATOR_COUNT - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                float tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;

                int tmp_index = indices[j];
                indices[j] = indices[j+1];
                indices[j+1] = tmp_index;
            }
        } 
    }
}