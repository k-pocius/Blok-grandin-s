#include "main.h"
#include <random>
#include <iostream>

int main() {
    // 1. Sugeneruojame vartotojus ir transakcijas
    userGen();
    transactionGen();

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));

    Blockchain myChain(mt);

    // Pridedame kelis blokus
    while(!transactions.empty()){
        myChain.addBlock(transactions, mt);
    }

    // Atspausdiname visą grandinę
    myChain.printChain();

    return 0;
}

