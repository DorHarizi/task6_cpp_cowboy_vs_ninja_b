#pragma once

#include "Team.hpp"
using namespace std;
using namespace ariel;

namespace ariel {
    class SmartTeam : public Team {
        public:
            SmartTeam(Character *leader);

            void findNewLeader();

            void findNewVictim(Character **victim, Team *enemyTeam);

            void attack(Team *enemyTeam);

    };
}