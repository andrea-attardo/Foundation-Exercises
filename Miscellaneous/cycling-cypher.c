#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

string encodedString(string str, int key);

/*
 *CYCLING CYPHER
 *Data una stringa di testo e
 *una chiave di cifratura,
 *mostra la frase cifrata,
 *spostando ogni carattere del testo
 *secondo il numero chiave.
 *(es. chiave =3 lettera A diventa D)
 */

int main() {
    string strUsr;
    int key;
    
    printf("CYCLING CHYPER\n\n");
    printf("Inserisci una frase da cifrare\n");
    strUsr = GetLine();
    printf("Inserisci una chiave di cifratura (un numero)\n");
    key = GetInteger();
    printf("La frase cifrata e': %s\n\n", encodedString(strUsr, key));

    return 0;
}



string encodedString(string str, int key) {
    char encCh, checkingCh;
    string encStr = "";
    
    for (int i = 0; i < StringLength(str); i ++) {
        checkingCh = IthChar(str, i);
        char min, max;

        if (!isspace(checkingCh)) {  
            if (isupper(checkingCh)) {
                min = 'A';
                max = 'Z';
            } else {
                min = 'a';
                max = 'z';
            }
            if ((checkingCh + key) > max) {
                encCh = (checkingCh + key - max + min - 1);
            } else if ((checkingCh  + key) < min) {
                encCh = (checkingCh + key + max - min + 1);
            } else {
                encCh = (checkingCh + key);
            }
        } else {
            encCh = checkingCh;
        }

        encStr = Concat(encStr, CharToString(encCh));
    }
    return encStr;
}














