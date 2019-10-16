/* 
 * File:   main.c
 * Author: Lukas Fischer
 * GitHub: https://github.com/Jinthebandit/Fibonacci-C.git
 * 
 * REQUIREMENTS HW-04:
 * + berechne die ersten n Fibonacci Zahlen
 * + benutze Datentyp int fuer die Berechnung
 * 
 * DEVELOPMENT CYCLE:
 * Gesucht: Fibonacci Rechner
 * Gegeben: Eingabe n-Wertes durch Benutzer
 * Vorgehen:
 *      1. Globale Variable erstellen: "FibType" um Datentyp einfach zu aendern
 *      2. Funktion fuer Eingabe
 *      5. Funktion fuer Berechnung und Ausgabe der Fibonacci-Folge
 * 
 * Mit dem long long Datentyp koennen noch groessere Fibonacci-Zahlen ausgegeben werden.
 * 
 * Created on 09. October, 11:21
 */

// Benötigte Bibliotheken importieren
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // strcspn()
#include <limits.h>     // Ermittelt Eigenschaften der Datentypen z.B. UINT_MAX

// FibType definieren int, unsigned int, long, long long
#define FibType unsigned int
// Maximale Zahlengroesse auf den gesetzten FibType anpassen:
//      int -> INT_MAX, 
//      unsigned int -> UINT_MAX
//      long -> LONG_MAX
#define MaxRange UINT_MAX

// Globale Variablen
int n;

// Forward Declarations
int inputNumber(void);
int showFib(void);

/*
 * Programm starten
 */
int main(int argc, char** argv) {

    printf("n: %i\n",inputNumber());
    n += 1;
    showFib();
    printf("\nDONE!");
    return (EXIT_SUCCESS);
}

/*
 * Eingabe einer Zahl n durch den Benutzer
 */
int inputNumber(void) {
    char input[2];
    
    printf("Bitte geben sie eine Zahl n ein: ");
     if (fgets(input, 40, stdin)) {
        input[strcspn(input, "\n")+1] = 0;
        sscanf(input, "%i", &n);
    }
    
    return n;
}

int showFib(void) {
    FibType fib = 0;
    FibType foo = 1;
    FibType bar = 1;
    
    for(int i=1; i <= n; ++i){
        switch(i) {
            case 1: printf("\n0"); continue;
            case 2: printf("\n1"); continue;
            case 3: printf("\n1"); continue;
            default: fib = bar + foo; bar = foo; foo = fib; break;
        }
        
        // f(i-1) <= LIMIT - f(i-2)
        if(fib <= MaxRange-bar) {
            printf("\n%lld", fib);
        } else {
            printf("\nDie Fibonacci-Zahl konnte nicht bis zur %i-ten Zahl berechnet werden.",n-1);
            break;
        }
    }
}