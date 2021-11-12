#include "CRat.hpp"
#include <math.h>

    CRat :: CRat(){
        this->coord = new int*[2];
        lenght = 0;
    }
    CRat :: CRat(CRat & cop){
        lenght = cop.get_lenght();
        coord = new int*[2];
        coord[0] = new int [lenght];
        coord[1] = new int [lenght];
        for(int i = 0; i < lenght; i++){
            coord[0][i] = cop.get_num(i);
            coord[1][i] = cop.get_den(i);
        }
}
    CRat :: CRat(int lenght){
        this->coord = new int*[2];
        coord[0] = new int [lenght];
        coord[1] = new int [lenght];
        this->lenght = lenght;
    }
     int CRat :: get_num(int n){
        
        return coord[0][n];
    }
    
     int CRat :: get_den(int n){
        return coord[1][n];
    }
    int CRat :: get_lenght(){
        return lenght;
    }
    void CRat :: coordinates(int** arr, int lenght){
        coord[0] = new int [lenght];
        coord[1] = new int [lenght];
        this->lenght = lenght;
        for(int i = 0; i < lenght; i++){
            coord[0][i] = arr[0][i];
            coord[1][i] = arr[1][i];
        }
    }
    float CRat :: lng(){
        float l = 0;
        float denominator = 1, numerator = 0, a = 1;
        for(int i = 0; i < lenght; i++){
            a *= coord[1][i];
        }
        denominator = a*a;
        for(int i = 0; i < lenght; i++){
            numerator += (pow(coord[0][i], 2) * denominator) / (pow(coord[1][i], 2));
        }
        l = sqrt(numerator/denominator);
        return l;;
    }
    void CRat :: print(){
        int m = 0;
        for(int i = 0; i < lenght; i++){
            if(abs(coord[0][i]) < abs(coord[1][i])){
              m = abs(coord[0][i]);
            }
            else{
                m = abs(coord[1][i]);
            }
            for(int j = m; j > 1; j--){
            if(abs(coord[0][i]) % j == 0 && abs(coord[1][i]) % j == 0){
                coord[0][i] /= j;
                coord[1][i] /= j;
            }
            }
        }
        cout << "(";
        for(int i = 0; i < lenght; i++){
            if(coord[0][i] == 0 || coord[0][i] == coord[1][i] || coord[1][i] == 1){
                if(coord[0][i] == 0){
                    cout << "0";
                    continue;
                }
                if(coord[0][i] == coord[1][i]){
                    cout << "1";
                    continue;
                }
                if (coord[1][i] == 1) {
                    cout << coord[0][i];
                    continue;
                }
            }
            else{
            cout << coord[0][i] << "/" << coord[1][i];
            }
            if(i < lenght-1){
                cout << ",";
            }
        }
        cout << ")";
    }
    CRat &CRat :: operator+(CRat &other){
        for(int i = 0; i < lenght; i++){
            int numerator = 0;
            if(this->coord[1][i] == other.get_den(i)){
                this->coord[0][i] += other.get_num(i);
            }
            else{
            numerator = this->coord[0][i] * other.get_den(i) + this->coord[1][i] * other.get_num(i);
            this->coord[1][i] *= other.get_den(i);
            this->coord[0][i] = numerator;
            }
        }
        return *this;
    }
    
    CRat &CRat :: operator-(CRat &other){
        for(int i = 0; i < lenght; i++){
            int numerator = 0;
            if(this->coord[1][i] == other.get_den(i)){
                this->coord[0][i] -= other.get_num(i);
            }
            else{
            numerator = this->coord[0][i] * other.get_den(i) - this->coord[1][i] * other.get_num(i);
            this->coord[1][i] *= other.get_den(i);
            this->coord[0][i] = numerator;
        }
        }
        return *this;
    }
    
    CRat &CRat :: operator*(CRat &other){
        int numerator = 0, denominator = 1;
        float swe = 0, tpu = 0;
        for(int i = 0; i < lenght; i++){
            denominator *= this->coord[1][i] * other.get_den(i);
            
        }
        for(int i = 0; i < lenght; i++){
            numerator += (this->coord[0][i] * other.get_num(i) * denominator) / (this->coord[1][i] * other.get_den(i));
        }
        swe = numerator;
        tpu = denominator;
        int **arr = new int*[2];
        arr[0] = new int[1];
        arr[1] = new int[1];
        CRat rez;
        rez.coordinates(arr, 1);
        delete [] arr[0];
        delete [] arr[1];
        delete [] arr;
        return rez;
    }
    
    CRat &CRat :: operator=(CRat &other){
        for(int i = 0; i < lenght; i ++){
            this->coord[0][i] = other.get_num(i);
            this->coord[1][i] = other.get_den(i);
        }
        return *this;
    }
    bool &CRat :: operator==(CRat &other){
        bool k = true;
    for(int i = 0; i < lenght; i ++){
        if (this->coord[0][i] != other.get_num(i) || this->coord[1][i] != other.get_den(i)) {
            k = false;
        }
    }
    return k;
}
    CRat :: ~CRat(){
        if(*coord[0] != NULL){
        delete [] coord[0];
        }
        if(*coord[1] != NULL){
        delete [] coord[1];
        }
        if(*coord != NULL){
        delete [] coord;
        }
    }
