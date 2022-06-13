#include "car.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

void printCar(Car c){
    printf("Brand: %25s ", c.brand);
    printf("Speed: %4u ", c.speed);
    printf("Price: %4.2lf\n", c.price);
}
int randint(int min, int max){
    return min + rand() % (max - min + 1);
}
double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
char* randomName(char* name){
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(4, 10);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}
int compareBrandASC(const void* c1, const void* c2){
    Car* car1 = (Car*)c1;
    Car* car2 = (Car*)c2;
    return strcmp(car1->brand, car2->brand);
}

int compareSpeedASC(const void* c1, const void* c2){
    Car* car1 = (Car*)c1;
    Car* car2 = (Car*)c2;
    return car1->speed - car2->speed;
}
int comparePriceASC(const void* c1, const void* c2){
    Car* car1 = (Car*)c1;
    Car* car2 = (Car*)c2;
    if(fabs(car1->price - car2->price) < 0.0001){
        return 0;
    }
    else if(car1 -> price > car2->price){
        return 1;
    }
    return -1;
}
int compareBrandDESC(const void* c1, const void* c2){
    Car* car1 = (Car*)c1;
    Car* car2 = (Car*)c2;
    return strcmp(car2->brand, car1->brand);
}

int compareSpeedDESC(const void* c1, const void* c2){
    Car* car1 = (Car*)c1;
    Car* car2 = (Car*)c2;
    return car2->speed - car1->speed;
}
int comparePriceDESC(const void* c1, const void* c2){
    Car* car1 = (Car*)c1;
    Car* car2 = (Car*)c2;
    if(fabs(car1->price - car2->price) < 0.0001){
        return 0;
    }
    else if(car1->price < car2->price){
        return 1;
    }
    return -1;
}