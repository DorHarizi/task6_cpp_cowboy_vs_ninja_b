#include "Point.hpp"
#include "Character.hpp"
#include <cmath>
#include <string>

using namespace ariel;
using namespace std;
 
 // constructors
 Character::Character(string name, Point location, int numHit):name(name), location(location), numHit(numHit){}
 
 // Getters and seters
string Character::getName(){
    return this->name;
}

Point Character::getLocation(){
    return this->location;
}

void Character::setName(string name){
    this->name = name;
}

void Character::setLocation(Point location){
    this->location = location;
}

// functions
bool Character::isAlive(){
    if(0 < this->numHit){
        return true;
    }
    return false;
}

double Character::distance(Character element){
    return this->location.distance(element.getLocation());
}

void Character::hit(int numHit){
    this->numHit = this->numHit - numHit;
}

string Character::print(){
    if(0 < this->numHit){
        return "name: " + this->name + " Hit: " + to_string(this->numHit) + " location: " + this->getLocation().print();
    } 
    return "name: (" + this->name + ")";
}