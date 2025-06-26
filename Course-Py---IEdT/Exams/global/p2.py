#!|usr|bin|python3
#-*- coding: utf-8-*-
#Max Vilà Ruiz
#Escola del Treball
#21/04/23
#Descripció:
#El programa li comença requerint a l'usuari que introdueixi la quantitat de números que vol entrar. A continuació, el programa li deixarà introduir tots els nombres enters positius que havia demanat de manera individual. Seguidament, el programa multiplicarà tots els nombres que l'usuari ha introduït i mostrarà el resultat.
#Especificacions d'entrada:
#Llegeix (input) un nombre enter positiu (int) i després llegirà (input) tots els nombres naturals (int) que hagui demanar l'usuari en el primer input.
#Joc de proves:
#		Entrades:			Sortides:
#Ex 1:		3, 1,2,3			6
#Programa:
a = int(input("Introdueix la quantitat de números que vols que es múltipliquin: ")) 
contador = 0
contador2 = 0
numero_base = 1
sol = 0
calcul = 0
while contador != a:
	contador += 1
	b = int(input("Introdueix un nombre natural: "))
	while contador2 != b:
		contador2 += 1
		calcul += numero_base
	contador2 = 0
	sol = calcul
	calcul = 0
	numero_base = sol
print(sol)
