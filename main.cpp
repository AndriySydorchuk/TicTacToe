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

int main()
{
    set_keypress();

    Field field;
    field.Show();

    int key = getchar();
    std::cout << key << std::endl;

    reset_keypress();

    std::cin.ignore();
    std::cin.get();
    return 0;
}
