#include "lib.h"

// konstanta: KRISTIS5
void sum(int A[]);

int main(){
    const string s = "KRISTIS5";
    int A[s.length()];
    for (int i = 0; i < s.length(); i++){
        A[i] = int(s[i]);
        cout << int(A[i]) << " ";
    }
    cout << endl;
    sum(A);
    for (int i = 0; i < s.length(); i++){
        cout << int(A[i]) << " ";
    }
}

void sum(int A[]){
    int sum;
    string a = "  ";
    int j = 0;
    for(int i = 0; i < a.length(); i++){
        int x = 0;
        while(x != 3){
            A[(i + x) % 8] += int(a[i]);
            x++;
        }
    }
}