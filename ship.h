#ifndef SHIP_H
#define SHIP_H

#include <string>

// Bas-klassen för skepp, innehåller allmänna egenskaper och metoder för skepp
class Ship {
private:
    std::string name;      // Skeppets namn
    int pointValue;        // Poängvärde för skeppet
    int size;              // Skeppets storlek (antal rutor)
    int hitCount;          // Antal gånger skeppet har blivit träffat
    bool isSunk;           // Om skeppet har blivit sänkt
    bool isCaptain;        // Om detta skepp är en kapten

public:
    // Konstruktor, anropas automatiskt när ett nytt objekt av klassen skapas
    Ship(std::string name, int pointValue, int size, bool isCaptain = false);

    // Getter-funktioner som returnerar skeppets egenskaper
    std::string getName() const;       // Returnerar skeppets namn
    int getPointValue() const;         // Returnerar poängvärdet
    int getSize() const;               // Returnerar storleken
    int getHitCount() const;           // Returnerar antalet träffar
    bool getIsSunk() const;            // Returnerar om skeppet är sänkt
    bool getIsCaptain() const;         // Returnerar om skeppet är kapten

    // Metoder
    void hit();                        // Markerar en träff på skeppet
    bool checkIfSunk() const;          // Kontrollera om skeppet är sänkt
};

// Subklass för Kapten (1x1) skepp
class Captain : public Ship {
public:
    Captain() : Ship("Captain", 100, 1, true) {}  // Konstruktor för Kapten-skepp med förvalda värden
};

// Subklass för Ubåt (2x1) skepp
class Submarine : public Ship {
public:
    Submarine() : Ship("Submarine", 200, 2) {}  // Konstruktor för Ubåt med förvalda värden
};

// Subklass för Destroyer (3x1) skepp
class Destroyer : public Ship {
public:
    Destroyer() : Ship("Destroyer", 300, 3) {}  // Konstruktor för Destroyer med förvalda värden
};

// Subklass för Kryssare (4x1) skepp
class Cruiser : public Ship {
public:
    Cruiser() : Ship("Cruiser", 400, 4) {}  // Konstruktor för Kryssare med förvalda värden
};

// Subklass för Hangarfartyg (5x1) skepp
class Carrier : public Ship {
public:
    Carrier() : Ship("Carrier", 500, 5) {}  // Konstruktor för Hangarfartyg med förvalda värden
};

#endif
