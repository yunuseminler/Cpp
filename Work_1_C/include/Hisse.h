#ifndef HISSE_H
#define HISSE_H

#include "stdlib.h"

struct HISSE{//Hisse Yapısı tanımlaması
    char* id;
    char* sembol;
    char* ad;
    double fiyat;
    void (*hisseYoket)(struct HISSE*); //Fonksiyon göstericisi tanımlaması.
};
typedef struct HISSE* Hisse;

//Fonksiyonların Prototip tanımlaması
Hisse hisseOlustur(char*,char*,char*,double);
void HisseYoket(Hisse);

#endif