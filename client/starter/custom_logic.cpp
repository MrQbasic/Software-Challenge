#include "logic.h"
#include <stdio.h>
#include "weights.h"

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

        Game::Board board = gameState.get_board();

        //calc score and get best
        float best_score = 0.0f;
        Game::Move best_move;
        for(Game::Move move : possibleMoves){
            float current_score = 0.0f;
            //extract infomations
            Game::Coordinate destination = move.destination;
            //fish calc
            int amount_of_fish = (int) board.get_field(destination);
            current_score += FISH_FACTOR * (float) amount_of_fish;
            //cutof calc
            
            //...

            //check if the current score is better the the best -> overwrite it
            if(current_score > best_score){
                best_score = current_score;
                best_move = move;
            }
        }

        return best_move;
    }
};