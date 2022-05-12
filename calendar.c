#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*FUNCTIONs PROTOTYPEs
--------------------*/
int GetYearFromUser(void);
void GiveInstructions(void);
void PrintCalendar(int year);
bool IsALeapYear(int year);
int DaysInMonth(int year, int month);
int AnnualDateCount(int year, int month, int day);   
int WichDayIs(int year, int month, int day);
void PrintHeadMonth(int year, int month);
string MonthName(int month);
void IndentationFirstDayMonth(year, month, day);
void PrintDays(year, month); 

/*------------CALENDAR-----------------
 *Questo programma, dato un anno inserito
 *dall'utente, mostra tutti i mesi dell'anno.
 * in un range dal 1582 a 9999
*/

/*  MAIN 
-----------*/
int main(int argc, char const *argv[]){
    int year;

    GiveInstructions();
    year = GetYearFromUser();
    PrintCalendar(year);
    
}
    

/*FUNCTIONs IMPLEMENTATIONS
------------------------*/
int GetYearFromUser(void) {
    int year;

    while(TRUE) {
        year = GetInteger();
        if( year > 1582 && year <= 9999 ) return(year);
    }   
}

void GiveInstructions(void) {
    printf("Questo programma mostra il calendario di un anno.\n");
    printf("Inserisci un anno dal 1582 a 9999.\n");
}

void PrintCalendar(int year) {
    int month;

    for (month = 1; month <= 12; month++ ) {
        PrintHeadMonth(year, month);
        IndentationFirstDayMonth(year, month, 1);
        PrintDays(year, month);
        printf("\n\n\n");
    }
}

bool IsALeapYear(int year) {
    return( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 );
}

int DaysInMonth(int year, int month) {
    if(month == 4 || month == 6 || month == 9 || month == 11 ){ 
        return(30);
    } 
    else if(month == 2 ) { 
        if( IsALeapYear(year)){ 
            return(29);
        } else {
            return(28);
        }
    } 
    else return(31);

}

/*AnnualDateCount 
serve per la Function WhicDaysIs 
e calcola a che numero esatto su 365/366 sta un giorno 
(esempio: il 1/05/1988 è 122° giorno su 366 giorni) */
int AnnualDateCount(int year, int month, int day) {
    int AnnualDateCount; 
    AnnualDateCount = 0;
    for(int i = 1; i < month; i++){
        AnnualDateCount += DaysInMonth(year, i);
    }
    return(AnnualDateCount + day);
}

/*Function WichDaysIs 
calcola che giorno è data la data completa
restituisce in int da 0 a 6 (sab -> ven)
*Formula da qua: 
*http://calendario.eugeniosongia.com/formula.htm */
int WichDayIs(int year, int month, int day) {
    return( ( year + ( (year - 1) / 4 ) - ( (year - 1) / 100 ) + ( (year - 1 ) / 400 ) + AnnualDateCount(year, month, day) ) % 7 );
}

void PrintHeadMonth(int year, int month) {
    printf("%20d\n%20s\n", year, MonthName(month));
    printf("%6s%6s%6s%6s%6s%6s%6s\n", "Sab", "Dom", "Lun", "Mar", "Mer", "Gio", "Ven");
    
}

string MonthName(int month) {
    switch(month){
        case 1: return("Gennaio");
        case 2: return("Febbraio");
        case 3: return("Marzo");
        case 4: return("Aprile");
        case 5: return("Maggio");
        case 6: return("Giugno");
        case 7: return("Luglio");
        case 8: return("Agosto");
        case 9: return("Settembre");
        case 10: return("Ottobre");
        case 11: return("Novembre");
        case 12: return("Dicembre");
        default: return("Mese non valido"); 
    }
}

void IndentationFirstDayMonth(year, month, day) {
    for ( int i = 0; i < WichDayIs(year, month, day); i++){
        printf("%6s", " ");
    }
    
}

void PrintDays(year, month) {

    for(int day = 1; day <= DaysInMonth(year, month); day++){
        if( WichDayIs(year, month, day) == 0 && day != 1 ) printf("\n");    
        printf("%6d", day);
    }
}
