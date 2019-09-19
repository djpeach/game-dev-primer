#include "Enemy.hpp"

#define dpi 2

Enemy::Enemy(sf::Texture & texture, sf::Vector2f position) {
  sprite.setTexture(texture);
  sprite.setPosition(position);
  sprite.setScale(dpi, dpi);
  sprite.scale(0.6f, 0.6f);
}

Enemy::~Enemy() {

}

const sf::Sprite & Enemy::getSprite() {
  return sprite;
}

void Enemy::update(float dt) {

}

void Enemy::draw(sf::RenderWindow & window) {
  window.draw(sprite);
}
