#include <iostream>
#include <stdio.h>
#include <termios.h>
#include "Field.h"

static struct termios storedSettings;

void Set_Keypress(void)
{
    struct termios newSettings;

    tcgetattr(0,&storedSettings);

    newSettings = storedSettings;

    /* Disable canonical mode, and set buffer size to 1 byte */
    newSettings.c_lflag &= (~ICANON);
    newSettings.c_cc[VTIME] = 0;
    newSettings.c_cc[VMIN] = 1;

    tcsetattr(0,TCSANOW,&newSettings);
    return;
}

void ResetKeypress(void)
{
    tcsetattr(0,TCSANOW,&storedSettings);
    return;
}

void SetCursorPosition(size_t x, size_t y)
{
    std::string escapeSequence = "\033[" + std::to_string(x) + ";" + std::to_string(y) + "f";
    std::cout << escapeSequence;
}

void SetCursorVisibility(bool on_or_off)
{
    if(on_or_off == false)
    {
        std::cout << "\e[?25l"; // disable cursor
    }
    else
    {
        std::cout << "\e[?25h"; // enable cursor
    }
}

enum Key
{
    ARROW_LEFT = 97, ARROW_UP = 119, ARROW_RIGHT = 100, ARROW_DOWN = 115
};

void Render(int key)
{
    if(key == ARROW_RIGHT)
    {
        SetCursorPosition(4,9);
        std::cout << ' ';
        SetCursorPosition(4, 25);
    }
}

void Game()
{
    bool gameover = false;
    while(!gameover)
    {
        Render(getchar());
        gameover = true;
    }
}

int main()
{
    set_keypress();

    Field field;
    SetCursorVisibility(0);
    field.Show();
    SetCursorVisibility(1);

    SetCursorPosition(4, 9);

    Game();

    int key = getchar();
    std::cout << key << std::endl;

    reset_keypress();
    std::cin.ignore();
    std::cin.get();
    return 0;
}
