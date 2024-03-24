// Board class that contains all pieces - function definitions

#include "board_pieces.h" // Include contents of self constructed header files
#include "general_functions.h"
#include "board.h"

void board::change_turn()
{
    if(turn == "Player One") {
        turn = "Player Two";
    } else if(turn == "Player Two") {
        turn = "Player One";
    }
} 
std::string board::get_turn()
{
    return turn;
}
bool board::get_check_mate()
{
    return check_mate;
}
// Creates the board and fills it with pieces in their initial positions
void board::initialise_board()
{
    // Creates new chess piece and wraps it in a unique, base class pointer to a board piece
    std::unique_ptr<board_piece> board_element{std::make_unique<rook>("Rook", " ♜  ", "Player One")};
    // Transferring ownership of rook to another unique base class pointer in board vector
    board_piece_storage[0].push_back(std::move(board_element));
    // Repeat for all board pieces and tiles
    board_element = std::make_unique<knight>("Knight", " ♞  ", "Player One");
    board_piece_storage[0].push_back(std::move(board_element));
    board_element = std::make_unique<bishop>("Bishop", " ♝  ", "Player One");
    board_piece_storage[0].push_back(std::move(board_element));
    board_element = std::make_unique<queen>("Queen", " ♛  ", "Player One");
    board_piece_storage[0].push_back(std::move(board_element));
    board_element = std::make_unique<king>("King", " ♚  ", "Player One");
    board_piece_storage[0].push_back(std::move(board_element));
    board_element = std::make_unique<bishop>("Bishop", " ♝  ", "Player One");
    board_piece_storage[0].push_back(std::move(board_element));
    board_element = std::make_unique<knight>("Knight", " ♞  ", "Player One");
    board_piece_storage[0].push_back(std::move(board_element));
    board_element = std::make_unique<rook>("Rook", " ♜  ", "Player One");
    board_piece_storage[0].push_back(std::move(board_element));
    for(int i{0}; i < 8; i++) {
        board_element = std::make_unique<pawn>("Pawn", " ♟︎  ", "Player One");
        board_piece_storage[1].push_back(std::move(board_element));
    }
    int tile_type_tracker{-1};
    // Loop fills central 32 board elements with alternating white and black tiles
    for(int i{2}; i < 6; i++) {
        for(int j{}; j < 8; j++) {
            if(tile_type_tracker > 0) {
                board_element = std::make_unique<white_tile>("White tile", " \u25FC  ");
                board_piece_storage[i].push_back(std::move(board_element));
            } else {
                board_element = std::make_unique<black_tile>("Black tile", " \u25FB  ");
                board_piece_storage[i].push_back(std::move(board_element));
            }
            tile_type_tracker *= -1;
        }
        tile_type_tracker *= -1;
    }
    for(int i{0}; i < 8; i++) {
        board_element = std::make_unique<pawn>("Pawn", " ♙  ", "Player Two");
        board_piece_storage[6].push_back(std::move(board_element));
    }
    board_element = std::make_unique<rook>("Rook", " ♖  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
    board_element = std::make_unique<knight>("Knight", " ♘  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
    board_element = std::make_unique<bishop>("Bishop", " ♗  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
    board_element = std::make_unique<queen>("Queen", " ♕  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
    board_element = std::make_unique<king>("King", " ♔  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
    board_element = std::make_unique<bishop>("Bishop", " ♗  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
    board_element = std::make_unique<knight>("Knight", " ♘  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
    board_element = std::make_unique<rook>("Rook", " ♖  ", "Player Two");
    board_piece_storage[7].push_back(std::move(board_element));
}
// Output separates player turns as well as printing total piece moves
void board::print_chess_and_moves()
{
    std::cout << "______________________________________________________________________________________" << "___" << std::endl;
    std::cout << "Enter y/n at any stage to toggle move assist on/off" << std::endl;
    std::cout << '\n';
    // Outputs the total number of moves played by each piece
    output_current_moves(player_one_piece_moves_vector, player_two_piece_moves_vector);
    std::cout << '\n' << '\n';
    std::cout << "   ██████╗██╗  ██╗███████╗███████╗███████╗" << std::endl;
    std::cout << "  ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝" << std::endl;
    std::cout << "  ██║     ███████║█████╗  ███████╗███████╗" << std::endl;
    std::cout << "  ██║     ██╔══██║██╔══╝  ╚════██║╚════██║" << std::endl;
    std::cout << "  ╚██████╗██║  ██║███████╗███████║███████║" << std::endl;
    std::cout << "   ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" << std::endl;
}
// Outputs the chess board and pieces in their current configuration
std::ostream &operator << (std::ostream &output_stream, board  const &current_board)
{  
    std::array<char, 8> allowed_rows = {'1', '2', '3', '4', '5', '6', '7', '8'};
    // Outputs an "in check" statement is the current player is in check and the game has not ended
    if(current_board.player_in_check == true && current_board.check_mate != true) {
        output_stream << '\n';
        std::cout << "You are in check!" << std::endl;
    }
    // Outputs chess board
    output_stream << '\n';
    output_stream << "      A   B   C   D   E   F   G   H" << std::endl;
    output_stream << '\n';
    // Outputs each element of the board, with the correpsonding pieces/tiles
    for(int i{8}; i >= 1; i --) {
        output_stream << "  " << i << "  ";
        // Iterates through each element of board to be printed
        for(int j{}; j < 8; j ++) {
            output_stream << current_board.board_piece_storage[i - 1][j]->get_symbol();
        }
        output_stream << "  " << i;
        output_stream << '\n';
    }
    output_stream << '\n';
    output_stream << "      A   B   C   D   E   F   G   H" << std::endl;
    return output_stream;
}
// Ensures the user is moving one of their own pieces
bool board::check_ownership_and_type()
{
    if(board_piece_storage[vector_board_coordinate.first][vector_board_coordinate.second]->is_chess_piece() != true
        || board_piece_storage[vector_board_coordinate.first][vector_board_coordinate.second]->get_ownership() != turn) {
        std::cout << '\n';
        std::cout << "* The board coordinate selected does not contain one of your chess pieces" << std::endl;
        std::cin.setstate(std::ios_base::failbit); // Fail the input stream as user input in invalid
        return false;
    } else {
        return true;
    }
}
// The hub for user inputted coordinates. Both validation and move calculation functions are called from here
void board::process_coordinate(std::string const from_to)
{
    // Put "process coordinate" code under inspection
    try {
        from_or_to = std::make_unique<std::string>(from_to); // DMA for member data not required throughout lifetime of code
        if(from_to == "from") {
            std::cout << turn << "'s turn" << std::endl;
        }
        bool good_input{false};
        // Performs all validation checks on piece selected to be moved from the first user inputted coordinate
        if(*from_or_to == "from") {
            while(good_input == false) {
                // User input read in and several first stage validation checks made
                enter_coordinate(*from_or_to);
                good_input = check_ownership_and_type();
                if(good_input == false) {
                    // Asks user to re-enter and clears istream
                    statement_and_clear();
                    continue;
                }
                // Finds all legal moves given piece user wants to move
                board_piece_storage[vector_board_coordinate.first][vector_board_coordinate.second]->
                    calculate_legal_moves(board_piece_storage, vector_board_coordinate, turn);
                // Checks if piece can move given current board
                good_input = legal_move_from(board_piece_storage[vector_board_coordinate.first][vector_board_coordinate.second]
                    ->get_legal_moves(), 
                    board_piece_storage[vector_board_coordinate.first][vector_board_coordinate.second]->get_name());
                if(good_input == false) {
                    statement_and_clear();
                }
            }
            vector_coordinate_from_to.first = vector_board_coordinate;
        }
        // Now process "to" coordinate
        good_input = false;
        if(*from_or_to == "to") {
            if(use_move_assistant == true) {
                run_move_assistant();
                std::cout << '\n';
                // Prints "moving from" statement underneath board when appropriate
                std::cout << "Moving " << board_piece_storage[vector_board_coordinate.first][vector_board_coordinate.second]
                    ->get_name() << " from " << requested_board_coordinate.second << requested_board_coordinate.first << std::endl;
            }
            while(good_input == false) {
                enter_coordinate(*from_or_to);
                good_input = legal_move_to(vector_board_coordinate, board_piece_storage[vector_coordinate_from_to.first.first]
                    [vector_coordinate_from_to.first.second]->get_legal_moves(), 
                    board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]->get_name());
                if(good_input == false) {
                    statement_and_clear();
                }
            }
            vector_coordinate_from_to.second = vector_board_coordinate;
        }
    } catch(int error_code) {
        if(error_code == 0) {
            std::cout << "Validation failed: entered coordinate could not be processed" << std::endl;
        }
    }
}
// Validation to inform user of exact input fault whilst transforming user input into a board coordinate pair
void board::find_coordinates_and_validate(char const character_1, char const character_2)
{
    // Initialise pair of board coordinates, that will be defined and returned if user input is valid
    bool character_1_good{false};
    bool character_2_good{false};
    int row_counter{};
    int column_counter{};
    std::array<char, 8> allowed_columns = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // Allowed user entries to test against
    std::array<char, 8> allowed_columns_lower = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    std::array<char, 8> allowed_rows = {'1', '2', '3', '4', '5', '6', '7', '8'};
    // Loops allow for user to enter board elements in a variety of manners
    for(int i{}; i < 8; i ++) { // Checks on the first character
        if(allowed_rows[i] == character_1) {
            requested_board_coordinate.first = character_1 - '0';
            row_counter ++;
            character_1_good = true;
            break;
        } else if(allowed_columns[i] == character_1) {
            requested_board_coordinate.second = character_1;
            column_counter ++;
            character_1_good = true;
            break;
        } else if(allowed_columns_lower[i] == character_1) {
            requested_board_coordinate.second = toupper(character_1); // Converts char to upper case if it is an acceptable input
            column_counter ++;
            character_1_good = true;
            break;
        }
    }
    if(character_1_good == false) {
        std::cout << '\n';
        std::cout << "* Error: first value of board coordinate is invalid" << std::endl;
        std::cin.setstate(std::ios_base::failbit); // Sets input stream to a fail state so user is asked to re-enter coordinate
    }
    for(int i{}; i < 8; i ++) { // Checks on the second character
        if(allowed_columns[i] == character_2) {
            requested_board_coordinate.second = character_2;
            column_counter ++;
            character_2_good = true;
            break;
        } else if(allowed_columns_lower[i] == character_2) {
            requested_board_coordinate.second = toupper(character_2);
            column_counter ++;
            character_2_good = true;
            break;
        } else if(allowed_rows[i] == character_2) {
            requested_board_coordinate.first = character_2 - '0';
            row_counter ++;
            character_2_good = true;
            break;
        }
    } 
    if(character_2_good == false) {
        std::cout << '\n';
        std::cout << "* Error: second value of board coordinate is invalid" << std::endl;
        std::cin.setstate(std::ios_base::failbit);
    }
    if(row_counter > 1) {
        std::cout << '\n';
        std::cout << "* Error: you have entered two rows" << std::endl;
        std::cin.setstate(std::ios_base::failbit);
    } else if(column_counter > 1) {
        std::cout << '\n';
        std::cout << "* Error: you have entered two columns" << std::endl; 
        std::cin.setstate(std::ios_base::failbit);
    }
    // Use cordinate map to set the vector board coordinate to the appropriate value
    vector_board_coordinate.first = coordinate_map.find(requested_board_coordinate)->second.first;
    vector_board_coordinate.second = coordinate_map.find(requested_board_coordinate)->second.second;
}
// Reads in user inputs and ensures they are coordinates on the chess board
void board::enter_coordinate(std::string const from_to)
{
    *from_or_to = from_to;
    while(true) {
        std::cout << '\n';
        std::cout << "- Coordinate of piece to move, " << *from_or_to <<": ";
        // Reads input to an istream which performs basic validation checks
        std::cin >> *this;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << '\n';
            std::cout << "* Please re-enter" << std::endl;
        } else {
            break;
        }
    }
    // Throws exception if board coordinate is not found on map after validation
    if(coordinate_map.find(requested_board_coordinate) == coordinate_map.end()) {
        throw 0;
    }
}
// Takes user input and tests for a request to toggle on/off move assistant, processing input accordingly
void board::toggle_move_assistant(std::istream &i_stream, char const character_1)
{
    // Checks for a y/n input to toggle move assistant on and off
    if((character_1 == 'y' || character_1 == 'Y') && i_stream.peek() == '\n') {
        // Set to false, ensuring that within enter_coordinate recursion, operator >> friend function is not skipped
        skip_user_input = false;
        std::cout << '\n';
        std::cout << "* Move assistant turned on" << std::endl;
        if(*from_or_to == "from") {
            use_move_assistant = true;
            // Ensures coordinate can be re-entered by user
            enter_coordinate("from");
            skip_user_input = true;
        } else {
            // If user has asked for move assistant to be turned on and it already is, don't re-process coordinate.
            if(use_move_assistant == true) {
                enter_coordinate("to");
            } else {
                use_move_assistant = true;
                // If user wishes to change move assistant setting at the "to" stage, coordinate must be re-processed
                process_coordinate("to");
            }
            skip_user_input = true;
        }
    } else if((character_1 == 'n' || character_1 == 'N') && i_stream.peek() == '\n') {
        // Set to false, ensuring that within enter_coordinate recursion, operator >> friend function is not skipped
        skip_user_input = false;
        std::cout << '\n';
        std::cout << "* Move assistant turned off" << std::endl;
        if(*from_or_to == "from") {
            use_move_assistant = false;
            // Ensures coordinate can be re-entered by user
            enter_coordinate("from");
            skip_user_input = true;
        } else {
            // Set board back to standard state (without move assistant)
            reset_move_assistant();
            // Only re-rint board (without move assistant) if move assistant is toggled off from on
            if(use_move_assistant == true) {
                std::cout << *this;
                std::cout << '\n';
                // Prints "moving from" statement underneath board
                std::cout << "Moving " << board_piece_storage[vector_board_coordinate.first][vector_board_coordinate.second]
                    ->get_name() << " from " << requested_board_coordinate.second << requested_board_coordinate.first << std::endl;
            }
            use_move_assistant = false;
            // If user wishes to change move assistant setting at the "to" stage, coordinate must be re-processed
            process_coordinate("to");
            skip_user_input = true;
        }
    }
}
// Takes input and ensures it is either a coordinate on the board or request for move assist
std::istream &operator >> (std::istream &input_stream, board &current_board)
{
    char character_1;
    char character_2;
    std::array<bool, 3> error_statements = {false, false, false};
    // Basic user input validation
    input_stream >> std::skipws >> character_1;
    if(input_stream.fail()) {
        error_statements[0] = true;
        input_stream.setstate(std::ios_base::failbit); // Set istream to a failbit if invalid input is found
    }
    // Checks if input is requesting for move assistant to be turned on/off
    current_board.toggle_move_assistant(input_stream, character_1); 
    // If move assistant has been toggled, the remainder of the function should be skipped
    if(current_board.skip_user_input == true) {
        current_board.skip_user_input = false; // Reset toggle
        return input_stream;
    }
    input_stream >> character_2;
    if(input_stream.fail()) {
        error_statements[1] = true;
        input_stream.setstate(std::ios_base::failbit);
    }
    if(input_stream.peek() != '\n') {
        error_statements[2] = true;
        input_stream.setstate(std::ios_base::failbit);
    }
    // Print correct error statements in an appropriate order
    if(error_statements[2] == true) {
        std::cout << '\n';
        std::cout << "* Error: input must be a two character board coordinate" << std::endl;
    } else {
        if(error_statements[0] == true) {
            std::cout << '\n';
            std::cout << "* Error: first value of board coordinate is invalid" << std::endl;
        }
        if(error_statements[1] == true) {
            std::cout << '\n';
            std::cout << "* Error: second value of board coordinate is invalid" << std::endl;
        } else {
            // If input passes initial checks, it is fed into a further validation function that creates a board coordinate
            current_board.find_coordinates_and_validate(character_1, character_2);
        }
    } 
    return input_stream;
}
// Creates map of board coordinate pairs to vector location pairs
void board::create_map()
{
    std::pair<int, char> board_coordinate;
    std::pair<int, int> vector_coordinate;
    std::array<char, 8> allowed_columns = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for(int i{}; i < 8; i ++) {
        board_coordinate.second = allowed_columns[i];
        vector_coordinate.second = i;
        for(int j{}; j < 8; j ++) {
            board_coordinate.first = j + 1;
            vector_coordinate.first = j;
            // Mapping each board coordinate onto the appropriate vector equivalent
            coordinate_map[board_coordinate] = vector_coordinate;
        }
    }
}
// Flip the board around, so the person who's turn it is can play with a forward facing board
void board::flip_board()
{
    std::reverse(board_piece_storage.begin(), board_piece_storage.end());
    for(auto current_line = board_piece_storage.begin(); current_line < board_piece_storage.end(); current_line ++) {
        std::reverse((*current_line).begin(), (*current_line).end());
    }
}
// Informs user of the move assistant feature, and allows for initial configuration
void board::move_assistant_initial_input()
{
    std::string user_input;
    while(true)
    {
        std::cout << '\n';
        std::cout << "Would you like to play with a move assistant?" << std::endl;
        std::cout << "This can be toggled on/off at any stage whilst playing a game by inputting y/n" << std::endl;
        std::cout << "Enter y/n: ";
        std::cin >> user_input;
        if(user_input == "y" || user_input == "Y" || user_input == "Yes" || user_input == "YES" || user_input == "yes") {
            use_move_assistant = true;
            break;
        } else if(user_input == "n" || user_input == "N" || user_input == "No" || user_input == "NO" || user_input == "no") {
            use_move_assistant = false;
            break;
        } else {
            std::cin.setstate(std::ios_base::failbit);
        }
        if(std::cin.fail()) {
            std::cout << '\n';
            std::cout << "* Invalid input, please enter y/n for a move assistant" << std::endl;;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
// Welcome statements/requests
void board::run_intro()
{
    std::cout << '\n';
    std::cout << "  Welcome to" << std::endl;
    std::cout << "   ██████╗██╗  ██╗███████╗███████╗███████╗" << std::endl;
    std::cout << "  ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝" << std::endl;
    std::cout << "  ██║     ███████║█████╗  ███████╗███████╗" << std::endl;
    std::cout << "  ██║     ██╔══██║██╔══╝  ╚════██║╚════██║" << std::endl;
    std::cout << "  ╚██████╗██║  ██║███████╗███████║███████║" << std::endl;
    std::cout << "   ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" << std::endl;
    std::cout << '\n';
    std::cout << "♚ = Player One's King" << std::endl;
    std::cout << "♔ = Player Two's King" << std::endl;
    move_assistant_initial_input();
}
// Now "from" and "to" coordinates have been processed, piece is moved, move counts are updated, and relavent tiles are added
void board::move_piece()
{
    std::array<std::string, 6> piece_names{"Pawn", "Rook", "Knight", "Bishop", "Queen", "King"};
    // Shifts ownership from of object from old to new coordinate
    board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second] =
    std::move(board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]);
    // Increases move count for singular object by one
    board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second]
        ->increase_individual_move_count();
    if(board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second]
        ->get_ownership() == "Player One") {
        // Increases the move count for piece that has moved
        board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second]
            ->increase_player_one_move_count();
        // Updating the correct element in player one's piece move vector with the corresponding piece's satic move count member data
        for(int i{}; i < 6; i ++) {
            if(piece_names[i] == board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second]
                ->get_name()) {
                player_one_piece_moves_vector[i] = board_piece_storage[vector_coordinate_from_to.second.first]
                    [vector_coordinate_from_to.second.second]->get_player_one_move_count();
            }
        }
    // Repeat above if there has been a player two move
    } else if (board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second]
        ->get_ownership() == "Player Two") {
        board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second]->increase_player_two_move_count();
        for(int i{}; i < 6; i ++) {
            if(piece_names[i] == board_piece_storage[vector_coordinate_from_to.second.first][vector_coordinate_from_to.second.second]
                ->get_name()) {
                player_two_piece_moves_vector[i] = board_piece_storage[vector_coordinate_from_to.second.first]
                [vector_coordinate_from_to.second.second]->get_player_two_move_count();
            }
        }
    }
    // Replaces empty vector space with a tile of an appropriate colour
    if((vector_coordinate_from_to.first.first + vector_coordinate_from_to.first.second) % 2 == 0) {
        board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second] = 
        std::make_unique<black_tile>("Black tile", " \u25FB  ");
    } else {
        board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second] = 
        std::make_unique<white_tile>("White tile", " \u25FC  ");
    }
}
// Promotes pawn to queen if it reaches the end of the table
void board::promote_pawn(int const row, int const column)
{
    if(board_piece_storage[row][column]->get_name() == "Pawn" && row == 7) {
        if(board_piece_storage[row][column]->get_ownership() == "Player One") {
            board_piece_storage[row][column] = std::make_unique<queen>("Queen", " ♛  ", "Player One");
        } else {
            board_piece_storage[row][column] = std::make_unique<queen>("Queen", " ♕  ", "Player Two");
        }
    }
}
// Tests for both check (to output check statement) and check mate to determine the end of the game
void board::check_and_check_mate_test()
{
    player_in_check = false; // Sets check to false to reset a previous "true" definition
    std::pair<int, int> vector_coordinate_temp;
    std::pair<int, int> opponents_king_position;
    // Initialise vector containing all possible new move coordinates (for piece that has just been moved)
    std::vector<std::pair<int, int>> opposition_king_locations;
    // Initialise vector to hold all of players possible next moves
    std::vector<std::pair<int, int>> all_possible_player_moves;
    // Initialise vector to hold players possible next moves for a given piece in loop
    std::vector<std::pair<int, int>> new_possible_player_moves;
    for(int i{}; i < 8; i++) {
        for(int j{}; j < 8; j++) {
            // Checks for oppositions king and finds possible moves
            if(board_piece_storage[i][j]->get_ownership() != turn && board_piece_storage[i][j]->get_name() == "King") {
                // Calculates the allowed moves of the oppoisitons king
                if(turn == "Player One") {
                    board_piece_storage[i][j]->calculate_legal_moves(board_piece_storage, std::make_pair(i, j), "Player Two");
                } else if(turn == "Player Two") {
                    board_piece_storage[i][j]->calculate_legal_moves(board_piece_storage, std::make_pair(i, j), "Player One");
                }
                // Add kings location alongside possible moves to vector
                opposition_king_locations = board_piece_storage[i][j]->get_legal_moves();
                opponents_king_position = std::make_pair(i, j);
                opposition_king_locations.push_back(opponents_king_position);
            }
            // Checks for any of the current players pieces and finds possible moves
            if(board_piece_storage[i][j]->get_ownership() == turn) {
                vector_coordinate_temp.first = i;
                vector_coordinate_temp.second = j;
                board_piece_storage[i][j]->calculate_legal_moves(board_piece_storage, vector_coordinate_temp, turn);
                new_possible_player_moves = board_piece_storage[i][j]->get_legal_moves();
                all_possible_player_moves.insert(all_possible_player_moves.end(), new_possible_player_moves.begin(),
                    new_possible_player_moves.end());
                promote_pawn(i, j); // Checks if pawn has reached the end of the board for promotion
            }
        }
    }
    int king_cant_move_count{};
    // Check if the opponents kings position matches any of current player's possible piece moves
    if(!(std::find(all_possible_player_moves.begin(), all_possible_player_moves.end(), opponents_king_position)
        == all_possible_player_moves.end())) {
        // If it matches the the opposition is in check
        player_in_check = true;
    }
    // Check if the opponents king's position/position of any possible moves match any of current player's possible piece moves
    for(auto i : opposition_king_locations) {
        if(!(std::find(all_possible_player_moves.begin(), all_possible_player_moves.end(), i) == all_possible_player_moves.end())) {
            king_cant_move_count ++;
        }
    }
    // If king has been taken (size = 0), there is no check mate statement; player wins.
    if(opposition_king_locations.size() == 0) {
        check_mate = true;
        std::cout << *this;
        std::cout << '\n';
        std::cout << turn << " wins!" << std::endl;
        return;
    }
    // If all of opponents king moves can be matched by current players moves, check mate is reached
    if(king_cant_move_count == opposition_king_locations.size()) {
        check_mate = true;
        std::cout << *this;
        std::cout << '\n';
        std::cout << "Check mate! " << turn << " wins!" << std::endl;
    }
}
// Relevant piece that is being moved has it's symbol updated here when running/resetting move assistant
void board::move_assistant_set_piece_symbol(const std::array<std::string, 6> symbols_one, const std::array<std::string, 6> symbols_two)
{
    std::array<std::string, 6> piece_names{"Pawn", "Rook", "Knight", "Bishop", "Queen", "King"};
    int counter{};
    // Lambda function sets the symbol of the piece in question to <... > (for run) or back to original symbol (for reset)
    std::for_each(piece_names.begin(), piece_names.end(), [&counter, symbols_one, symbols_two, this] (std::string name) {
        if(board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
            ->get_ownership() == "Player One") {
            if(board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
                ->get_name() == name) {
                board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
                    ->set_symbol(symbols_one[counter]);
            }
        } else if(board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
            ->get_ownership() == "Player Two") {
            if(board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
                ->get_name() == name) {
                board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
                    ->set_symbol(symbols_two[counter]);
            }
        }
        counter ++;
    });
}
// Possible piece moves as well as potential pieces user can take have their symbols updated here (for move assistant)
void board::move_assistant_set_neighbours_symbols(const std::string run_or_reset, const std::array<std::string, 6> symbols_one,
    const std::array<std::string, 6> symbols_two)
{
    // Array used as size of contained data is known
    const std::array<std::string, 6> piece_names = {"Pawn", "Rook", "Knight", "Bishop", "Queen", "King"};
    int counter;
    // For each valid move coordinate, piece occupying that space is found
    for(auto z : board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
        ->get_legal_moves()) {
        if(board_piece_storage[z.first][z.second]->is_chess_piece() == true) {
            counter = 0;
            // Lambda function that replaces appropriate piece symbol with (... ) to indicate that it can be taken
            std::for_each(piece_names.begin(), piece_names.end(), [&counter, symbols_one, symbols_two, this, z] (std::string name) {
                if(board_piece_storage[z.first][z.second]->get_ownership() == "Player One") {
                    if(board_piece_storage[z.first][z.second]->get_name() == name) {
                        board_piece_storage[z.first][z.second]->set_symbol(symbols_one[counter]);
                    }
                } else if(board_piece_storage[z.first][z.second]->get_ownership() == "Player Two") {
                    if(board_piece_storage[z.first][z.second]->get_name() == name) {
                        board_piece_storage[z.first][z.second]->set_symbol(symbols_two[counter]);
                    }
                }
            });
        } else {
            if(run_or_reset == "run") {
                // If coordinate contains a tile, it will be replaced with " .  "
                board_piece_storage[z.first][z.second]->set_symbol(" x  ");
            } 
        }
    }
}
// Initiates move assistant once a "from" coordinate is given
void board::run_move_assistant()
{   
    const std::array<std::string, 6> piece_names{"Pawn", "Rook", "Knight", "Bishop", "Queen", "King"};
    const std::array<std::string, 6> new_symbols_one{"(♟︎ )", "(♜ )", "(♞ )", "(♝ )", "(♛ )", "(♚ )"};
    const std::array<std::string, 6> new_symbols_selected_one{"<♟︎ >", "<♜ >", "<♞ >", "<♝ >", "<♛ >", "<♚ >"};
    const std::array<std::string, 6> new_symbols_two{"(♙ )", "(♖ )", "(♘ )", "(♗ )", "(♕ )", "(♔ )"};
    const std::array<std::string, 6> new_symbols_selected_two{"<♙ >", "<♖ >", "<♘ >", "<♗ >", "<♕ >", "<♔ >"};
    // Sets the symbol of the piece in question to <... >, or back to original symbol
    move_assistant_set_piece_symbol(new_symbols_selected_one, new_symbols_selected_two);
    // Sets the symbols of nieghbours pieces that could be taken to (... ), or back to original symbols
    move_assistant_set_neighbours_symbols("run", new_symbols_one, new_symbols_two);
    std::cout << *this;
}
// Resets move assistant such that pieces return to their original symbols
void board::reset_move_assistant()
{
    if(use_move_assistant == true) {
        std::array<std::string, 6> original_symbols_one{" ♟︎  ", " ♜  ", " ♞  ", " ♝  ", " ♛  ", " ♚  "};
        std::array<std::string, 6> original_symbols_two{" ♙  ", " ♖  ", " ♘  ", " ♗  ", " ♕  ", " ♔  "};
        // Restor each tile back to its original black/white symbol
        for(auto i : board_piece_storage[vector_coordinate_from_to.first.first][vector_coordinate_from_to.first.second]
            ->get_legal_moves()) {
            if(board_piece_storage[i.first][i.second]->get_name() == "White tile") {
                board_piece_storage[i.first][i.second]->set_symbol(" \u25FC  ");
            } else if(board_piece_storage[i.first][i.second]->get_name() == "Black tile") {
                board_piece_storage[i.first][i.second]->set_symbol(" \u25FB  ");
            }
        }
        // Sets the symbol of the piece in question to <... >, or back to original symbol
        move_assistant_set_piece_symbol(original_symbols_one, original_symbols_two);
        // Sets the symbols of nieghbours pieces that could be taken to (... ), or back to original symbols
        move_assistant_set_neighbours_symbols("reset", original_symbols_one, original_symbols_two);
    }
}