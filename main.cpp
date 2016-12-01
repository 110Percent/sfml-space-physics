// main.cpp - A template for SFML programs.
// Ivan Fonseca 2016


#include <stdio.h>
// I/O
#include <iostream>
// Math
#include <cmath>
// Vectors
#include <vector>
// SFML
#include <SFML/Graphics.hpp>
// Physics
#include "includes/Physics.h"
// Drawing
#include "includes/Draw.h"


// Function declarations
// Move the planets
void movePlanets(std::vector<PhysicsObject> &planets);


// Planets
std::vector<PhysicsObject> planets;


// Main
int main() {

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Template");

    // Limit to 60 FPS./maui
    window.setFramerateLimit(60);

    // Add two planets
    PhysicsObject planet1;
    planet1.position = sf::Vector2f(50.0f, 50.0f);
    planet1.velocity = sf::Vector2f(0.0f, 0.0f);
    planet1.mass = 2000000000000;

    PhysicsObject planet2;
    planet2.position = sf::Vector2f(300.0f, 300.0f);
    planet2.velocity = sf::Vector2f(0.0f, 0.0f);
    planet2.mass = 2000000000000;

    planets.push_back(planet1);
    planets.push_back(planet2);

    // Main loop
    while(window.isOpen()) {

        // Get events
        sf::Event event;

        while(window.pollEvent(event)) {
            // Check if the window should close
            if(event.type == sf::Event::Closed) {
                // Close the window
                window.close();
            // Check if the mouse button was released
            } else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                // Create a new planet
                PhysicsObject newPlanet;
                newPlanet.position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                newPlanet.velocity = sf::Vector2f(0.0f, 0.0f);
                newPlanet.mass = 2000000000000;
                planets.push_back(newPlanet);
            }
        }

        // Check if the escape key is pressed
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            // Close the window
            window.close();
        }

        // Clear the window
        window.clear();

        // Add gravity
        addGravity(planets);

        // Move planets
        moveObjects(planets);

        // Draw the planets
        drawPlanets(planets, window);

        // Display onto window
        window.display();        
    }

    // Exit with no errors
    return 0;
}