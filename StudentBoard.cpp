#include "Board.hpp"
#include "BoardValues.hpp"

#include <algorithm>
#include <iostream>


Board::Board(){
    grid = new int[WIDTH * HEIGHT];
    visible = true;

}

Board::Board(const Board& other){
    // // the first field we copy
    // visible = other.visible;

    // // since it is a pointer
    // grid = new int[WIDTH * HEIGHT];

    // // now we copy the old values in
    // for(int i = 0; i < HEIGHT; i++){
    //     for(int j =0; j <WIDTH;j++){
    //         grid[i][j]= other.grid[i][j];
    //     }
    // }
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

    // int i =0;
    // int j=0;
    // int n =WIDTH;
    // os << *b.grid + i *n +j << " ";
    // i=0;
    // j=1;
    // os<< *b.grid + i *n +j;

    std::string boat = " ";
    os<<"   0  1  2  3  4  5  6  7  8  9"<<'\n';
    os<<"-------------------------------"<<'\n';
    for(int i=0;i<WIDTH;i++){
        os<<i<<" |";
        for(int j=0;j< HEIGHT;j++){
            if(*(b.grid + i * WIDTH + j) == 66) os<<"B";
            if(*(b.grid + i * WIDTH + j) == 67) os<< "C";
            if(*(b.grid + i * WIDTH + j) == 68) os<< "D";
            if(*(b.grid + i * WIDTH + j) == 80) os<< "P";
            if(*(b.grid + i * WIDTH + j) == 83) os<< "S";
            if(*(b.grid + i * WIDTH + j) == 0) os<< "j";
            

            os <<boat<<" ";
        }
        os<<'\n';
    }   
    return os;
    

}
// count the number of hits
int Board::count() const{
}

// compare to
bool Board::operator< (const Board& other){
    

}
void Board::setVisible(bool v){

}
