#include <iostream>

int main()
{
    std::cout << "\n\n";

    char** field = new char* [16];

    for (int i = 0; i < 16; ++i)
    {
        field[i] = new char[49];
    }

    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 49; ++j)
        {
            switch (i)
            {
                case 0:
                    field[i][j] = '_';
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 6:
                case 7:
                case 8:
                case 9:
                case 11:
                case 12:
                case 13:
                case 14:
                    switch (j)
                    {
                        case 0:
                        case 16:
                        case 32:
                        case 48:
                            field[i][j] = '|';
                            break;
                        default:
                            field[i][j] = ' ';
                            break;
                    }
                    break;
                case 5:
                case 10:
                case 15:
                {
                    switch (j)
                    {
                        case 0:
                        case 16:
                        case 32:
                        case 48:
                            field[i][j] = '|';
                            break;

                        default:
                            field[i][j] = '_';
                            break;
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 49; ++j)
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cin.get();
    return 0;
}
