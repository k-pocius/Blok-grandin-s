#include "main.h"

Blockchain::Blockchain(std::mt19937& mt) {
    // Genesis block with previousHash = "0"
    Block genesis("0");
    vector<Transaction> emptyTx;
    genesis.setHeader(emptyTx, mt);
    genesis.mineBlock(1000000);
    chain.push_back(genesis);
}

// Gauti paskutinį bloką
Block Blockchain::getLatestBlock() const {
    return chain.back();
}

// Pridėti naują bloką
void Blockchain::addBlock(vector<Transaction>& transactions, std::mt19937& mt) {

    vector <Block> fiveCandidates;
    string prevHash = getLatestBlock().getBlockHash();

    for(int i = 0; i < 5; i++){
        Block newBlock(prevHash);
        newBlock.setHeader(transactions, mt);
        fiveCandidates.push_back(newBlock);
    }
      
    int attempts = 5;
    bool mined = false;
    while(!mined){
        for(auto& block : fiveCandidates){
            mined = block.mineBlock(attempts);
            if(mined){
                chain.push_back(block);
                break;
            }
        }
        attempts *= 2;
    }
}

// Atspausdinti visą grandinę
void Blockchain::printChain() const {
    for (size_t i = 0; i < chain.size(); i++) {
        cout << "=== Block " << i << " ===" << endl;
        cout << "Previous Hash: " << chain[i].getPreviousHash() << endl;
        cout << "Block Hash:    " << chain[i].getBlockHash() << endl;
        cout << "Nonce:         " << chain[i].getNonce() << endl;
        cout << "Difficulty:    " << chain[i].getDifficulty() << endl;
        cout << "Version:       " << chain[i].getVersion() << endl;
        cout << "Timestamp:     " << chain[i].getTimeStamp() << endl;
        cout << endl;
    }
}
