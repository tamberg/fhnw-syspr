#include <stdio.h>

int main() {
    //float temp_values[3];
    float temp_values[3] = { 20.1, 23, 15.2 };
    printf("%.1f\n", temp_values[1]);
    temp_values[1] =  7.0;
    printf("%.1f\n", temp_values[2]);
}

