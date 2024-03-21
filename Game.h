#pragma once

class Game
{
public:
    ~Game();

    //Main game cycles
    bool IsRunning() const;
    void HandleInput();
    void Update();
    void Render();

    //Handle game exception
    //Handle other exception

    //Singleton pattern
    static Game& GetInstance();
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;


private:
    Game();


};


