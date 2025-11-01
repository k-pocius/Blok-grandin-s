#include "main.h"

// konstruktorius
User::User(string n, string pk, uint32_t bal) : name(n), publicKey(pk), balance(bal) {}

// metodai
string User::getName() const {
    return name;
}

string User::getPublicKey() const {
    return publicKey;
}

uint32_t User::getBalance() const {
    return balance;
}

void User::updateBalance(int amount) {
    balance += amount;
}
