/*
    Draw.h
    Ivan Fonseca 2016

    Various functions for drawing objects.
*/

// Include guard
#ifndef INCLUDES_DRAW_H
#define INCLUDES_DRAW_H


// Vectors
#include <vector>
// SFML
#include <SFML/Graphics.hpp>
// Physics
#include "Physics.h"


// Draws planets from a vector
void drawPlanets(std::vector<PhysicsObject> &planets, sf::RenderWindow &window);


#endif