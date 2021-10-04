/**
* @file Dosya.h
* @description Dosya.cpp kaynak kodlarının başlık dosyası,tanımlamalar yapılıyor.
* @course 2. Ogretim C grubu 
* @assignment 1
* @date ‎24 ‎Kasım ‎2020 ‎Salı
*/

#ifndef DOSYA_H
#define DOSYA_H
#include "Node.h"

class Dosya{
    public:
    Node* ortancalar;
    void dosyaOku();
    void satirlariOku();
    void caprazla();
    void ekranaYaz(Node*,int);
    void dugumBagla(Node*,int);
    Node* kucukBul();
    Node* buyukBul();
    int elemanHesapla(std::string);
    int satirHesapla();
    int pozitifmi(int);
};

#endif