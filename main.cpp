#include "lib.h"
#include "main.h"


int main(){
    const string s = "KRISTIS5";
    vector<int> A;
    for (char c : s){
        A.push_back(c);
        cout << int(c) << " ";
    }
    cout << endl;
    sum(A);
    K(A);
    R(A);
    I(A);
    for (int x : A){
        cout << x << " ";
    }
    cout << A.size() << endl;
}

