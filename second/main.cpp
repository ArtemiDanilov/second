#include <iostream>
#include <math.h>
#include "Header.hpp"

using namespace std;


int main(){
    Autotest();
    int n = 0, a = 0, m = 0, b = 0, k = 0;
    cout << "Write lenght of vectors:" << endl;
    cin >> n;
    int **coord = new int*[2];
    coord[0] = new int[n];
    coord[1] = new int[n];
    cout << "How many vectors you want to make:" << endl;
    cin >> m;
    CRat* vectors = new CRat[m];
    for(int j = 0; j < m; j++){
    for(int i = 0; i < n; i++){
        cout << "Write numerator of "<< i+1 <<"'th coordinate of " << j+1<< "th vector:" << endl;
        cin >> a;
        coord[0][i] = a;
        cout << "Write denominator of "<< i+1 <<"'th coordinate of " << j+1<< "th vector:"  << endl;
        cin >> a;
        if(a > 0){
        coord[1][i] = a;
        }
        else{
            cout << "Please, enter a number greater than zero:" << endl;
            cin >> a;
            coord[1][i] = a;
        }
    }
        vectors[j].coordinates(coord, n);
        cout << endl;
    }
    delete [] coord[0];
    delete [] coord[1];
    delete [] coord;
    cout << "What do you wanna do?" << endl << "1.Add two vectors" << endl << "2.Find the difference of two vectors" << endl << "3.Multiply two vectors" << endl;
    cin >>  a;
    cout << "Write the numbers of vectors" << endl;
    cin >> b  >> k;
    b--;
    k--;
    if (a == 1) {
        CRat res(n);
        res = vectors[b] + vectors[k];
        cout << "Answer:" << endl;
        res.print();
        cout << endl;
    }
    if (a == 2) {
        CRat res(n);
        res = vectors[b] - vectors[k];
        cout << "Answer:" << endl;
        res.print();
        cout << endl;
    }
    if (a == 3) {
        cout << "Answer:" << endl;
        CRat res(n);
        res = vectors[b] * vectors[k];
        res.print();
    }
    
    return 0;
}
