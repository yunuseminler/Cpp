#include "Banka.h"

Banka bankaOlustur(){//Banka yapısının kurucu fonksiyonu
    //Banka nesnesi oluşturarak fonksiyon göstericilerine fonksiyonların adresi atanıyor.
    Banka this;
    this = (Banka)malloc(sizeof(struct BANKA));
    this->dosya = dosyaOlustur();
    this->hisseler = this->dosya->hisseOku(this->dosya);
    this->emirler = this->dosya->emirOku(this->dosya);
    this->portfoyler = this->dosya->portfoyOku(this->dosya);
    this->hesapla = &Hesapla;
    this->hisseBul = &HisseBul;
    this->portfoyBul = &PortfoyBul;
    this->portfoyEkranaYaz = &PortfoyEkranaYaz;
    this->bankaYoket = &BankaYoket;
    return this;
}
void Hesapla(Banka banka){//Banka yapısının hesapla fonksiyonu. Bu fonksiyon emirler dizisindeki işlemleri yaparak son durumu ekrana yazdırır.
    int emirUzunluk = banka->dosya->dosyaUzunlukBul(banka->dosya,2);//Emirler dizisinin uzunluğunu buluyor.
    double toplam;
    printf("\nSatışlar Kar/Zarar: \n"); 
    for (int i = 0; i < emirUzunluk; i++)//Emirler dizisinin uzunluğu kadar dönrülüyor.
    {
        int hisseNo = banka->hisseBul(banka,banka->emirler[i]->sembol);//Emirler dizisinin i. elemanının sembolü ile aynı sembola sahip hissenin index numarasını buluyor.
        int portfoyNo = banka->portfoyBul(banka,banka->emirler[i]->sembol);//Emirler dizisinin i. elemanının sembolü ile aynı sembola sahip portfoyun index numarasını buluyor.
        if(banka->emirler[i]->islem==0){//ALIŞ İSE
            double guncelFiyat = (banka->hisseler[hisseNo]->fiyat)*(banka->emirler[i]->adet);//Güncel fiyat bulunuyor
            banka->portfoyler[portfoyNo]->maliyet = ((banka->portfoyler[portfoyNo]->maliyet*banka->portfoyler[portfoyNo]->adet)+(guncelFiyat))/(banka->portfoyler[portfoyNo]->adet+banka->emirler[i]->adet);//Yeni maliyet hesaplanıyor
            banka->portfoyler[portfoyNo]->adet += banka->emirler[i]->adet;//Adet ekleniyor.
        }
        else{//Satış ise
            double guncelFiyat = (banka->hisseler[hisseNo]->fiyat)*(banka->emirler[i]->adet);//Güncel fiyat bulunuyor
            double maliyet = (banka->portfoyler[portfoyNo]->maliyet)*(banka->portfoyler[portfoyNo]->adet);//Maliyet hesaplanıyor.
            printf("%s : %.2lf",banka->hisseler[hisseNo]->sembol,(guncelFiyat-maliyet));
            if(maliyet>guncelFiyat){
                printf(" TL Zarar\n");
            }
            else{
                printf(" TL Kar\n");
            }
            toplam += (maliyet-guncelFiyat);//Toplam kar zarar hesaplanıyor.
            banka->portfoyler[portfoyNo]->adet -= banka->emirler[i]->adet;// Portfoy adedi hesaplanıyor
        }
    }
    printf("Toplam Kar/Zarar: %.1lf TL \n \n", toplam);
    banka->portfoyEkranaYaz(banka);
}

int HisseBul(Banka banka,char* sembol){//Gönderilen sembole sahip hissenin index numarasını döndürüyor.
    int uzunluk = banka->dosya->dosyaUzunlukBul(banka->dosya,0);
    for (int i = 0; i < uzunluk; i++)
    {   
        if(!(strcmp(banka->hisseler[i]->sembol,sembol))){
            return i;
        }
    }
    return (-1);
}
int PortfoyBul(Banka banka,char* sembol){//Gönderilen sembole sahip portfoyün index numarasını döndürüyor.
    int uzunluk = banka->dosya->dosyaUzunlukBul(banka->dosya,1);
    for (int i = 0; i < uzunluk; i++)
    {   
        if(!(strcmp(banka->portfoyler[i]->sembol,sembol))){
            return i;
        }
    }
    return (-1);
}

void PortfoyEkranaYaz(Banka banka){//Portfoy dizisini uygun şekilde ekrana yazdırıyor.
    int uzunluk = banka->dosya->dosyaUzunlukBul(banka->dosya,1);
    printf("Guncel Portföy:\n");
    for (int i = 0; i < uzunluk; i++)
    {
        if(!(banka->portfoyler[i]->adet==0)){
            printf("Hisse: %s \n",banka->portfoyler[i]->sembol);
            printf("Adet: %d \n",banka->portfoyler[i]->adet);
            printf("Maliyet: %.2lf TL\n",banka->portfoyler[i]->maliyet);
            if(!(i==(uzunluk-1))){
            printf("-------------- \n");
            }
        }
    }
    
}
void BankaYoket(Banka banka){//Banka yapısının yıkıcı metodu. İstenilen bellek alanları geri iade ediliyor.
    for (int i = 0; i < 3; i++)
    {
        int uzunluk = banka->dosya->dosyaUzunlukBul(banka->dosya,i);
        for (int j = 0; j < uzunluk; j++)
        {
            if(i == 0){
                banka->hisseler[j]->hisseYoket(banka->hisseler[j]);
            }
            else if(i == 1){
                banka->portfoyler[j]->portfoyYoket(banka->portfoyler[j]);
            }
            else{
                banka->emirler[j]->emirYoket(banka->emirler[j]);
            }
        }
    }
    free(banka->hisseler);
    free(banka->emirler);
    free(banka->portfoyler);
    banka->dosya->dosyaYoket(banka->dosya);
    free(banka);
}