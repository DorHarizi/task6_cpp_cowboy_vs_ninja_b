#pragma once
#include "Ninja.hpp"
class TrainedNinja:public Ninja {
    public:
        TrainedNinja(string name, Point location):Ninja(name, location, 120, 12) {}
};