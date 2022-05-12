#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

string extractAlnum(string str);
bool isPalindrome(string str);

/*
 *FRASE PALINDROMA CHECK
 *Data una frase,
 *controlla se è palinroma,
 *non considerando spazi o
 *punteggiatura. 
 *(es. "Madam, I'm Adam." è palindroma)
*/

//main
int main() {
    string sentence;
    
    while(TRUE) {
        printf("\nFRASE PALINDROMA CHECK\n");
        printf("----------------------\n");
        printf("Insert sentence to check: ");

        sentence = GetLine();
        printf("Is the sentence %s palidrome?\n", sentence);
        (isPalindrome(extractAlnum(sentence) ? printf("Yes.\n") : printf("No.\n"); 

        printf("-------THE END--------\n\n");
    }

    return 0;
}


//Functions implementation

string extractAlnum(string str) {
    char lastChar, ithCh;;
    string alnumStr;

    lastChar = (StringLength(alnumStr) - 1);
    for (int i =  0; i < StringLength(alnumStr); i++) {
        ithCh = IthChar(alnumStr, i);
        if (ispunct(ithCh) || isspace(ithCh)) {
            alnumStr = Concat(SubString(alnumStr, 0, i - 1), SubString(alnumStr, (i + 1), lastChar));
            i--;
        }
    }
    return alnumStr;    
}


bool isPalindrome(string str) {
    string lowerStr = ConvertToLowerCase(str);
    
    for (int i =  0; i < (StringLength(lowerStr) / 2); i++) {
            if (IthChar(lowerStr, i) != IthChar(lowerStr, (StringLength(lowerStr) - 1 - i))) { 
                return FALSE; 
            }
    }
    return TRUE;
}












