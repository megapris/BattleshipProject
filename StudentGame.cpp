#include "Board.hpp"
#include "Direction.hpp"
#include "Game.hpp"
#include "Ship.hpp"
#include <iostream>
#include <random>

/**
 * Constructor will create the ships vector and add ships to it.
 */
Game::Game(){
	Ship* ships[6];
	ships[0] = new Ship(5,"Tank",0);
	ships[1] = new Ship(4,"Battleship",1);
	ships[2] = new Ship(3,"Destroyer",2);
	ships[3] = new Ship(3,"Submarine",3);
	ships[4] = new Ship(2,"Patrol Boat",4);

	std::cout << *ships[0] << std::endl;
	std::cout << *ships[1] << std::endl;
	std::cout << *ships[2] << std::endl;
	std::cout << *ships[3] << std::endl;
	std::cout << *ships[4] << std::endl;

}

/**
 * Begin Game let's user and then computer setup boards then calls run()
 */
void Game::beginGame(){
	Game::hello();
}


/**
 * Handle the human placing ships.
 */
void Game::placeShips(){
}

/**
 * Handle the computer placing ships.
 */
void Game::placeShipsPC(){
}

/**
 * Helper method that checks if it is safe to put a ship
 * at a particular spot with a particular direction.
 */
bool Game::place(const int& x, const int& y, Direction d, const Ship& s, Board& b){
}

/**
 * Call human turn/computer turn until someone wins.
 */
void Game::run(){
}

void Game::humanTurn(){
}

void Game::computerTurn(){
}

void Game::hello(){
	std::cout<<"Hello welcome to the game" << '\n' << '\n';
	

}

/**
 * Create a game instance and start.
 */
int main(int argc, char** argv){
	(void)argc;
	(void)argv;
	Game g;
	g.beginGame();

	return 0;
}
