/*
 * generator.hpp
 *
 * An abstract class defining the interface
 * that is implemented by different types of
 * map generators.
 */

#ifndef GENERATOR_HPP_
#define GENERATOR_HPP_

class Generator {
public:
    
    Generator() {}
    ~Generator() {}
    
    // Fill the map (which was allocated in the constructor)
    virtual void makeMap() = 0;
};

#endif /* GENERATOR_HPP_ */
