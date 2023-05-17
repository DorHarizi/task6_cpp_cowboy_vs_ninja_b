#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Point.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Point class test")
{
    SUBCASE("constructor Getters and setters"){
        Point tmp1 = Point(0, 0);
        Point tmp2 = Point(0.5, 0.556);
        Point tmp3 = Point(1, 2);
        Point tmp4 = Point(3, 1);

        CHECK(tmp1.getX() ==0);
        CHECK(tmp1.getY() == 0);
        CHECK(tmp2.getX() == 0.5);
        CHECK(tmp2.getY() == 0.556);
        CHECK(tmp3.getX() == 1);
        CHECK(tmp3.getY() == 2);
        CHECK(tmp4.getX() == 3);
        CHECK(tmp4.getY() == 1);

        tmp4.setX(0);
        tmp4.setY(0);
        tmp3.setX(0.5);
        tmp3.setY(0.556);
        tmp2.setX(1);
        tmp2.setY(2);
        tmp1.setX(3);
        tmp1.setY(1);

        CHECK(tmp4.getX() == 0);
        CHECK(tmp4.getY() == 0);
        CHECK(tmp3.getX() == 0.5);
        CHECK(tmp3.getY() == 0.556);
        CHECK(tmp2.getX() == 1);
        CHECK(tmp2.getY() == 2);
        CHECK(tmp1.getX() == 3);
        CHECK(tmp1.getY() == 1);
    }

    SUBCASE("Distance function test"){
        Point tmp1 = Point(8, 5);
        Point tmp2 = Point(2, 3);
        Point tmp3 = Point(4, 7);
        Point tmp4 = Point(-5, 9);
        CHECK(int(tmp1.distance(tmp2)) == 6);
        CHECK(int(tmp3.distance(tmp4)) == 9);
    }

    SUBCASE("moveTowards function test"){
        Point tmp1 = Point(2, 2);
        Point tmp2 = Point(7, 7);
        Point tmp3 = Point(0, 0);
        tmp3.moveTowards(tmp1, tmp2, 2.0);
        CHECK(tmp2.distance(tmp3) <= 10.0);
    }

    SUBCASE("print function test"){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        CHECK(tmp1.print() == "(1,2)");
        CHECK(tmp2.print() == "(3,7)");
    }

}

TEST_CASE("Character class test")
{
    SUBCASE("constructor Getters and setters"){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        Character ch1 = Character("Dor", tmp1, 100);
        Character ch2 = Character("roni", tmp2, 100);
        CHECK(ch1.getName() == "Dor");
        CHECK(ch2.getName() == "roni");
        CHECK(ch1.getLocation().getX() == 1);
        CHECK(ch1.getLocation().getY() == 2);
        CHECK(ch2.getLocation().getX() == 3);
        CHECK(ch2.getLocation().getY() == 7);
        ch1.setName("roni");
        ch2.setName("Dor");
        CHECK(ch2.getName() == "Dor");
        CHECK(ch1.getName() == "roni");
        ch1.setLocation(tmp2);
        ch2.setLocation(tmp1);
        CHECK(ch2.getLocation().getX() == 1);
        CHECK(ch2.getLocation().getY() == 2);
        CHECK(ch1.getLocation().getX() == 3);
        CHECK(ch1.getLocation().getY() == 7);
    }

    SUBCASE("isAlive and hit functions test"){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        Character ch1 = Character("Dor", tmp1, 100);
        Character ch2 = Character("roni", tmp2, 100);
        CHECK(ch1.isAlive() == true);
        CHECK(ch2.isAlive() == true);
        ch1.hit(100);
        ch2.hit(100);
        CHECK(ch1.isAlive() == false);
        CHECK(ch2.isAlive() == false);
    }
}

TEST_CASE("Cowboy class test")
{
    SUBCASE("cowboy constructor test "){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        Cowboy cb1 = Cowboy("Dor", tmp1);
        Cowboy cb2 = Cowboy("roni", tmp2);
        CHECK(cb1.getName() == "Dor");
        CHECK(cb2.getName() == "roni");
        CHECK(cb1.getLocation().getX() == 1);
        CHECK(cb1.getLocation().getY() == 2);
        CHECK(cb2.getLocation().getX() == 3);
        CHECK(cb2.getLocation().getY() == 7);
    }
    SUBCASE("cowboy functions test"){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        Cowboy cb1 = Cowboy("Dor", tmp1);
        Cowboy cb2 = Cowboy("roni", tmp2);
        CHECK(cb1.hasboolets() == true);
        CHECK(cb2.hasboolets() == true);
//        while(cb1.isAlive()){
//            cb1.shoot(&cb2);
//        }
        CHECK(cb1.hasboolets() == true);
        cb1.reload();
        CHECK(cb1.hasboolets() == true);
    }
}

TEST_CASE("Ninja class test")
{
    SUBCASE("Ninja constructor test"){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        Ninja n1 = Ninja("Dor", tmp1, 100, 60);
        Ninja n2 = Ninja("roni", tmp2, 100, 60);
        CHECK(n1.getName() == "Dor");
        CHECK(n2.getName() == "roni");
        CHECK(n1.getLocation().getX() == 1);
        CHECK(n1.getLocation().getY() == 2);
        CHECK(n2.getLocation().getX() == 3);
        CHECK(n2.getLocation().getY() == 7);
    }

    SUBCASE("Ninja functions test"){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        Ninja n1 = Ninja("Dor", tmp1, 100, 60);
        Ninja n2 = Ninja("roni", tmp2, 100, 80);
        n1.move(&n2);
        CHECK(n1.getLocation().getX() == 1);
        CHECK(n1.getLocation().getY() == 2);
        n1.slash(&n2);
        n1.slash(&n2);
        CHECK(n2.isAlive() == true);
    }
}

TEST_CASE("Team class test")
{
    SUBCASE("Team constructor test"){
        Point tmp1 = Point(1, 2);
        Ninja n1 = Ninja("Dor", tmp1, 100, 80);
        Team t1 = Team(&n1);
        CHECK(t1.stillAlive() == false);
    }

    SUBCASE("Team functions test"){
        Point tmp1 = Point(1, 2);
        Point tmp2 = Point(3, 7);
        Ninja n1 = Ninja("Dor", tmp1, 100, 80);
        Ninja n2 = Ninja("roni", tmp2, 100, 80);
        Team t1 = Team(&n1);
        Team t2 = Team(&n2);
        CHECK(t1.stillAlive() == false);
        CHECK(t2.stillAlive() == false);
        t1.attack(&t2);
        t1.attack(&t2);
        CHECK(t1.stillAlive() == false);
        CHECK(t2.stillAlive() == false);
    }
}



