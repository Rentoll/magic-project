#include <string.h>
#include <time.h>
#include <stdio.h>
#include "nameGenerator.h"


void generateName(char *first) {
    srand(time(NULL));
    int nameSize;
    char buffName;
    char soglasnieMass[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    char glasnieMass[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int glasn, soglasn, buf;
    int glasnSize = 6, soglasnSize = 21;
    nameSize = 3 + rand()%10;
    if((rand()%10)%2 == 0){
        buf = rand()%glasnSize;
        *(first) = glasnieMass[buf] - 32;
    }
    else {
        buf = rand()%soglasnSize;
        *(first) = soglasnieMass[buf] - 32;
    }
    for(int j = 0; j < nameSize - 1; j++) {
        if(j%2 != 0) {
            buf = rand()%glasnSize;
            *(first + j) = glasnieMass[buf];
        }
        else {
            buf = rand()%soglasnSize;
            *(first + j) = soglasnieMass[buf];
        }
    }
}



