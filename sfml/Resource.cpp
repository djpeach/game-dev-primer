#include "Resource.hpp"

#define dpi 2

#include <ctime>

Resource::Resource(sf::Texture & texture, sf::Vector2f position) {
  static bool seeded = false;
  if(!seeded) {
      srand(time(nullptr));
      seeded = true;
  }

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
