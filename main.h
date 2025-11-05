#pragma once
#include "lib.h"


class Hasher {
private:
    vector<uint32_t> A;
    vector<string> B;
    string seed = "KRISTIS5";

    void ASCII(vector<uint32_t> & A);
    void sum(const string& input);
    void K();
    void R();
    void I();
    void S(int length);
    void T(int length);

public:
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
    void updateBalance(int amount);
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
    Hasher hasher;
    vector<Transaction> body;

    string previousHash;
    string timeStamp;
    string merkleRootHash;    
    string version;
    string difficulty;
    int nonce;
    string blockHash;


public:
    Block(string prevHash);

    string getPreviousHash() const;
    string getTimeStamp() const;
    string getVersion() const;
    string getBlockHash() const;
    int getNonce() const;
    string getDifficulty() const;

    void setHeader(vector<Transaction>& transactions, std::mt19937& mt);

    void bodyTransactions(vector<Transaction>& transactions, std::mt19937& mt);
    string calculateHash();
    string calculateMerkleRoot(const vector<Transaction>& txs);
    bool mineBlock(int maxAttempts, int& attemptsUsed);
};



class Blockchain {
private:
    vector<Block> chain;

public:
    Blockchain(std::mt19937& mt);  // konstruktorius su Genesis bloku

    Block getLatestBlock() const;
    void addBlock(vector<Transaction>& transactions, std::mt19937& mt);
    void printChain() const;
};



void userGen();
void transactionGen();

extern vector<User> users;
extern vector<Transaction> transactions;


