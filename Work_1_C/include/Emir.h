#ifndef EMIR_H
#define EMIR_H

#include "stdlib.h"

struct EMIR{//Emir yapısı tanımlaması
    char* id;
    char* sembol;
    int islem;
    int adet;
    void (*emirYoket)(struct EMIR*);//Fonksiyon göstericisi tanımlaması.
};
typedef struct EMIR* Emir;

//Fonksiyonların Prototip tanımlaması
Emir emirOlustur(char*,char*,int,int);
void EmirYoket(Emir);

#endif