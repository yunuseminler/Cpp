/**
* @file Node.h
* @description  Node.cpp kaynak kodlarının başlık dosyası,tanımlamalar yapılıyor.
* @course 2. Ogretim C grubu 
* @assignment 1
* @date ‎23 ‎Kasım ‎2020 ‎Pazartesi
*/

#ifndef NODE_HPP
#define NODE_HPP
#include <string>

class Node{
    public:
        std::string data;
        Node* after;
        Node* before;
        Node(std::string);
};

#endif