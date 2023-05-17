#pragma once
#include "Ninja.hpp"
class OldNinja:public Ninja {
    public:
        OldNinja(string name, Point location):Ninja(name, location, 150, 8) {}
};

