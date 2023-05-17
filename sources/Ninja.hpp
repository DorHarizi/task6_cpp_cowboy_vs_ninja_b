#pragma once

#include "Point.hpp"
#include "Character.hpp"

using namespace std;
using namespace ariel;


namespace ariel{
    class Ninja:public Character{
        private:
            int speed;

        public:
            // constructors 
            Ninja(string name, Point location, int numHit, int speed);
            
            // functions
            void move(Character *enemy);
            bool slash(Character *enemy);
    };
}