#Examen de programació iterativa:
#Max Vilà Ruiz - 24/02/2023

#Programa 2:
#!/usr/bin/python3
#-*- coding_ utf-8-*-
#
#Max Vilà Ruiz
#24/02/2023
#
#Descripció:
#El programa llegeix dos nombre enters que posa l'usuari i retorna el mínim comú múltiple d'aquests dos nombres.
#
#Especificacions d'entrada:
#Que el programa llegeixi (input) dos nombre enter positius (int) que doni l'usuari.
#
#Joc de Proves:
#		Entrades:		Sortides:
#Ex 1:		3,5			15
#Ex 2:		0,0			0
#Ex 3:		8,2			8
a = int(input("Introdueix el primer nombre enter positiu: "))
b = int(input("Introdueix el segon nombre enter positiu: "))
contador = 1
key = True
while key == True:
	if (contador % a == 0) and (contador % b == 0):
		print(contador)
		key = False
	contador += 1
