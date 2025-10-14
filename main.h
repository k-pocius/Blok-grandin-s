#include "lib.h"

void sum(vector<int> & A){
    string a = "  ";
    int j = 0;
    for(int i = 0; i < a.length(); i++){
        for(int x = 0; x < 3; x++){
            A[(i + x) % A.size()] += int(a[i]);
        }
    }
}

