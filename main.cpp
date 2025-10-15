#include "lib.h"
#include "main.h"


int main(){
    vector<uint32_t> A;
    ASCII(A);
    // for(int x : A){
    //     cout << x << " ";
    // }
    // cout << endl;
    sum(A); 
    // for(int x : A){
    //     cout << x << " ";
    // }
    cout << endl;   
    vector<string> B(A.size());

    
    K(A);
    // for(int x : A){
    //     cout << x << " ";
    // }
    // cout << endl;
    R(A);
    // for(int x : A){
    //     cout << x << " ";
    // }
    // cout << endl;
    I(A);
    // for(int x : A){
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << endl;
    S(A,B,8);
    // for(int x : A){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (string x : B){
    //     cout << x;
    // }
    // cout << endl;
    // cout << endl;
    T(A,B,8);
    //     for(int x : A){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (string x : B){
    //     cout << x;
    // }

    I(A);
    S(A,B,8);
    cout << endl;
    for (string x : B){
        cout << x;
    }

    return 0;
}

