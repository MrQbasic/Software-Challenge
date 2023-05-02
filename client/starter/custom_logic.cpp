#include "logic.h"
#include <stdio.h>

/**
 * @brief A subclass of a game logic.
 *        Here you can implement your own logic, which will pick the moves in the game.
 * 
 */
class RandomLogic : public Logic::Logic
{
private:
public:
    
    /**
     * @brief This method will be called once the server requests a move.
     * 
     * @param gameState The current state of the game. 
     * @return Game::Move 
     */
    Game::Move get_move(Game::GameState& gameState) {
        // Get all moves that are currently possible.
        std::vector<Game::Move> possibleMoves = gameState.get_possible_moves();

        if (possibleMoves.size() == 0) {
            std::cout << "ERROR: NO MOVES FOUND!" << std::endl;
            throw;
        }

        int best_score = 0;
        int best_index;

        Game::Board board = gameState.get_board();

        for(int i=0; i<possibleMoves.size(); i++){
            Game::Move current_move = possibleMoves[i];
            char field_val = board.get_field(current_move.destination);

            if(field_val > best_score){
                best_score = field_val;
                best_index = i;
            }

        }
        return possibleMoves[best_index];
    }
};