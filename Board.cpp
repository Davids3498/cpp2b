#include <iostream>
#include "Board.hpp"
#include <limits.h>
#include <stdexcept>
using namespace std;

namespace ariel
{
    void Board::post(uint row, uint col, Direction course, string const &msg)
    {
        switch (course)
        {
        case Direction::Horizontal:
        {

            if (col + msg.length() > UINT_MAX)
            {
                throw std::out_of_range{"Can't post on the board, the message is exceeding the board length."};
            }

            board_bounds_start(row, col);
            end_col(col, msg.length());
            uint colPost = col;
            for (uint i = 0; i < msg.length(); i++)
            {
                board_map[row][colPost] = msg.at(i);
                colPost++;
            }
            break;
        }

        case Direction::Vertical:
        {
            if (row + msg.length() > UINT_MAX)
            {
                throw std::out_of_range{"Can't post on the board, the message is exceeding the board length."};
            }

            board_bounds_start(row, col);
            end_row(row, msg.length());
            uint rowPost = row;
            for (uint i = 0; i < msg.length(); i++)
            {
                board_map[rowPost][col] = msg.at(i);
                rowPost++;
            }
            break;
        }
        }
    }
    string Board::read(uint row, uint col, Direction course, uint length)
    {
        string returnString;

        switch (course)
        {
        case Direction::Horizontal:
        {
            if (col + length > UINT_MAX)
            {
                throw std::out_of_range{"Can't post on the board, the message is exceeding the board length."};
            }

            uint colPost = col;
            for (uint i = 0; i < length; i++)
            {
                if (board_map.find(row) == board_map.end() || board_map[row].find(colPost) == board_map[row].end())
                {
                    returnString += '_';
                }
                else
                {
                    returnString += board_map[row][colPost];
                }
                colPost++;
            }
            return returnString;

            break;
        }

        case Direction::Vertical:
        {
            if (row + length > UINT_MAX)
            {
                throw std::out_of_range{"Can't post on the board, the message is exceeding the board length."};
            }
            uint rowPost = row;
            for (uint i = 0; i < length; i++)
            {
                if (board_map.find(rowPost) == board_map.end() || board_map[rowPost].find(col) == board_map[rowPost].end())
                {
                    returnString += '_';
                }
                else
                {
                    returnString += board_map[rowPost][col];
                }
                rowPost++;
            }
            return returnString;

            break;
        }
        }
    }

    void Board::show()
    {

        if (board_map.empty())
        {
            cout << "Board is empty" << endl;
            return;
        }
        // board boarders
        // cout << "row : start " << board_start_row << endl;
        // cout << "row : end " << board_end_row << endl;
        // cout << "col : start " << board_start_col << endl;
        // cout << "col : end " << board_end_col << endl;

        for (uint r = board_start_row; r < board_end_row; r++)
        {
            cout << "  _";
            for (uint c = board_start_col; c <= board_end_col; c++)
            {
                if (board_map.find(r) == board_map.end() || board_map[r].find(c) == board_map[r].end())
                {
                    cout << "_";
                }
                else
                {
                    cout << board_map[r][c];
                }
            }
            cout << " : " << r << "\n";
        }
    }
    void Board::board_bounds_start(uint row, uint col)
    {
        start_row(row);
        start_col(col);
    }

    void Board::start_row(uint row)
    {
        if (board_start_row > row)
        {
            board_start_row = row;
        }
    }

    void Board::start_col(uint col)
    {
        if (board_start_col > col)
        {
            board_start_col = col;
        }
    }

    void Board::end_row(uint row, uint word_length)
    {
        if (board_end_row < row + word_length)
        {
            board_end_row = row + word_length;
        }
    }

    void Board::end_col(uint col, uint word_length)
    {
        if (board_end_col < col + word_length)
        {
            board_end_col = col + word_length;
        }
    }
}