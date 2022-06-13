#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

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

void printCar(Car);

#endif