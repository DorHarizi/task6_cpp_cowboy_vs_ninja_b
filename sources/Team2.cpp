#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include <stdexcept>
#include <limits>

using namespace ariel;
using namespace std;

Team2::Team2(ariel::Character *leader):Team(leader) {}

void Team2::findNewLeader(){
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

void Team2::findNewVictim(Character **victim, Team *enemyTeam) {
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

void Team2::attack(ariel::Team *enemyTeam) {
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
        if(this->team[i]->isAlive())
            this->team[i]->attack(victim);
    }
}
