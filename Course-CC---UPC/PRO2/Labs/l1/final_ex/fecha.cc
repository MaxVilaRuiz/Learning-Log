
#include <ctime>	// time, localtime, tm, ...
#include <fstream>	// Leer y escribir ficheros
#include <iomanip>	// setfill, setw
#include <iostream>
#include <vector>
#include "fecha.hh"

using std::cin;
using std::cout;

/**
 * @brief Lee una fecha en formato DD/MM/AAAA.
 */
Fecha fecha_leer() {
	char  sep;	// Leemos el separador pero no lo usamos
	Fecha f;
	cin >> f.dia_ >> sep >> f.mes_ >> sep >> f.anyo_;
	return f;
}

/**
 * @brief Escribe una fecha en formato DD/MM/AAAA.
 */
void fecha_escribir(const Fecha& f) {
	cout << std::setfill('0') << std::setw(2) << f.dia_;
	cout << '/' << std::setfill('0') << std::setw(2) << f.mes_;
	cout << '/' << std::setfill('0') << std::setw(4) << f.anyo_;
}

/**
 * @brief Determina si un anyo es bisiesto.
 *
 * @param anyo El anyo a comprobar.
 */
bool es_bisiesto(int anyo) {
	return (anyo % 4 == 0 && anyo % 100 != 0) || anyo % 400 == 0;
}

/**
 * @brief Determina el número de días de un mes
 *
 * @param mes El mes a comprobar.
 * @param anyo El anyo al que pertenece el mes.
 *
 * @return El número de días del mes.
 */
int dias_mes(int mes, int anyo) {
	if (mes == 2) {
		return es_bisiesto(anyo) ? 29 : 28;
	} else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		return 30;
	} else {
		return 31;
	}
}

/**
 * @brief Añade un número de días a una fecha.
 *
 * @param f La fecha a la que añadir los días.
 * @param dias El número de días a añadir.
 */
Fecha fecha_sumar_dias(const Fecha& f, int dias) {
	Fecha res = f;
	res.dia_ += dias;
	while (res.dia_ > dias_mes(res.mes_, res.anyo_)) {
		res.dia_ -= dias_mes(res.mes_, res.anyo_);
		res.mes_++;
		if (res.mes_ > 12) {
			res.mes_ = 1;
			res.anyo_++;
		}
	}
	return res;
}

/**
 * @brief Devuelve `true` si `a` es anterior a `b`, `false` en caso contrario.
 */
bool fecha_menor(const Fecha& a, const Fecha& b) {
	if (a.anyo_ != b.anyo_) {
		return a.anyo_ < b.anyo_;
	} else if (a.mes_ != b.mes_) {
		return a.mes_ < b.mes_;
	} else {
		return a.dia_ < b.dia_;
	}
}

/**
 * @brief Devuelve la fecha actual.
 */
Fecha fecha_actual() {
	time_t t = time(nullptr);
	tm	  *now = localtime(&t);
	// `now` es un puntero. Veremos punteros en la segunda parte del curso.

	Fecha f;
	f.dia_ = now->tm_mday;
	f.mes_ = now->tm_mon + 1;
	f.anyo_ = now->tm_year + 1900;
	return f;
}

/**
 * @brief Leer secuencia de fechas de un fichero
 * @param filename Nombre del fichero
 * @return `vector` con las fechas leídas
 */
std::vector<Fecha> leer_fechas_de_fichero(const std::string& filename) {
	std::vector<Fecha> res;
	std::ifstream	  fin(filename);

	Fecha f;
	while (fin >> f) {
		res.push_back(f);
	}
	return res;
}

/**
 * @brief Devuelve la fecha mayor dadas dos fechas cualquiera
*/
Fecha fecha_mayor(const Fecha& fecha1, const Fecha& fecha2) {
	Fecha res = fecha1;
	if (fecha1.anyo_ < fecha2.anyo_) res = fecha2;
	else if (fecha1.anyo_ == fecha2.anyo_) {
		if (fecha1.mes_ < fecha2.mes_) res = fecha2;
		else if (fecha1.mes_ == fecha2.mes_) {
			if (fecha1.dia_ < fecha2.dia_) res = fecha2;
		}
	}

	return res;
}