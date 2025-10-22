#include "lib.h"
#include "main.h"

vector<uint32_t> A;
vector<string> B;
vector<string> TXT;


int main(){

    userGen();
    // transactionGen();
  
    string line;
    ifstream file("transactions.txt");
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
    cout << fixed << setprecision(6);
    return 0;
}

