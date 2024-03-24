// Definition of functions used to fill allowed moves

#include "board_pieces.h" // Include contents of self constructed header files
#include "general_functions.h"
#include "board.h"

// Fills moves in the forwards direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_forward_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    for(int i{1}; i <= (7 - vector_coordinate.first); i ++) {   // Loop also ensures coordinate being accessed is on the board
        if(piece_storage[vector_coordinate.first + i][vector_coordinate.second]->get_ownership() == turn) {
            break; // Stops foor loop if piece player owns is encountered
        } else if(piece_storage[vector_coordinate.first + i][vector_coordinate.second]->is_chess_piece() == true) {
            // Can move to oppositions piece coordinate and take it, so add to valid moves vector
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first + i, vector_coordinate.second));
            break; // Stops foor loop if oppositions owns is encountered
        } else {
            // If object is not a chess piece an is on the board, your piece can move to that coordinate
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first + i, vector_coordinate.second));
        }
    }
    return valid_moves_vector_temp;
}
// Fills moves in the backwards direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_backward_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    for(int i{1}; i <= vector_coordinate.first; i ++) {
        if(piece_storage[vector_coordinate.first - i][vector_coordinate.second]->get_ownership() == turn) {
            break;
        } else if(piece_storage[vector_coordinate.first - i][vector_coordinate.second]->is_chess_piece() == true) {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first - i, vector_coordinate.second));
            break;
        } else {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first - i, vector_coordinate.second));
        }
    }
    return valid_moves_vector_temp;
}
// Fills moves in the left hand direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_left_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    for(int i{1}; i <= vector_coordinate.second; i ++) {
        if(piece_storage[vector_coordinate.first][vector_coordinate.second - i]->get_ownership() == turn) {
            break; 
        } else if(piece_storage[vector_coordinate.first][vector_coordinate.second - i]->is_chess_piece() == true) {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first, vector_coordinate.second - i));
            break;
        } else {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first, vector_coordinate.second - i));
        }
    }
    return valid_moves_vector_temp;
}
// Fills moves in the right hand direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_right_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    for(int i{1}; i <= (7 - vector_coordinate.second); i ++) {
        if(piece_storage[vector_coordinate.first][vector_coordinate.second + i]->get_ownership() == turn) {
            break; 
        } else if(piece_storage[vector_coordinate.first][vector_coordinate.second + i]->is_chess_piece() == true) {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first, vector_coordinate.second + i));
            break;
        } else {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first, vector_coordinate.second + i));
        }
    }
    return valid_moves_vector_temp;
}
// Fills moves in the forward right hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_forward_right_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    // Turnary operator to return the smaller distance to the edges of the board
    int number_of_loops = ((7 - vector_coordinate.first) < (7 - vector_coordinate.second)) ?
        (7 - vector_coordinate.first):(7 - vector_coordinate.second);
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    // Find board pieces in the coordinates between the current piece and furtherst potential move (on the board)
    for(int i{1}; i <= number_of_loops; i ++) { // Loop also ensures coordinate being accessed is on the board
        if(piece_storage[vector_coordinate.first + i][vector_coordinate.second + i]->get_ownership() == turn) {
            break; // Stops foor loop if piece player owns is encountered
        } else if(piece_storage[vector_coordinate.first + i][vector_coordinate.second + i]->is_chess_piece() == true) {
            // Can move to oppositions piece coordinate and take it, so add to valid moves vector
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first + i, vector_coordinate.second + i));
            break; // Stops foor loop if oppositions owns is encountered
        } else {
            // If object is not a chess piece an is on the board, your piece can move to that coordinate
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first + i, vector_coordinate.second + i));
        }
    }
    return valid_moves_vector_temp;
}
// Fills moves in the backward right hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_backward_right_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    // Turnary operator to return the smaller distance to the edges of the board
    int number_of_loops = ((vector_coordinate.first) < (7 - vector_coordinate.second)) ?
        (vector_coordinate.first):(7 - vector_coordinate.second);
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    // Find board pieces in the coordinates between the current piece and furtherst potential move (on the board)
    for(int i{1}; i <= number_of_loops; i ++) {
        if(piece_storage[vector_coordinate.first - i][vector_coordinate.second + i]->get_ownership() == turn) {
            break;
        } else if(piece_storage[vector_coordinate.first - i][vector_coordinate.second + i]->is_chess_piece() == true) {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first - i, vector_coordinate.second + i));
            break;
        } else {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first - i, vector_coordinate.second + i));
        }
    }
    return valid_moves_vector_temp;
}
// Fills moves in the backward left hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_backward_left_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    // Turnary operator to return the smaller distance to the edges of the board
    int number_of_loops = ((vector_coordinate.first) < (vector_coordinate.second)) ?
        (vector_coordinate.first):(vector_coordinate.second);
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    // Find board pieces in the coordinates between the current piece and furtherst potential move (on the board)
    for(int i{1}; i <= number_of_loops; i ++) {
        if(piece_storage[vector_coordinate.first - i][vector_coordinate.second - i]->get_ownership() == turn) {
            break;
        } else if(piece_storage[vector_coordinate.first - i][vector_coordinate.second - i]->is_chess_piece() == true) {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first - i, vector_coordinate.second - i));
            break;
        } else {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first - i, vector_coordinate.second - i));
        }
    }
    return valid_moves_vector_temp;
}
// Fills moves in the forward left hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_forward_left_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &piece_storage,
    const std::pair<int, int> vector_coordinate, const std::string turn)
{
    // Turnary operator to return the smaller distance to the edges of the board
    int number_of_loops = ((7 - vector_coordinate.first) < (vector_coordinate.second)) ?
        (7 - vector_coordinate.first):(vector_coordinate.second);
    std::vector<std::pair<int, int>> valid_moves_vector_temp{};
    // Find board pieces in the coordinates between the current piece and furtherst potential move (on the board)
    for(int i{1}; i <= number_of_loops; i ++) {
        if(piece_storage[vector_coordinate.first + i][vector_coordinate.second - i]->get_ownership() == turn) {
            break;
        } else if(piece_storage[vector_coordinate.first + i][vector_coordinate.second - i]->is_chess_piece() == true) {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first + i, vector_coordinate.second - i));
            break;
        } else {
            valid_moves_vector_temp.push_back(std::make_pair(vector_coordinate.first + i, vector_coordinate.second - i));
        }
    }
    return valid_moves_vector_temp;
}
// Checks if all moves from user inputted "from" coordinate would land piece in an illegal location
bool legal_move_from(const std::vector<std::pair<int, int>> valid_moves, const std::string name)
{
    if(valid_moves.size() == 0) {
        std::cout << '\n';
        std::cout << "* Invalid coordiate: You can't move your " << name << " from that position!" << std::endl;
        std::cin.setstate(std::ios_base::failbit);
        return false;
    } else {
        return true;
    }
}
// Checks is particular move from user inputted "to" coordinate would land piece in an illegal location
bool legal_move_to(const std::pair<int, int> vector_coordinate, const std::vector<std::pair<int, int>> valid_moves, const std::string name)
{
    bool valid_to_coordinate{false};
    for(auto i : valid_moves) {
        if(vector_coordinate == i) {
            valid_to_coordinate = true;
        }
    }
    if(valid_to_coordinate == true) {
        return true;
    } else {
        std::cout << '\n';
        std::cout << "* Invalid coordiate: You can't move your "<< name << " to that position!" << std::endl;
        std::cin.setstate(std::ios_base::failbit);
        return false;
    }
}
// Outputs the total number of moves by piece and owner
void output_current_moves(const std::vector<int> piece_moves_one, const std::vector<int> piece_moves_two)
{
    std::array<std::string, 6> piece_names{"Pawn", "Rook", "Knight", "Bishop", "Queen", "King"};
    std::cout << "Total piece moves:" << std::endl;
    std::cout << "Player One " << std::endl;
    for(int i{}; i < 6; i ++) {
        std::cout << piece_names[i] << ": " << piece_moves_one[i];
        if(i != 5) {
            std::cout << ", ";
        }
    }
    std::cout << '\n';
    std::cout << "Player Two " << std::endl;
    for(int i{}; i < 6; i ++) {
        std::cout << piece_names[i] << ": " << piece_moves_two[i];
        if(i != 5) {
            std::cout << ", ";
        }
    }
}
// Basic re-enter statement for conciseness
void statement_and_clear()
{
    std::cout << '\n';
    std::cout << "* Please re-enter" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}