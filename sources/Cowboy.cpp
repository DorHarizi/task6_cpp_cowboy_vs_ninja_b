#include "Cowboy.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

Cowboy::Cowboy(string name, Point location):Character(name, location, 110), numOfBullets(6){}

void Cowboy::attack(Character *enemy){
    if(!this->isAlive() || !enemy->isAlive())
        return;
    if(!this->hasboolets())
        this->reload();
    else
        this->shoot(enemy);
}

void Cowboy::shoot(Character *enemy){
    if(this == enemy)
        throw runtime_error("The user cant shoot himself");
    if(!this->isAlive() || !enemy->isAlive())
        throw runtime_error("Error try to shoot but the cowboy is dead\n");
    if(this->hasboolets()){
        enemy->hit(10);
        this->numOfBullets -= 1;
    }
}

bool Cowboy::hasboolets(){
    if(0 < this->numOfBullets && this->isAlive()){
        return true;
    }
    return false;
}

void Cowboy::reload(){
    if(!this->isAlive())
        throw runtime_error("Error try to reload but the cowboy is dead\n");
    this->numOfBullets += 6 -this->numOfBullets;
}



