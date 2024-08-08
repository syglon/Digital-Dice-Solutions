#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAIN_PROBABILITY 0.01
#define HOME_UMBRELLA 1
#define OFFICE_UMBRELLA 1
#define SIMULATION_COUNT 100000

int raining();
int count_dry(int count);

int main(void){
    srand(time(0));
    float a = 0;
    int count = 0;
    int sum = 0;
    for (int i = 0; i< SIMULATION_COUNT; i++){
        sum += count_dry(count);
    }
    a = ((float)sum/(float)SIMULATION_COUNT);
    printf("%f", a);
    return 0;
    }


int raining(){
    return ((((float)rand()/(float)RAND_MAX) > RAIN_PROBABILITY) ? 1 : 0);
}

int count_dry(int count){
    int X = HOME_UMBRELLA;
    int Y = OFFICE_UMBRELLA;
    for (;;){
        if (X == 0) break;
        if (raining()){
            X--;
            Y++;
            count++;
        }else if (!raining()){
            count++;
        } if (Y == 0) break;
        if (raining()){
            Y--;
            X++;
            count++;
        }else if (!raining()){
            count++;}
            
    }
    return count;  
}