User klasė <br>
Saugo informaciją apie vartotoją: vardą, viešą raktą (publicKey) ir balansą.


Transaction klasė<br>
Aprašo vieną transakcijas: ID, siuntėją, gavėją, sumą.
ID yra hash’as, apskaičiuotas iš siuntėjo, gavėjo ir sumos.


Hasher klasė<br>
Atsakinga už hash’ų skaičiavimą.
Naudojama tiek transakcijų ID patikrai, tiek blokų hash’ams generuoti.
Metodai:<br>
computeHash() – paskaičiuoja bloko hash.


Block klasė saugo:<br>
previousHash, timestamp, merkleRootHash, version difficulty, nonce, blockHash.
body – transakcijų sąrašą.
Metodai:<br>
bodyTransactions(...) – atrenka 100 išmaišytų transakciju, patikrina jų galiojimą, atnaujina balansus, sudeda į bloką.<br>
calculateHash(...) - skaiciuoja kasamo bloko hash'a<br>
calculateMerkleRoot(...) - iš 100 transakcijų id poromis atrenka transakcijas ir iš jų padaro vieną hash, ir taip kartoja kol lieka vienas hashas.<br>
mineBlock(...) – ieško nonce, kad hash atitiktų difficulty.


Blockchain klasė<br>
Laiko visą blokų grandinę (vector<Block> chain).
Prideda naujus blokus.
metodai:<br>
Blockchain(...) - konstruktorius, sukonstruoja genesis bloka.<br>
addBlock(...) -  sukuria 5 kandidatinius blokus, kuriuos lygegriačiai kasa, o po to prideda į blockchain su mažiausiu nonce.<br>
printChain(...) - atspausdina visus iškastus blokus į konsolę<br>

main.cpp<br>
vykdo vartotojų ir transakcijų generavimą.
Inicijuoja blockchain’ą.



Programos eiga nuo pradžios iki galo:


1. Iš users.txt sukuriami User objektai: vardas, publicKey, balansas<br>

2. Iš transactions.txt sukuriamos Transaction struktūros su ID, siuntėju, gavėju, suma.<br>

3. Sukuriamas genesis blokas iš tuščių transakcijų.<br>

Po to vyksta blokų paruošimas pridėti juos į blockchaina, kol nebeliks transakcijų:<br>

4. Iš pradžių gauname praeito bloko hash.<br>

5. Sugneruojame 5 kandidatinius blokus.<br>

6. Sudedam juos į fiveCadidates vektorių.<br>

7. Paraleliai kasam visus 5 blokus.<br>

8. Jei nors vienas blokas iškastas, pridedam jį i blockchain, jei yra daugiau blokų, pridedam, kurio nonce mažiausias.<br>

9. Spausdinam iškastus blokus į konsolę.<br>


Konsolėje parodoma:<br>

![blokas](console.png)<br>
=== Block 3 ===<br>
Previous Hash: 0002C360B7ED71B4...<br>
Block Hash:    000C0F5AC4ECC83E...<br>
Nonce:         512<br>
Difficulty:    000<br>
Version:       v0.1<br>
Timestamp:     1762360054<br>
Tai reiškia:<br>
Blokas Nr. 20 buvo sukurtas.<br>
Ankstesnio bloko hash.<br>
Bloko hash.<br>
Nonce buvo rastas 512‑uoju bandymu.<br>
Sunkumas - Bloko hash prasideda ("000").<br>
Bloko versija. <br>
Timestamp rodo Unix laiką, kada blokas buvo sugeneruotas.