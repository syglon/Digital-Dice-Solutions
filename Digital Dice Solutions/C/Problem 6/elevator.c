#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RIDER_COUNT 3
#define FLOOR_COUNT 11
#define SIMULATION_COUNT 1000000

/**************************************************
 *  WORKS FINE IF RIDER COUNT IS 2 BUT AN ERROR   *
 * OCCURS AND INCREASES STARTING FROM RIDER COUNT *
 *                    EQUALS 3                    *
 **************************************************/

int stop_countt(void);
float monte_carlo(void);

int main(void){
    srand(time(0));
    printf("Average number of stops: %f\n", monte_carlo());
    return 0;
}

int stop_countt(void){
    int stops = 1;
    for (int i = 1; i < RIDER_COUNT; i++){
        
        int random_number = (int)(rand() % 11 + 1);
        if (random_number < 9){
            stops++;
        } else continue;
    
}
return stops;
}

float monte_carlo(void){
    int sum = 0;
    for (int i = 0; i < SIMULATION_COUNT; i++){
        sum += stop_countt();
    }
    return (float)sum/(float)SIMULATION_COUNT;
}