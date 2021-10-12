#include "stdio.h"
#include "stdlib.h"

#include "Banka.h"

int main(){//Main fonksyonunda Banka yapısından nesne oluşturuluyor ve programın işleyişi için gerekli fonksiyonlar çağrılıyor.
    Banka banka = bankaOlustur();
    banka->hesapla(banka);
    banka->bankaYoket(banka);
    return 0;
}