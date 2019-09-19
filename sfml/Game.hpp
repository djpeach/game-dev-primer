#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Resource.hpp"
#include "Station.hpp"
#include "Enemy.hpp"

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
    void setInfoText(const std::string & string);

    sf::RenderWindow screen;
    sf::View view;
    sf::FloatRect space;
    sf::Texture bgTexture, shipTexture, resTexture, enemyTexture, stationTexture;
    sf::Sprite bg, ship;
    float r, vel;
    sf::Vector2f screenSize, shipPos, viewPos;
    std::vector<Resource> resources;
    std::vector<Resource> loot;
    int score, cargoCount;
    sf::Font font;
    sf::Text infoText, cargoText, scoreText;
    Station station;
    std::vector<Enemy> enemies;
};
