#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include <string>
#include <stdexcept>

using namespace ariel;
using namespace std;

Ninja::Ninja(string name, Point location, int numHit, int speed):Character(name, location,numHit),speed(speed){}

void Ninja::move(Character *enemy){
    if(!this->isAlive() && !enemy->isAlive())
        throw invalid_argument("The player or the enemy is dead");
    if((this->getLocation().getX() != enemy->getLocation().getX()) && (this->getLocation().getY() != enemy->getLocation().getY())){
        Point new_location = ariel::Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
        this->setLocation(new_location);
    }
}
void Ninja::attack(Character *enemy){
    if(!this->isAlive() || !enemy->isAlive())
        return;
    if(this->distance(enemy) < 1)
        this->slash(enemy);
    else
        this->move(enemy);
}

bool Ninja::slash(Character *enemy) {
    if(this == enemy)
        throw runtime_error("The user cant slash himself");
    if(!this->isAlive())
        throw runtime_error("The user is dead already dead");
    if(!enemy->isAlive())
        throw runtime_error("The enemy is already dead");
    double distance = this->distance(enemy);
    if(distance < 1){
        enemy->hit(40);
        return true;
    }
    return false;
}


