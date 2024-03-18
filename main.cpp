#include <iostream>
#include <stdio.h>
#include <termios.h>
#include "Field.h"

static struct termios stored_settings;

void set_keypress(void)
{
    struct termios new_settings;

    tcgetattr(0,&stored_settings);

    new_settings = stored_settings;

    /* Disable canonical mode, and set buffer size to 1 byte */
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0,TCSANOW,&new_settings);
    return;
}

void reset_keypress(void)
{
    tcsetattr(0,TCSANOW,&stored_settings);
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
