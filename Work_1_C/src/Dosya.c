#include "Dosya.h"

Dosya dosyaOlustur(){//Dosya yapısın yapıcı metodu. Gerekli atamalar yapılıyor.
    Dosya this;
    this = (Dosya)malloc(sizeof(struct DOSYA));
    this->dosyaUzunlukBul = &DosyaUzunlukBul;
    this->yolDondur = &YolDondur;
    this->ayikla = &Ayikla;
    this->hisseOku = &HisseOku;
    this->emirOku = &EmirOku;
    this->portfoyOku = &PortfoyOku;
    this->dosyaYoket = &DosyaYoket;
    return this;
}

int DosyaUzunlukBul(Dosya d,int index){//Gönderilen index numarasına göre dosyanın içinde kaç adet veri olduğunu döndüren fonksiyon.
    char *yol = d->yolDondur(index);
    FILE *dosya = fopen(yol,"r");
    int satirSayisi = 0;
    char sonraki;
    while (!feof(dosya))
    {
        char a;
        a=fgetc(dosya);
        if(a=='\n')
        {
            satirSayisi++;
            sonraki=fgetc(dosya);
        }
    }
    if(sonraki!=EOF){
        satirSayisi++;
    }
    fclose(dosya);
    return (satirSayisi-2);  
}
char* YolDondur(int index){//Gönderilen index numarasına göre dosya yolunu döndüren fonksiyon.
    char* yol;
    switch (index)
    {
    case 0:
        yol = "./doc/hisseler.json";
        break;
    case 1:
        yol = "./doc/portfoy.json";
        break;
    case 2:
        yol = "./doc/emirler.json";
        break;
    default:
        break;
    }
    return yol;
}
char* Ayikla(FILE* dosya){//Gönderilen FILE yapısının imlecin kaldığı yerden devam ederek "" arasındaki değeri ayıklayarak geri döndürüyor.
    char a;
    char* temp=malloc(sizeof(char)*50);
    int index = 0;
    while(!(a == '\"')){
        a = fgetc(dosya);
    }
    a = fgetc(dosya);
    while(!(a == '\"')){
        temp[index] = a;
        a = fgetc(dosya);
        index++;
    }
    return temp;
}
Hisse* HisseOku(Dosya d){//Hisseler.json dosyasındaki verileri tek tek okuyarak hisseler dizisine atıyor daha sonra hisseler dizisini Banka yapısındaki hisseler dizisine döndürüyor.
    int uzunluk = d->dosyaUzunlukBul(d,0);
    char* yol = d->yolDondur(0);
    Hisse *hisseler = malloc(sizeof(Hisse)*uzunluk);
    FILE *dosya = fopen(yol,"r");
    while (!feof(dosya)){   //Dosyanın sonuna kadar okuyor.
        char* id;
        char* sembol;
        char* ad;
        double fiyat;
        char a;
        a = fgetc(dosya);
        if(a=='\n'){//ilk satırın sonunda gelince içeri giriyor.
            for (int i = 0; i < uzunluk; i++){//Dosyanın veri sayısı kadar dönüyor.
                int index = 0;
                while (!feof(dosya)){//Tekrar dosyanın sonuna kadar okuyor.
                    a = fgetc(dosya);
                    if(a==':'){//ilk : ya gelince ayikla fonksiyonunu çağırıp "" arasındaki id değerini alıyor.
                        if(index == 0){
                            id = d->ayikla(dosya);
                        }
                        else if(index ==1){ //ikinci : ya gelince ayikla fonksiyonunu çağırıp "" arasındaki sembol değerini alıyor.
                            sembol = d->ayikla(dosya);
                        }
                        else if(index == 2){//ücüncü : ya gelince ayikla fonksiyonunu çağırıp "" arasındaki ad değerini alıyor.
                            ad = d->ayikla(dosya);
                        }
                        else{//son : ya gelince ayikla fonksiyonunu çağırıp fiyat değerini alıyor ve dizinin index numarasına sahip elemanına atıyor.
                            a = fgetc(dosya);
                            fscanf(dosya,"%lf",&fiyat);
                            hisseler[i] = hisseOlustur(id,sembol,ad,fiyat);
                            break;
                        }
                        index++;
                    }
                }
            }
        }
    }
    fclose(dosya);
    return hisseler;
}
Emir* EmirOku(Dosya d){//Emirler.json dosyasındaki verileri tek tek okuyarak emirler dizisine atıyor daha sonra emirler dizisini Banka yapısındaki emirler dizisine döndürüyor.
    int uzunluk = d->dosyaUzunlukBul(d,2);
    char* yol = d->yolDondur(2);
    Emir *emirler = malloc(sizeof(struct EMIR)*uzunluk);
    FILE *dosya = fopen(yol,"r");
    while (!feof(dosya)){    //Dosyanın sonuna kadar okuyor.
        char* id;
        char* sembol;
        char* temp;
        int adet;
        int islem;
        char a;
        a = fgetc(dosya);
        if(a=='\n'){
            for (int i = 0; i < uzunluk; i++){//Dosyadaki veri sayısı kadar döndürüyor.
                int index = 0;
                while (!feof(dosya)){ //Dosyanın sonuna kadar okuyor.
                    a = fgetc(dosya);
                    if(a==':'){
                        if(index == 0){//ilk : ya gelince ayikla fonksiyonunu çağırıp "" arasındaki id değerini alıyor.
                            id = d->ayikla(dosya);
                        }
                        else if(index ==1){//ikinci : ya gelince ayikla fonksiyonunu çağırıp "" arasındaki sembol değerini alıyor.
                            sembol = d->ayikla(dosya);
                        }
                        else if(index == 2){//Üçüncü : ya gelince ayikla fonksiyonunu çağırıp islem değerini okuyor. 0 ve 1 olarak kodluyor.
                            temp = d->ayikla(dosya);
                            if(strcmp(temp,"SATIS")){
                                islem = 0;
                            }
                            else{
                                islem = 1;
                            }
                        }
                        else{//dördüncü : ya gelince adet sayısını okuyor .
                            a = fgetc(dosya);
                            fscanf(dosya,"%d",&adet);
                            emirler[i] = emirOlustur(id,sembol,islem,adet);
                            break;
                        }
                        index++;
                    }
                }
            }
        }
    }
    fclose(dosya);
    return emirler;
}
Portfoy* PortfoyOku(Dosya d){//Portfoy.json dosyasındaki verileri tek tek okuyarak portfoy dizisine atıyor daha sonra portfoy dizisini Banka yapısındaki portfoyler dizisine döndürüyor.
    int uzunluk = d->dosyaUzunlukBul(d,1);
    char* yol = d->yolDondur(1);
    Portfoy *portfoyler = malloc(sizeof(Portfoy)*uzunluk);
    FILE *dosya = fopen(yol,"r");
    while (!feof(dosya)){   //Dosyanın sonuna kadar okuyor.
        char* id;
        char* sembol;
        char* ad;
        double maliyet;
        int fiyat;
        char a;
        a = fgetc(dosya);
        if(a=='\n'){
            for (int i = 0; i < uzunluk; i++){//Dosyadaki veri sayısı kadar döndürüypr.
                int index = 0;
                while (!feof(dosya)){//Dosyanın sonuna kadar okuyor.
                    a = fgetc(dosya);
                    if(a==':'){
                        if(index == 0){//ilk : ya gelince ayikla fonksiyonunu çağırıp "" arasındaki id değerini alıyor.
                            id = d->ayikla(dosya);
                        }
                        else if(index ==1){//ikinci : ya gelince ayikla fonksiyonunu çağırıp "" arasındaki sembol değerini alıyor.
                            sembol = d->ayikla(dosya);
                        }
                        else if(index == 2){//üçüncü : ya gelince maliyet değerini alıyor.
                            a = fgetc(dosya);
                            fscanf(dosya,"%lf",&maliyet);
                        }
                        else{
                            a = fgetc(dosya);//dördüncü : ya gelince fiyat değerini alıyor.
                            fscanf(dosya,"%d",&fiyat);
                            portfoyler[i] = portfoyOlustur(id,sembol,maliyet,fiyat);
                            break;
                        }
                        index++;
                    }
                }
            }
        }
    }
    fclose(dosya);
    return portfoyler;
}

void DosyaYoket(Dosya d){//Dosya yapısının yıkıcı fonksiyonu.Alınan alanları geri iade ediyor.
    if(d == NULL) return;
    free(d);
}
