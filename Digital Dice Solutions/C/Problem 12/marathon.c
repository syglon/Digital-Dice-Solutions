#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_n();

int main(void) {
    srand(time(0));
    printf("%d", random_n());
    return 0;
}



int random_n(){
    return (rand() % 900 + 101);
}