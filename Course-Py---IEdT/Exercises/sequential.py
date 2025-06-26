# Ex a:
segons = 123456
minuts = segons // 60
segons_finals = segons % 60
minuts_finals = minuts % 60
hores_finals = minuts // 60
print (segons_finals , minuts_finals , hores_finals)

# Ex b:
a = float(input())
b = float(input())
c = float(input())
x1 = (-b + (b**2-4*a*c)**(0.5))/(2*a)
x2 = (-b - (b**2-4*a*c)**(0.5))/(2*a)
print (x1, x2)

# Ex 1:
segons_bruts = int(input("Introdueix un nombre enter "))
minuts_bruts = int(segons_bruts // 60)
segons = int(segons_bruts % 60)
minuts = int(minuts_bruts % 60)
hores = int(minuts_bruts // 60)
print(hores,minuts,segons)

# Ex 2:
a = int(input("Introdueix un nombre enter "))
b = int(input("Introdueix un nombre enter "))
c = a
a = b
b = c
print(a,b)

# Ex 3:
a = str(input("Introdueix una paraula "))
b = str(input("Introdueix una paraula "))
c = a
a = b
b = c
print(a,b)

# Ex 4:
sou_a = float(input("Introdueix el primer sou "))
sou_b = float(input("Introdueix el segon sou "))
sou_c = float(input("Introdueix el tercer sou "))
sou1 = sou_a * 1.10
sou2 = sou_b * 1.12
sou3 = sou_c * 1.17
print(sou1,sou2,sou3)

# Ex 5:
nom = input("Introdueix el nom del treballador ")
hores = int(input("Introdueix les hores que ha treballat "))
preu = float(input("Introdueix el preu que cobra per hora "))
sou_net = hores*preu
sou_brut = sou_net*0.8
print(round(sou_net,2), round(sou_brut,2))

# Ex 6:
catet1 = float(input("Introdueix el nombre del primer catet "))
catet2 = float(input("Introdueix el nombre del segon catet ")) 
A = catet1 * catet2 / 2
print ("L'àrea del triangle és: ", A, "metros quadrats.")

# Ex 7:
euros = float(input("Introdueix el nombre d'euros "))
pessetes = euros * 166
print ("La quantitat de pessetes és: ", pessetes)

# Ex 8:
dolars = float(input("Introdueix el nombre de dolars "))
euros = dolars * 0.82
print ("La quantitat d'euros és: ", euros)

# Ex 9:
metres = float(input("Introdueix el nombre de metres "))
kilòmetres = metres / 1000
print ("La quantitat de kilòmetres és: ", kilòmetres)

# Ex 10:
centímetres = float(input("Introdueix el nombre de centímetres "))
polzades = centímetres * 0.39737
print ("La quantitat de polzades és: ", polzades)

# Ex 11:
hores_b = int(input("Introdueix el nombre d'hores "))
minuts_b = int(input("Introdueix el nombre de minuts "))
segons_b = int(input("Introdueix el nombre de segons "))
segons_n = segons_b % 60
minuts_n = (minuts_b % 60) + (segons_b // 60)
hores_n = (minuts_n // 60) + (hores_b)
print (hores_n, "h ", minuts_n, "min ", segons_n, "s.")

# Ex 12:
print ("Ara hauràs d'introduir 8 dígits d'un codi binari (1 o 0 en ordre d'esquerra a dreta.)")
digit1 = int(input("Introdueix el primer nombre "))
digit2 = int(input("Introdueix el segon nombre "))
digit3 = int(input("Introdueix el tercer nombre "))
digit4 = int(input("Introdueix el quart nombre "))
digit5 = int(input("Introdueix el cinquè nombre "))
digit6 = int(input("Introdueix el sisè nombre "))
digit7 = int(input("Introdueix el setè nombre "))
digit8 = int(input("Introdueix el vuitè nombre "))
digit_a = digit1 * 2 ** 7
digit_b = digit2 * 2 ** 6
digit_c = digit3 * 2 ** 5
digit_d = digit4 * 2 ** 4
digit_e = digit5 * 2 ** 3
digit_f = digit6 * 2 ** 2
digit_h = digit7 * 2 ** 1
digit_i = digit8 * 2 ** 0
print ("El número en decimal és: ", digit_a + digit_b + digit_c + digit_d + digit_e + digit_f + digit_h + digit_h + digit_i)

# Ex 13:
b = int(input("Introdueix el nombre de la base (màx 10)"))
print ("Ara, hauràs d'introduir 8 dígits d'un codi binari (0,1,2,3,4,5,6,7,8 o 9, depend de la base que haguis escollir. Ex: si la base és 3 has d'escollir entre 0, 1 o 2.) Recorda de posar el número binari ordenat d'esquerra a dreta.")
digit1 = int(input("Introdueix el primer nombre "))
digit2 = int(input("Introdueix el segon nombre "))
digit3 = int(input("Introdueix el tercer nombre "))
digit4 = int(input("Introdueix el quart nombre "))
digit5 = int(input("Introdueix el cinquè nombre "))
digit6 = int(input("Introdueix el sisè nombre "))
digit7 = int(input("Introdueix el setè nombre "))
digit8 = int(input("Introdueix el vuitè nombre "))
digit_a = digit1 * b ** 7
digit_b = digit2 * b ** 6
digit_c = digit3 * b ** 5
digit_d = digit4 * b ** 4
digit_e = digit5 * b ** 3
digit_f = digit6 * b ** 2
digit_h = digit7 * b ** 1
digit_i = digit8 * b ** 0
print ("El número en decimal és: ", digit_a + digit_b + digit_c + digit_d + digit_e + digit_f + digit_h + digit_h + digit_i)

# Ex 14:
d = float(input("Introdueix el nombre d'euros "))
b500 = d // 500
b200 = (d%500)//200
b100 = (d%200)//100
b50 = (d%100)//50
b20 = (d%50)//20
b10 = (d%20)//10
b5 = (d%10)//5
m2 = (d%5)//2
m1 = (d%2)//1
m50 = (d%1)//0.5
m20 = (d%0.5)//0.2
m10 = (d%0.2)//0.1
m5 = (d%0.1)//0.05
m02 = (d%0.05)//0.02
m01 = (d%0.02)//0.01
print("Utilitzarem: ", b500, "bitllets de 500€,", b200, "bitllets de 200€,", b100, "bitllets de 100€,", b50, "bitllets de 50€,", b20, "bitllets de 20€,", b10, "bitllets de 10€,", b5, "bitllets de 5€,", m2, "monedes de 2€ i ", m1, "monedes d'1€,", m50, "monedes de 50 cèntims,", m20, "monedes de 20 cèntims,", m10, "monedes de 10 cèntims,", m5, "monedes de 5 cèntims,", m02, "monedes de 2 cèntims,", m01, "monedes d'1 cèntim.")

# Ex 5 (ej. examen):
# !/usr/bin/python3
# -*- coding: utf-8-*-
# 
# Escola del treball
# Python per Batx
# Curts 2022/23
# Max Vilà Ruiz
#
# Descripció
# El programa llegeix un nombre de plantes enter d'un bloc de pisos i et retorna la planta mitjana en cas de que el nombre de pisos sigui parell, en el cas contrari et retorna la planta mitjana més aproximada a la planta màxima.
#
# Especificacions d'entrada:
# Llegeix (input) un nombre enter (int) més gran que 0.
# 
# Joc de proves:
# 			Entrada:			Sortida:
# 	Ex 1:		8				4
# 	Ex 2:	11				6
#	Ex 3:	1				1
# 
num_p = int(input("Introdueix el número de plantes positiu "))
sol = num_p/2
print(round(sol,0))
# ----------------------------------------------------------------
num_p = int(input("Introdueix el número de plantes positiu "))
pisos_div = num_p // 2
pisos_rsd = num_p % 2
sol = pisos_div + pisos_rsd
print(sol)

# Ex 6 (ej. examen)
# !/usr/bin/python3
# -*- coding: utf-8-*-
# 
# Escola del treball
# Python per Batx
# Curts 2022/23
# Max Vilà Ruiz
#
# Descripció
# El programa llegeix dos nombres decimals dels quals un t'indica el radi de la base d'un con i l'altre l'altura d'aquest. Una vegada llegit, el programa calcularà el volum del con i ,finalment, el retornarà.
#
# Especificacions d'entrada:
# Llegeix (input) dos nombres decimals (float) més grans que 0.
# 
# Joc de proves:
# 			Entrada:			Sortida:
# 	Ex 1:		3,3				37.61406
# 			3,3
# 	Ex 2:	3				28.26
# 			3
# 
r = float(input("Introdueix el radi del con en m "))
h = float(input("Introdueix la altura del con en m"))
v = ((r * r) * h * 3.14) / 3
print(v,"m2")

# Ex prep examen:
# !/usr/bin/python3
# -*- coding: utf-8-*-
# 
# Escola del treball
# Python per Batx
# Curts 2022/23
# Max Vilà Ruiz
#
# Descripció
# El programa llegeix un nombre de minuts enters o decimals de les hores que han transcorregut des de que un rellotge ha arribat a les 00:00h.
#
# Especificacions d'entrada:
# Llegeix (input) un nombre enter o decimal (float) més gran o igual que 0.
#
# Joc de proves:
#       Entrada:      Sortida:
# Ex 1: 477           voltes agulla min: 7
#                     		voltes agulla h: 0
# Ex 2: 59,9         voltes agulla min: 7
#                  	   voltes agulla h: 0

minbr = float(input("Introdueix el nombre de minuts que han trascorregut des de les 00:00h "))
min = int(minbr) // 60
h = min // 12
print("Nombre de voltes que ha donat l'agulla dels minuts: ", min, "\nNombre de voltes que ha donat l'agulla de les hores: ", h)

# Ex Boolears:
nombre = int(input("Posa un nombre real. \n"))
if nombre > 5 and nombre < 8:
  print(True)
else:
  print(False)

# Ex Boolears 11:
# A)
a = int(input("Posa el nombre a"))
b = int(input("Posa el nombre b"))
c = int(input("Posa el nombre c"))
sol = (a or b) > c
print(sol)
# B)
a = int(input("Posa el nombre a"))
b = int(input("Posa el nombre b"))
c = int(input("Posa el nombre c"))
sol = a == b or b == c or a == c
print(sol)
# C)
a = int(input("Posa el nombre a"))
b = int(input("Posa el nombre b"))
c = int(input("Posa el nombre c"))
sol = a == b*b and a == c*c
print(sol)
# D)
hora = int(input("Posa la hora d'ara"))
dia = int(input("Posa el dia que és avui"))
sol = hora >= 8 and hora <= 20 and dia >= 1 and dia <= 15
print(sol)