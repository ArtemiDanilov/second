#include <stdio.h>
#include "Header.hpp"

int autotest_1(){
    int k = 2, m = 1;
    int **arr = new int*[k];
    arr[0] = new int[m];
    arr[1] = new int[m];
    
    int **arr_2 = new int*[k];
    arr_2[0] = new int[m];
    arr_2[1] = new int[m];
    
    int **r = new int*[k];
    r[0] = new int[m];
    r[1] = new int[m];
    
    arr[0][0] = 1;
    arr[1][0] = 2;
    
    arr_2[0][0] = 3;
    arr_2[1][0] = 2;
    
    r[0][0] = 4;
    r[1][0] = 2;
    
    CRat v_1;
    CRat v_2;
    CRat res;
    v_1.coordinates(arr, m);
    v_2.coordinates(arr_2, m);
    res.coordinates(r, m);
    CRat sum = v_1 + v_2;
    if(sum == res){
        k = 1;
    }
    else{
        k = 0;
    }
    delete [] arr[0];
    delete [] arr[1];
    delete [] arr;
    
    delete [] arr_2[0];
    delete [] arr_2[1];
    delete [] arr_2;
    
    delete [] r[0];
    delete [] r[1];
    delete [] r;

    return k;
}

int autotest_2(){
    int k = 2, m = 1;
    int **arr = new int*[k];
    arr[0] = new int[m];
    arr[1] = new int[m];
    
    int **arr_2 = new int*[k];
    arr_2[0] = new int[m];
    arr_2[1] = new int[m];
    
    int **r = new int*[k];
    r[0] = new int[m];
    r[1] = new int[m];
    
    arr[0][0] = 1;
    arr[1][0] = 2;
    
    arr_2[0][0] = 3;
    arr_2[1][0] = 2;
    
    r[0][0] = -2;
    r[1][0] = 2;
    
    CRat v_1;
    CRat v_2;
    CRat res;
    CRat sum = v_1 - v_2;
    v_1.coordinates(arr, m);
    v_2.coordinates(arr_2, m);
    res.coordinates(r, m);
    if(sum == res){
        k = 1;
    }
    else{
        k = 0;
    }
    delete [] arr[0];
    delete [] arr[1];
    delete [] arr;
    
    delete [] arr_2[0];
    delete [] arr_2[1];
    delete [] arr_2;
    
    delete [] r[0];
    delete [] r[1];
    delete [] r;
    
    
    return k;
}


void Autotest(){
    if(autotest_1() == 1){
        cout << "First autotest passed!" << endl;
    }
    else{
        cout << "First autotest failed!" << endl;
    }
    if(autotest_2() == 1){
        cout << "Second autotest passed!" << endl;
    }
    else{
        cout << "Second autotest failed!" << endl;
    }
}
