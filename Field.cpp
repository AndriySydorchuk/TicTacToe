#include "Field.h"
#include <iostream>

void Field::Clear()
{
    // Make field empty
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            field[i][j] = ' ';
        }
    }
}

void Field::InitRows()
{
    for (int i = 0; i < ROWS; ++i)
    {
        if (i % 5 == 0)
        {
            for (int j = 0; j < COLUMNS; ++j)
            {
                field[i][j] = '_';
            }
        }
    }
}

void Field::InitColumns()
{
    for (int j = 0; j < COLUMNS; j += 16)
    {
        for (int i = 1; i < ROWS; ++i)
        {
            if (i % 5 != 0)
            {
                field[i][j] = '|';
            }
            else if(j % 16 == 0)
            {
                field[i][j] = '|';
            }
        }
    }
}

Field::Field() : ROWS(16), COLUMNS(49)
{
    // Create 2D array for field
    field = new char* [ROWS];
    for (int i = 0; i < ROWS; ++i)
    {
        field[i] = new char[COLUMNS];
    }

    Clear();
    InitRows();
    InitColumns();
}

Field::~Field()
{
    for (int i = 0; i < ROWS; ++i)
    {
            delete[] field[i];
    }

    delete[] field;
}

void Field::Show() const
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}