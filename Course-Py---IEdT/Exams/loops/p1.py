#Examen de programació iterativa:
#Max Vilà Ruiz - 24/02/2023

#Programa 1:
#!/usr/bin/python3
#-*- coding_ utf-8-*-
#
#Max Vilà Ruiz
#24/02/2023
#
#Descripció:
#El programa llegeix un nombre enters que posa l'usuari i retorna si és un nombre primer o si no ho és.
#
#Especificacions d'entrada:
#Que el programa llegeixi (input) un nombre enter (int) que doni l'usuari.
#
#Joc de Proves:
#		Entrades:		Sortides:
#Ex 1:		13			És un nombre primer.
#Ex 2:		10			No és un nombre primer.
#Ex 3:		-2			No és un nombre primer.
a = int(input("Introdueix un nombre: "))
contador = 1
suma_divisors = 0
while contador <= a:
	if a % contador == 0:
		suma_divisors += 1
	contador += 1
if suma_divisors == 2:	
	print("És un nombre primer.")
else:
	print("No és un nombre primer.")
