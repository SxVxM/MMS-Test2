#include "car.h"
#define COUNT 10
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));
    Car cars[COUNT]; 
    int option;
    comparef_t compfunc[] = {
        compareBrandASC,
        compareSpeedASC,
        comparePriceASC,
        compareBrandDESC,
        compareSpeedDESC,
        comparePriceDESC
    };
    for(int i = 0; i < COUNT; i++){
        randomName(cars[i].brand);
        cars[i].speed = randint(100, 255);
        cars[i].price = randReal(1000.0, 100000.0);
    }
    printf("Pick a number from 0 to 5 to sort:\n");
    scanf("%d", &option);
    qsort(cars, COUNT, sizeof(cars[0]), compfunc[option]);

    for(int i = 0; i < COUNT; i++){
        printCar(cars[i]);
    }
    return 0;
}