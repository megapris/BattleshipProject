#include "Board.hpp"
#include "Direction.hpp"
#include "Game.hpp"
#include "Ship.hpp"
#include <iostream>
#include <random>



Board* player_board; 
Board* pc_board; 



/**
 * Constructor will create the ships vector and add ships to it.
 */
Game::Game(){

	Ship* barcos[6];

	barcos[0] = new Ship(5,"Carrier",67);
	barcos[1] = new Ship(4,"Battleship",66);
	barcos[2] = new Ship(3,"Destroyer",68);
	barcos[3] = new Ship(3,"Submarine",83);
	barcos[4] = new Ship(2,"Patrol Boat",80);


	ships.push_back(*barcos[0]);
	ships.push_back(*barcos[1]);
	ships.push_back(*barcos[2]);
	ships.push_back(*barcos[3]);
	ships.push_back(*barcos[4]);

	
	

}

/**
 * Begin Game let's user and then computer setup boards then calls run()
 */
void Game::beginGame(){
	player_board = new Board;
	pc_board = new Board;


	


	for(int i=0; i < HEIGHT; i++){
		for(int j=0; j < WIDTH;j++){
			player_board->operator[](i).operator[](j)=00;
		}
	}
	
	std::cout <<*player_board << std::endl;

	placeShips();

	


	
}


/**
 * Handle the human placing ships.
 */
void Game::placeShips(){

	int x =0;
	int y=0;
	int tmp = 0;
	bool status = false;
	Direction user_dir = HORIZONTAL;

	

	for(int i = 0; i < 6;i++){
		std::cout<<"where do you want to place " << ships[i] << std::endl;
		std::cin >> x >> y;
		std::cout<< "Horizontal (0) or Vertical (1)"<<std::endl;
		std::cin>> tmp;
		if(tmp == 1) user_dir = VERTICAL;
		else user_dir = HORIZONTAL;
		
		do{
			status=place(x,y,user_dir,ships[i],*player_board);
			if(status == false){
				std::cout<<"Lets try that again"<<std::endl;
				std::cin >> x >> y;
				std::cout<< "Horizontal (0) or Vertical (1)"<<std::endl;
				std::cin>> tmp;
				if(tmp == 1) user_dir = VERTICAL;
				else user_dir = HORIZONTAL;
			}
		}while(status==false);
			
		std::cout <<*player_board << std::endl;

	}
	
	


	

	

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

	BoardValues boardVal = EMPTY;
	if(d==HORIZONTAL){
		std::cout<<"Attempting horizontal placement"<<std::endl;
		for(int v=0; v< s.getSpaces(); v++){
			if(b.operator[](x).operator[](y+v) == 66 ||
				b.operator[](x).operator[](y+v) == 67 ||
				b.operator[](x).operator[](y+v) == 68 ||
				b.operator[](x).operator[](y+v) == 80 ||
				b.operator[](x).operator[](y+v) == 83)

				return false;
		}
		if(x==WIDTH-1) return false;
		if(x+s.getSpaces() > WIDTH) return false;
		for(int v=0; v< s.getSpaces();v++){
			b.operator[](x).operator[](y+v)= (int)s.getChr();
		}
		


		return true;

	}
	if(d==VERTICAL){
		std::cout<<"Attempting vertical placement"<<std::endl;
		for(int v=0; v < s.getSpaces();v++){
			if(b.operator[](x+v).operator[](y) == 66 ||
				b.operator[](x+v).operator[](y) == 67 ||
				b.operator[](x+v).operator[](y) == 68 ||
				b.operator[](x+v).operator[](y) == 80 ||
				b.operator[](x+v).operator[](y) == 83 )

				return false;
		}
		if(y== HEIGHT -1) return false;
		if(y+s.getSpaces() > HEIGHT) return false;
		for(int v=0; v <s.getSpaces();v++){
			b.operator[](x+v).operator[](y) = (int)s.getChr();
		}

		



		return true;
	}
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
