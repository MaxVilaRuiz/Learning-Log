#include <iostream> // Incloem la llibreria "iostream" que serveix per a fer 
                    // les funcions de "cin" i "cout".
using namespace std; // Per a no haver de posar tota l'estona std::codi.


int main() { // Definim la funció principal (main).

// VARIABLES
// Definició de variable
int enter = 0;
double decimal = 0.0;
char caracter = 'i'; // Amb comentes simples ('').
string cadena = "Hello World"; // Amb cometes dobles ("").
bool boolea = true; // Valor = true o false (també es pot introduir una 
                    // condició que acabi donant el valor true o false).

// Definició múltiple
int x, y, z, w, k; // Es pot fer el mateix per a la resta de tipus de variables. 
                   // Tal com es pot veure, es poden definir variables sense 
                   // assignar-li un valor.

// Reassignacions de variables
enter = 1;
decimal = 1.1;
caracter = 'j';
cadena = "Hello Ray";
boolea = false;



// OPERADORS
// Operadors matemàtics
enter = 1 + 2; // Suma
enter = 1 - 2; // Resta
enter = 1 * 2; // Multiplicació
enter = 1 / 2; // Divisió Entera

// Operadors lògics
boolea = 1 < 2; // Més petit que
boolea = 1 > 2; // Més gran que
boolea = 1 <= 2; // Més petit o igual que
boolea = 1 >= 2; // Més gran o igual que
boolea = 1 == 2; // Igual a
boolea = 1 != 2; // Diferent a
boolea = true and true; // Operador booleà "and"
boolea = true or true; // Operador booleà "or"
boolea = not true; // Operador booleà "not"



// CONDICIONALS
if (decimal > enter) { // Si es compleix la condició, s'executa el codi dins el condicional.
    cout << "El número decimal és més gran." << endl;
}
else if (decimal < enter) { // Si no es compleix el "if", passa a veure si es compleix la 
                            // condició del "else if" (si es compleix la condició del "if" no 
                            // mira la condició del "else if").
    cout << "El número decimal és més petit." << endl;
}
else { // Si no es compleix cap de les condicions, executa el codi del "else" (si ha entrat 
       // al "if" o al "else if" no executa el "else").
    cout << "El número decimal és igual al número enter." << endl;
}



// ITERATIUS
// While()
int i = 0;
while (i < 3) { // Mentre es compleixi la condició, s'executarà el contingut del "while".
    cout << i << endl;
    i++; // Funció Fita (assegura que el bucle acabi en algun instant).
}

// For()
for (int i = 0; i < 3; i++) { // Igual que el "While()", però amb la funció fita dins els parèntesis.
    cout << i << endl;
}

}