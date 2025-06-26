#Ex 1:
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

#Ex 2:
a = int(input("Introdueix el nombre de files de la matriu: "))
b = int(input("Introdueix el nombre de columnes de la matriu: "))
llista = []
contador_fila = 0
contador_col = 0
for i in range(a*b+1):
    if contador_col == b:
        contador_col = 0
        contador_fila += 1
    else: 
        c = int(input(f"Introdueix l'element {contador_fila} {contador_col} de la matriu: "))
        llista += [c]
        contador_col += 1
"""""
contador = 0
for i in range(len(llista)+1):
    if contador == b:
        print("\n")
        contador = 0
    else:
        print(f"{llista[i]}     ")
        contador += 1
"""
element_fila = int(input("Introdueix la fila de l'element: "))
element_col = int(input("Introdueix la columna de l'element: "))
calcul_num = element_fila*b + element_col
calcul_i = element_fila*b
calcul_f = calcul_i+b
calcul_colf = element_col+b*a
sol = ""
contador_sol1 = 0
res = 0
for i in range(calcul_i,calcul_f+1):
    if i == calcul_num:
        res += 1
    elif llista[calcul_num] < llista[i]:
        contador_sol1 += 1
for i in range(element_col,len(llista),4):
    if i == calcul_num:
        res += 1
    elif llista[calcul_num] > llista[i]:
        contador_sol1 += 1
if contador_sol1 == (a+b-2):
    sol = "és"
else:
    sol = "no és"
print(f"EL nombre {llista[calcul_num]} correspon a la posició {element_fila} {element_col} {sol} un punt de la sella")