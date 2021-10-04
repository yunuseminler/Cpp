/****************************************************************************
**
**				OGRENCI ADI.................: Yunus Emre Eminler
**				OGRENCI NUMARASI............: g191210046
**				DERS GRUBU..................: 2.Ogretim B grubu
****************************************************************************/

#include <iostream>
#include <Stdlib.h>
#include <fstream> //Dosya islemleri icin gerekli kutuphane 
#include <iomanip> //Setw manipulatoru icin gerekli kutuphane
#include <Windows.h> //koordinatAta fonksiyonu icin gerekli kutuphane
#include <ctime> //srand fonksiyonu icin gerekli kutuphane


using namespace std;

char solUstKose = 201;
char duz = 205;
char sagUstKose = 187;
char solAltKose = 200;
char sagAltKose = 188;
char dikey = 186;
void koordinatAta(int x, int y)//Kursoru verilen x y degerlerine goturuyor.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ustYazdir(int elemanSayisi)//kutunun ust kismini yazdiriyor.
{

	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagUstKose;
} 
void altYazdir(int elemanSayisi) //Kutunun alt kismini yazdiriyor.
{
	cout << solAltKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagAltKose;
}


class Ogrenci {
private:
	string ad;
	string soyad;
	int numara;
public:
	void ogrencirastgele() {//Ogrenci adini ,soyadini ve numarasini rastgele atiyor.
		srand(time(0));
		 ifstream dosya;		
		 dosya.open("isimler.txt");
		 string isim;

		 int b;
		 b = rand() % 4945 + 1;
		 for (int i = 0; i < b; i++) { //Random degisken kadar deger okunuyor
			 dosya >> isim;
		 }
		 ad = isim;				
		 dosya.close();
		 ifstream dosya1;
		 dosya1.open("soyisimler.txt");
		 
		 string soyisim;
		 int c;
			c = rand() % 278+1;
		 for (int i = 0; i < c; i++) {  //Random degisken kadar deger okunuyor
			 dosya1 >> soyisim;
		 }
		 soyad = soyisim;
		 dosya1.close();
		 numara = rand()% 101 + 100;
	 }
	 void ata(string isim,string soyisim,int no) {//Verilen degerleri Ogrencinin private kismindaki degerlere atiyor.
		 ad = isim;
		 soyad = soyisim;
		 numara = no;
	 }
	 string adyaz() {	 return ad;}//Ogrenci adini donduruyor
	 string soyadyaz() { return soyad; }//Ogrenci soyadini donduruyor
	 int noyaz() { return numara; }//Ogrenci numarasini donduruyor
};

