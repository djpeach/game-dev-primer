#include <iostream>
#include <SFML/Graphics.hpp>

class Explosion {
  public:
    Explosion(sf::Texture & texture, sf::Vector2f position);
    ~Explosion();

    const sf::Sprite & getSprite();
    const sf::Time & getTimeAlive();

    void update(float dt);
    void draw(sf::RenderWindow & window);
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Time timeAlive;
};
