#ifndef UTILS_HH
#define UTILS_HH

#include <vector>
#include "geometry.hh"
#include "window.hh"

namespace pro2 {

/**
 * @brief Dibuja una línea horizontal en la ventana.
 *
 * @param window Ventana en la que se dibuja la línea.
 * @param xini Coordenada x inicial.
 * @param xfin Coordenada x final.
 * @param y Coordenada y.
 * @param color Color de la línea (opcional, si no se pone se asume `white`).
 */
void paint_hline(pro2::Window& window, int xini, int xfin, int y, pro2::Color color = pro2::white);

/**
 * @brief Dibuja una línea vertical en la ventana.
 *
 * @param window Ventana en la que se dibuja la línea.
 * @param x Coordenada x.
 * @param yini Coordenada y inicial.
 * @param yfin Coordenada y final.
 * @param color Color de la línea (opcional, si no se pone se asume `white`).
 */
void paint_vline(pro2::Window& window, int x, int yini, int yfin, pro2::Color color = pro2::white);

/**
 * @brief Dibuixa una imatge/textura a la finestra a partir d'una posició
 *
 * @param window Finestra a la que pintar
 * @param orig   Origen (cantonada de dalt a l'esquerra) del rectangle que forma el _sprite_
 * @param sprite Matriu de colors que representa la imatge (_sprite_).
 * @param mirror Si cal pintar girar la textura horitzontalment
 */
void paint_sprite(pro2::Window&                        window,
                  pro2::Pt                             orig,
                  const std::vector<std::vector<int>>& sprite,
                  bool                                 mirror);

/**
 * @brief Dibuixa un rectangle ple a la finestra amb un color donat.
 *
 * @param window    Finestra a la que pintar.
 * @param rectangle Rectangle que es vol pintar.
 * @param color     Color amb el qual es pintarà el rectangle.
 */
void paint_rect(pro2::Window& window, pro2::Rect rectangle, pro2::Color color);

/**
 * @brief Diu si els dos objectes s'estan col·lisionant (true) o si no (false).
 *
 * La funció 'objs_collision' compara les posicions dels rectangles dels dos objectes que
 * rep pels paràmetres per determinar si s'estan tocant / col·lisionant. En cas vafirmatiu, 
 * la funció retorna 'true'; altrament, retorna 'false'.
 *
 * @param obj1 Rectangle que conté a l'objecte 1
 * @param obj2 Rectangle que conté a l'objecte 2
 */
bool objs_collision(pro2::Rect obj1, pro2::Rect obj2);
}  // namespace pro2

#endif