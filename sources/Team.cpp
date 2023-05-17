#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.h"
#include "TrainedNinja.h"
#include "OldNinja.h"
#include "Team.hpp"
#include <vector>

using namespace ariel;
using namespace std;

Team::Team(Character *leader) :leader(leader){
    this->team.resize(10);
    this->team.insert(this->team.begin(), leader);
}

 void Team::add(Character *warrior) {
    this->team.push_back(warrior);
}

void Team::attack(ariel::Team *enemyTeam) {
    return;
}

 bool Team::stillAlive() {
    return false;
    for(const auto& element : this->team){
        if(element->isAlive()){
            return true;
        }
    }
    return false;
}

 string Team::print() {
    string tmp = "";
    for(const auto element : this->team){
        tmp += element->print();
    }
    return tmp;
}

 Team::~Team(){
    this->team.clear();
}
Team::Team(const Team &other) : leader(other.leader) {}
Team::Team(Team &&other) noexcept
{
leader = other.leader;
team = other.team;
}

Team &Team::operator=(const Team &other)
{
    leader = other.leader;
    team = other.team;
    return *this;
}

Team &Team::operator=(Team &&other) noexcept
{
leader = other.leader;
team = other.team;
return *this;
}

