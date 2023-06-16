#ifndef game_h
#define game_h

#include "interface.h"
#include "../shopUtils/shop.h"

class Game
{
public:
    Game();
    void process();
    void start();
};

Game::Game()
{
    Interface::start();
}

void Game::process()
{
    char code = getch();
    switch (code)
    {
    case 13:
        this->start();
    }
}

void Game::start()
{
    Shop shop;
}

#endif