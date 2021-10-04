/****************************************************************************
**
**				OGRENCI ADI..............:  Yunus Emre EMINLER
**				OGRENCI NUMARASI.........:  g191210046				
**				DERS GRUBU...............:	2. Ogretim B grubu
****************************************************************************/

#include <iostream>
#include <ctime>//srand fonksiyonu icin gerekli dosya.
#include <Windows.h>//system cls ve sleep fonksiyonlari icin gerekli dosya.


using namespace std;

struct sahne { //sahne yapi tipini tanimliyoruz.
	int genisligi;
	int yuksekligi;
	char cizimKarakteri;

};

struct LSekli {//Lsekli yapi tipini tanimliyoruz.
	int x;
	int y;
	int boyut;
	char Lkarakteri;
};


sahne sahneOlustur(sahne);					//int mainin altinda sahneOlustur adli fonksiyon oldugunu belirtiyoruz.
LSekli lSekliOlustur(LSekli);				//int mainin altinda lSekliOlustur adli fonksiyon oldugunu belirtiyoruz.
LSekli lSekliAsagiGotur(LSekli);		    //int mainin altinda lSekliAsagiGotur adli fonksiyon oldugunu belirtiyoruz.
void sahneCiz(sahne);						//int mainin altinda sahneCiz adli fonksiyon oldugunu belirtiyoruz.
void lSekliCiz(LSekli);					    //int mainin altinda lSekliCiz adli fonksiyon oldugunu belirtiyoruz.
void sahneTemizle(char[50][30], sahne);     //int mainin altinda sahneTemizle adli fonksiyon oldugunu belirtiyoruz.
void koordinatGit(int, int);				//int mainin altinda koordinatGit adli fonksiyon oldugunu belirtiyoruz.
void kursoruGizle();						//int mainin altinda kursoruGizle adli fonksiyon oldugunu belirtiyoruz.
int kacaesit(LSekli, sahne);			    //int mainin altinda kacaesit adli fonksiyon oldugunu belirtiyoruz.

char olusturulansahne[50][30];



int main() {
	kursoruGizle();
	srand(time(0));
	sahne c{};
	LSekli b{};
	c = sahneOlustur(c);
	while (1) {
		system("cls");
		b = lSekliOlustur(b);
		
		for (int i = 0; i <kacaesit(b,c);i++) { //kaca esit fonksiyonu cagriliyor burdan donen deger L nin kac satir asagiya gidecegini gosteriyor bu dongu ile L harfi olusturuyor ve donen sayi kadar asagiya otelenip bitiyor.
			koordinatGit(0, 0);
			lSekliCiz(b);
			sahneCiz(c);
			b = lSekliAsagiGotur(b);
			sahneTemizle(olusturulansahne, c);
		    Sleep(100);
		}
		
		Sleep(100);
	}
}
sahne sahneOlustur(sahne olusturulacakSahne) {//bu fonksiyon gonderilen sahnenin genisligine 30-40-50 degerlerinden birini, sahnenin yuksekligine 20-30 arasinda deger,cizim karakterine ise (*,+,$,@,#) karakterlerinden birini atiyor.
	
	int genislikayarlamakicin = rand() % 3;

	if (genislikayarlamakicin == 0) { //Bu if elseler genisligi 30-40-50 degerinden birini atiyor.
		olusturulacakSahne.genisligi = 30;
	}
	else if (genislikayarlamakicin == 1) {
		olusturulacakSahne.genisligi = 40;
	}
	else {
		olusturulacakSahne.genisligi = 50;
	}

	olusturulacakSahne.yuksekligi = rand() % 11 + 20;//yukseklige 20-30 arasi deger atiyor.

	int index = rand() % 5;

	if (index == 0) {//bu if elseler cizim karakterine  (*,+,$,@,#) birini atiyor.
		olusturulacakSahne.cizimKarakteri = '*';
	}
	else if (index == 1) {
		olusturulacakSahne.cizimKarakteri = '#';
	}
	else if (index == 2) {
		olusturulacakSahne.cizimKarakteri = '$';
	}
	else if (index == 3) {
		olusturulacakSahne.cizimKarakteri = '+';
	}
	else {
		olusturulacakSahne.cizimKarakteri = '@';
	} 
	
	for (int i = 0; i < olusturulacakSahne.genisligi; i++) {  //Bu for dongusu olusturulansahne dizisinin en ustundeki ve en altindaki satirlarina cizim karakteri atiyor
		olusturulansahne[i][0] = olusturulacakSahne.cizimKarakteri;
		olusturulansahne[i][olusturulacakSahne.yuksekligi - 1] = olusturulacakSahne.cizimKarakteri;
	}
	for (int i = 0; i < olusturulacakSahne.yuksekligi; i++) { //Bu for dongusu olusturulansahne dizisinin en sag ve en soldaki sutunlarina cizim karakterini atiyor.
		olusturulansahne[0][i] = olusturulacakSahne.cizimKarakteri;
		olusturulansahne[olusturulacakSahne.genisligi - 1][i] = olusturulacakSahne.cizimKarakteri;
	}
	return olusturulacakSahne; //sahneyi donduruyor
}

