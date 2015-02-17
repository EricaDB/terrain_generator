/*
 * raffle.hpp
 * Sage Berg
 */

#include <map>
#include <iostream>

#ifndef RAFFLE_HPP_
#define RAFFLE_HPP_

class Raffle {
public:
    Raffle();
    void put(char terrain, int weight);
    char get();
private:
    std::map<char, int> options;
};

#endif 
