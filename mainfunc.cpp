#include "lib.h"
#include "main.h"
#include <sstream>

vector <User> users;
vector <Transaction> transactions;


const string s = "KRISTIS5";
using hrClock = std::chrono::high_resolution_clock;
std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
std::uniform_int_distribution<int> dist(1, 1000000);
std::uniform_int_distribution<int> dist_1000(0, 999);


void userGen(){
    const string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*-_=+?/,.;:";
    vector <string> Names = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ian", "Jack",
                    "Kara", "Liam", "Mia", "Noah", "Olivia", "Paul", "Quinn", "Rachel", "Sam", "Tina",
                    "Uma", "Victor", "Wendy", "Xavier", "Yara", "Zach", "Leo", "Nora", "Max", "Jade"};
    ofstream file("user.txt");
    for (size_t i = 0; i < 1000; ++i) {
        string key;
        for(int j = 0; j < 10; j++){
            key += symbols[dist(mt) % symbols.size()];
        }
        string name = Names[dist(mt) % Names.size()];
        uint32_t balance = dist(mt);
        users.push_back(User(name, key, balance));
        file << name << " " << key << " " << balance << "\n";
    }
    file.close();
}

void transactionGen(){
    Hasher hasher;

    ofstream file("transaction.txt");
    for (int i = 0; i < 10000; i++) {
        int a = dist_1000(mt);
        int b = dist_1000(mt);
        while(a == b){
            b = dist_1000(mt);
        }

        uint32_t amount = dist(mt) % users[a].getBalance();
        string line = users[a].getPublicKey() + " " + users[b].getPublicKey() + " " + to_string(amount);

        string hash = hasher.computeHash(line);

        transactions.push_back(Transaction(hash, users[a].getPublicKey(), users[b].getPublicKey(), amount));
        file << hash << " " << line << "\n";
    }
    file.close();
}

