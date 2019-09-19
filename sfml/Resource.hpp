#include <iostream>
#include <SFML/Graphics.hpp>

class Resource {
  public:
    Resource(sf::Texture & texture, sf::Vector2f position);
    ~Resource();

    const sf::Sprite & getSprite();

    void update(float dt);
    void draw(sf::RenderWindow & window);
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
};
