#Ex: Fer funció que et doni els punts de tall de x i y d'una grafica quan l'usuari et dona el terme independent de y i la pendent (m):
def tall_func(m,n):
  if m == 0:
    x = "infinit"
  else:
    x = n/m
  a = [x,n]
  return a
#Codi principal
m = float(input("Posa la pendent de la funció: "))
n = float(input("Posa el terme independent de y: "))
print(tall_func(m,n))

#Ex: Fes un programa que demani a l'usuari "n" nombres primers i que el programa et confirmi si ho son o no.
def es_primer(num):
  sol = False
  contador = 0
  for i in range(1, num+1):
    if num % i == 0:
      contador += 1
  if contador == 2:
    sol = True
  return sol
#Codi principal:
n = int(input("Quants nombres primers vols introduir: "))
for i in range(n):
  num = int(input("Posa un nombre primer: "))
  print(es_primer(num))

#Ex: Fes un programa que retorni tots els numeros primers que existeixin fins al número que ha posat l'usuari.
def es_primer(num):
  sol = False
  contador = 0
  for i in range(1, int(num**(1/2))+1):
    if num % i == 0:
      contador += 1
  if contador == 1:
    sol = True
  return sol
#Codi principal:
n = int(input("Imprimeix tots els nombres primers que siguin més petits que: "))
for i in range(n):
  if es_primer(i):
    print(i)

#Ex: programa que et diu si coincideixen les inicials de 2 noms.
def son_iguals(x,y):
	a = x.split()
	b = y.split()
	cadena1 = ""
	cadena2 = ""
	for i in a:
		cadena1 += i[0]
	for i in b:
		cadena2 += i[0]
	cadena1 = cadena1.upper()
	cadena2 = cadena2.upper()
	return (cadena1 == cadena2)
#Codi principal
nom1 = input("Posa un nom i un cognom: ")
nom2 = input("Posa un nom i un cognom: ")
if son_iguals(nom1, nom2):
    print("Són iguals.")
else:
	print("No són iguals.")
#------------------------------------------
def son_iguals(x,y):
	a = x.split()
	b = y.split()
	return(a[0][0].upper() == b[0][0].upper() and a[1][0].upper() == b[1][0].upper())
#Codi principal
nom1 = input("Posa un nom i un cognom: ")
nom2 = input("Posa un nom i un cognom: ")
if son_iguals(nom1, nom2):
    print("Són iguals.")
else:
	print("No són iguals.")
        
#Ex: Mira si el dni es valid (1. ha de tenir 9 caracters 2. els 8 primers han de ser digits 3. el primer digit no pot ser 0(no real) 4. tots els numeros del teu dni amb el residu de 23 a de donar entre 0 i 22 i la lletra ha de ser corresponent amb la que toca --> (TRWAGMYFPDXBNJZSQVHLCKE)).