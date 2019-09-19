#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Enemy.hpp"

#define dpi 2

Enemy::Enemy(sf::Texture & texture, sf::Vector2f position, sf::FloatRect space) : space(space) {
  static bool seeded = false;
  if(!seeded) {
      srand(time(nullptr));
      seeded = true;
  }
  sprite.setTexture(texture);
  sprite.setPosition(position);
  sprite.setScale(dpi, dpi);
  sprite.scale(0.6f, 0.6f);
  sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
  int dirs[2] = {-1, 1};
  int randXDir = dirs[rand() % 2] * 100;
  int randYDir = dirs[rand() % 2] * 100;
  dir = sf::Vector2f(randXDir, randYDir);
}

Enemy::~Enemy() {

}

const sf::Sprite & Enemy::getSprite() {
  return sprite;
}

const sf::Vector2f & Enemy::getPosition() {
  return sprite.getPosition();
}

void Enemy::update(float dt) {
  if (sprite.getGlobalBounds().left < space.left || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > space.width) {
    dir.x = -dir.x;
  }
  if (sprite.getGlobalBounds().top < space.top || sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > space.height) {
    dir.y = -dir.y;
  }
  sprite.move(dir.x * dpi * dt, dir.y * dpi * dt);
  distance.x += abs(dir.x * dpi * dt);
  distance.y += abs(dir.y * dpi * dt);

  if (distance.x > 500) {
    if (dir.x != 0) {
      int dirs[3] = {-1, 0, 1};
      dir.y = dirs[rand() % 3] * 100;
    } else {
      int dirs[2] = {-1, 1};
      dir.y = dirs[rand() % 2] * 100;
    }
    distance.x = 0;
  }

  if (distance.y > 500) {
    if (dir.y != 0) {
      int dirs[3] = {-1, 0, 1};
      dir.x = dirs[rand() % 3] * 100;
    } else {
      int dirs[2] = {-1, 1};
      dir.x = dirs[rand() % 2] * 100;
    }
    distance.y = 0;
  }

  setRotation();
}

void Enemy::setRotation() {
  if (dir.x == 0) {
    if (dir.y < 0) {
      sprite.setRotation(0);
    } else if (dir.y > 0) {
      sprite.setRotation(180);
    }
  } else if (dir.x < 0) {
    if (dir.y == 0) {
      sprite.setRotation(270);
    } else if (dir.y < 0) {
      sprite.setRotation(315);
    } else if (dir.y > 0) {
      sprite.setRotation(225);
    }
  } else if (dir.x > 0) {
    if (dir.y == 0) {
      sprite.setRotation(90);
    } else if (dir.y < 0) {
      sprite.setRotation(45);
    } else if (dir.y > 0) {
      sprite.setRotation(135);
    }
  }
}

void Enemy::draw(sf::RenderWindow & window) {
  window.draw(sprite);
}