void sahneCiz(sahne cizilecekSahne) {//Bu fonksiyon sahneyi ekrana cizidiriyor.
 
	for (int y = 0; y < cizilecekSahne.yuksekligi; y++) { 	//Bu donguler sahneyi ekrana cizdiriyor.
		for (int x = 0; x < cizilecekSahne.genisligi; x++) {
			cout << olusturulansahne[x][y];
		}
		cout << endl;
	}
}

LSekli lSekliOlustur(LSekli olusturulacakLsekli) {//Bu fonksiyon disaridan gelen L seklinin x ine 5 ile 25 arasinda deger veriyor , y sine 3 veriyor , boyutunada 2 ile 7 arasinda deger , cizim karakterinede (*,+,$,@,#) den birini atiyor.
	
	olusturulacakLsekli.x = rand() % 21 + 5; //Lsekli nin x degerine 5-25 arasi deger atiyor.

	olusturulacakLsekli.y = 3; //Lseklinin y sine 3 atiyor.

	olusturulacakLsekli.boyut = rand()%6+2; //Lseklinin boyutuna 2-7 arasinda deger atiyor.
	
	int gecici = rand() % 5;

	if (gecici == 0) {// Bu if elseler cizim karakterine (*,+,$,@,#) den birini atiyor.
		olusturulacakLsekli.Lkarakteri = '*';
	}
	else if (gecici == 1) {
		olusturulacakLsekli.Lkarakteri = '#';
	}
	else if (gecici == 2) {
		olusturulacakLsekli.Lkarakteri = '$';
	}
	else if (gecici == 3) {
		olusturulacakLsekli.Lkarakteri = '+';
	}
	else {
		olusturulacakLsekli.Lkarakteri = '@';
	} 

	return olusturulacakLsekli;
}

void lSekliCiz(LSekli b) { //Olusturulan L seklini ciziyor.

	for (int i = 0; i < b.boyut; i++) { //Lsekli boyutu kadar cizim karakterini ciziyor.
		olusturulansahne[b.x+i][b.y] = b.Lkarakteri;
	}

	for (int i = 0; i < b.boyut-1; i++) { //L seklinin boyutu - 1 kadar *  * su sekilden yapýyor
		olusturulansahne[b.x][b.y+i+1] = b.Lkarakteri;
		olusturulansahne[b.x+(b.boyut-2)+1][b.y+i+1] = b.Lkarakteri;

	}

	olusturulansahne[b.x][b.y+(b.boyut)] = b.Lkarakteri;

	for (int i = 0; i < b.boyut; i++) { // L seklinin boyutu +1 kadar cizim karakterini yan yana ciziyor.
		olusturulansahne[b.x + (b.boyut - 2)+i+1][b.y+(b.boyut)]= b.Lkarakteri;
	}

	for (int i = 0; i < b.boyut-1; i++) {//L seklinin boyutu - 1 kadar *  * su sekilden yapýyor
		olusturulansahne[b.x][b.y+(b.boyut)+1+i] = b.Lkarakteri;
		olusturulansahne[b.x +(2*(b.boyut))-2][b.y+ (b.boyut) + 1 + i] = b.Lkarakteri;
	}

	for (int i = 0; i < (2*b.boyut)-1; i++) {//L seklinin boyutu*2 kadar cizim karakterini yan yana ciziyor.
		olusturulansahne[b.x + i][b.y+ 2 * (b.boyut)] = b.Lkarakteri;
	}

}

LSekli lSekliAsagiGotur(LSekli h) { //Bu fonksiyon sekli 1 birim asagiya kaydiriyor.
	h.y++;
	return h;
}

void sahneTemizle(char k[50][30], sahne temizlenecekSahne) {//Bu fonksiyon sahnenin cercevesi disindaki heryeri bosluk olarak atiyor.

	for (int y = 0; y < temizlenecekSahne.yuksekligi; y++) {//Bu dongu olusturulansahne dizisinin butun elemanlarina bosluk atiyor.
		for (int x = 0; x < temizlenecekSahne.genisligi; x++) {
			olusturulansahne[x][y] = ' ';
		}
	}

	for (int i = 0; i < temizlenecekSahne.genisligi; i++) {//Bu for dongusu olusturulansahne dizisinin en ustundeki ve en altindaki satirlarina cizim karakteri atiyor
		olusturulansahne[i][0] = temizlenecekSahne.cizimKarakteri;
		olusturulansahne[i][temizlenecekSahne.yuksekligi - 1] = temizlenecekSahne.cizimKarakteri;
	}

	for (int i = 0; i < temizlenecekSahne.yuksekligi; i++) {//Bu for dongusu olusturulansahne dizisinin en sag ve en soldaki sutunlarina cizim karakterini atiyor.
		olusturulansahne[0][i] = temizlenecekSahne.cizimKarakteri;
		olusturulansahne[temizlenecekSahne.genisligi - 1][i] = temizlenecekSahne.cizimKarakteri;
	}
}

int kacaesit(LSekli c, sahne a) { //Olusturulan L seklinin boyutu ve sahnenin yuksekligi ile gereken islemi yaparak dongu tekrar sayisini donduruyor.
	return a.yuksekligi - (2*c.boyut) - 4;
}

void koordinatGit(int x, int y) //kursoru girilen x ve y koordinatina goturuyor.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void kursoruGizle() { //Kursoru gizliyor.
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
