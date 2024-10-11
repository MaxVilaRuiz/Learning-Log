#include <iostream>
using namespace std;

// Precondició: entrada de tres nombres enters entre l'1 i el 10.
// Postcondició: mostrar un missatge que digui el tipus de reconeixement que se li atribueix al candidat segons els valors d'entrada (Medalla or: si la puntuació mitjana és major o igual a 9; Medalla plata: si la puntuació mitjana és major o igual a 7 i menor que 9; Medalla bronze: si la puntuació mitjana és major o igual a 5 i menor a 7; Cap premi: si la puntuació mitjana és menor a 5). També mostrarà la mitjana aritmètica dels tres valors d'entrada amb dos decimals (mitjana >= 1 && mitjana <= 10). A més, aquesta mitjana es veurà afectada si dos dels tres nombres d'entrada són iguals i l'altre és diferent: si el nombre diferent és major als altres, se li restarà un punt a la mitjana; si és menor, li sumarà un punt a la mitjana. Finalment, si els tres nombres d'entrada són iguals, es mostrarà un missatge de sortida que digui "Premi a la unanimitat".

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    int nota1, nota2, nota3;
    cin >> nota1 >> nota2 >> nota3;

    // Per a saber si els nombres són tots diferents, tots iguals o si hi ha dos iguals i un diferent:
    int numsIguals = 0;
    if (nota1 == nota2) numsIguals += 1;
    if (nota1 == nota3) numsIguals += 1;
    if (nota2 == nota3) numsIguals += 1;

    // Per a calcular la mitjana i aplicar, si s'escau, la suma o la resta d'un punt: 
    double mitjana = (nota1 + nota2 + nota3) / 3.00;
    if (numsIguals == 1) {
        if (((nota1 < nota2) && (nota2 == nota3)) || ((nota2 < nota1) && (nota1 == nota3)) || ((nota3 < nota1) && (nota1 == nota2))) {
            mitjana += 1;
        }
        else if (((nota1 > nota2) && (nota2 == nota3)) || ((nota2 > nota1) && (nota1 == nota3)) || ((nota3 > nota1) && (nota1 == nota2))) {
            mitjana -= 1;
        }
    }

    // Outputs:
    if (mitjana >= 9) cout << "Medalla or" << endl;
    else if (mitjana >= 7) cout << "Medalla plata" << endl;
    else if (mitjana >= 5) cout << "Medalla bronze" << endl;
    else cout << "Cap premi" << endl;

    cout << mitjana << endl;

    if ((mitjana >= 5) && (numsIguals == 3)) cout << "Premi a la unanimitat" << endl;
}