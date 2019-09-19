#include "Explosion.hpp"

#define dpi 2

Explosion::Explosion(sf::Texture & texture, sf::Vector2f position) {
  sprite.setTexture(texture);
  sprite.setPosition(position);
  sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
  sprite.scale(dpi, dpi);
  timeAlive = sf::seconds(0);
}

Explosion::~Explosion() {

}

const sf::Sprite & Explosion::getSprite() {
  return sprite;
}

const sf::Time & Explosion::getTimeAlive() {
  return timeAlive;
}

void Explosion::update(float dt) {
  timeAlive += sf::seconds(dt);
}

void Explosion::draw(sf::RenderWindow & window) {
  window.draw(sprite);
}
