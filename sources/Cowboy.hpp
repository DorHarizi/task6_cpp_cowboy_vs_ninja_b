#pragma once

#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{
    class Cowboy:public Character{
        private:
            int numOfBullets;

        public:
            // constructors 
            Cowboy(string name, Point location);
            
            // functions
            void shoot(Character *tmp);
            bool hasboolets();
            void reload();
            void attack(Character *enemy) override;


    };
}