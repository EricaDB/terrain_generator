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
    virtual void makeMap(int row_size, int col_size) = 0;
    
private:
    //the dimensions of the map
    int row;
    int col;
    
    char **maze;
};

#endif /* GENERATOR_HPP_ */