# Ex 1 (ifs):
edat = int(input("Posa la teva edatn\ "))
if edat >= 18 and a <= 120:
  print("Benvingut")
elif a <= 17 and a >= 0:
  print("Ets menor d'edat")
elif a > 120:
  print("Ets massa gran")
else:
  print("Error")

# Ex 1 (ifs):
nombre = int(input("Escriu un nombre enter\n "))
if nombre >= 0:
  print(nombre)
else:
  print(nombre * -1)

# Ex 2 (ifs):
stnombre = float(input("Introdueix el primer nombre\n "))
ndnombre = float(input("Introdueix el segon nombre\n "))
a = stnombre % ndnombre
b = ndnombre % stnombre
if a == 0:
  print("si")
elif b == 0:
  print("si")
else:
  print("no")

# Ex 3 (ifs):
dia = int(input("Introdueix el dia "))
mes = int(input("Introdueix el mes "))
any = int(input("Introdueix l'any "))
tardor = (any == 2021) and (mes == 10 or mes == 11 or (mes == 9 and dia >= 22) or (mes == 12 and dia <= 21))
if tardor == True:
	print("Sí, correspon.")
else:
	print("No, no correspon.")

# Ex 4 (ifs):
mida = float(input("Posa la mida del cargol: "))
if mida >= 1 and mida < 3:
	print("El clau és petit.")
elif mida >= 3 and mida < 5:
	print("El clau és mitjà.")
elif mida >= 5 and mida < 6.5:
	print("El clau és gran.")
elif mida >= 6.5 and mida < 8.5:
	print("El clau és molt gran.")
else:
	print("Per caracteritzar-te la mesura a d'estar entre els intervals de 1cm i 8.5cm.")

# Ex 5 (ifs):
hora = int(input("Posa la hora "))
minut = int(input("Posa el minut "))
segon = int(input("Posa el segon "))
if segon < 59:
	segon = segon + 1
else:
	segon = 0
if segon == 0 and minut < 59:
	minut = minut + 1
elif segon == 0 and minut == 59:
  minut = 0
if minut == 0:
	hora = hora + 1
if hora == 24:
  hora = 0
print(hora, minut, segon)

# Ex 6 (ifs):
n = int(input("Posa l'any: "))
traspas = n % 4 == 0 and not(n % 100 == 0 and n % 400 != 0)
if traspas:
	print("Ës un any de traspàs.")
else:
	print("No és un any de traspàs.")

# Ex 1 (ifs 2):
a = float(input("Posa el primer número: "))
b = float(input("Posa el segon número: "))
c = float(input("Posa el tercer número: "))
zeroa = -c/b
zeroab = c
calcul = b**2 -4*a*c
czero = -b / (2*a)
cposia = (-b +(calcul)**(1/2)) / (2*a)
cposib = (-b -(calcul)**(1/2)) / (2*a)
if a == 0:
	if b == 0:
		if c == 0:
			print("No té solució.")
		elif c != 0:
			print("Té solucions infinites.")
		else:
			print(zeroab)
	else:
		print(zeroa)
else:
	if calcul == 0:
		print(czero)
	elif calcul > 0:
		print(cposia, cposib)
	else:
		print("No té solució real.")

# Ex 2 (ifs 3):
a = int(input("Posa el primer nombre: "))
b = int(input("Posa el segon nombre: "))
c = int(input("Posa el tercer nombre: "))
if a > b:
	aux = a
	a = b
	b = aux
if b > c:
	aux = b
	b = c
	c = aux
if a > b:
	aux = a
	a = b
	b = aux
print(a,b,c)

# Ex 1 (ifs 3):
ip1 = int(input("Posa la primera I.P: "))
ip2 = int(input("Posa la segona I.P: "))
ip3 = int(input("Posa la tercera I.P: "))
ip4 = int(input("Posa la quarta I.P: "))
ip_valida = (ip4 == 0 or ip4 == 255) and (ip1 == 10 or (ip1 == 172 and ip2 == 16) or (ip1 == 192 and ip2 == 168))
print(ip_valida)

# Exs add:
a = float(input("Posa la mesura d'un dels costats del triangle: "))
b = float(input("Posa la mesura del segon dels costats del triangle: "))
c = float(input("Posa la mesura de l'últim costats del triangle: "))
var = (c + b > a) and (a + b > c) and (c + a > b)
error = (a < 0) or (b < 0) or (c < 0)
equi = (a == b) and (b == c)
esc = (a != b) and (a != c) and (b != c)
if var:
	if esc:
		print("És un triangle escalé.")
	elif equi:
		print("És un triangle equilater.")
	else:
		print("És un triangle isòsceles.")
elif error:
	print("Error.")
else:
	print("No forma un triangle.")

# Ex 1 (ifs.str):
nom1 = input("Posa el primer nom: ")
nom2 = input("Posa el segon nom: ")
if nom1 < nom2:
	print(nom1, nom2)
else:
	print(nom2 , nom1)

# Ex 2 (ifs.str):
lletra = input("Introdueix una lletra: ")
num = ord(letra)
if num >= 65 and num <= 90:
	print("La lletra és majúscula.")
elif num >= 97 and num <= 122:
	print("La lletra és minúscula.")
else:
	print("No és una lletra.")

# Ex 3 (ifs.str):
password1 = input("Introdueix la contrassenya: ")
password2 = input("Repeteix la contrassenya: ")
if password1 == password2:
	print("Contrassenya vàlida.")
else:
	print("Contrassenya invàlida.")

# Ex 4 (ifs.str):
password1 = input("Introdueix la contrassenya: ")
password2 = input("Repeteix la contrassenya: ")
a = ord(password2[0])
var1 = len(password1)
var2 = (a >= 65) and (a <= 90)
if password1 == password2:
	if var1 > 8:
		if var2 / password1[0] >= "A" and password1 <= "Z":
			print("Contrassenya vàlida.")
		else:
			print("La contrassenya ha de començar per majúscula.")
	else:
		print("La contrassenya és massa curta.")
else:
	print("Les contrassenyes no coincideixen..")

# Ex (ifs.str): Programa que llegeixi 3 números i ens fa print del més gran utilitzant obligadoriament el seguent procediment:	maxim = 0, a = int(input("...")). Si a és més gran que màxim --> maxim = a.
maxim = 0
a = int(input("Introdueix un nombre: "))
if a > maxim:
	maxim = a
a = int(input("Introdueix un nombre: "))
if a > maxim:
	maxim = a
a = int(input("Introdueix un nombre: "))
if a > maxim:
	maxim = a
print(maxim)
