#Ex: L'usuari escriu una frase i el programa et diu quantes paraules conté. (rsplit, count)
a = input("Escriu una frase: ")
print(len(a.rsplit()))

#Ex: És un Sign Up d'una app. --> si vols que els usuaris s'emmagatzemin s'ha de crear un document a part i citar-lo.
basedades = ["id5", "id4", "id3", "id2", "id1"]
u1 = input("Introdueix el teu nom d'usuari: ")
u2 = input("Introdueix-lo un altre cop: ")
if u1 == u2:
  if u1.isidentifier():
    if basedades.count(u1) == 0:
      basedades.insert(0, u1)
      basedades.reverse()
      print("Benvingut,", u1)
      print(basedades)
    else:
      print("Aquest usuari ja existeix.")
  else:
    print("El nom d'usuari ha de contenir caracters valids.")
else:
  print("Els noms d'usuari han de ser iguals.")

#Ex: Fes un programa que llegeixi un text per entrada estandard i faci un hisitograma horitzontal de les frequencies de les longituds de les paraules del text.
text = input("Write a phrase: ")
symb = input("Which symbol do you want to use for the histogram? ")
contatge = []
for i in text.split():
	contatge.append(len(i))
contatge.sort()
num = 1
while num <= contatge[-1]:
	print(num, ":", symb*contatge.count(num))
	num += 1

#Ex: Fer un programa de la llista de la compra.
a = int(input(""))
llista = []
for i in range(a):
	fruita = input("")
	preu = float(input(""))
	llista.append([fruita, preu])
print("\n")
for j in llista:
	print(f"El/la {j[0]:20} val {j[1]:>10.2f} €/Kg")

#Ex: L'usuari entra una paraula i el programa et diu si es cap i cua o no.
a = input("Posa una paraula: ")
llista = []
for i in a:
	llista.append(i)
llista.reverse()
b = ""
b = b.join(llista)
if b == a:
	print("És cap i cua.")
else:
	print("No és cap i cua.")
	
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