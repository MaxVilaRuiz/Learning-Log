# mario-pro2

**mario-pro2** és un projecte de videojoc 2D inspirat en el clàssic "Super Mario", desenvolupat com a pràctica per aplicar estructures de dades, gestió gràfica i lògica de joc en C++. Aquest joc permet jugar sol o en parella, afegint un component cooperatiu per afavorir el treball en equip.

---

## Contingut

- [Característiques generals](#característiques-generals)
- [Funcionament de les classes](#funcionament-de-les-classes)
- [Requisits](#requisits)
- [Compilació i execució](#compilació-i-execució)
- [Controls](#controls)
- [Autors](#autors)

---

## Característiques generals

- Joc en 2D amb gràfics simples i animacions.
- Opció per jugar 1 o 2 jugadors.
- Sistemes de col·lisió, recompenses i penalitzacions.
- Menús dinàmics d’inici i final de partida.
- Ús de sprites per animacions i efectes visuals.
- Implementació pròpia d'estructures de dades per a la gestió dels objectes del joc.

---

## Funcionament de les classes

### `Game`
Classe principal que gestiona tota la lògica del joc. S'encarrega de crear i actualitzar els objectes del joc, controlar el flux de les partides i integrar totes les altres classes.

---

### `Mapa`
- Mapa finit amb límits físics perquè els personatges no surtin fora dels marges.
- Si un jugador arriba al límit dret, activa la bandera i guanya la partida.

---

### `Menús`
- Permet seleccionar entre 1 o 2 jugadors.
- En mode de 2 jugadors, la partida acaba si un dels dos perd totes les vides.
- Mostra instruccions de teclat a la part superior dreta.
- Al final de la partida, es mostra un menú amb opcions per reiniciar o sortir.

---

### `Accions`
- Immunitat temporal després de col·lidir amb enemics.
- Si un personatge cau fora del mapa, reapareix en l'última plataforma tocada.

---

### `Coin`
- **Animació**: gir de 360º i moviment sinusoidal vertical.
- **Acció**: en recollir-la, desapareix i augmenta el comptador de monedes.

---

### `Spike`
- **Acció**: col·lisionar-hi fa perdre una vida.
- El personatge pot quedar-se a sobre com si fos una plataforma.

---

### `Goomba`
- **Animació**: moviment entre dos punts i animació d’aixafament.
- **Accions**: fa perdre vides quan col·lideix amb els personatges; si és aixafat, desapareix.

---

### `Mushroom`
- **Accions**: recuperar totes les vides i augmentar de mida quan es recull.
- El canvi de mida es manté fins a perdre una vida.

---

### `Star`
- **Animació**: girs de 360º i moviment vertical sinusoidal.
- **Accions**: transforma el personatge augmentant la velocitat i habilitat de salt; desapareix després de recollir-la.

---

### `MainChar`
- **Animacions**: moviment de córrer, creixement per mushroom, canvi de colors per star.
- **Accions**:
  - Immunitat temporal després de rebre dany.
  - Creixement i curació total per mushroom.
  - Transformació per star (més velocitat i salt, canvi de color).

---

### `Finder`
- Implementa una estructura per retornar ràpidament tots els punters dins un interval bidimensional.
- Usat a `Game` per optimitzar la càrrega dels objectes visibles dins del rang de la càmera.

---

### `List`
- Estructura pròpia de llista doblement enllaçada, optimitzada per als requisits del joc.
- S’utilitza dins la classe `Game` per gestionar col·leccions d’objectes amb eficiència.

---

### Altres classes

- **`Window`**: gestiona la finestra de joc, renderització i entrada.
- **`Utils`**: funcions d’utilitat compartides per diferents components.
- **`Platforms`**: crea i gestiona les plataformes del mapa.

---

## Requisits

- Compilador C++ compatible amb C++11 o superior.
- Llibreries gràfiques (com SFML, SDL o similars) segons implementació del joc.
- Sistema operatiu: Windows, Linux o macOS.

---

## Compilació i execució

1. Compila el projecte:
    make

2. Executa el joc:
    ./mario-pro2

---

## Autor

Max Vilà Ruiz