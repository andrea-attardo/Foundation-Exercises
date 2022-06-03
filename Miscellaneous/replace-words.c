#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

//Constants

//Functions Prototype
int myFindString(string str, string text, int start);
string replace(string text, string stc, string stp);

/*
 *REPLACE WORDS
 *Data un testo, inserita la parola 
 *da cambiare e la nuova parola da 
 *sostituire, il programma mostra
 *la nuova frase con la parola cambiata.
*/

//main
int main() {
    string text, stringToChange, stringToPut;
    
    text = "Cappuccetto Rosso andava per il bosco verso la casa della nonna";
    printf("%s\n", text);
    printf("inserisci le parola da cambiare: "); 
    stringToChange = GetLine();
    printf("inserisci le parola da mettere: ");
    stringToPut = GetLine();
    printf("Nuova frase: %s\n", replace(text, stringToChange, stringToPut)); 
   

    return 0;
}


//Functions implementions

int myFindString(string str, string text, int start) {
    char frstChStr;
    string sliceText;

    frstChStr = IthChar(str, 0);
    for (int i = start; i < StringLength(text); i++) {
        if (frstChStr == IthChar(text, i)) {
            sliceText = SubString(text, i, (i + StringLength(str) - 1));
            if (StringEqual(str, sliceText)) return i;    
        }
    }
    return -1; //return -1 if nothing is found

}


string replace(string text, string stc, string stp) { //stc = stringtochange, stp = stringtoput
    int startStc, endStc;
    string beforeStc, afterStc, newText;

    newText = text;
    for (int i = 0; i < StringLength(text); i++) {
        if (myFindString(stc, newText, i) != - 1) {
            startStc = myFindString(stc, newText, i);
            endStc = (startStc + StringLength(stc) - 1);
            afterStc = SubString(newText, endStc + 1, (StringLength(newText) - 1));
            beforeStc = SubString(newText, 0, startStc - 1); 
            newText = Concat(Concat(beforeStc, stp), afterStc);
        }
    }
    return newText;
}












