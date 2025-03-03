#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

string traducir_frase(
    const map<string, string>& diccionario, 
    const string& frase) {
  stringstream ss(frase);
  string palabra, traduccion, resultado = "";

  while (ss >> palabra) {
    if (diccionario.find(palabra) != diccionario.end()) {
      traduccion = diccionario.at(palabra);
    } else {
      // Si no se encuentra, dejamos la palabra original
      traduccion = palabra;  
    }
    resultado += traduccion + " ";
  }

  // Eliminar el último espacio extra
  if (!resultado.empty()) {
    resultado.pop_back();
  }

  return resultado;
}

int main() {
  // Diccionario de castellano a inglés
  map<string, string> diccionario = {
    {"hola", "hello"},
    {"mundo", "world"},
    {"me", "I am"},
    {"llamo", "called"},
    {"soy", "I am"},
    {"estudiante", "student"},
    {"de", "of"},
    {"y", "and"}
  };

  // Frase en castellano
  string frase = "hola mundo me llamo Juan y soy estudiante de C++";

  // Traducir y mostrar la frase
  string frase_traducida = traducir_frase(diccionario, frase);

  cout << "Frase traducida: " << frase_traducida << endl;

  return 0;
}
