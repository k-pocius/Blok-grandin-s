
Kaip naudotis programa?
į konsolę parašyti - make
tuomet sukompiliavus konsolėje parašyti - ./blockchain, tai paleis kodą.




User klasė <br>
Saugo informaciją apie vartotoją: vardą, viešą raktą (publicKey) ir balansą.


Transaction klasė<br>
Aprašo vieną transakcijas: ID, siuntėją, gavėją, sumą.
ID yra hash’as, apskaičiuotas iš siuntėjo, gavėjo ir sumos.


Hasher klasė<br>
Atsakinga už hash’ų skaičiavimą.
Metodai:<br>
computeHash() – paskaičiuoja bloko hash.


Block klasė saugo:<br>
previousHash, timestamp, merkleRootHash, version difficulty, nonce, blockHash.
body – transakcijų sąrašą.
Metodai:<br>
bodyTransactions(...) – atrenka 100 išmaišytų transakciju, patikrina ar sutampa transakciju ID, atnaujina user balansus, sudeda body vektorių.<br>
setHeader(...) - iš sugeneruotų 100 transakcijų sukuria merkleRootHash ir timestamp <br>
calculateHash(...) - skaičiuoja kasamo bloko hash'a<br>
calculateMerkleRoot(...) - iš 100 transakcijų id poromis atrenka transakcijas, iš jų padaro vieną hash ir taip kartoja kol lieka vienas hashas.<br>
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
Previous Hash: 000B2680927DD...<br>
Block Hash:    000B28C0C27B8...<br>
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



Sugeneruotų vartotojų vardas, public key ir balansas: <br>
![user](user.png) <br>



Sugeneruotų transakcijų ID, siuntejo, gavejo raktai, siunčiama suma.<br>
![transaction](transaction.png)<br>





Vartotojų balansai po patvirtintų transakcijų<br>
![after](afterMine.png)