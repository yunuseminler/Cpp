/**
* @file main.cpp
* @description Dosya sınıfından eleman oluşturarak programın işlemesi için gerekli fonksiyonları çağırıyor
* @course 2. Ogretim C grubu 
* @assignment 1
* @date ‎23 ‎Kasım ‎2020 Pazartesi
*/

#include <iostream>
#include "Dosya.h"

using namespace std;

int main(){
    Dosya kayitlar;
    kayitlar.dosyaOku();
    kayitlar.caprazla();
    return 0;
}