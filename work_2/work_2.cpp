/****************************************************************************
**
**                OGRENCI ADI........:  Yunus Emre Eminler
**                OGRENCI NUMARASI...:  g191210046
**                DERS GRUBU.........:  2.Ogretim B grubu
****************************************************************************/

#include <iostream>
#include <iomanip>		//Setw Manipulatoru icin 
#include <ctime>
using namespace std;

void matrisYazmaMenu(int boyut, int matris[25][25]); //int main()'den sonra matrisYazmaMenu adli fonksiyon oldugunu belirtiyor


int main() {
	int matris[25][25];
	int boyut, menu, satir, sutun, tutucu[25];
	srand(time(0));//Rastgele verilen sayilarin program her calistirildiginda farkli degerler vermesini saglar.

	do {
		cout << "Matrisin boyutunu giriniz. (5 ile 25 arasinda olmasi gerekiyor)" << endl;
		cin >> boyut;
	} while (boyut < 5 || boyut >25);  //Bu do while dongusu girilen boyutun 5 ile 25 arasinda olup olmadigini kontrol ediyor.
	for (int i = 0; i < boyut; i++) {   //Bu for dongusu matrisin elemanlarina 1-9 arasinda rastgele deger veriyor.
		for (int j = 0; j < boyut; j++) {
			matris[i][j] = rand() % 9 + 1;
		}
	}
	do { /*Bu do while dongusu butun switch case yapisini icine alir.Switch case icinde tekrar menu yazdirmaya ihtiyac duyulursa switch case dongusu kirilir ve Menu ile birlikte matris tekrar yazilir.*/

		matrisYazmaMenu(boyut, matris); //Menusuyle birlikte matrisi yazdirir.

		cin >> menu;
		while (menu > 4 || menu < 1) {
			cout << "Hangi islemi yapmak istiyorsaniz basindaki sayiyi giriniz. (Sadece 1,2,3,4 sayilarini giriniz.)" << endl;
			cin >> menu;
		} //Bu while dongusu girilen degerin 1-4 arasinda olup olmadigini kontrol ediyor.
		switch (menu) {
		case 1:
			cout << "Islem yapmak istediginiz satir ve sutun degerini girin" << endl;
			cin >> satir >> sutun;

			if (satir > boyut || satir < 1) {
				cout << "Satir degeriniz matrisin boyutu ile uyusmamaktadir." << endl;
				break;
			}

			else if (sutun <1 || sutun>boyut) {
				cout << "Sutun degeriniz matrisin boyutu ile uyusmamaktadir." << endl;
				break;
			}

			else {
				int satirtutucu[25];
				int toplamtutucu = 0;
				satir = satir - 1;
				sutun = sutun - 1;
				for (int l = 0; l < boyut; l++) {  //Matrisin girilen sutun degerindeki degerleri tutucu bir diziye aktariyor.
					tutucu[l] = matris[l][sutun];
				}
				for (int l = 0; l < boyut; l++) {  //Matrisin girilen satir degerindeki degerleri satirtututucu diziye yaziyor.
					satirtutucu[l] = matris[satir][l];
				}

				for (int l = 0; l < boyut; l++) {  //satirtutucu dizideki matris satir degerlerini sutuna yaziyor.
					matris[l][sutun] = satirtutucu[l];
				}
				toplamtutucu = matris[satir][sutun]; //Kesisecek olan degerlerin birinin kaybolmamasi icin gecici olarak toplamtutucu degiskenine ataniyor.
				for (int l = 0; l < boyut; l++) { //Tutucu dizideki matris sutun degerlerini satira yaziyor.
					matris[satir][l] = tutucu[l];
				}
				matris[satir][sutun] = matris[satir][sutun] + toplamtutucu;//Kesisen degerleri toplayip kesisen matris elemanina yaziyor.
				
				break; //Switch case 'in disina cikartir ve menusuyle birlikte yeni matrisi ekrana yazdirir
			}

		case 2:
			cout << "Islem yapmak istediginiz satir numarasi giriniz" << endl;
			cin >> satir;

			if (satir > boyut || satir < 1) { //Bu if girilen satir degerinin matrisin boyutu ile 1 arasinda olup olmadigini kontrol ediyor.
				cout << "Satir degeriniz matrisin boyutu ile uyusmamaktadir." << endl;
				break;
			}

			else {
				satir = satir - 1;
				int index = 0;
				int ciftindex = 0;
				for (int l = 0; l < boyut; l++) {//Girilen satir sayisindaki elemanlari kontrol ediyor.
					if (matris[satir][l] % 2 == 0) {
						tutucu[ciftindex] = matris[satir][l];//Eleman cift ise tutucu bir diziye aktariliyor.
						ciftindex++;
					}

					else {
						matris[satir][index] = matris[satir][l]; //Tek ise matrisin ilk elemanina yazdiriyor.
						index++;
					}
				}
				int ciftsayi = boyut - index;//Cift sayilarin sayisini buluyoruz
				for (int l = 0; l < ciftsayi; l++) {//Tek sayilar en bastan itibaren yazildiktan sonra kalan elemanlara cift sayilari atiyor.
					matris[satir][index] = tutucu[l];
					index++;
				}

				break; //Switch case 'in disina cikartir ve menusuyle birlikte yeni matrisi ekrana yazdirir
			}
		case 3:
			cout << "Islem yapmak istediginiz sutun numarasi giriniz" << endl;
			cin >> sutun;
			if (sutun > boyut || sutun < 1) { //Bu if girilen sutun degerinin matrisin boyutu ile 1 arasinda olup olmadigini konmtrol ediyor.
				cout << "Sutun degeriniz matrisin boyutu ile uyusmamaktadir." << endl;
				break;
			}
			else {
				sutun = sutun - 1;
				for (int l = 0; l < boyut; l++) { //Matrisin secilen sutundaki elemanlari gecici bir diziye aktariliyor.
					tutucu[l] = matris[l][sutun];
				}

				int gecici = boyut - 1;
				for (int l = 0; l < boyut; l++) {//Matrisin secilen sutundaki elemanlarina gecici dizideki elemanlari sondan baslayarak atiyor.
					matris[l][sutun] = tutucu[gecici];
					gecici--;
				}

				break; //Switch case 'in disina cikartir ve menusuyle birlikte yeni matrisi ekrana yazdirir
			}
		case 4:
			int index = 0;
			for (int i = 0; i < boyut; i++) {//Matrisin butun elemanlari toplaniyor ve index degerine ataniyor.
				for (int j = 0; j < boyut; j++) {
					index = matris[i][j] + index;
				}
			}

			index = index + matris[0][0];
			for (int i = 0; i < boyut; i++) {//Satir degerini kontrol ediyor.
				for (int j = 0; j < boyut; j++) {//Sutun degerini kontrol ediyor.
					matris[i][j] = index - matris[i][j];//index degerinden matrisin [i][j]'nci elemani cikartilip tekrar [i][j]'nci degerine yaziliyor.
					index = matris[i][j];//Bir onceki yapilan islemde cikan sonuc yeni matris index degeri olarak ataniyor.
				}
			}
			break; //Switch case 'in disina cikartir ve menusuyle birlikte yeni matrisi ekrana yazdirir
		}
	}

	while (1);/*Bu dongu butun switch case yapisini icine alir.Switch case icinde tekrar menu yazdirmaya ihtiyac duyulursa switch case dongusu kirilir ve Menu ile birlikte matris tekrar yazilir.*/

}

void matrisYazmaMenu(int boyut, int matris[25][25]) {
	cout << "    ";
	for (int k = 0; k < boyut; k++) {//Sutun numaralari yazdirilir.
		cout << setw(5) << left << k + 1;
	}
	cout << endl << "   -";
	for (int l = 0; l < boyut - 1; l++) {//Sutun numaralarinin altindaki cizgiler yazdirilir.
		cout << "-----";
	}
	cout << "--" << endl;
	for (int i = 0; i < boyut; i++) {//Satir numaralari ile birlikte yanindaki | isareti ekrana yazdirilir.
		cout << setw(2) << left << i + 1 << "| ";
		for (int j = 0; j < boyut; j++) {//Matrisin elemanlari yazdirilir.
			cout << setw(5) << left << matris[i][j];
		}
		cout << endl;
	}
	cout << endl << "1) Sutun Satir degistir." << endl << "2) Tekleri basa al(satir)" << endl << "3) Ters cevir (sutun)" << endl << "4) Toplamlari yazdir" << endl;
}
