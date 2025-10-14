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
    for (int x : A){
        cout << x << " ";
    }
}