class Sinif {
public:
	string sinifIsmi;
	char sinifHarfi;
	int sinifno;
	int ogrenciAdedi;
	Ogrenci ogrenciBilgileri[50];
	void rastgele(int a) {//Sinifharfini, sinifnosunu , ogrenci adedini atiyor.
		sinifHarfi = rand() % 25 + 65;
		sinifno = a;
		ofstream dosya;
		dosya.open("kayitlar.txt", ios::out);
		dosya << a << sinifHarfi;
		dosya.close();
		ifstream dosya1;
		dosya1.open("kayitlar.txt");
		dosya1 >> sinifIsmi;
		dosya1.close();
		ogrenciAdedi = 0;

	}
	
	
};
class Okul {
public:
	Sinif siniflar[10];
	int sinifsayisi;
	void yazdir() {
		int x = 3, y = 3;
		int sinifsayici = 0;

		for (int i = 0; i < sinifsayisi; i++) { //Sinif sayisi kadar dikdortgenlerin ust tarafini yazdiriyor.
			ustYazdir(16);
		}
		cout << endl;
		for (int x = 0; x < sinifsayisi; x++) {//Sinif sayisi kadar  siniflari belirtilen sekilde yaziyor.
			cout << dikey << right << setw(8) << siniflar[sinifsayici].sinifIsmi << setw(8) << " " << dikey;
			sinifsayici++;
		}
		cout << endl;
		for (int i = 0; i < sinifsayisi; i++) { //Sinif sayisi kadar dikdortgenlerin alt tarafini yazdiriyor.
			altYazdir(16);
		}
		sinifsayici = 0;
		for (int j = 0; j < sinifsayisi; j++) {//Dongudeki siniflarin indexini kontrol ediyor
			if (!(sinifsayici == 0)) {//KoordiatAta fonksiyonu icin gereken x degerini ayarliyor.
				for (int i = 0; i < sinifsayici; i++) {//kacinci Sinif ise x degerine o kdar 18 ekliyor.
					x = x + 18;
				}
			}
			y = 3;
			for (int k = 0; k < siniflar[sinifsayici].ogrenciAdedi; k++) {//sinifin ogrencilerini ekrana yaziyor.
				koordinatAta(x, y++);
				ustYazdir(10);
				koordinatAta(x, y++);
				cout << dikey << right << setw(10) << siniflar[sinifsayici].ogrenciBilgileri[k].adyaz() << dikey;
				koordinatAta(x, y++);
				cout << dikey << right << setw(10) << siniflar[sinifsayici].ogrenciBilgileri[k].soyadyaz() << dikey;
				koordinatAta(x, y++);
				cout << dikey << right << setw(10) << siniflar[sinifsayici].ogrenciBilgileri[k].noyaz() << dikey;
				koordinatAta(x, y++);
				altYazdir(10);
			}
			x = 3;
		sinifsayici++;
		}
		int index = 0;
		for (int i = 0; i < sinifsayisi; i++) {//En buyuk ogrenci sayisi olan sinifi buluyor
			if (siniflar[i].ogrenciAdedi > index) {//Buldugu sinifin ogrenci sayisini k ya atiyor;
				index = siniflar[i].ogrenciAdedi;
			}

		}
		y = (index * 5) + 3;
		koordinatAta(0, y);
	

	}

};
	
class dosyaYonetim {
public:
	string IsimGetir() {//Rastgele isim getiriyor.
		ifstream dosya;
		dosya.open("isimler.txt");
		string isim;

		int b;
		b = rand() % 4945 + 1;
		for (int i = 0; i < b; i++) { //Random degisken kadar deger okunuyor
			dosya >> isim;
		}

		return isim;
		dosya.close();
	}
	string soyisimGetir() {//Rastgele soyisim getiriyor.
		ifstream dosya1;
		dosya1.open("soyisimler.txt");

		string soyisim;
		int c;
		c = rand() % 278 + 1;
		for (int i = 0; i < c; i++) {  //Random degisken kadar deger okunuyor
			dosya1 >> soyisim;
		}
		return soyisim;
		dosya1.close();
	}
	Okul dosyaoku() {//Dosyadan okudugu bilgileri olusturdugu okul nesnesine aktariyor ve donduruyor.
	Okul okulnesnesi;
		okulnesnesi.sinifsayisi = 0;
		ifstream dosya;
		dosya.open("kayitlar.txt", ios::app);
		string sinifadi;
		while (dosya >> sinifadi) {//Dosyayi okudugu surece devam eder
			string ad, soyad;
			int ogrenciadedi, no;

			dosya >> ogrenciadedi;

			okulnesnesi.siniflar[okulnesnesi.sinifsayisi].ogrenciAdedi = ogrenciadedi;
			okulnesnesi.siniflar[okulnesnesi.sinifsayisi].sinifIsmi = sinifadi;

			for (int i = 0; i < ogrenciadedi; i++) {//Ogrenci adedi kadar dosyayi okur
				dosya >> ad >> soyad >> no;
				okulnesnesi.siniflar[okulnesnesi.sinifsayisi].ogrenciBilgileri[i].ata(ad, soyad, no);
			}
			okulnesnesi.sinifsayisi++;
		}

		dosya.close();
		return okulnesnesi;
	}
	void okulyaz(Okul verilenokul) {//Kendsine gonderilen okul nesnesini dosyaya yazar.
		ofstream dosya;
		dosya.open("kayitlar.txt", ios::out);

		for (int i = 0; i < verilenokul.sinifsayisi; i++) {//Sinif ismi sinifin ogrenci adedi ve ogrencinin bilgileri yaziliyor.
			dosya << verilenokul.siniflar[i].sinifIsmi << endl;
			dosya << verilenokul.siniflar[i].ogrenciAdedi << endl;
			for (int j = 0; j < verilenokul.siniflar[i].ogrenciAdedi; j++) {//ogrencinin bilgileri dosyaya yaziliyor.
				dosya << verilenokul.siniflar[i].ogrenciBilgileri[j].adyaz() << " ";
				dosya << verilenokul.siniflar[i].ogrenciBilgileri[j].soyadyaz() << " ";
				dosya << verilenokul.siniflar[i].ogrenciBilgileri[j].noyaz() << endl;
			}
		}
		dosya.close();
	}
};

