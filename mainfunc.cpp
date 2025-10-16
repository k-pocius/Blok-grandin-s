#include "lib.h"
#include "main.h"
#include <sstream>


const string s = "KRISTIS5";
using hrClock = std::chrono::high_resolution_clock;
std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
std::uniform_int_distribution<int> dist(1, 10);


string random_string(size_t length) {
    const string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*-_=+?/,.;:";
    string result;
    for (size_t i = 0; i < length; ++i) {
        result += symbols[dist(mt) % symbols.size()];
    }
    return result;
}


void generuojam(){
    vector<int> lengths = {10, 100, 500, 1000};
    const int pairs_per_file = 100000;

    for (int length : lengths) {
        string filename = to_string(length) + "sugeneruota" + ".txt";
        ofstream file(filename);

        for (int i = 0; i < pairs_per_file; ++i) {
            string s1 = random_string(length);
            string s2 = random_string(length);
            file << s1 << " " << s2 << "\n";
        }

        file.close();
    }
}

void generuojamsimb(){
    const int pairs_per_file = 100000;
        string filename = "2string.txt";
        ofstream file(filename);

        for (int i = 0; i < pairs_per_file; ++i) {
            string a = random_string(1);
            string b = random_string(1);
            while(b == a){
                b = random_string(1);
            }
            string s1 = "la" + a + "as";
            string s2 = "la" + b + "as";
            file << s1 << " " << s2 << "\n";
        }
    file.close();
}


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
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < A.size(); i++){
            A[i] = (A[i] ^ A[(i + 1) % n]) + (A[(i + 2) % n] ^ A[(i + 3) % n]);
        }
    }
}

void S(vector<uint32_t> &A, vector<string> &B, int length) {
    if (B.size() < A.size()) B.resize(A.size());

    for (int i = 0; i < A.size(); i++) {
        B[i].clear();
        uint32_t number = A[i];
        char a;

        for (int j = 0; j < length; j++) {
            int val = number % 16;  // use unsigned math to avoid negatives
            if (val < 10)
                a = '0' + val;
            else {
                switch (val) {  // ✅ restored your original style
                    case 10: a = 'A'; break;
                    case 11: a = 'B'; break;
                    case 12: a = 'C'; break;
                    case 13: a = 'D'; break;
                    case 14: a = 'E'; break;
                    case 15: a = 'F'; break;
                }
            }
            B[i] += a;
            number /= 16;
        }

        reverse(B[i].begin(), B[i].end());
    }
}



void T(vector<uint32_t>  & A, vector<string> & B, int length){
    string hexString;
    vector<uint32_t> Tnums;
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