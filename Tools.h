#pragma once
#include <iostream>
#include <termios.h>

namespace Tools
{
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

    void SetCursorPosition(size_t x, size_t y)
    {
        std::string escapeSequence = "\033[" + std::to_string(x) + ";" + std::to_string(y) + "f";
        std::cout << escapeSequence;
    }

    static struct termios storedSettings;

    void SetKeypress(void)
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

    void ClearScreen()
    {
        system("clear");
    }

}
