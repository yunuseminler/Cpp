#ifndef BANKA_H
#define BANKA_H

#include "Dosya.h"

struct BANKA{//Banka Yapı tanımlaması
    Dosya dosya;
    Hisse *hisseler;                        //Hisse yapısı dizisi
    Emir *emirler;                          //Emir yapısı dizisi
    Portfoy *portfoyler;                    //Portfoy yapısı dizisi;
    void (*hesapla)();                      //Hesapla fonksiyonunun gösterici tanımlaması
    int (*hisseBul)(struct BANKA*,char*);   //hisseBul fonksiyonunun gösterici tanımlaması
    int (*portfoyBul)(struct BANKA*,char*); //portfoyBul fonksiyonunun gösterici tanımlaması
    void (*portfoyEkranaYaz)(struct BANKA*);//portfoyEkranYaz fonksiyonunun gösterici tanımlaması
    void (*bankaYoket)(struct BANKA*);      //bankaYoket fonksiyonunun gösterici tanımlaması
};
typedef struct BANKA* Banka;

//Fonksiyonların Prototip tanımlamaları.
Banka bankaOlustur();                   
void Hesapla();
int HisseBul(const Banka,char*);
int PortfoyBul(const Banka,char*);
void PortfoyEkranaYaz(const Banka);
void BankaYoket(Banka);
#endif