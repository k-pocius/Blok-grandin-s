#include "main.h"
#include <random>
#include <iostream>

int main() {
    // 1. Sugeneruojame vartotojus ir transakcijas
    userGen();
    transactionGen();

    // 2. Paruošiame random generatorių
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));

    // 3. Sukuriame bloką
    // Genesis blokui previousHash = "0"
    Block newBlock("0");

    // 4. Užpildome header (timestamp + merkle root hash)
    newBlock.setHeader(transactions, mt);

    // 5. Iškasame bloką
    newBlock.mineBlock();

    // 6. Išvedame rezultatą
    std::cout << "Previous Hash: " << newBlock.getPreviousHash() << std::endl;
    std::cout << "Block Hash:    " << newBlock.getBlockHash() << std::endl;
    std::cout << "Nonce:         " << newBlock.getNonce() << std::endl;
    std::cout << "Difficulty:    " << newBlock.getDifficulty() << std::endl;
    std::cout << "Version:       " << newBlock.getVersion() << std::endl;
    std::cout << "Timestamp:     " << newBlock.getTimeStamp() << std::endl;

    return 0;
}

