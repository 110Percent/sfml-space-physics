/*
    Physics.cpp
    Ivan Fonseca 2016

    Contains various physics calculations.
*/


// Header file
#include "Physics.h"

// Math
#include <cmath>


// Graviy constant
const double GRAVITY = 6.67300e-11;
const double PI = acos(-1);

// Calculates the distance between two points
double distance(PhysicsObject &firstObject, PhysicsObject &secondObject) {
    return sqrt(pow(firstObject.position.x - secondObject.position.x, 2) + pow(firstObject.position.y - secondObject.position.y, 2));
}

// Calculates the acceleration for the first object based
// on gravitational force between it and the second object
double gravitationalAcceleration(PhysicsObject &firstObject, PhysicsObject &secondObject) {
    return (GRAVITY * (firstObject.mass * secondObject.mass / pow(distance(firstObject, secondObject), 2))) / firstObject.mass;
}

// 

// Adds acceleration from gravitational force to all the physics objects
void addGravity(std::vector<PhysicsObject> &objects) {
    // Loop through objects
    for(int i = 0; i < objects.size(); i++) {
        // Acceleration that will be added
        sf::Vector2f totalAcceleration(0, 0);

        // Loop through the other objects
        for(int n = 0; n < objects.size(); n++) {
            // Make sure this isn't the original object
            if(n != i) {
                // Calculate the gravitational acceleration
                double gravAccel = gravitationalAcceleration(objects[i], objects[n]);
                double theta = atan2(objects[i].position.y - objects[n].position.y, objects[i].position.x - objects[n].position.x) + PI;
                double xAccel = cos(theta) * gravAccel;
                double yAccel = sin(theta) * gravAccel;
                // Add the gravitational acceleration to the total
                totalAcceleration.x += xAccel;
                totalAcceleration.y += yAccel;
            }
        }

        // Add the acceleration to the first object
        objects[i].velocity += totalAcceleration;
    }
}

// Move objects based on velocity
void moveObjects(std::vector<PhysicsObject> &objects) {
    // Loop through objects
    for(int i = 0; i < objects.size(); i++) {
        // Add velocity to position
        objects[i].position += objects[i].velocity;
    }
}
