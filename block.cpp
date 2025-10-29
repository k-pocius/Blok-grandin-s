#include "main.h"

Block::Block(string prevHash) : 
previousHash(prevHash), version("v0.1"), difficulty("000"), nonce(0), blockHash("") {}

string Block::getPreviousHash() const{
    return previousHash;
}
    
string Block::getTimeStamp() const{
    return timeStamp;
}

string Block::getVersion() const{
    return version;
}

string Block::getDifficulty() const{
    return difficulty;
}

string Block::getBlockHash() const { 
    return blockHash; 
}

int Block::getNonce() const { 
    return nonce; 
}


void Block::setHeader(vector<Transaction>& transactions, std::mt19937& mt) {
    string txIDs = bodyTransactions(transactions, mt);

    timeStamp = to_string(static_cast<uint32_t>(std::time(nullptr)));
    merkleRootHash = hasher.computeHash(txIDs);
    // version ir difficulty gali būti nustatyti konstruktoriuje
}


string Block::bodyTransactions(vector<Transaction>& transactions, std::mt19937& mt){
    if(transactions.empty()) {
        cout << "No more transactions to include in a block." << endl;
        return "";
    }

    size_t numTx = min((size_t)100, transactions.size());

    // Maišome globalų vektorių
    std::shuffle(transactions.begin(), transactions.end(), mt);

    // Paimame pirmas numTx transakcijas
    body.assign(transactions.begin(), transactions.begin() + numTx);

    // Pašaliname įtrauktas transakcijas iš globalaus vektoriaus
    transactions.erase(transactions.begin(), transactions.begin() + numTx);

    string txIDs; //transaction IDs
    for(const auto& tx : body){
        txIDs += tx.getTransactionID();
    }
    return txIDs;
}

string Block::calculateHash() {
    string headerData = previousHash + timeStamp + version + merkleRootHash + to_string(nonce);
    return hasher.computeHash(headerData);
}

// Proof-of-Work kasimas
void Block::mineBlock() {
    nonce = 0;
    do {
        nonce++;
        blockHash = calculateHash();
    } while (blockHash.substr(0, difficulty.size()) != difficulty);

}

