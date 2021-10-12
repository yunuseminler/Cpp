#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Hisse.h"
#include "Emir.h"
#include "Portfoy.h"


struct DOSYA{//Dosya yapısı tanımlaması
    //Fonksiyon Göstericileri tanımlaması:
    Hisse* (*hisseOku)(struct DOSYA*);
    Emir* (*emirOku)(struct DOSYA*);
    Portfoy* (*portfoyOku)(struct DOSYA*);
    int (*dosyaUzunlukBul)(struct DOSYA*,int);
    char* (*yolDondur)(int);
    char* (*ayikla)(FILE*);
    void (*dosyaYoket)(struct DOSYA*);

};
typedef struct DOSYA* Dosya;

//Fonksiyonların Prototip tanımlaması
Dosya dosyaOlustur();
Hisse* HisseOku(const Dosya);
Emir* EmirOku(const Dosya);
Portfoy* PortfoyOku(const Dosya);
int DosyaUzunlukBul(const Dosya,int);
char* YolDondur(int);
char* Ayikla(FILE*);
void DosyaYoket(Dosya);

#endif