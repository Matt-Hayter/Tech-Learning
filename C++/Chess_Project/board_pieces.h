#ifndef BOARD_PIECES_H // Header guard (pre-processor directive)
#define BOARD_PIECES_H

// Class definitions for all board pieces, including tiles and chess pieces

#include <vector>
#include <string>
#include <memory>

// Abstract base class for pieces - class definition
class board_piece
{
    public:
        virtual ~board_piece() {}
        virtual std::string get_symbol() = 0;
        virtual void set_symbol(std::string const) = 0;
        virtual bool is_chess_piece() const = 0;
        virtual std::string get_ownership() const = 0;
        virtual std::string get_name() const = 0;
        virtual void increase_player_one_move_count() = 0;
        virtual void increase_player_two_move_count() = 0;
        virtual int get_player_one_move_count() = 0;
        virtual int get_player_two_move_count() = 0;
        virtual void increase_individual_move_count() = 0;
        virtual void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &,
            std::pair<int, int> const, std::string const) = 0;
        virtual std::vector<std::pair<int, int>> get_legal_moves() = 0;
};
// Derived class for tiles - class definition
class tile : public board_piece
{
    protected:
        std::string name;
        std::string tile_symbol;
        std::string ownership{"No One"};
        std::vector<std::pair<int, int>> valid_move_coordinates_vector{0};
        int player_one_total_move_count{};
        int player_two_total_move_count{};
        int individual_move_count{};
    public:
        tile() : name{"Nul"}, tile_symbol{"Z"} {}
        tile(std::string input_name, std::string input_symbol) : name{input_name}, tile_symbol{input_symbol} {}
        virtual ~tile() {}
        void increase_player_one_move_count() {}
        void increase_player_two_move_count() {}
        void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &, std::pair<int, int> const,
            std::string const) {}
        void increase_individual_move_count() {}
        std::string get_symbol();
        bool is_chess_piece() const;
        std::string get_ownership() const;
        std::string get_name() const;
        int get_player_one_move_count();
        int get_player_two_move_count();
        std::vector<std::pair<int, int>> get_legal_moves();
        void set_symbol(std::string const);
};
// Derived white tile class - class definition
// Relative colours may be flipped depending on user terminal settings
class white_tile : public tile
{
    public:
        white_tile() : tile{"Nul", "Z"} {}
        white_tile(std::string input_name, std::string input_symbol) : tile{input_name, input_symbol} {}
        ~white_tile() {}
};
// Derived black tile class - class definition
// Derived black tile class. Relative colours may be flipped depending on user terminal settings
class black_tile : public tile
{
    public:
        black_tile() : tile{"Nul", "Z"} {}
        black_tile(std::string input_name, std::string input_symbol) : tile{input_name, input_symbol} {}
        ~black_tile() {}
};
// Abstract derived class for chess pieces - class definition
class chess_piece : public board_piece
{
    protected:
        std::string name;
        std::string piece_symbol;
        std::string ownership;
        // Holds all valid knight move coordinatves, given user "from" coordinate
        std::vector<std::pair<int, int>> valid_move_coordinates_vector;
        int individual_move_count; // Count for individual piece object
        // Protected constructors as class is abstract
        chess_piece () : name{"Nul"}, piece_symbol{"X"}, ownership{"No one"}, valid_move_coordinates_vector{},
            individual_move_count{} {}
        chess_piece(std::string input_name, std::string input_symbol, std::string input_owner) : name{input_name},
            piece_symbol{input_symbol}, ownership{input_owner}, valid_move_coordinates_vector{}, 
            individual_move_count{} {}
    public:
        virtual ~chess_piece() {}
        std::string get_symbol();
        bool is_chess_piece() const;
        std::string get_ownership() const;
        std::string get_name() const;
        std::vector<std::pair<int, int>> get_legal_moves();
        void increase_individual_move_count();
        void set_symbol(std::string const);
};
// Derived pawn piece class - class definition
class pawn : public chess_piece
{
    private:
        static int player_one_total_move_count; // Declare static member data to be accessed by all pawn objects
        static int player_two_total_move_count;
    public:
        pawn() : chess_piece{"Nul", "X", "No one"} {}
        // Abstract class constructor for chess_piece can only be excecuted from a derived class as below
        pawn(std::string title, std::string symbol, std::string owner) : chess_piece{title, symbol, owner} {}
        ~pawn() {}
        void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &, std::pair<int, int> const, std::string const);
        void increase_player_one_move_count();
        void increase_player_two_move_count();
        int get_player_one_move_count();
        int get_player_two_move_count();
};
// Derived rook piece class - class definition
class rook : public chess_piece
{   
    private:
        static int player_one_total_move_count; // Declare static member data to be accessed by all pawn objects
        static int player_two_total_move_count;
    public:
        rook() : chess_piece{"Nul", "X", "No one"} {}
        rook(std::string title, std::string symbol, std::string owner) : chess_piece{title, symbol, owner} {}
        ~rook() {}
        void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &, std::pair<int, int> const, std::string const);
        void increase_player_one_move_count();
        void increase_player_two_move_count();
        int get_player_one_move_count();
        int get_player_two_move_count();
};
// Derived knight piece class - class definition
class knight : public chess_piece
{
    private:
        static int player_one_total_move_count; // Declare static member data to be accessed by all pawn objects
        static int player_two_total_move_count;
    public:
        knight() : chess_piece{"Nul", "X", "No one"} {}
        knight(std::string title, std::string symbol, std::string owner) : chess_piece{title, symbol, owner} {}
        ~knight() {}
        void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &, std::pair<int, int> const, std::string const);
        void increase_player_one_move_count();
        void increase_player_two_move_count();
        int get_player_one_move_count();
        int get_player_two_move_count();
};
// Derived bishop piece class - class definition
class bishop : public chess_piece
{
    private:
        static int player_one_total_move_count; // Declare static member data to be accessed by all pawn objects
        static int player_two_total_move_count;
    public:
        bishop() : chess_piece{"Nul", "X", "No one"} {}
        bishop(std::string title, std::string symbol, std::string owner) : chess_piece{title, symbol, owner} {}
        ~bishop() {}
        void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &, std::pair<int, int> const,
            std::string const);
        void increase_player_one_move_count();
        void increase_player_two_move_count();
        int get_player_one_move_count();
        int get_player_two_move_count();
};
// Derived queen piece class - class definition
class queen : public chess_piece
{
    private:
        static int player_one_total_move_count; // Declare static member data to be accessed by all pawn objects
        static int player_two_total_move_count;
    public:
        queen() : chess_piece{"Nul", "X", "No one"} {}
        queen(std::string title, std::string symbol, std::string owner) : chess_piece{title, symbol, owner} {}
        ~queen() {}
        void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &, std::pair<int, int> const, std::string const);
        void increase_player_one_move_count();
        void increase_player_two_move_count();
        int get_player_one_move_count();
        int get_player_two_move_count();
};
// Derived king piece class - class definition
class king : public chess_piece
{
    private:
        int player_one_total_move_count; // Member data not static here as there can only ever be one king per side
        int player_two_total_move_count;
    public:
        king() : chess_piece{"Nul", "X", "No one"}, player_one_total_move_count{}, player_two_total_move_count{} {}
        king(std::string title, std::string symbol, std::string owner) : chess_piece{title, symbol, owner}, player_one_total_move_count{},
            player_two_total_move_count{} {}
        ~king() {}
        void calculate_legal_moves(std::vector<std::vector<std::unique_ptr<board_piece>>> const &, std::pair<int, int> const, std::string const);
        void increase_player_one_move_count();
        void increase_player_two_move_count();
        int get_player_one_move_count();
        int get_player_two_move_count();
};

#endif