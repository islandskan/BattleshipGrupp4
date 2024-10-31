#include "Ship.h"
#include <iostream>

// Konstruktor för Ship-klassen som tar emot parametrar som specificerar vissa egenskaper hos ett skepp,
// såsom name, pointValue, size och isCaptain, och sätter dessa till motsvarande privata variabler i klassen.
Ship::Ship(std::string name, int pointValue, int size, bool isCaptain)
    : name(name), pointValue(pointValue), size(size), hitCount(0), isSunk(false), isCaptain(isCaptain) {}

// Getter-funktioner som returnerar skeppets egenskaper
std::string Ship::getName() const { return name; }      // Returnerar skeppets namn
int Ship::getPointValue() const { return pointValue; }  // Returnerar skeppets poängvärde
int Ship::getSize() const { return size; }              // Returnerar skeppets storlek
int Ship::getHitCount() const { return hitCount; }      // Returnerar antalet träffar på skeppet
bool Ship::getIsSunk() const { return isSunk; }         // Returnerar om skeppet är sänkt
bool Ship::getIsCaptain() const { return isCaptain; }   // Returnerar om skeppet är en kapten

// Metod för att markera en träff på skeppet
void Ship::hit() {
    if (isSunk) { // Om skeppet redan är sänkt, skriv ut ett meddelande
        std::cout << "Skeppet " << name << " är redan sänkt.\n";
        return;
    }
    hitCount++; // Om skeppet inte är sänkt, ökar vi hitCount med 1 för att registrera den nya träffen
    if (hitCount >= size) { // Kontrollera om hela skeppet är sänkt
        isSunk = true;
        std::cout << "Skeppet " << name << " har blivit sänkt!\n";
    } else {
        std::cout << "Skeppet " << name << " har blivit träffat! Totala träffar: " << hitCount << "\n";
    }
}

// Kontrollera om skeppet är sänkt
bool Ship::checkIfSunk() const {
    return isSunk; // Returnerar true om skeppet är sänkt, annars false
}
