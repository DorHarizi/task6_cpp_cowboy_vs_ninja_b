#pragma once
#include "Ninja.hpp"
class YoungNinja:public Ninja {
    public:
        YoungNinja(string name, Point location):Ninja(name, location, 100, 14){}
};