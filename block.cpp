#include "main.h"

Block::Block(string prevHash, string time, string ver, string blkHash, int nce, string diff) : 
previousHash(prevHash), timeStamp(time), version(ver), blockHash(blkHash), nonce(nce), difficulty(diff) {}

string Block::getPreviousHash() const{
    return previousHash;
}
    
string Block::getTimeStamp() const{
    return timeStamp;
}

string Block::getVersion() const{
    return version;
}

string Block::getBlockHash() const{
    return blockHash;
}

int Block::getNonce() const{
    return nonce;
}

string Block::getDifficulty() const{

}

void Block::setBody(const vector<Transaction>& transactions){
    body = transactions;
}

string Block::randomTransactions(vector<Transaction>& transactions, std::mt19937& mt){
    if(transactions.empty()) {
        cout << "No more transactions to include in a block." << endl;
        return;
    }

    size_t numTx = min((size_t)100, transactions.size());

    // Maišome globalų vektorių
    std::shuffle(transactions.begin(), transactions.end(), mt);

    // Paimame pirmas numTx transakcijas
    body.assign(transactions.begin(), transactions.begin() + numTx);

    // Pašaliname įtrauktas transakcijas iš globalaus vektoriaus
    transactions.erase(transactions.begin(), transactions.begin() + numTx);
}
