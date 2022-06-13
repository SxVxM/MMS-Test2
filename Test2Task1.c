#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define COUNT 10

typedef int (*comparef_t)(const void*, const void*);

int compareBrandASC(const void*, const void*);
int compareSpeedASC(const void*, const void*);
int comparePriceASC(const void*, const void*);
int compareBrandDESC(const void*, const void*);
int compareSpeedDESC(const void*, const void*);
int comparePriceDESC(const void*, const void*);

int randint(int, int);
double randReal(double, double);
char* randomName(char*);

typedef struct Car{
    char brand[20];
    int speed;
    double price;
} Car;

void printCar(Car c){
    printf("Brand: %25s ", c.brand);
    printf("Speed: %4u ", c.speed);
    printf("Price: %4.2lf\n", c.price);
}

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
        cars[i].speed = randint(100, 300);
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