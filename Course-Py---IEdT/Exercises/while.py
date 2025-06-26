
#Ex (while): Ex anterior pero el programa li demana x:
maxim = 0
contador = 0
num_v = int(input("Quants números vols introduir? "))
while contador < num_v:
	a = int(input("Introdueix un nombre: "))
	if a > maxim:
		maxim = a
	contador = contador + 1
print(maxim)

#Ex (while): Ex anterior però que també funcioni amb número negatius.
contador = 1
num_v = int(input("Quants números vols introduir? "))
maxim = int(input("Introdueix un nombre: "))
while contador < num_v:
	a = int(input("Introdueix un nombre: "))
	if a > maxim:
		maxim = a
	contador = contador + 1
print(maxim)

#Ex (while): Un programa que et digui "okey" si pots comprar algo i "no pots" si no pots.
diners = int(input("Quant diners tens?"))
while not diners <= 0:
	a = int(input("Cuan val allò que et vols comprar?"))
	if a <= diners:
		print("okey.")
	else:
		print("no pots comprar-ho.")
	diners -= a

#Ex (while): Un programa que imprimeixi els múltiples d'un nombre x.
contador = 0
potencia = 1
num1 = int(input("Introdueix el número que vols que es mostrin els seus múltiples: "))
num_v = int(input("Introdueix el número de multiples que vols que apareixin del número que has posat: "))
while contador < num_v:
	sol = num1*potencia
	print(sol)
	contador += 1
	potencia += 1

#Ex 4.(while):
a = 0
b = 2
while b < 100:
	a += b
	b += 2
print(a)

#Ex 4.(while): Amb n i m que introdueix l'usuari.
n = float(input("Introdueix els multiples que vols que sumi."))
m = float(input("Introdueix fins quin número vols que arribi."))
suma = 0
multiple = n
while multiple < m:
	suma += multiple
	multiple += n
print(suma)

#Ex 5.(while):
n = float(input("Introdueix la base de la potència."))
m = float(input("Introdueix fins quin número vols que arribi."))
suma = 0
potencia = 1
while n ** potencia < m:
	suma = suma + n**potencia
	potencia += 1
print(suma)

#Ex I.P(while):
ip_valida = True
num_caps = 0
while ip_valida and num_camps < 4:
	camp = int(input("Introdueix el camp de la I.P: "))
	if camp < 0 or camp > 255:
		ip_valida = False
	num_caps += 1
if ip_valida:
	print("La I.P és vàlida.")
else:
	print("La I.P no és vàlida.")

#Ex 1.Mitjana noms llegits(while):
contador = 0
a = 0
b = True
while b:
	num = float(input("Introdueix un nombre: "))
	if num >= 0:
		a += num
		contador += 1
	else:
		b = False
calcul = a / contador
print(calcul)

#Ex 2.Mitjana noms llegits(while):
a = int(input("Quants nombres vols que llegeixi el programa? \n"))
contador = 0
c = 0
contador_pos = 0
while  contador < a:
	b = int(input("Introdueix un nombre.  "))
	if b >= 0:
		c = c + b
		contador_pos += 1
	contador += 1
sol = c / contador_pos
print(sol)

#Ex (while): Ex anterior pero el programa li demana 314:
maxim = 0
contador = 0
num_v = int(input("Quants números vols introduir? "))
while contador < num_v:
	a = int(input("Introdueix un nombre: "))
	if a > maxim:
		maxim = a
	contador = contador + 1
print(maxim)

#Ex (while): Ex anterior però que també funcioni amb número negatius.
contador = 1
num_v = int(input("Quants números vols introduir? "))
maxim = int(input("Introdueix un nombre: "))
while contador < num_v:
	a = int(input("Introdueix un nombre: "))
	if a > maxim:
		maxim = a
	contador = contador + 1
print(maxim)

#Ex (while): Un programa que imprimeixi els 10 primers múltiples de 2.
contador = 0
potencia = 1
num1 = int(input("Introdueix el número que vols que es mostrin els seus múltiples: "))
num_v = int(input("Introdueix el número de multiples que vols que apareixin del número que has posat: "))
while contador < num_v:
	sol = num1*potencia
	print(sol)
	contador += 1
	potencia += 1

#Ex 4.(while):
a = 0
b = 2
while b < 100:
	a += b
	b += 2
print(a)

#Ex 4.(while): Amb n i m que introdueix l'usuari.
n = float(input("Introdueix els multiples que vols que sumi."))
m = float(input("Introdueix fins quin número vols que arribi."))
suma = 0
multiple = n
while multiple < m:
	suma += multiple
	multiple += n
print(suma)

#Ex 5.(while):
n = float(input("Introdueix la base de la potència."))
m = float(input("Introdueix fins quin número vols que arribi."))
suma = 0
potencia = 1
while n ** potencia < m:
	suma = suma + n**potencia
	potencia += 1
print(suma)

#Ex I.P(while):
ip_valida = True
num_caps = 0
while ip_valida and num_camps < 4:
	camp = int(input("Introdueix el camp de la I.P: "))
	if camp < 0 or camp > 255:
		ip_valida = False
	num_caps += 1
if ip_valida:
	print("La I.P és vàlida.")
else:
	print("La I.P no és vàlida.")

#Ex Mitjana noms llegits(while):
contador = 0
a = 0
b = True
while b:
	num = float(input("Introdueix un nombre: "))
	if num >= 0:
		a += num
		contador += 1
	else:
		b = False
calcul = a / contador
print(calcul)

#Ex while: L'usuari dona un nombre enter positiu i el programa li diu al usuari quantes xifres te el nombre.
a = int(input("Introdueix un nombre positiu"))
valor = 0
result = 0
key = True
while key:
	if a >= valor:
		result += 1
	else:
		key = False
	if valor < 10:
		valor = 10
	else:
		valor = valor * 10
print(result)