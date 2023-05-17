#include "Character.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

Cowboy::Cowboy(string name, Point location):numOfBullets(6), Character(name, location, 110){}

void Cowboy::shoot(Character *enemy){
    return;
}

bool Cowboy::hasboolets(){
    if(0 < this->numOfBullets){
        return true;
    }
    return false;
}

void Cowboy::reload(){
    return;
}



