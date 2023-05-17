 #pragma once

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.h"
#include "TrainedNinja.h"
#include "OldNinja.h"
#include "Team.hpp"
#include <vector>

 using namespace std;
 using namespace ariel;

 namespace ariel{
     class Team{
         private:
             vector<Character *> team;
             Character *leader;

         public:
            Team(Character *leader);
            void add(Character *warrior);
            void attack(Team *enemyTeam);
            bool stillAlive();
            string print();
            ~Team();
            Team(const Team &);
            Team &operator=(const Team &);
            Team(Team &&) noexcept;
            Team &operator=(Team &&) noexcept;
     };
 }



