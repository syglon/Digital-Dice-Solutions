#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define epsilon 0.005
#define STARTING_MONEY 10
#define BIN_COUNT 50
#define GAMES_PER_BIN 1000

void game2coin1(int *capital);
void game2coin2(int *capital);
void game1(int *capital);
int random_game(void);

int main(void){
    srand(time(0));
    int capital = STARTING_MONEY;
    for (int i = 0; i < BIN_COUNT; i++){
        
        for(int j = 0; j < GAMES_PER_BIN; j++){
            
            if (random_game() == 0){
                game1(&capital);
            }else {
                if ((capital % 3) == 0){
                    game2coin1(&capital);
                }else {
                    game2coin2(&capital);
                }
            }
        }
    printf("%d coins after %d more games.\n", capital, BIN_COUNT);
    }
    return 0;
}

int random_game(void){
    return (rand() % 2);
}

void game1(int *capital){
    if (((float)rand()/(float)RAND_MAX) < ((0.50)-epsilon)){
        (*capital)++;
    } else {
        (*capital)--;
    }
}

void game2coin1(int *capital){
    if (((float)rand()/(float)RAND_MAX) < ((0.10)-epsilon)){
        (*capital)++;
    } else {
        (*capital)--;
    }
}

void game2coin2(int *capital){
    if (((float)rand()/(float)RAND_MAX) < ((0.75)-epsilon)){
        (*capital)++;
    } else {
        (*capital)--;
    }
}