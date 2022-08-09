#pragma once

#include "coordinates.h"
#include "move.h"

#include <vector>

#define BOARD_SIZE_X 8
#define BOARD_SIZE_Y 8

#define EMPTY 0
#define ONE_FISH 1 
#define TWO_FISHES 2 
#define THREE_FISHES 3 
#define PLAYER_ONE 4
#define PLAYER_TWO 5

namespace Game {
	using namespace Coordinates;
	class Board {
	private:
		/**
		 * @brief Checks if a given Double Hex Coordinate is a valid field.
		 * 		  Has to be in bounds and on a non-empty field.
		 * 
		 * @param c 
		 * @return true 
		 * @return false 
		 */
		bool isValidField(Coordinate c); 

		/**
		 * @brief Get the Moves from a position in a given direction.
		 * 
		 * @param start The starting position.
		 * @param dir The direction.
		 * @param moves Vector in which the moves will be stored.
		 */
		void getMovesInDirection(Coordinate &start, Coordinate dir, std::vector<Move>& moves);
	public:
		Board();

		Board(const Board& other);

		/**
		 * @brief The game board as a X * Y char array.
		 * 
		 */
		char board[BOARD_SIZE_X][BOARD_SIZE_Y];

		/**
		 * @brief Gets the field from the board at the position of c.
		 * 
		 * @param c Coordinates of the field.
		 * @return Value of the field as a char.
		 */
		char getField(Coordinates::Coordinate c);

		/**
		 * @brief Sets a field on the board to a new value.
		 * 
		 * @param c The coordinate of the field.
		 * @param field The new value.
		 */
		void setField(Coordinates::Coordinate c, char field);

		/**
		 * @brief Get the Possible Moves From a specific field.
		 * 
		 * @param c The starting position.
		 * @param moves A vector of moves that will be used as storage.
		 */
		void getPossibleMovesFrom(Coordinate c, std::vector<Move>& moves);

		/**
		 * @brief Get the fields fith a single fish on them.
		 * 
		 * @param moves Set-Moves that land on fields with single fish on them.
		 */
		void getFieldsWithSingleFish(std::vector<Move>& moves);

		/**
		 * @brief Get the positions of the penguins of the given team
		 * 
		 * @param team Team that the penguins belong to.
		 * @return std::vector<Coordinate> Coordinates of the penguins. 
		 */
		std::vector<Coordinate> getPenguinPositions(bool team);
	};
}