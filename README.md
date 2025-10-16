# Bloku grandines

HASH GENERATORIUS

Idėja: Naudoju savo vardo trumpinį KRISTIS + simbolį 5, kad iš viso būtų 8 simboliai = 8 baitai (64 bitai). Toliau programos eigoje, prie savo vardo pridedu nuskaityto failo string'u ASCII vertes ir vykdau funkcijas iš savo vardo raidžių kurios atspindi ką funkcijos daro. PVZ:

K - Key weighting (multiplication by index)
R - Rotate bits (bitwise rotation)
I - Iterative mixing (XOR + addition)
S - Stringify (convert to HEX string)
T - Transform (text merge and key re-application)
I - Iterative mixing (XOR + addition)
S - Stringify (convert to HEX string)

Veikimo principas, pseudo kodas:

K: 
kiekvienas elementas padauginamas iš indekso
A[i] = A[i] * (i + 1)

R:
bitų rotacija, perkelia kiekvieno elemento bitus į kairę per 1-3 vietas 
A[i] = (A[i] << ((i % 3) + 1)) | (A[i] >> (32 - ((i % 3) + 1)))

I:
5 kartus sumaišo bitus pagal XOR operaciją
repeat 5 times:
    A[i] = (A[i] XOR A[i+1]) + (A[i+2] XOR A[i+3])

S:
paverčia kiekvieną 32bit skaičių į 8 ženklų hex string
for each A[i]:
    B[i] = toHex(A[i], length=8)

T:
sujungia visus hex ženklus į vieną, sudeda baitus su KRISTIS5 
ir atstato į 32bitų bloką
hexString = concat(B)
Tnums = convertHexToNibbles(hexString)
for each Tnums[i]:
    Tnums[i] = (Tnums[i] + ASCII("KRISTIS5")[i % 7]) % 16
A = groupEach8NibblesInto32bit(Tnums)




![Diagrama](diagram.png)



porų hash'ai nesutampa




Išvada: kodas veikia, tačiau pati idėja nėra optimali, kadangi kodas skaičius į hex formatą verčia du kartus.