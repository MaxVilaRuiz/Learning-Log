class Fecha {
private:
	// Atributos, campos o miembros de clase
	int dia, mes, any;
public:

	/*
	 * Constructores
	 */ 
	Fecha(); // Constructor por defecto 
	// Pre: 0<d<=31 AND 0<m<=12 AND a>0
	Fecha(int d, int m, int a); // Constructor por sobrecarga

	/*
	 * Métodos estáticos. No son operaciones directas sobre fechas
	 */ 
	// Pre: True
	// Post: Lee una fecha de la entrada estandar y la devuelve
	static Fecha lee();

	// Pre: True
	// Post: Devuelve la fecha de hoy
	static Fecha hoy();

	/*
	 * Métodos consultores y modificadores
	 */
	// Pre: True
	// Post: Escribe por la salida estandar la fecha (this)
	void escribe() const; // método consultor

	// Pre: d es positivo
	// Post: Suma a la fecha actual (this) el número de dias d
	void suma_dias(int d); // método modificador

	/*
	 * Otros métodos (comparadores, operadores entre fechas, etc)
	 */ 
	// Pre: True
	// Post: Devuelve True si (this) es menos que f, si no False
	bool menor(const Fecha& f) const;

	// Pre: True
  // Post: Devuelve True si las fechas son iguales, si no False
	bool igual(const Fecha& f) const;

	// Pre: True
	// Post: Devuelve el número de dias entre las fechas (this) y f2
	int dias_entre(const Fecha& f) const;
};
