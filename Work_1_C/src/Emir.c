#include "Emir.h"

Emir emirOlustur(char id[],char sembol[],int islem,int adet){//Emir yapısının yapıcı fonksiyonu. gerekli atamalar yapılıyor.
    Emir this;
    this = (Emir)malloc(sizeof(struct EMIR));
    this->id = id;
    this->sembol = sembol;
    this->islem = islem;
    this->adet = adet;
    this->emirYoket = &EmirYoket;
    return this;
}
//Emir yapısının yıkıcı fonksiyonu. alınan alanlar iade ediliyor.
void EmirYoket(Emir this){
    if(this == NULL) return;
    free(this);
}