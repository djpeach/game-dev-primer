#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

  int dpi = 2;
  int w = 500 * dpi;
  int h = 500 * dpi;

  int r = 75 * dpi;
  int v = 1;

  sf::RenderWindow screen(sf::VideoMode(w, h), "Primer");

  sf::CircleShape circle(r);
  circle.setFillColor(sf::Color(0, 0, 255));
  circle.setOrigin(r, r);
  circle.setPosition(screen.getSize().x / 2.f, screen.getSize().y / 2.f);

  while (screen.isOpen()) {
    int x = 0;
    int y = 0;

    sf::Event event;
    while (screen.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        screen.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      if(circle.getPosition().y - v > r) {
        y -= v;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      if(circle.getPosition().y + v < h - r) {
        y += v;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      if(circle.getPosition().x - v > r) {
        x -= v;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      if(circle.getPosition().x + v < w - r) {
        x += v;
      }
    }

    circle.move(x, y);

    screen.clear(sf::Color(255, 255, 255));
    screen.draw(circle);
    screen.display();
  }
}
