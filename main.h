#pragma once
#include "lib.h"

extern vector<User> users;
extern vector<Transaction> transactions;


class Hasher {
private:
    vector<uint32_t> A;
    vector<string> B;
    const string seed = "KRISTIS5";

    void ASCII(vector<uint32_t> & A);
    void sum(const string& input);
    void K();
    void R();
    void I();
    void S(int length);
    void T(int length);

public:
    // Pagrindinis metodas, kurį naudosime main.cpp
    string computeHash(const string& input);
};




class User {
private:
    string name;
    string publicKey;
    uint32_t balance;

public:
    User(string n, string pk, uint32_t bal);

    string getName() const;
    string getPublicKey() const;
    uint32_t getBalance() const;
    void updateBalance(int amount); // papildomas metodas balanso keitimui
};




class Transaction{
private:
    string transactionID;
    string sender;
    string receiver;
    uint32_t amount;

public:
    Transaction(string id, string s, string r, uint32_t amt);

    string getTransactionID() const;
    string getSender() const;
    string getReceiver() const;
    uint32_t getAmount() const;
};

class Block{
private:
    string previousHash;
    string timeStamp;
    string version;
    string blockHash;
    int nonce;
    string difficulty;
    vector<Transaction> body;

public:
    Block(string prevHash, string time, string ver, string blkHash, int nce, string diff);

    string getPreviousHash() const;
    string getTimeStamp() const;
    string getVersion() const;
    string getBlockHash() const;
    int getNonce() const;
    string getDifficulty() const;

    void setBody(const vector<Transaction>& transactions);
    string randomTransactions(vector<Transaction>& transactions, std::mt19937& mt);

};


void userGen();
void transactionGen();

