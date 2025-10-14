#ifndef FRUIT_HH
#define FRUIT_HH

#include <string>

class Fruit {
    std::string name_;
    int price_;

 public:
    Fruit(std::string name, int price) : name_(name), price_(price) {}

    /**
     * @brief Retorna el nom de la fruita
     *
     * @returns El nom de la fruita
     */
    std::string name() const {
        return name_;
    }

    /**
     * @brief Retorna el preu de la fruita
     *
     * @returns El preu de la fruita
     */
    int price() const {
        return price_;
    }

    /**
     * @brief Compara dues fruites
     *
     * Es fa servir un criteri de comparació exactament igual que el que necessita el problema, és a
     * dir, una fruita és "més gran" si té un preu més gran, o bé si el preu és igual, si el seu nom
     * és anterior en ordre lexicogràfic.
     *
     * @param other L'altra fruita (la primera és el paràmetre implícit)
     * @returns `true` si la primera fruita és major que la segona, `false` en cas contrari.
     */
    bool is_greater_than(const Fruit& other) const {
        if (price_ != other.price_) {
            return price_ > other.price_;
        } else {
            return name_ < other.name_;
        }
    }
};

#endif  // FRUIT_HH