/*
    Draw.cpp
    Ivan Fonseca 2016

    Various functions for drawing objects.
*/


// Header file
#include "Draw.h"

#include <iostream>


// Draws planets from a vector
void drawPlanets(std::vector<PhysicsObject> &planets, sf::RenderWindow &window) {
    // Loop through planets
    for(int i = 0; i < planets.size(); i++) {
        // Create a circle
        sf::CircleShape circle(planets[i].radius);
        // Colour the circle
        circle.setFillColor(sf::Color::Red);
        // Set the position
        circle.setPosition(planets[i].position);
        // Draw the circle
        window.draw(circle);
        std::cout << "(" << planets[i].position.x << ", " << planets[i].position.y << ")" << std::endl;
    }
}