#!|usr|bin|python3
#-*- coding: utf-8-*-
#Max Vilà Ruiz
#Escola del Treball
#21/04/23
#Descripció:
#El programa li comença requerint a l'usuari que introdueixi la quantitat de números que vol entrar. A continuació, el programa li deixarà introduir tots els nombres que havia demanat de manera individual. En cas de que l'usuari introdueixi tres nombres iguals de manera consecutiva, el programa l'indicarà de l'error: "número repetit". Y finalment, en cas que s'introdueixin correctament, el programa li comunicarà a l'usuari dient-li: "s'han introduït tots els nombres".
#Especificacions d'entrada:
#Llegeix (input) un nombre enter (int) i després llegirà (input) tots els nombres cualsevols (float) que hagui demanar l'usuari en el primer input.
#Joc de proves:
#		Entrades:			Sortides:
#Ex 1:		5, 1,1,1			"número repetit"
#Ex 2:		3, 1,2,3			"s'han desat correctament"
#Ex 3:		4, 1,1,2,1			"s'han desat correctament"
#Programa:
a = int(input("Introdueix el número de nombres que vols que et llegeixi el programa: "))
contador = 0
contador2 = 1
num_anterior = 0
while contador != a:
	contador += 1
	b = float(input("Introdueix un nombre: "))
	if num_anterior == b:
		contador2 += 1
		if contador2 == 3:
			print("S'han introduït tres nombres iguals consecutius --> número repetit.")
	elif contador == a:
		print("S'han introduït tots els nombres.")
	num_anterior = b
