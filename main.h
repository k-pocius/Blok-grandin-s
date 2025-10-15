#include "lib.h"
#include <iostream>
#include <algorithm>
using namespace std;

const string s = "KRISTIS5";


void ASCII(vector<uint32_t> & A){
    for (char c : s){
        A.push_back(int(c));
    }
}

void sum(vector<uint32_t> & A, string a){
    for(int i = 0; i < a.length(); i++){
        for(int x = 0; x < 3; x++){
            A[(i + x) % A.size()] += int(a[i]);
        }
    }
}

void K(vector<uint32_t> & A){
    for(int i = 0; i < A.size(); i++){
        A[i] *= i + 1;
    }
}

void R(vector<uint32_t> & A){
    int n;
    for(int i = 0; i < A.size(); i++){
        n = (i % 3) + 1;
        A[i] = (A[i] << n) | (A[i] >> (32 - n));
    }
}

void I(vector<uint32_t> & A){
    int n = A.size();
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < A.size(); i++){
            A[i] = (A[i] ^ A[(i + 1) % n]) + (A[(i + 2) % n] ^ A[(i + 3) % n]);
        }
    }
}

void S(vector<uint32_t> & A, vector<string> & B, int length){
    if (B.size() < A.size()) B.resize(A.size());

    int number;
    char a;
    for(int i = 0; i < A.size(); i++){
        B[i].clear(); 
        number = A[i];
        for(int j = 0; j < length; j++){
            int val = abs(number % 16);  // ✅ Prevent negatives (fixes weird chars)

            if (val < 10)
                a = '0' + val;
            else {
                switch(number % 16) {
                    case 10: a = 'A'; break;
                    case 11: a = 'B'; break;
                    case 12: a = 'C'; break;
                    case 13: a = 'D'; break;
                    case 14: a = 'E'; break;
                    case 15: a = 'F'; break;
                }
            }
            B[i] += a;
            number = number / 16;
        }
        reverse(B[i].begin(), B[i].end());
    }
}

void T(vector<uint32_t>  & A, vector<string> & B, int length){
    string hexString;
    vector<int> Tnums;
    vector<uint32_t> Knums;
    for(string x : B){
        hexString += x;
    }

    ASCII(Knums);
    for(int i = 0; i < hexString.length(); i++){
        switch(hexString[i]){
            case '0': Tnums.push_back(0); break;
            case '1': Tnums.push_back(1); break;
            case '2': Tnums.push_back(2); break;
            case '3': Tnums.push_back(3); break;
            case '4': Tnums.push_back(4); break;
            case '5': Tnums.push_back(5); break;
            case '6': Tnums.push_back(6); break;
            case '7': Tnums.push_back(7); break;
            case '8': Tnums.push_back(8); break;
            case '9': Tnums.push_back(9); break;
            case 'A': Tnums.push_back(10); break;
            case 'B': Tnums.push_back(11); break;
            case 'C': Tnums.push_back(12); break;
            case 'D': Tnums.push_back(13); break;
            case 'E': Tnums.push_back(14); break;
            case 'F': Tnums.push_back(15); break;
        }
    }

    for(int i = 0; i < Tnums.size(); i++){
        Tnums[i] = (Tnums[i] + Knums[i % 7]) % 16;
    }

    vector<uint32_t>  newA;
    for(int i = 0; i < Tnums.size(); i += 8){
        int num = 0;
        for(int j = 0; j < 8; j++){
            num = (num << 4) | Tnums[i + j];
        }
        newA.push_back(num);
    }

    A = newA;
    B.resize(A.size());
}
