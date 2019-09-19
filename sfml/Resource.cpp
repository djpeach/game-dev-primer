#include "Resource.hpp"

#define dpi 2

Resource::Resource(sf::Texture & texture, sf::Vector2f position) {
  sprite.setTexture(texture);
  sprite.setPosition(position);
  sprite.scale(dpi, dpi);
}

Resource::~Resource() {

}

const sf::Sprite & Resource::getSprite() {
  return sprite;
}

void Resource::update(float dt) {

}

void Resource::draw(sf::RenderWindow & window) {
  window.draw(sprite);
}
