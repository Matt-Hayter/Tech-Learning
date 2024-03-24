// Function definitions for all board pieces, including tiles and chess pieces

#include "board_pieces.h" // Include contents of self constructed header files
#include "general_functions.h"

// Function definitions for abstract chess piece class

std::string chess_piece::get_symbol()
{
    return piece_symbol;
}
bool chess_piece::is_chess_piece() const
{
    return true;
}
std::string chess_piece::get_ownership() const
{
    return ownership;
}
std::string chess_piece::get_name() const
{
    return name;
}
std::vector<std::pair<int, int>> chess_piece::get_legal_moves()
{
    return valid_move_coordinates_vector;
}
void chess_piece::increase_individual_move_count()
{
    individual_move_count ++;
}
void chess_piece::set_symbol(std::string const symbol)
{
    piece_symbol = symbol;
}

// Function definitions for derived tile class

std::string tile::get_symbol()
{
    return tile_symbol;
}
bool tile::is_chess_piece() const
{
    return false;
}
std::string tile::get_ownership() const
{
    return ownership;
}
std::string tile::get_name() const
{
    return name;
}
int tile::get_player_one_move_count()
{
    return player_one_total_move_count; 
}
int tile::get_player_two_move_count()
{
    return player_two_total_move_count; 
}
std::vector<std::pair<int, int>> tile::get_legal_moves()
{
    return valid_move_coordinates_vector;
}
void tile::set_symbol(std::string const symbol)
{
    tile_symbol = symbol;
}

// Function definitions for derived pawn class

int pawn::player_one_total_move_count{}; // Initialise static member data
int pawn::player_two_total_move_count{};

void pawn::increase_player_one_move_count()
{
    player_one_total_move_count ++; 
}
void pawn::increase_player_two_move_count()
{
    player_two_total_move_count ++; 
}
int pawn::get_player_one_move_count()
{
    return player_one_total_move_count; 
}
int pawn::get_player_two_move_count()
{
    return player_two_total_move_count;
}
// Finds all legal pawn moves, given a current position
void pawn::calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &piece_storage,
    std::pair<int, int> const vector_coordinate, std::string const turn)
{
    valid_move_coordinates_vector = {};
    // If pawns first move, check if it can move forward two spaces
    if(individual_move_count == 0) {
        if(vector_coordinate.first > 5) {  // First level "if" statement ensures coordinate is on the board
        } else if(piece_storage[vector_coordinate.first + 2][vector_coordinate.second]->is_chess_piece() == true) {
        } else {
            valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 2, vector_coordinate.second));
        }
    }
    // Checks if pawn can move forward one place
    if(vector_coordinate.first > 6) {  // First level "if" statement ensures coordinate is on the board
    } else if(piece_storage[vector_coordinate.first + 1][vector_coordinate.second]->is_chess_piece() == true) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second));
    }
    // Checks if pawn can take an opposition's piece to the front left
    if(vector_coordinate.first > 6 || vector_coordinate.second < 1) {
    } else if(piece_storage[vector_coordinate.first + 1][vector_coordinate.second - 1]->get_ownership() == turn) {
    } else if(piece_storage[vector_coordinate.first + 1][vector_coordinate.second - 1]->is_chess_piece() == true) {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second - 1));
    }  
    // Checks if pawn can take an opposition's piece to the front right
    if(vector_coordinate.first > 6 || vector_coordinate.second > 6) {
    } else if(piece_storage[vector_coordinate.first + 1][vector_coordinate.second + 1]->get_ownership() == turn) {
    } else if(piece_storage[vector_coordinate.first + 1][vector_coordinate.second + 1]->is_chess_piece() == true) {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second + 1));
    }  
}

// Function definitions for derived rook class

int rook::player_one_total_move_count{}; // Initialise static member data
int rook::player_two_total_move_count{};

