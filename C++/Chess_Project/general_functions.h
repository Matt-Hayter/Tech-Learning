#ifndef GENERAL_FUNCTIONS_H // Header guard (pre-processor directive)
#define GENERAL_FUNCTIONS_H

#include <iostream> // Include system files
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>

// Initialisation of functions used to fill allowed moves

// Fills moves in the forwards direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_forward_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Fills moves in the backwards direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_backward_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Fills moves in the left hand direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_left_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Fills moves in the right hand direction when called for the rook and queen, using a loop
std::vector<std::pair<int, int>> fill_right_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Fills moves in the forward right hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_forward_right_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Fills moves in the backward right hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_backward_right_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Fills moves in the backward left hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_backward_left_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Fills moves in the forward left hand diagonal direction when called for the bishop and queen, using a loop
std::vector<std::pair<int, int>> fill_forward_left_moves_loop(const std::vector<std::vector<std::unique_ptr<board_piece>>> &,
    const std::pair<int, int>, const std::string);
// Checks if all moves from user inputted "from" coordinate would land piece in an illegal location
bool legal_move_from(const std::vector<std::pair<int, int>>, const std::string);
// Checks is particular move from user inputted "to" coordinate would land piece in an illegal location
bool legal_move_to(const std::pair<int, int>, const std::vector<std::pair<int, int>>, const std::string);
// Outputs the total number of moves by piece and owner
void output_current_moves(const std::vector<int>, const std::vector<int>);
// Basic re-enter statement for conciseness
void statement_and_clear();

#endif