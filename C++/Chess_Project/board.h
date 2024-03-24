#ifndef BOARD_H // Header guard (pre-processor directive)
#define BOARD_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>
#include <list>

// Initialise mapping of board coordinate (char, int) to vector locations (int, int)
typedef std::map<std::pair<char, int>, 
    std::pair<int, int>> board_to_vector_mapping;

// Board class that contains all pieces - class definition
// Holds various member functions that perform operations on these pieces
class board
{
    friend std::ostream &operator << (std::ostream &, board  const &);
    friend std::istream &operator >> (std::istream &, board &);
    private:
        // Board has_a vector of vectors containing unique, smart base class pointers to a board piece
        std::vector<std::vector<std::unique_ptr<board_piece>>> board_piece_storage{8};
        std::unique_ptr<std::string> from_or_to; // Temporary data goverened by unique pointer
        std::string turn;
        board_to_vector_mapping coordinate_map;
        // Following two pairs will be redefined throughout players turn
        std::pair<int, char> requested_board_coordinate;
        std::pair<int, int> vector_board_coordinate;
        // Pair holds both from and to coordinates once they are validated
        std::pair<std::pair<int, int>, std::pair<int, int>> vector_coordinate_from_to;
        // Holds total moves played to be printed after each turn
        std::vector<int> player_one_piece_moves_vector;
        std::vector<int> player_two_piece_moves_vector;
        bool check_mate;
        bool use_move_assistant;
        bool skip_user_input;
        bool player_in_check;
        bool print_moving_from;
    public: 
        board() : turn{"Player One"}, requested_board_coordinate(std::make_pair(0, '0')),
            vector_board_coordinate(std::make_pair(0, '0')), vector_coordinate_from_to(std::make_pair(std::make_pair(0, '0'),
            std::make_pair(0, '0'))), check_mate{false}, use_move_assistant{true}, skip_user_input{false},
            player_one_piece_moves_vector(6, 0), player_two_piece_moves_vector(6, 0), player_in_check{false} {}
        ~board() {}
        // Prevents a copy assignment operator from attempting to copy a unique base class pointer
        board(const board& a) = delete;
        board& operator=(const board& a) = delete;
        void initialise_board();
        void print_chess_and_moves();
        void move_assistant_initial_input();
        void create_map();
        void run_intro();
        void process_coordinate(const std::string);
        void find_coordinates_and_validate(char const, char const);
        bool check_ownership_and_type();
        bool check_legal_moves();
        void run_move_assistant();
        void reset_move_assistant();
        void move_assistant_set_piece_symbol(const std::array<std::string, 6>, const std::array<std::string, 6>);
        void move_assistant_set_neighbours_symbols(const std::string, const std::array<std::string, 6>, const std::array<std::string, 6>);
        void move_piece();
        void check_and_check_mate_test();
        void promote_pawn(const int, const int);
        void flip_board();
        void toggle_move_assistant(std::istream &, const char);
        void change_turn();
        std::string get_turn();
        bool get_check_mate();
        // Reads in user inputs and ensures they are coordinates on the chess board
        void enter_coordinate(const std::string);
        // Basic re-enter statement for conciseness
};

#endif