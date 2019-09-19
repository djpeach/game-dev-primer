#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Resource.hpp"

class Game {
  public:
    Game();
    ~Game();
    void run();
    void handleEvent(sf::Event event);
    void update(float fps);
    void handleInput(float fps);
    void draw();
  private:
    sf::RenderWindow screen;
    sf::View view;
    sf::FloatRect space;
    sf::Texture bgTexture, shipTexture, resTexture, enemyTexture;
    sf::Sprite bg, ship;
    float r, vel;
    sf::Vector2f screenSize, shipPos, viewPos;
    std::vector<Resource> resources;
    std::vector<Resource> loot;
    int score, cargoCount;
};
