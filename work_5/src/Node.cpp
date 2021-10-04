/**
* @file Node.cpp
* @description Node classının fonksiyonlarının içeriğini tanımlıyoruz.
* @course 2. Ogretim C grubu 
* @assignment 1
* @date ‎23 ‎Kasım ‎2020 ‎Pazartesi
*/
#include "Node.h"
#include <iostream>

Node::Node(std::string data){//Node constructor fonksiyon tanımlaması
    this->data = data;
    this->after = NULL;
    this->before = NULL;
}