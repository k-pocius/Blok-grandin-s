#include "lib.h"
#include "main.h"


int main(){
    vector<uint32_t> A;
    vector<string> B;
    vector<string> TXT;

    generuojam();
    generuojamsimb();

    string line;
    ifstream file("2string.txt");
    while (file >> line) {
        TXT.push_back(line);
    }
    file.close();

    ofstream outFile("output.txt");
    int x = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for(string i : TXT){
        if(x == 100000) break;
        x++;
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
    auto end = std::chrono::high_resolution_clock::now();
    cout << fixed << setprecision(6);
    cout << "Hashing time: " << std::chrono::duration<double>(end - start).count() << " seconds" << endl;

    return 0;
}

