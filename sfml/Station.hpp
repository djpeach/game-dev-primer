#include <iostream>
#include <SFML/Graphics.hpp>

class Station {
  public:
    Station(sf::Texture & texture, sf::Vector2f position);
    ~Station();

    const sf::Sprite & getSprite();

    void update(float dt);
    void draw(sf::RenderWindow & window);
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
};
