#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"
#include <stdexcept>
#include <limits>

using namespace ariel;
using namespace std;

Team::Team(Character *leader):leader(leader){
    if(leader->getInTeam())
        throw runtime_error("The user try to insert character but this character already use\n");
    leader->setInTeam(true);
    this->team.reserve(10);
    this->team.insert(this->team.begin(), leader);
}

 void Team::add(Character *warrior) {
     if(warrior->getInTeam())
         throw runtime_error("The user try to insert character but this character already use\n");
    if(this->team.size() < 10){
        warrior->setInTeam(true);
        this->team.push_back(warrior);
    }
    else
        throw runtime_error("The user try to insert character but the team is full\n");
}

void Team::findNewLeader(){
    double minDistance = numeric_limits<double>::max();
    Character *tmpCh = this->leader;
    for(vector<Character*>::size_type i = 0; i < team.size(); i++){
        if(this->team[i]->isAlive()){
            double tmp = this->leader->distance(this->team[i]);
            if(tmp < minDistance && this->leader != this->team[i]){
                minDistance = tmp;
                tmpCh = this->team[i];
            }
        }
    }
    this->leader = tmpCh;
}

void Team::findNewVictim(Character **victim, Team *enemyTeam) {
    double minDistance = numeric_limits<double>::max();
    for(vector<Character*>::size_type i = 0; i < enemyTeam->team.size(); i++){
        if(enemyTeam->team[i]->isAlive()){
            double tmp = this->leader->distance(enemyTeam->team[i]);
            if(tmp < minDistance && (*victim != enemyTeam->team[i])){
                minDistance = tmp;
                *victim = enemyTeam->team[i];
            }
        }
    }
}

void Team::attack(ariel::Team *enemyTeam) {
    if(enemyTeam == NULL)
        throw invalid_argument("The user attack null pointer enemyTeam()");
    if(enemyTeam->stillAlive() == 0)
        throw runtime_error("The enemyTeam already dead");
    if(!this->leader->isAlive())
        findNewLeader();
    Character *victim;
    findNewVictim(&victim, enemyTeam);
    for(vector<Character*>::size_type i = 0; i < team.size(); i++){
        if(!victim->isAlive())
            findNewVictim(&victim, enemyTeam);
        if(this->team[i]->isAlive()) {
            if (dynamic_cast<Cowboy *>(this->team[i]))
                this->team[i]->attack(victim);
            }
    }
    for(vector<Character*>::size_type i = 0; i < team.size(); i++){
        if(!victim->isAlive())
            findNewVictim(&victim, enemyTeam);
        if(this->team[i]->isAlive()) {
            if (dynamic_cast<Ninja*>(this->team[i]))
                this->team[i]->attack(victim);
        }
    }
}

int Team::stillAlive() {
    int count = 0;
    for(vector<Character*>::size_type i = 0; i < team.size(); i++){
        if(this->team[i]->isAlive()){
            count += 1;
        }
    }
    return count;
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

