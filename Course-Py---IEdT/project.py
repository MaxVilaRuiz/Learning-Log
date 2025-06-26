def caracters(x):
    if len(x) == 9:
        return True
    else:
        return False
def primers8(x):
    contador = 0
    for i in x:
        if type(i) != int:
            contador += 1
    if contador == 1:
        return True
    else:
        return False  
def lletra_v(x):
    llista = "TRWAGMYFPDXBNJZSQVHLCKE"
    a = x[:-1]
    b = x[-1]
    calcul = a%23
    if llista[calcul] == b:
        return True
    else:
        return False
def esvalid(x):
    if caracters(x) and primers8(x) and (x[0] != 0) and lletra_v(x):
        return True
    else:
        return False
#Codi principal
a = input("Introdueix el teu dni: ")
if primers8(a):
    print("És vàlid.")
else:
    print("No es vàlid.")