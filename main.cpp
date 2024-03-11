#include <iostream>

void ShowField(char** field)
{
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 49; ++j)
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


int main()
{
    std::cout << "\n\n";

    // Dimensions
    const size_t ROWS = 16;
    const size_t COLUMNS = 49;

    // Create 2D array for field
    char** field = new char* [ROWS];
    for (int i = 0; i < ROWS; ++i)
    {
        field[i] = new char[COLUMNS];
    }

    // Init field to empty
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            field[i][j] = ' ';
        }
    }

    // Do rows
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

    // Do columns
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

    ShowField(field);

    std::cin.get();
    return 0;
}
