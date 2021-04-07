#pragma once
#include <iostream>
#include <string>
#include "Direction.hpp"
#include <map>
#include <limits.h>

namespace ariel
{
    class Board
    {
        std::map<uint, std::map<uint, char>> board_map;
        uint board_start_row = UINT_MAX;
        uint board_start_col = UINT_MAX;
        uint board_end_row = 0;
        uint board_end_col = 0;
        void board_bounds_start(uint, uint);
        void start_row(uint);
        void start_col(uint);
        void end_row(uint, uint);
        void end_col(uint, uint);

    public:
        Board() {}
        void post(uint, uint, Direction, std::string const &);
        std::string read(uint, uint, Direction, uint);
        void show();
    };
}