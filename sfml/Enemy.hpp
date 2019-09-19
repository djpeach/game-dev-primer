#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy {
  public:
    Enemy(sf::Texture & texture, sf::Vector2f position, sf::FloatRect space);
    ~Enemy();

    const sf::Sprite & getSprite();
    const sf::Vector2f & getPosition();

    void update(float dt);
    void draw(sf::RenderWindow & window);
  private:
    void setRotation();

    sf::Sprite sprite;
    sf::Vector2f position, dir, distance;
    sf::FloatRect space;
};
