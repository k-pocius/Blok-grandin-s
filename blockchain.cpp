#include "main.h"

Blockchain::Blockchain(std::mt19937& mt) {
    // Genesis block with previousHash = "0"
    Block genesis("0");
    vector<Transaction> emptyTx;
    genesis.setHeader(emptyTx, mt);
    int zero = 0;
    genesis.mineBlock(1000000, zero);
    chain.push_back(genesis);
}

// Gauti paskutinį bloką
Block Blockchain::getLatestBlock() const {
    return chain.back();
}


// Pridėti naują bloką

void Blockchain::addBlock(vector<Transaction>& transactions, std::mt19937& mt) {
    string prevHash = getLatestBlock().getBlockHash();
    int maxAttempts = 1000; 
    bool mined = false;
    Block bestBlock(prevHash);
    int bestNonce = INT_MAX;

    // 1. Sugeneruojam 5 kandidatus
    vector<Block> fiveCandidates;
    for (int i = 0; i < 5; i++) {
        Block newBlock(prevHash);
        newBlock.setHeader(transactions, mt);
        fiveCandidates.push_back(newBlock);
    }

    while (!mined) {
        // 2. Paleidžiam lygiagrečiai
        vector<int> attemptsUsed(5, 0);
        vector<std::future<bool>> futures;
        for (int i = 0; i < 5; i++) {
            futures.push_back(std::async(std::launch::async,
                [&fiveCandidates, i, maxAttempts, &attemptsUsed]() {
                    return fiveCandidates[i].mineBlock(maxAttempts, attemptsUsed[i]);
                }
            ));
        }

        // 3. Surenkam rezultatus
        for (int i = 0; i < 5; i++) {
            bool success = futures[i].get();
            if (success) {
                int nonce = fiveCandidates[i].getNonce();

                // išrenkam geriausią (mažiausią nonce)
                if (nonce < bestNonce) {
                    bestNonce = nonce;
                    bestBlock = fiveCandidates[i];
                }
                mined = true;
            }
        }

        // 4. Jei nei vienas neiškastas – didinam limitą
        if (!mined) {
            maxAttempts *= 2;
        }
    }

    // 5. Į grandinę pridedam geriausią bloką
    chain.push_back(bestBlock);
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
