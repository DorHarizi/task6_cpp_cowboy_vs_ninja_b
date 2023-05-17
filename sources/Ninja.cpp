#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include <string>

using namespace ariel;
using namespace std;

Ninja::Ninja(string name, Point location, int numHit, int speed):Character(name, location,numHit),speed(speed){}

void Ninja::move(Character *enemy){
    return;
}

bool Ninja::slash(Character *enemy){
    return true;
}

