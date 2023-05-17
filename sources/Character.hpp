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
            int numHit; 


        public:
            // constructors
            Character(string name, Point location, int numHit);
           
            // Getters and seters
            string getName();
            Point getLocation();
            void setName(string name);
            void setLocation(Point location);
        
            // functions
            bool isAlive();
            double distance(Character element);
            void hit(int numhit);
            string print();
            
        };
}