void rook::increase_player_one_move_count()
{
    player_one_total_move_count ++; 
}
void rook::increase_player_two_move_count()
{
    player_two_total_move_count ++; 
}
int rook::get_player_one_move_count()
{
    return player_one_total_move_count; 
}
int rook::get_player_two_move_count()
{
    return player_two_total_move_count;
}
// Finds all legal rook moves, given a current position
void rook::calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &piece_storage, std::pair<int,int> const
    vector_coordinate, std::string const turn)
{
    valid_move_coordinates_vector = {};
    std::vector<std::pair<int, int>> new_valid_moves_vector;
    // Finds valid moves in a given direction
    valid_move_coordinates_vector = fill_forward_moves_loop(piece_storage, vector_coordinate, turn);
    // Fills temporary vector
    new_valid_moves_vector = fill_backward_moves_loop(piece_storage, vector_coordinate, turn);
    // Appends temporary vector to member vector
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    // Repeats for other moves
    new_valid_moves_vector = fill_left_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    new_valid_moves_vector = fill_right_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
}

// Function definitions for derived knight class

int knight::player_one_total_move_count{}; // Initialise static member data
int knight::player_two_total_move_count{};

void knight::increase_player_one_move_count()
{
    player_one_total_move_count ++; 
}
void knight::increase_player_two_move_count()
{
    player_two_total_move_count ++; 
}
int knight::get_player_one_move_count()
{
    return player_one_total_move_count; 
}
int knight::get_player_two_move_count()
{
    return player_two_total_move_count;
}
// Finds all legal knight moves, given a current position
void knight::calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &piece_storage,
    std::pair<int, int> const vector_coordinate, std::string const turn)
{
    valid_move_coordinates_vector = {};
    // First level "if" statement ensures coordinate is on the board
    if(vector_coordinate.first > 5 || vector_coordinate.second > 6) {
    } else if(piece_storage[vector_coordinate.first + 2][vector_coordinate.second + 1]->get_ownership() == turn) {
    } else {
        // Creates pair of coordinates of possible move if it is valid and adds it to member data
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 2, vector_coordinate.second + 1));
    }
    // Repeat process for all potential moves
    if(vector_coordinate.first > 6 || vector_coordinate.second > 5) {
    } else if(piece_storage[vector_coordinate.first + 1][vector_coordinate.second + 2]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second + 2)); 
    }
    if(vector_coordinate.first < 1 || vector_coordinate.second > 5) {
    } else if(piece_storage[vector_coordinate.first - 1][vector_coordinate.second + 2]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first - 1, vector_coordinate.second + 2)); 
    }
    if(vector_coordinate.first < 2 || vector_coordinate.second > 6) {
    } else if(piece_storage[vector_coordinate.first - 2][vector_coordinate.second + 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first - 2, vector_coordinate.second + 1));
    }
    if(vector_coordinate.first < 2 || vector_coordinate.second < 1) {
    } else if(piece_storage[vector_coordinate.first - 2][vector_coordinate.second - 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first - 2, vector_coordinate.second - 1)); 
    }
    if(vector_coordinate.first < 1 || vector_coordinate.second < 2) {
    } else if(piece_storage[vector_coordinate.first - 1][vector_coordinate.second - 2]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first - 1, vector_coordinate.second - 2));
    }
    if(vector_coordinate.first > 6 || vector_coordinate.second < 2) {
    } else if(piece_storage[vector_coordinate.first + 1][vector_coordinate.second - 2]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second - 2));
    }
    if(vector_coordinate.first > 5 || vector_coordinate.second < 1) {
    } else if(piece_storage[vector_coordinate.first + 2][vector_coordinate.second - 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 2, vector_coordinate.second - 1)); 
    }
}

// Function definitions for derived bishop class

int bishop::player_one_total_move_count{}; // Initialise static member data
int bishop::player_two_total_move_count{};

void bishop::increase_player_one_move_count()
{
    player_one_total_move_count ++; 
}
void bishop::increase_player_two_move_count()
{
    player_two_total_move_count ++; 
}
int bishop::get_player_one_move_count()
{
    return player_one_total_move_count; 
}
int bishop::get_player_two_move_count()
{
    return player_two_total_move_count;
}
// Finds all legal bishop moves, given a current position
void bishop::calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &piece_storage,
    std::pair<int, int> const vector_coordinate, std::string const turn)
{
    valid_move_coordinates_vector = {};
    std::vector<std::pair<int, int>> new_valid_moves_vector;
    // Finds valid moves in a given direction
    valid_move_coordinates_vector = fill_forward_right_moves_loop(piece_storage, vector_coordinate, turn);
    // Fills temporary vector
    new_valid_moves_vector = fill_backward_right_moves_loop(piece_storage, vector_coordinate, turn);
    // Appends temporary vector to member vector
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    // Repeats for other moves
    new_valid_moves_vector = fill_backward_left_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    new_valid_moves_vector = fill_forward_left_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
}

