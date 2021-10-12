#ifndef PORTFOY_H
#define PORTFOY_H

#include "stdlib.h"

struct PORTFOY{//Portfoy Yapısı tanımlaması
    char* id;
    char* sembol;
    double maliyet;
    int adet;
    void(*portfoyYoket)(struct PORTFOY*); //portfoyYoket Fonksiyonunun gösterici tanımlaması.
};
typedef struct PORTFOY* Portfoy;

//Fonksiyonların Prototip tanımlaması
Portfoy portfoyOlustur(char*,char*,double,int);
void PortfoyYoket(Portfoy);

#endif