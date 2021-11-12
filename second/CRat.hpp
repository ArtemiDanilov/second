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
    CRat(CRat &);
     int get_num(int n);
    int get_den(int n);
    void coordinates(int**, int);
    float lng();
    void print();
     int get_lenght();
    CRat &operator+(CRat &other);
    CRat &operator-(CRat &other);
    CRat &operator*(CRat &other);
    CRat &operator=(CRat &other);
    bool &operator==(CRat &other); 
    ~CRat();
};
