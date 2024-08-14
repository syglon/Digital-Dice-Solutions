#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIMULATION_COUNT 10000
#define SAMPLE_PERCENTAGE 2

int random_n();
int random_numbers(int N);
int formula(int sample_size, int max_value);
void bubble_sort(int *arr, int n);
float percent_error(int possible_max, int N);

int main(void) {
    srand(time(0));
    FILE *data = fopen("data.csv", "w");
    fprintf(data, "errors(2)\n");

    for (int i = 0; i < SIMULATION_COUNT; i++){
        int N = random_n();
        int sample = round((SAMPLE_PERCENTAGE * N) / 100);
        int arr[sample];

        for (int j = 0; j < sample; j++){
            arr[j] = random_numbers(N);
        }

        bubble_sort(arr, sample);
        int max_value = arr[sample - 1];
        int possible_max = formula(sample, max_value);
        fprintf(data, "%f\n", percent_error(possible_max, N));

    }
    fclose(data);
    printf("Data is successfully written to data.csv\n");
    return 0;
}

int random_n(){
    return (rand() % 900 + 101);
}

int random_numbers(int N){
    return (rand() % N + 1);
}

int formula(int sample_size, int max_value){
    return (int)(((float)(sample_size + 1) / sample_size) * (max_value - 1));;
}

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float percent_error(int possible_max, int N){
    return ((((((float)possible_max - (float)N)) / (float)N)) * 100.0);
}