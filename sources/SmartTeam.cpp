#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"
#include <stdexcept>
#include <limits>

using namespace ariel;
using namespace std;

SmartTeam::SmartTeam(ariel::Character *leader):Team(leader) {}

void SmartTeam::findNewLeader(){
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

void SmartTeam::findNewVictim(Character **victim, Team *enemyTeam) {
    int numOfCowboys = 0;
    int numOfNinjas = 0;
    int numOfLifeVictim = 0;
    int maxDamage2 = numeric_limits<double>::min();

//    Check how many players from type ninja and from type cowboy
    for(vector<Character*>::size_type i = 0; i < this->team.size(); i++){
        if(this->team[i]->isAlive()) {
            if(dynamic_cast<Cowboy *>(this->team[i]))
                numOfCowboys += 1;
            if(dynamic_cast<Ninja *>(this->team[i]))
                numOfNinjas += 1;

        }
    }
//  here we chose the optimal victim for the attack enemy that can kill or
    for(vector<Character*>::size_type i =0; i<enemyTeam->team.size(); i++){
        int maxDamage1 = 0;
        if(enemyTeam->team[i]->isAlive()){
            numOfLifeVictim = enemyTeam->team[i]->getNumOfHit();
//          check if in enemy team have a victim that the ninja can kill
            if(numOfLifeVictim <= ((numOfNinjas * 40) + (numOfCowboys * 10))){
                for(vector<Character*>::size_type j = 0; j < this->team.size(); j++){
                    if(this->team[j]->isAlive() && (dynamic_cast<Ninja *>(this->team[j])) && (this->team[j]->distance(enemyTeam->team[i]) < 1)){
                        numOfLifeVictim -= 40;
                        maxDamage1 += 40;
                        numOfNinjas -= 1;
                        if(numOfLifeVictim <= 0){
                            *victim = enemyTeam->team[i];
                            return;
                        }
                    }
                }
            }
//          check if the chosen victim after ninja attack the cowboys can kill him
            if(numOfLifeVictim <= (numOfCowboys * 10)){
                for(vector<Character*>::size_type j = 0; j < this->team.size(); j++){
                    if((this->team[j]->isAlive()) && (dynamic_cast<Cowboy *>(this->team[j]))){
                        Cowboy *c1 = dynamic_cast<Cowboy *>(this->team[j]);
                        if(c1->hasboolets()){
                            numOfLifeVictim -= 10;
                            maxDamage1 += 10;
                            numOfCowboys -= 1;
                            if(numOfLifeVictim <= 0){
                                *victim = enemyTeam->team[i];
                                return;
                            }
                        }
                    }
                }
            }
//          if we are here the attack team can't kill the chosen victim and save him maybe
//          this victim is the beast option for the attack team because they cause MaxDamage
            if((maxDamage2 < maxDamage1) && (maxDamage1 != 0)){
                maxDamage2 = maxDamage1;
                *victim = enemyTeam->team[i];
            }
        }
    }
}

void SmartTeam::attack(Team *enemyTeam) {
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

