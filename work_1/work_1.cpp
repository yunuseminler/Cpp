/****************************************************************************
**
**				ÖÐRENCÝ ADI......: Yunus Emre Eminler
**				ÖÐRENCÝ NUMARASI.: G191210046
**				DERS GRUBU…………………: 2.Ögretim B grubu
****************************************************************************/

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	int sutun, sayac1, satir, sayac2, ortabosluk = 2, r, a = 0;
	cout << "------Uyarilar------" << endl << "1-) Satir degerleri 5-15 arasinda olmak zorundadir. (5-15 dahil)" << endl << "2-) Sutun degerleri 5-40 araliginda olmalidir.(5-40 dahil)" << endl << "3-) Sutun degeri satir degerinin 2 kati olmak zorundadir." << endl << "--------------------" << endl << "Satir degerini giriniz : ";
	//Bu while dögüsü girilen satir degerinin 5-15 arasinda olup olmadigini kontrol ediyor.
	while (a == 0) {
		cin >> satir;
		if (satir >= 5 && satir <= 15) {
			cout << "Satir degeriniz " << satir << " olarak belirlenmistir" << endl;
			a = 1; //Döngüden cikartmak icin                                        
		}
		else {
			cout << "Lutfen sadece 5-15 arasinda deger giriniz. " << endl << "Tekrar giriniz ! " << endl;
		}
	}
	cout << "Sutun degerini giriniz : ";
	//Bu while dongusu girilen sutun degerinin  5-40 arasinda olup olmadigini ayni zamanda da satir sayisinin 2 kati olup olmadigini sorguluyor.
	while (a == 1) {            
		cin >> sutun;
		if (sutun >= 5 && sutun <= 40) {
			if (sutun == 2 * satir) {
				cout << "Sutun degeriniz " << sutun << " olarak belirlenmistir" << endl << endl;
				a = 2;        //Donguden cikartmak icin
				r = (sutun / 2 - 3);
			}
			else {
				cout << "Girdiginiz deger 5-40 arasindadir fakat sutun sayisi satir sayisinin 2 kati olmak zorundadir. Satir degeriniz " << satir << " olarak belirlenmistir.Bu durumda sadece " << 2 * satir << " degerini girebilirsiniz." << endl << "Tekrar giriniz ! " << endl;
			}
		}
		else {
			cout << "Lutfen sadece 5-40 arasinda deger giriniz. " << endl << "Tekrar giriniz ! " << endl;
		}
	}
	
	for (sayac1 = 1; sayac1 <= satir; sayac1++) {//Bu döngü satir sayisinin belirlemek icindir.

		if (sayac1 == 1 || sayac1 == satir) {
			for (sayac2 = 1; sayac2 <= sutun; sayac2++) {//Bu döngü basindaki ve sonundaki yildiz satirini yapmak icin.
				cout << "*";
			}
		}
		else {
			cout << "*";
			for (sayac2 = 1; sayac2 <= r; sayac2++) {//Bu döngü ilk bosluklar icin. 
				cout << " ";
			}
			cout << "*";
			for (int a = 1; a <= ortabosluk; a++) {//Bu döngü ortadaki bosluklar icin
				cout << " ";
			}
			cout << "*";
			for (int t = 1; t <= r; t++) {//Bu döngü sondaki bosluklar icin
				cout << " ";
			}

			cout << "*";
			r = r - 1;                  // 67. ve 68. kod satiri her satir icin gerekli bosluklari ayarliyor
			ortabosluk = ortabosluk + 2;

		}
		cout << endl;
		Sleep(100); //	Programin calismasini 100 milisaniye geciktirir
	}
	cout << endl;
	r = r + 1;
	ortabosluk = ortabosluk - 2;
	Sleep(100);
	for (sayac1 = 1; sayac1 <= satir; sayac1++) {           //Bu döngü satir sayisini ayarlamak icin

		if (sayac1 == 1 || sayac1 == satir) {
			for (sayac2 = 1; sayac2 <= sutun; sayac2++) {  //Bu döngü basindaki ve sonundaki yýldýz satirini yapmak icin.
				cout << "*";
			}
		}
		else {
			cout << "*";
			for (sayac2 = 1; sayac2 <= r; sayac2++) { //Bu döngü ilk bosluklar icin.
				cout << " ";
			}
			cout << "*";
			for (int a = 1; a <= ortabosluk; a++) { //Bu döngü ortadaki bosluklar icin
				cout << " ";
			}
			cout << "*";
			for (int t = 1; t <= r; t++) { //Bu döngü sondaki bosluklar icin
				cout << " ";
			}
			cout << "*";
			r = r + 1;                               // 97. ve 98. kod satiri her satir icin gerekli bosluklari ayarliyor
			ortabosluk = ortabosluk - 2;


		}
		cout << endl;
		Sleep(100); //	Programin calismasini 100 milisaniye geciktirir
	}


	system("pause");
}