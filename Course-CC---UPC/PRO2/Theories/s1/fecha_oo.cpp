#include <iostream>
#include <stdexcept>
#include <ctime>
#include "fecha_oo.hpp"

using namespace std;

/*
 * Métodos internos
 */
// Método auxiliar para verificar si un año es bisiesto
bool es_bisiesto(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

// Método auxiliar para obtener la cantidad de días en un mes
int dias_en_mes(int mes, int anio) {
  if (mes < 1 || mes > 12) return 0;
  int dias_por_mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if (mes == 2 && es_bisiesto(anio)) return 29;
  return dias_por_mes[mes - 1];
}

// Método auxiliar para validar la fecha
void validar_fecha(int d, int m, int a) {
  if (a <= 0 || m < 1 || m > 12 || d < 1 || d > dias_en_mes(m, a)) {
    throw std::invalid_argument("Fecha inválida");
  }
}

/*
 * Constructores
 */ 
Fecha::Fecha() : dia(1), mes(1), any(2000) {} // Fecha por defecto
// Pre: 0<d<=31 AND 0<m<=12 AND a>0
Fecha::Fecha(int d, int m, int a) {
  validar_fecha(d, m, a);
  this->dia = d;
  this->mes = m;
  this->any = a;
}

/*
 * Métodos estáticos. No son operaciones directas sobre fechas
 */ 
// Pre: True
// Post: Lee una fecha de la entrada estandar y la devuelve
Fecha Fecha::lee() {
  int d, m, a;
  std::cout << "Introduce la fecha (dd mm aaaa): ";
  std::cin >> d >> m >> a;
  return Fecha(d, m, a);
}

// Pre: True
// Post: Devuelve la fecha de hoy
Fecha Fecha::hoy() {
  time_t t = time(0);
  tm* now = localtime(&t);
  return Fecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

/*
 * Métodos consultores y modificadores
 */
// Pre: True
// Post: Escribe por la salida estandar la fecha (this)
void Fecha::escribe() const {
  std::cout << dia << "/" << mes << "/" << any << std::endl;
}

// Pre: d es positivo
// Post: Suma a la fecha actual (this) el número de dias d
void Fecha::suma_dias(int d) {
  if (d < 0) throw std::invalid_argument("El número de días debe ser positivo");
  while (d > 0) {
    int dias_restantes = dias_en_mes(mes, any) - dia;
    if (d > dias_restantes) {
      d -= (dias_restantes + 1);
      dia = 1;
      if (++mes > 12) {
        mes = 1;
        ++any;
      }
    } else {
      dia += d;
      d = 0;
    }
  }
} 

/*
 * Otros métodos (comparadores, operadores entre fechas, etc)
 */ 
// Pre: True
// Post: Devuelve True si (this) es menos que f, si no False
bool Fecha::menor(const Fecha& f) const {
  if (any < f.any) return true;
  if (any == f.any && mes < f.mes) return true;
  if (any == f.any && mes == f.mes && dia < f.dia) return true;
  return false;
}

// Pre: True
// Post: Devuelve True si las fechas son iguales, si no False
bool Fecha::igual(const Fecha& f) const {
  return dia == f.dia && mes == f.mes && any == f.any;
}

// Pre: True
// Post: Devuelve el número de dias entre las fechas (this) y f2
int Fecha::dias_entre(const Fecha& f) const {
  int total_dias = 0;
  int signo = menor(f) ? 1 : -1;
  Fecha temp = *this;
  while (temp.any != f.any || temp.mes != f.mes || temp.dia != f.dia) {
    int dias_restantes = dias_en_mes(temp.mes, temp.any) - temp.dia + 1;
    if (temp.any == f.any && temp.mes == f.mes) {
      total_dias += signo * (f.dia - temp.dia);
      break;
    }
    total_dias += signo * dias_restantes;
    temp.dia = 1;
    if (++temp.mes > 12) {
      temp.mes = 1;
      ++temp.any;
    }
  }
  return abs(total_dias);
}
