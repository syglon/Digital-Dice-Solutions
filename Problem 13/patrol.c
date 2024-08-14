#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*******************************************************************************
 * A %10 ERROR OCCURS IN THE SIMULATION WHEN SCENARIO IS 3 AND SEPERATION IS 2 *
 *******************************************************************************/

#define SIMULATION_COUNT 1000000
#define SEPERATION 1 /*1 if grass, 2 if concrete*/
#define SCENARIO 2 /*1 if a, 2 if b, 3 if c*/
#define POLICE_COUNT 2

int random_lane(void);
float random_accident(void);
void bubble_sort(float *arr, int n);

int main(void){
    srand(time(0));
    float sum = 0;
    for (int i = 0; i < SIMULATION_COUNT; i++) { 
        int police_lane = random_lane();
        int accident_lane = random_lane();
        float accident = random_accident();
        float y;
        #if (SCENARIO == 1)
            y = 0.5;
        #elif (SCENARIO == 2)
            y = random_accident();
        #endif
        if ((SCENARIO == 1 || SCENARIO == 2) && SEPERATION == 1){
            sum += fabs((accident - y));   
        }
        if ((SCENARIO == 1 || SCENARIO == 2) && SEPERATION == 2){
            if (police_lane == accident_lane){
                if (accident > y){
                    sum += (accident-y);
                }else {
                    sum += (2+ accident-y);
                }
                }else {
                    if (accident > y){
                        sum += (2 - accident - y);
                    }else {
                        sum += (2 - accident - y);
                    }
                }
        }

        if (SCENARIO == 3){
            struct Police {
                int police_lane;
                float police_position;
                float distance;
            };
            struct Police abc[POLICE_COUNT];
            if (SEPERATION == 1){
                for (int b = 0; b < POLICE_COUNT; b++){
                    abc[b].police_lane = random_lane();
                    abc[b].police_position = random_accident();
                    abc[b].distance = fabs(accident - abc[b].police_position);
                }
            }
            if (SEPERATION == 2){
                for (int a = 0; a < POLICE_COUNT; a++){
                    abc[a].police_lane = random_lane();
                    abc[a].police_position = random_accident();
                    if (abc[a].police_lane == accident_lane){
                        if (accident > abc[a].police_position){
                            abc[a].distance = fabs((accident-abc[a].police_position));
                        }else {
                            abc[a].distance = (2+ accident-abc[a].police_position);
                        }
                        }else if (abc[a].police_lane != accident_lane && accident > abc[a].police_position){
                            abc[a].distance = (2 - accident - abc[a].police_position);
                        }else {
                            abc[a].distance = (2 - accident - abc[a].police_position);
                        }
                        }
                
            }
            float arr[POLICE_COUNT];
            for (int k = 0; k < POLICE_COUNT; k++){
                arr[k] = abc[k].distance;
            }
            bubble_sort(arr, POLICE_COUNT);
            sum += arr[0];
            }
    }
    printf ("Average distance to the accident in %d simulations is %f\n", SIMULATION_COUNT, (float)sum/(float)SIMULATION_COUNT);  
    return 0;
}

int random_lane(void){
    return ((rand() % 2) + 1);
}

float random_accident(void){        /*Returns the position of the accident.*/
    return ((float)rand() / (float)RAND_MAX);
}

void bubble_sort(float *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}