#include "lib.h"
#include "main.h"


int main(){
    const string s = "KRISTIS5";
    vector<int> A;
    for (char c : s){
        A.push_back(c);
        cout << int(c) << " ";
    }
    vector<string> B(A.size());
    cout << endl;
    sum(A);
    K(A);
    R(A);
    I(A);
    S(A, B, 8);
    for (string x : B){
        cout << x;
    }

    return 0;
}

