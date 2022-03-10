#include "Board.hpp"
#include "BoardValues.hpp"

#include <algorithm>
#include <iostream>


Board::Board(){
    this->grid = new int[WIDTH * HEIGHT];
    this->visible = true;
}

Board::Board(const Board& other){
    // the first field we copy
    this->visible = other.visible;

    // since it is a pointer
    this->grid = new int[WIDTH * HEIGHT];

    // now we copy the old values in
    for(int i = 0; i < (WIDTH*HEIGHT); i++){
        this->grid[i]= other.grid[i];
    }
}

Board& Board::operator=(Board& other){
    std::swap(this->visible,other.visible);
    std::swap(this->grid,other.grid);

    return *this;
}

Board::~Board(){
    delete [] grid;
}



int& Board::Internal::operator[](int index){
    if(index >= WIDTH){
            throw std::out_of_range(std::to_string(index) + " is greater value than or equal to grid width of " + std::to_string(WIDTH));
    }
    return _grid[index];
}

Board::Internal Board::operator[](int index){
    if(index >= HEIGHT){
        throw std::out_of_range(std::to_string(index) + " is greater value than or equal to grid height of " + std::to_string(HEIGHT));
    }
    return Board::Internal(grid+(index * WIDTH));
}

std::ostream& operator<<(std::ostream& os, Board const& b){
    return std::cout << b.grid << std::endl;

}
// count the number of hits
int Board::count() const{
}

// compare to
bool Board::operator< (const Board& other){
    

}
void Board::setVisible(bool v){

}
