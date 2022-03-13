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
    for(int i = 0; i < HEIGHT; i++){
        for(int j =0; j <WIDTH;j++){
            this->grid[i]= other.grid[i];
        }
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

    std::string boat = " ";
    os<<"   0  1  2  3  4  5  6  7  8  9"<<'\n';
    os<<"-------------------------------"<<'\n';
    for(int i=0;i<WIDTH;i++){
        os<<i<<" |";
        for(int j=0;j< HEIGHT;j++){
            if(*(b.grid + i * WIDTH + j) == 66) os<< "B";
            if(*(b.grid + i * WIDTH + j) == 67) os<< "C";
            if(*(b.grid + i * WIDTH + j) == 68) os<< "D";
            if(*(b.grid + i * WIDTH + j) == 80) os<< "P";
            if(*(b.grid + i * WIDTH + j) == 83) os<< "S";
            
            if(*(b.grid + i * WIDTH + j) == 42) os<< "*";
            if(*(b.grid + i * WIDTH + j) == 95) os<< "-";


            if(*(b.grid + i * WIDTH + j) == 0) os<< " ";
            

            os <<boat<<" ";
        }
        os<<'\n';
    }   
    return os;
    

}
// count the number of hits
int Board::count() const{
    int hits=0;
    for(int i=0; i < WIDTH;i++){
        for(int j=0; j < HEIGHT; j++){
            if(*(this->grid + i * WIDTH + j) == 42)
                hits++;
        }
    }
    return hits;

}

// compare to
bool Board::operator< (const Board& other){

    return this->count() < other.count();

}
void Board::setVisible(bool v){

}
