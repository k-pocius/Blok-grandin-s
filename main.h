#include "lib.h"

void sum(vector<int> & A){
    string a = "Labas";
    int j = 0;
    for(int i = 0; i < a.length(); i++){
        for(int x = 0; x < 3; x++){
            A[(i + x) % A.size()] += int(a[i]);
        }
    }
}

void K(vector<int> & A){ //“K” is like a key that unlocks and expands differences.
    for(int i = 0; i < A.size(); i++){
        A[i] *= i + 1;
    }
}

void R(vector<int> & A){ // R-rotate bits
    int n;
    for(int i = 0; i < A.size(); i++){
        n = (i % 3) + 1;
        A[i] = (A[i] << n) | (A[i] >> (32 - n));
    }
}

void I(vector<int> & A){ // I-invert bits XOR
    int n = A.size();
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < A.size(); i++){
            A[i] = (A[i] ^ A[(i + 1) % n]) + (A[(i + 2) % n] ^ A[(i + 3) % n]);
        }
    }
}

void S(vector<int> & A){ // S-shape hex format

}