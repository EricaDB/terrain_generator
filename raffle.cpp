/*
 * raffle.cpp
 * Sage Berg
 */

#include <random>
#include <iostream>
#include <map>
#include "raffle.hpp"

Raffle::Raffle() {
}

void Raffle::put(char tile, int weight) {
    if (this->options.find(tile) != this->options.end()) {
        this->options[tile] += weight;
    }
    else {
        this->options[tile] = weight;
    }
}

char Raffle::get() {
    int total_weight = 0;
    for (auto iter = this->options.begin(); 
         iter != this->options.end(); 
         iter++) {
        total_weight += iter->second;
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, total_weight);
    int roll = dist(mt);
    for (auto iter = this->options.begin(); 
         iter != this->options.end(); 
         iter++) {
        if (roll <= iter->second) {
            return iter->first;  // return the key
        }
        else {
            roll -= iter->second;
        }
    }
}
