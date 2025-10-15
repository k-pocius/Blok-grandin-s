
const string s = "KRISTIS5";

void ASCII(vector<uint32_t> &A){
    for(char c : s){
        A.push_back(uint32_t(c));
    }
}

void sum(vector<uint32_t> &A){
    string a = "this is simple";
    for(int i = 0; i < a.length(); i++){
        for(int x = 0; x < 3; x++){
            A[(i + x) % A.size()] += uint32_t(a[i]);
        }
    }
}

void K(vector<uint32_t> &A){
    for(int i = 0; i < A.size(); i++){
        A[i] *= (i + 1);
    }
}

void R(vector<uint32_t> &A){
    int n;
    for(int i = 0; i < A.size(); i++){
        n = (i % 3) + 1;
        A[i] = (A[i] << n) | (A[i] >> (32 - n));
    }
}

void I(vector<uint32_t> &A){
    int n = A.size();
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < A.size(); i++){
            A[i] = (A[i] ^ A[(i + 1) % n]) + (A[(i + 2) % n] ^ A[(i + 3) % n]);
        }
    }
}

void S(vector<uint32_t> &A, vector<string> &B, int length){
    if(B.size() < A.size()) B.resize(A.size());
    
    for(int i = 0; i < A.size(); i++){
        B[i].clear();
        uint32_t number = A[i];
        string temp;
        for(int j = 0; j < length; j++){
            int nibble = number % 16;
            char a = (nibble < 10) ? '0' + nibble : 'A' + (nibble - 10);
            temp += a;
            number /= 16;
        }
        reverse(temp.begin(), temp.end());
        B[i] = temp;
    }
}

void T(vector<uint32_t> &A, vector<string> &B, int length){
    string hexString;
    vector<uint32_t> Tnums;
    vector<uint32_t> Knums;

    for(string x : B) hexString += x;

    // convert hex characters to 0-15 integers
    for(char c : hexString){
        if(isdigit(c)) Tnums.push_back(c - '0');
        else Tnums.push_back(c - 'A' + 10);
    }

    // key ASCII
    ASCII(Knums);

    // twist digits
    for(int i = 0; i < Tnums.size(); i++){
        Tnums[i] = (Tnums[i] + (Knums[i % 7] % 16)) % 16;
    }

    // repack 64 digits into 8 big numbers
    vector<uint32_t> newA;
    for(int i = 0; i < Tnums.size(); i += 8){
        uint32_t num = 0;
        for(int j = 0; j < 8; j++){
            num = (num << 4) | Tnums[i + j];
        }
        newA.push_back(num);
    }

    A = newA;
    B.resize(A.size());
}

