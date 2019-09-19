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
  std::cout << "creating resource: " << position.x << ", " << position.y << std::endl;
}

Resource::~Resource() {

}

void Resource::update(float dt) {

}

void Resource::draw(sf::RenderWindow & window) {
  // std::cout << "drawing resource" << std::endl;
  window.draw(sprite);
}
