#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Game {
  public:
    Game();
    ~Game();
    void run();
    void handleEvent(sf::Event event);
    void update(float fps);
    void draw();
  private:
    sf::RenderWindow screen;
    sf::View view;
    sf::FloatRect space;
    sf::Texture bgTexture, shipTexture;
    sf::Sprite bg, ship;
    float dpi, r, vel;
    sf::Vector2f screenSize, shipPos, viewPos;
};
