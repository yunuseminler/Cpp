/**
* @file Dosya.cpp
* @description Dosyadan okuma, Ekrana Yazma , Çaprazlama işlemlerini yapıyor.
* @course 2. Ogretim C grubu 
* @assignment 1
* @date ‎24 ‎Kasım ‎2020 ‎Salı
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "Dosya.h"
#include "Node.h"

using namespace std;

void Dosya::dosyaOku(){//Dosyadan verileri okuyarak uygun yerlere yeni Nodelar oluşuturup verilerini atıyor.
    satirlariOku();
    Node* tempNode = ortancalar;
    ifstream dosya;
    dosya.open("./doc/kayitlar.txt", ios::in);
    string satir;
    int satirIndex = 0;
    while(getline(dosya, satir)){//Dosyanın sonuna kadar okuyor
        istringstream ssatir(satir);
        string data;
        int elemanSayisi = elemanHesapla(satir);

        for(int i = 0;i< satirIndex;i++){//Ortancalar dugumununden ilgili satırın başlangıç Node'una gidiyor
            tempNode = tempNode->before;
        }
        tempNode->data = to_string(elemanSayisi);
        
        for(int i = 0;i<elemanSayisi;i++){//Eleman sayisi kadar tekrar edip gerekli Nodelari oluşturup değerelerini atıyor
            getline(ssatir, data, ' ');
            int sayi = pozitifmi(stoi(data));
            data = to_string(sayi);
            if(i == 0){//ilk ortanda düğümü oluşturup atıyor
                tempNode->after = new Node(data);
                tempNode = tempNode->after;
            } 
            else if(i <= ((elemanSayisi-1)/2)){//Okuduğu değerleri ortanca değerin before'una giderek değerleri atıyor
                tempNode->before = new Node(data);
                tempNode->before->after = tempNode;
                tempNode = tempNode->before;
            }
            else{//Kalan elemanları ortanca değerin afterına atıyor;
                if(i == (((elemanSayisi-1)/2)+1)){//ortanca dugumu buluyor
                    for(int j = 0;j<((elemanSayisi-1)/2);j++){
                        tempNode = tempNode->after;
                    }
                }
                tempNode->after = new Node(data);
                tempNode->after->before = tempNode;
                tempNode = tempNode->after;
                if(i==(elemanSayisi-1)){//En son dugume gelince diğer tempNode'u listenin diğer başına yollayarak 2 sini biririne bağlıyor.
                    Node* tempNode1 = tempNode;
                    for(int j = 0;j<(elemanSayisi-1);j++){
                        tempNode = tempNode->before;
                    }
                    tempNode1->after = tempNode;
                    tempNode->before = tempNode1;
                }
            }
        }
        tempNode = ortancalar;
        satirIndex++;
    }
    dosya.close();
};
void Dosya::satirlariOku(){//Dosyadan satırları okuyarak satır sayısı kadar yeni Node'u birbirinin before'una bağlıyor
    Node* tempNode;
    int satirSayisi = satirHesapla();
    for(int i =0;i<satirSayisi;i++){
        if(i == 0){
            ortancalar = new Node(to_string(i+1));
            tempNode = ortancalar;
        }
        else{
        tempNode->before = new Node(to_string(i+1));
        tempNode = tempNode->before;
        }
    }
};
void Dosya::caprazla(){// En kucuk ve En buyuk Nodeların çaprazlama işlemini yapıyor.
    Node* kucuk = kucukBul();
    Node* buyuk = buyukBul();
    int kucukBoyut = stoi(kucuk->data);
    int buyukBoyut = stoi(buyuk->data);
    kucuk = kucuk->after;
    buyuk = buyuk->after;
    Node* tempNode = kucuk->before;
    Node* tempNode1;

    for(int i = 0;i<((kucukBoyut-1)/2)-1;i++){//Kucuk olan Node'un beforundaki Nodeları ters sırada diziyor.
        tempNode->after = tempNode->before;
        tempNode = tempNode->before;
    }

    tempNode = kucuk->before;
    tempNode1 = buyuk->after;
    buyuk->after = tempNode;
    tempNode = tempNode1;
    
    for(int i = 0;i<((buyukBoyut-1)/2)-1;i++){//Buyuk olan Nodeun Afterındaki Nodeları ters sırada diziyor.
        tempNode->before = tempNode->after;
        tempNode = tempNode->after; 
    }

    kucuk->before = tempNode1;
    tempNode = kucuk->after;

    for(int i = 0;i<((kucukBoyut-1)/2)-1;i++){//Kucuk olan Node'un afterındaki nodeları ters sırada diziyor.
        tempNode->before = tempNode->after;
        tempNode = tempNode->after; 
    }

    tempNode = kucuk->after;
    tempNode1 = buyuk->before;
    buyuk->before = tempNode;
    tempNode = tempNode1;

    for(int i = 0;i<((buyukBoyut-1)/2)-1;i++){//Buyuk olan Nodeların before'undaki Nodeları ter sırada diziyor.
        tempNode->after = tempNode->before;
        tempNode = tempNode->before; 
    }
    kucuk->after = tempNode1;

    dugumBagla(kucuk,buyukBoyut);
    dugumBagla(buyuk,kucukBoyut);

    cout << "En Buyuk Liste Orta Dugum Adres: " << buyuk << endl<<"En Buyuk Liste Degerler:" << endl;
    ekranaYaz(buyuk,kucukBoyut);
    cout << endl << "En Kucuk Liste Orta Dugum Adres: " << kucuk << endl<<"En Kucuk Liste Degerler:" << endl;
    ekranaYaz(kucuk,buyukBoyut);

    
};
void Dosya::ekranaYaz(Node* liste,int boyut){//Gönderilen cift yönlü listeyi ekrana yazdırıyor
    Node* tempNode = liste;
    for(int i = 0;i<((boyut-1)/2);i++){
        tempNode = tempNode->before;
    }

    for(int i = 0;i<boyut;i++){
        cout << tempNode->data << " ";
        tempNode=tempNode->after;
    }
    cout << endl;
}
void Dosya::dugumBagla(Node* liste,int boyut){//Gönderilen cift yönlü listenin butun elemanlarının afterlarını ve beforelarını birbirine bağlıyor
    Node* tempNode = liste;
    Node* tempNode1 = liste;
    for(int i = 0;i<((boyut-1)/2);i++){
        tempNode->after->before = tempNode;
        tempNode = tempNode->after;
        tempNode1->before->after = tempNode1;
        tempNode1 = tempNode1->before;
    }
    tempNode1->before= tempNode;
    tempNode->after = tempNode1;
};
Node* Dosya::kucukBul(){//Orta göstericilerin arasından en kucuk veriye sahip olanını buluyor
    int satirSayisi = satirHesapla();
    Node* tempNode = ortancalar;
    Node* kucuk = ortancalar;
    for(int i = 0;i<satirSayisi;i++){
        int a = stoi(tempNode->after->data);
        int b = stoi(kucuk->after->data);
        if(a<=b){
            kucuk = tempNode;
            tempNode = tempNode->before;
        }
        else{
            tempNode = tempNode->before;
        }
    }
    delete tempNode;
    return kucuk;
};
Node* Dosya::buyukBul(){//Orta göstericilerin arasından en buyuk veriye sahip olanını buluyor
    int satirSayisi = satirHesapla();
    Node* tempNode = ortancalar;
    Node* buyuk = ortancalar;
    for(int i = 0;i<satirSayisi;i++){
        int a = stoi(tempNode->after->data);
        int b = stoi(buyuk->after->data);
        if(a>=b){
            buyuk = tempNode;
            tempNode = tempNode->before;
        }
        else{
            tempNode = tempNode->before;
        }
    }
    delete tempNode;
    return buyuk;
};
int Dosya::elemanHesapla(string gelen) {//Gönderilen String içerisinde kaç tane eleman olduğunu buluyor
    int boslukSayisi = 0;
    for (int i = 0; i < gelen.length(); i++) {
        if (gelen[i] == ' ') {
            boslukSayisi++;
        }
    }
    return (boslukSayisi + 1);
};
int Dosya::satirHesapla() {//Dosyamızın içerisinde kaç tane satır olduğunu hesaplıyor
    ifstream dosya;
    dosya.open("./doc/kayitlar.txt", ios::in);
    int satirSayisi = 0;
    string satir;
    while (getline(dosya, satir)) {
        satirSayisi++;
    }
    dosya.close();
    return satirSayisi;
};
int Dosya::pozitifmi(int data){//Dosyadan okunan sayının pozitif olup olmadığını kontrol ediyor negatif ise pozitife çeviriyor
    if(data <0){
        return (data*(-1));
    }
    return data;
};
