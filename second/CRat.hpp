//
//  CRat.h
//  second
//
//  Created by Артемий Данилов on 08.11.2021.
//
#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class CRat
{
private:
    int lenght;
    int **coord = new int*[2];
public:
    CRat();
    CRat(int lenght);
    int get_num(int n);
    int get_den(int n);
    void coordinates(int**, int);
    float lng();
    void print();
    CRat &operator+(CRat &other);
    CRat &operator-(CRat &other);
    float &operator*(CRat &other);
    CRat &operator=(CRat &other);
    bool &operator==(CRat &other); 
    ~CRat();
};
