#include "Portfoy.h"

Portfoy portfoyOlustur(char id[],char sembol[],double maliyet,int adet){//portfoy yapısının yapıcı fonksiyonu. gerekli atamalar yapılıyor.
    Portfoy this;
    this = (Portfoy)malloc(sizeof(struct PORTFOY));
    this->id = id;
    this->sembol = sembol;
    this->maliyet = maliyet;
    this->adet = adet;
    this->portfoyYoket = &PortfoyYoket;
    return this;
}
//potföy yapısının yıkıcı fonksiyonu. alınan alanlar iade ediliyor.
void PortfoyYoket(Portfoy this){
    if(this == NULL) return;
    free(this);
}

