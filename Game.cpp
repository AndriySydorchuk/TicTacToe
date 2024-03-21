#include "Game.h"

Game& Game::GetInstance()
{
    static Game game;
    return game;
}