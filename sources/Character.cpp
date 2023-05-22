#include "Character.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;
 
 // constructors
 Character::Character(string name, Point location, int numOfHit):name(name), location(location), numOfHit(numOfHit){
     this->setInTeam(false);
 }
 
 // Getters and seters
string Character::getName(){
    return this->name;
}

bool Character::getInTeam() {
    return this->inTeam;
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

void Character::setInTeam(bool tmp) {
     this->inTeam = tmp;
 }

// functions
bool Character::isAlive() const{
    if(0 < this->numOfHit){
        return true;
    }
    return false;
}

double Character::distance(Character *element){
    return this->location.distance(element->getLocation());
}

void Character::hit(int Hit){
     if(Hit <= 0)
         throw invalid_argument("The user hit negative number");
     this->numOfHit -= Hit;
     if(this->numOfHit < 0)
         this->numOfHit = 0;
}

void Character::attack(ariel::Character *tmp) {

 }

string Character::print(){
    if(0 < this->numOfHit){
        return "name: " + this->name + " Hit: " + to_string(this->numOfHit) + " location: " + this->getLocation().print();
    } 
    return "name: (" + this->name + ")";
}