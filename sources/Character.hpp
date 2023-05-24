#pragma once

#include "Point.hpp"
#include <string>
#include <stdbool.h>

using namespace std;

namespace ariel{
    class Character{
        private:
            string name;
            Point location;
            int numOfHit;
            bool inTeam;

        public:
            // constructors
            Character(string name, Point location, int numOfHit);
           
            // Getters and setters
            string getName();
            Point getLocation();
            bool getInTeam();
            int getNumOfHit();
            void setName(string name);
            void setLocation(Point location);
            void setInTeam(bool tmp);
        
            // functions
            bool isAlive() const;
            double distance(Character *element);
            virtual void attack(Character *enemy);
            void hit(int Hit);
            string print();
            
        };
}