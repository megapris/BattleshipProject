#ifndef			__HPP_BOARD__
#define			__HPP_BOARD__

#include "BoardValues.hpp"
#include <iostream>
#include <algorithm>

#define HEIGHT 10
#define WIDTH 10

class Board {

	public:
		Board();
		Board(const Board &other);
		Board& operator=(Board& other);
		int count() const;
		bool operator< (const Board& other);
		~Board();
		void setVisible(bool v);

		class Internal {
			public:
			Internal(int* _g) {
				_grid = _g;
			}
			int& operator[](int index);

			private:
				int* _grid;
		};
		Internal operator[](int index);

	private:
		int* grid;
		bool visible;
		int* grido = new int[100];

	
	friend std::ostream& operator<<(std::ostream& os, Board & b);

};


#endif
