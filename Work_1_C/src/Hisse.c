#include "Hisse.h"

Hisse hisseOlustur(char id[],char sembol[],char ad[],double fiyat){//Hisse yapısının yapıcı fonksiyonu. gerekli atamalar yapılıyor.
    Hisse this;
    this = (Hisse)malloc(sizeof(struct HISSE));
    this->id = id;
    this->sembol = sembol;
    this->ad = ad;
    this->fiyat = fiyat;
    this->hisseYoket = &HisseYoket;
    return this;
}
//Hisse yapısının yıkıcı fonksiyonu. alınan alanlar geri iade ediliyor.
void HisseYoket(Hisse this){
    if(this == NULL) return;
    free(this);
}