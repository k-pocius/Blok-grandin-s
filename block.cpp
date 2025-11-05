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
    bodyTransactions(transactions, mt);

    merkleRootHash = calculateMerkleRoot(body);
    timeStamp = to_string(static_cast<uint32_t>(std::time(nullptr)));    

}


void Block::bodyTransactions(vector<Transaction>& transactions, std::mt19937& mt) {
    if (transactions.empty()) {
        return;
    }
    int processed = 0;

    std::shuffle(transactions.begin(), transactions.end(), mt);

    body.clear(); // išvalom prieš užpildydami

    for (const auto& tx : transactions) {
        processed++;
        string expectedID = hasher.computeHash(
            tx.getSender() + " " + tx.getReceiver() + " " + to_string(tx.getAmount())
        );
        if (expectedID != tx.getTransactionID()) {
            continue; // neteisinga transakcija – praleidžiam
        }
        // surandam siuntėją
        for (auto& user : users) {
            if (user.getPublicKey() == tx.getSender()) {
                if (user.getBalance() >= tx.getAmount()) {
                    // atnaujinam balansus
                    user.updateBalance(-tx.getAmount());
                    for (auto& u : users) {
                        if (u.getPublicKey() == tx.getReceiver()) {
                            u.updateBalance(tx.getAmount());
                        }
                    }
                    body.push_back(tx);
                }
                break;
            }
        }
        if (body.size() >= 100) break;
    }

    // pašalinam tiek transakcijų, kiek įtraukėm į body
    transactions.erase(transactions.begin(), transactions.begin() + processed);
}




string Block::calculateHash() {
    string headerData = previousHash + timeStamp + version + merkleRootHash + to_string(nonce);
    return hasher.computeHash(headerData);
}

string Block::calculateMerkleRoot(const vector<Transaction>& txs) {
    vector<string> hashes;

    // 1. Paverčiame kiekvieną transakciją į maišą
    for (const auto& tx : txs) {
        hashes.push_back(hasher.computeHash(tx.getTransactionID()));
    }

    // 2. Kol turime daugiau nei vieną maišą, sujungiame poromis
    while (hashes.size() > 1) {
        vector<string> newHashes;
        for (int i = 0; i < hashes.size(); i += 2) {
            if (i + 1 < hashes.size()) {
                newHashes.push_back(hasher.computeHash(hashes[i] + hashes[i + 1]));
            } else {
                // Jei nelyginis skaičius – dubliuojame paskutinį
                newHashes.push_back(hasher.computeHash(hashes[i] + hashes[i]));
            }
        }
        hashes = newHashes;
    }

    // 3. Grąžiname šaknies maišą
    return hashes.empty() ? "" : hashes[0];
}


// Proof-of-Work kasimas
bool Block::mineBlock(int maxAttempts, int& attemptsUsed) {
    for (int i = 0; i < maxAttempts; i++) {
        nonce = i;
        blockHash = calculateHash();

        if (blockHash.substr(0, difficulty.size()) == difficulty) {
            attemptsUsed = i + 1;   // kiek bandymų prireikė
            return true;            // blokas iškastas
        }
    }

    attemptsUsed = maxAttempts;     // nepavyko, bet grąžinam kiek bandymų atlikta
    return false;
}



