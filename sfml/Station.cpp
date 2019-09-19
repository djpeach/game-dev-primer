#include "Station.hpp"

#define dpi 2

Station::Station(sf::Texture & texture, sf::Vector2f position) {
  sprite.setTexture(texture);
  sprite.setPosition(position);
  sprite.scale(dpi, dpi);
}

Station::~Station() {

}

const sf::Sprite & Station::getSprite() {
  return sprite;
}

void Station::update(float dt) {

}

void Station::draw(sf::RenderWindow & window) {
  std::cout << "drawing station" << std::endl;
  window.draw(sprite);
}
