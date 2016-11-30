/*
    Physics.h
    Ivan Fonseca 2016

    Contains various physics calculations.
*/


// Include guard
#ifndef INCLUDES_PHYSICS_H
#define INCLUDES_PHYSICS_H


// SFML
#include <SFML/Graphics.hpp>


// A physics object
struct PhysicsObject {
    // Position
    sf::Vector2f position;
    // Direction
    double direction;
    // Velocity
    sf::Vector2f velocity;
    // Mass
    double mass;
};

// Calculates the distance between two points
double distance(PhysicsObject &firstObject, PhysicsObject &secondObject);

// Calculates the acceleration for the first object based
// on gravitational force between it and the second object
double gravitationalAcceleration(PhysicsObject &firstObject, PhysicsObject &secondObject);

// Adds acceleration from gravitational force to all the physics objects
void addGravity(std::vector<PhysicsObject> &objects);

// Move objects based on velocity
void moveObjects(std::vector<PhysicsObject> &objects);


#endif