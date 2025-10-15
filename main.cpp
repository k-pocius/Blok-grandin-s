#include "lib.h"
#include "main.h"


int main(){
    vector<uint32_t> A;
    vector<string> B;
    vector<string> TXT;

    string line;
    ifstream file("1000simb.txt");
    while (getline(file, line)) {
        TXT.push_back(line);
    }
    file.close();


    
    ofstream outFile("output.txt");
    for(string i : TXT){
        A.clear();
        B.clear();
        ASCII(A);
        sum(A, i); 

        K(A);
        R(A);
        I(A);
        S(A,B,8);
        T(A,B,8);
        I(A);
        S(A,B,8);

        for (string x : B) {
            outFile << x;
        }
        outFile << endl; 
    }
    outFile.close();

    return 0;
}

