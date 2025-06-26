# Ex (cuenta atrás BOOM):
for i in [5,4,3,2,1,"BOOM"]:
	print(i)

# Ex (cuenta atrás llarga):
for i in range(100,0,-1):
	print(i)

# Ex (bitllets):
diners = int(input("Entra la quantitat de diners: "))
for valor in [500, 200, 100, 50, 20, 10, 5, 2, 1 ]:
	print(diners//valor)
	diners = diners % valor

# Ex: els n multiples de m.
n = int(input("Introdueix el número de múltiples que vols que apareixin."))
m = int(input("Introdueix el número que vols que apareixin els múltiples."))
m_inicial = m
for i in range(n):
	print(m)
	m += m_inicial

# Ex: L'usuari dona un nombre enter positiu i el programa li diu al usuari quantes xifres te el nombre.
a = int(input("Introdueix un nombre positiu: "))
xifres = 1
for i in range(a):
	if 10**xifres == i:	
		xifres += 1
print(xifres)

# Ex: L'usuari dona un nombre enter positiu i el programa li diu al usuari quins són els divisors d'aquell nombre.
a = int(input("Introdueix un nombre positiu"))
for i in range(1,a//2+1):
	if a % i == 0:
		print(i)

# Ex: L'usuari dona un nombre enter positiu i el programa et diu si és un nombre perfecte o no.
a = int(input("Introdueix un nombre positiu "))
suma_nums = 0
for i in range(1,a//2+1):
	if a % i == 0:
		suma_nums += i
operacio = suma_nums == a
if operacio:
	print("El número és perfecte.")
else:
	print("El número no és perfecte.")

# Ex: L'usuari introdueix un nombre i el programa mostrarà en pantalla els primers x nombres perfectes que hagui demanat l'usuari.
a = int(input("Introdueix el nombre de números perfectes que vols que mostri per pantalla. "))
contador = 0
n = 6
while contador != a:
	suma = 0
	for i in range(1, n//2 +1):
		if n % i == 0:
			suma += i
	if suma == n:
		print(n)
		contador += 1
	n += 1

# Ex: L'usuari introdueix un nombre i el programa mostrarà en pantalla si el nombre és múltiple de 3 o no.
n = input("Posa un número: ")
while len(str(n)) > 1:
  suma = 0
  for digit in range(len(str(n))):
    suma += int(str(n)[digit])
  n = suma 
if (n == 3) or (n == 6) or (n == 9):
    print("És un nombre múltiple de 3.")
else:
    print("No és un nombre múltiple de 3.")
# -----------------------------------------------------
a = input("Posa un número: ")
xifres = len(a)
contador = 0
contador2 = True
suma = 0
for i in range(1, xifres + 1):
	suma += int(a[contador])
	contador += 1
suma2 = str(suma)
while contador2:
	if suma > 10:
		xifres = len(suma2)
		contador = 0
		for i in range(1, xifres + 1):
			suma += int(a[contador])
			contador += 1
	else:
		if suma == 3 or 6 or 9:
			print("És múltiple de 3.")
		else:
			print("no és múltiple de 3.")
		contador2 = False

# Ex: L'usuari introdueix un nombre i el programa mostrarà en pantalla la factorització d'aquest nombre.
a = int(input("Posa un número: "))
sol = 1
contador = True
while contador:
  for i in range(2, a):
    if (a % i) == 0:
      sol = sol * i
      print(i)
  if sol == a:
    contador = False
  else:
    contador = False
    print(a)
# -----------------------------------------------------
a = int(input("Posa un número: "))
print(1)
anterior_trobat = 1
while a != 1:
  no_trobat = True
  i = 2
  while no_trobat:
    if a % i == 0:
      if anterior_trobat < i:
        print(i)
      anterior_trobat = i
      a = a // i
      no_trobat = False
    else:
      i += 1

# Ex: L'usuari escriu una frase i també el programa li demana que indiqui una lletra, a continuació el prorama et diu el número de vegades que es repeteix aquesta lletra en la frase que ha introduit l'usuari.
a = input("Posa una frase en minusculas: ")
b = input("Indica una lletra en minuscula: ")
contador = 0
for i in a:
	if i == b:
		contador += 1
print(contador)

# Ex: Creació d'arbre de nadal en funció de les files que introdueixi l'usuari.
a = int(input(""))
sep = 50
for i in range(1, a*2, 2):
	print(sep, i*"*")
	sep -= 1
for i in range(a):
	print((sep - i)*" " + "*" * (2*i + 1))

# Ex: L'usuari posa una frase i després una lletra i el programa et retorna la mateixa frase però sense les lletres que l'usuari ha posat.
a = input("Posa una frase: ")
b = input("Posa una lletra: ")
sol = ""
for i in a:
	if i != b:
		sol += i
print(sol)

# Ex: L'usuari entra una paraula i el programa et diu si es cap i cua o no.
a = input("Posa una paraula: ")
b = ""
for i in range(len(a), 0, -1):
	b += a[i-1]
if b == a:
	print("És cap i cua.")
else:
	print("No és cap i cua.")

# Ex: Fes un programa que l'usuari t'entri una frase i el programa et diu quantes paraules té la frase.
a = input("Posa una frase: ")
sol = 1
if a[0] == " ":
	sol = 0
if a[len(a-1)] == " ":
	sol -= 1
repeticions = 0
for i in range(espais_i,len(a),1):
	if a[i] == " ":
		repeticions += 1
		if repeticions == 1:
			sol += 1
	else:
		repeticions = 0
print("Aquesta frase té", sol, "paraules.")
# ----------------------------------------------
frase = "   hola com estas  "
while frase[0] == " ":
	frase = frase[1:]
while frase[-1] == " ":
	frase = frase[:-1]
...

# Ex: Fer un programa que en una llista et retorni el número més petit i la seva posiciósense methods (selection sort --> algoritme).
a = int(input("Introdueix el nombre de número que vols introduir: "))
llista = []
for i in range(a):
  num = int(input("Introdueix un número: "))
  llista += [num]
num = 0
sol = 0
min = llista[0]
for i in llista[num:]:
  if i < min:
    min = i
    sol = num
  num += 1
print(min, sol)

# Ex: Fer un programa que en una llista et retorni el número més petit, la seva posició i que ho canvii a la primera posició sense methods (selection sort --> algoritme).
a = int(input("Introdueix el nombre de número que vols introduir: "))
llista = []
for i in range(a):
  num = int(input("Introdueix un número: "))
  llista += [num]
num = 0
sol = 0
min = llista[0]
for i in llista[num:]:
  if i < min:
    min = i
    sol = num
  num += 1
llista[sol] = llista[0]
llista[0] = min
print(llista)

# Ex: Selection sort (llista ordenada de num més petit a més gran sense methods).
a = [1,7,5,9,2]
for i in range(len(a)):
	min = i
	for j in range(i+1, len(a)):
		if a[min] > a[j]:
			min = j
	b = a[i]
	a[i] = a[min]
	a[min] = b
print(a)