class Program {
public:
	Okul Okulum;
	dosyaYonetim dosyayonet;

	int calistir() {//Butun programin calistigi Metotdur.
		Okulum= dosyayonet.dosyaoku();
		Okulum.yazdir();
		

		cout << endl << "1. Ogrenci Ekle" << endl << "2.Sinif Ekle" << endl << "3.Ogrenci Degistir" << endl << "4.Ogrenci Sil" << endl << "5.Sinif Sil" << endl << "6.Cikis" << endl;
		int menu;
		while (1) {//Girilen sayinin 1-2-3-4-5-6 olup olmadigina bakiyor.
			cin >> menu;
			if (menu > 6 || menu < 1) {//1-6 arasinda degilse hata mesajini ortaya cikartiyor.
				cout << "Hatali sayi girdiniz lutfen 1-6 giriniz." << endl;
			}
			else {//1-6 arasinda ise donguyu bitiriyor.
				break;
			}
		}
		string girilen;
		switch (menu) {
		case 1://Girilen sinifisminin Okul nesnesinde olup olmadigini kontrol ediyor Okul nesnesinde varsa ogrenci ekleme islemini yapiyor yok isse kendini tekrar cagriyor.
			while (1) {
				
				cout << "Hangi sinifa eklemek istiyorsunuz ? : ";
				cin >> girilen;
				for (int i = 0; i <Okulum.sinifsayisi; i++) {//Sinif indexini kontrol ediyor.
					if (girilen == Okulum.siniflar[i].sinifIsmi) {//Girilen sinif ismi okul nesnesindekilerden biri ile uyusursa rastgele degerli ogrenci nesnesi olusturup o sinifa ekler.
						Ogrenci geciciogrenci;
						geciciogrenci.ogrencirastgele();
						cout << "Ogrenci Adi : " << geciciogrenci.adyaz() << endl;
						cout << "Ogrenci Soyadi : " << geciciogrenci.soyadyaz()<< endl;
						cout << "Numara : " << geciciogrenci.noyaz() << endl;
						system("pause");
						Okulum.siniflar[i].ogrenciAdedi++;
						Okulum.siniflar[i].ogrenciBilgileri[(Okulum.siniflar[i].ogrenciAdedi) - 1] = geciciogrenci;
						dosyayonet.okulyaz(Okulum);
						system("cls");
						calistir();
					}
				}	
				system ("cls");
				calistir();
			}
			
		case 2://Okul nesnesinin sinif sayisini 1 arttirip olusturaln sinifin ismini rastgele atiyor ve ogrenci sayisini 0 atiyor.
			Okulum.sinifsayisi++;
			Okulum.siniflar[(Okulum.sinifsayisi) - 1].rastgele(Okulum.sinifsayisi);
			dosyayonet.okulyaz(Okulum);
			system("cls");
			calistir();
		case 3://Girilen ogrenci no sunun Okul nesnesindeki siniflarin icerisindeki ogrenclier ile uyup uymadigina bakiyor uyuyor ise rastgele ogrenci getirip yerlerini degistiriyor.
			while (1) {
				int girilensayi;
				cout << "Ogrenci no giriniz : ";
				cin >> girilensayi;
				for (int i = 0; i < Okulum.sinifsayisi; i++) {//	Sinif indexini kontrol ediyor.
					for (int j = 0; j < Okulum.siniflar[i].ogrenciAdedi; j++) {//Ogrenci indexini kontrol ediyor.
						int aktarilan;
						aktarilan = Okulum.siniflar[i].ogrenciBilgileri[j].noyaz();
					  if (aktarilan == girilensayi) {//Girilen numara ogrenci numarasi ile ayni ise rastgele ogrenci olusturulur ve yerleri degistirilir.
						  Ogrenci geciciogrenci;
						  geciciogrenci.ogrencirastgele();
						  cout << "Ogrenci Adi : " << geciciogrenci.adyaz() << endl;
						  cout << "Ogrenci Soyadi : " << geciciogrenci.soyadyaz() << endl;
						  cout << "Numara : " << geciciogrenci.noyaz() << endl;
						  system("pause");
						  Okulum.siniflar[i].ogrenciBilgileri[j] = geciciogrenci;
						 
					  }
					}
				}
				dosyayonet.okulyaz(Okulum);
				system("cls");
				calistir();
			}
		case 4://Girilen numara ile okul nesnesinin siniflarindaki ogrencilerin numarasini karsilatiriyor ayni ise o ogrenci dizisindeki ogrenciyi siliyor ve ondan sonra ogrenci varsa bi onceki dizi elemanina aktariliyor.
			while (1) {
				int girilensayi;
				cout << "Ogrenci no giriniz : ";
				cin >> girilensayi;
				for (int i = 0; i < Okulum.sinifsayisi; i++) {//Sinif indexini kontrol ediyor.
					for (int j = 0; j < Okulum.siniflar[i].ogrenciAdedi; j++) {//Ogrenci indexini kontrol ediyor.
						int aktarilan;
						aktarilan = Okulum.siniflar[i].ogrenciBilgileri[j].noyaz();
						 if (aktarilan == girilensayi) {//Girilen sayi ogrencinin nosuna esit ise ogrenciyi siliyor ve o ogrenciden sonra baska ogrenci varsa bir once dizi elmanina ataniyorlar.
							Okulum.siniflar[i].ogrenciBilgileri[j] = Okulum.siniflar[i].ogrenciBilgileri[j + 1];
							Okulum.siniflar[i].ogrenciAdedi--;
						}
					}
				}
				dosyayonet.okulyaz(Okulum);
				system("cls");
				calistir();
			}
		case 5://Girilen sinif ismi okul nesnesindeki sinif isimleri ile uyusursa o sinifi siler ver o siniftan sonra sinif var is bir onceki sinif dizisi elemanina atanir, Sinif sayisi 1 azaltilir.
			while (1) {
				cout << "Hangi sinifi cikarmak istiyorsunuz ? : ";
				cin >> girilen;
				for (int i = 0; i < Okulum.sinifsayisi; i++) {
					if (girilen == Okulum.siniflar[i].sinifIsmi) {
						for (int k = 0; k < ((Okulum.sinifsayisi-1)-i); k++) {
							Okulum.siniflar[k] = Okulum.siniflar[k + 1];
						}
						Okulum.sinifsayisi--;
						dosyayonet.okulyaz(Okulum);
						system("cls");
						calistir();
					}
				}
				
				system("cls");
				calistir();
			}
		case 6://Programi kapatiyor.
			cout << "Program sona ermistir." << endl;
			exit(0);
			
		}
	}
};




	int main() {
		Program prog;
		prog.calistir();
	}
