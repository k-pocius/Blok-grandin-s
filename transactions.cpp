#include "main.h"

Transaction::Transaction(string id, string s, string r, uint32_t amt) : transactionID(id), sender(s), receiver(r), amount(amt) {}

string Transaction::getTransactionID() const {
    return transactionID;
}

string Transaction::getSender() const {
    return sender;
}

string Transaction::getReceiver() const {
    return receiver;
}

uint32_t Transaction::getAmount() const {
    return amount;
}