// Function definitions for derived queen class

int queen::player_one_total_move_count{}; // Initialise static member data
int queen::player_two_total_move_count{};

void queen::increase_player_one_move_count()
{
    player_one_total_move_count ++; 
}
void queen::increase_player_two_move_count()
{
    player_two_total_move_count ++; 
}
int queen::get_player_one_move_count()
{
    return player_one_total_move_count; 
}
int queen::get_player_two_move_count()
{
    return player_two_total_move_count;
}
// Finds all legal queen moves, given a current position
void queen::calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &piece_storage,
    std::pair<int, int> const vector_coordinate, std::string const turn)
{
    valid_move_coordinates_vector = {};
    std::vector<std::pair<int, int>> new_valid_moves_vector;
    // Finds valid moves in a given direction
    valid_move_coordinates_vector = fill_forward_right_moves_loop(piece_storage, vector_coordinate, turn);
    // Fills temporary vector
    new_valid_moves_vector = fill_backward_right_moves_loop(piece_storage, vector_coordinate, turn);
    // Appends temporary vector to member vector
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    // Repeats for other moves
    new_valid_moves_vector = fill_backward_left_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    new_valid_moves_vector = fill_forward_left_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    new_valid_moves_vector = fill_forward_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    new_valid_moves_vector = fill_backward_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    new_valid_moves_vector = fill_left_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
    new_valid_moves_vector = fill_right_moves_loop(piece_storage, vector_coordinate, turn);
    valid_move_coordinates_vector.insert(valid_move_coordinates_vector.end(), new_valid_moves_vector.begin(),
        new_valid_moves_vector.end());
}

// Function definitions for derived king class

void king::increase_player_one_move_count()
{
    player_one_total_move_count ++; 
}
void king::increase_player_two_move_count()
{
    player_two_total_move_count ++; 
}
int king::get_player_one_move_count()
{
    return player_one_total_move_count; 
}
int king::get_player_two_move_count()
{
    return player_two_total_move_count;
}
// Finds all legal king moves, given a current position
void king::calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &piece_storage,
    std::pair<int, int> const vector_coordinate, std::string const turn)
{
    valid_move_coordinates_vector = {};
    // Checks if king can move forward one place
    if(vector_coordinate.first > 6 || piece_storage[vector_coordinate.first + 1][vector_coordinate.second] ->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second));
    }
    // Checks if king can move forward right one place
    if(vector_coordinate.first > 6 || vector_coordinate.second > 6 || piece_storage[vector_coordinate.first + 1]
        [vector_coordinate.second + 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second + 1));
    }
    // Checks if king can move right one place
    if(vector_coordinate.second > 6 || piece_storage[vector_coordinate.first][vector_coordinate.second + 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first, vector_coordinate.second + 1));
    }
    // Checks if king can move back right one place
    if(vector_coordinate.first < 1 || vector_coordinate.second > 6 || piece_storage[vector_coordinate.first - 1]
        [vector_coordinate.second + 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first - 1, vector_coordinate.second + 1));
    }
    // Checks if king can move back one place
    if(vector_coordinate.first < 1 || piece_storage[vector_coordinate.first - 1][vector_coordinate.second]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first - 1, vector_coordinate.second));
    }
    // Checks if king can move back left one place
    if(vector_coordinate.first < 1 || vector_coordinate.second < 1 || piece_storage[vector_coordinate.first - 1]
        [vector_coordinate.second - 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first - 1, vector_coordinate.second - 1));
    }
    // Checks if king can move left one place
    if(vector_coordinate.second < 1 || piece_storage[vector_coordinate.first][vector_coordinate.second - 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first, vector_coordinate.second - 1));
    }
    // Checks if king can move forward left one place
    if(vector_coordinate.first > 6 || vector_coordinate.second < 1 || piece_storage[vector_coordinate.first + 1]
        [vector_coordinate.second - 1]->get_ownership() == turn) {
    } else {
        valid_move_coordinates_vector.push_back(std::make_pair(vector_coordinate.first + 1, vector_coordinate.second - 1));
    }
}