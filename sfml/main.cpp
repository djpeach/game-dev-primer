#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

  int dpi = 2;
  int w = 500 * dpi;
  int h = 500 * dpi;

  int r = 75 * dpi;

  sf::RenderWindow screen(sf::VideoMode(w, h), "Primer");

  sf::CircleShape circle(r);
  circle.setFillColor(sf::Color(0, 0, 255));
  circle.setOrigin(r, r);
  circle.setPosition(screen.getSize().x / 2.f, screen.getSize().y / 2.f);

  while (screen.isOpen()) {
    sf::Event event;
    while (screen.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        screen.close();
      }
    }

    screen.clear(sf::Color(255, 255, 255));
    screen.draw(circle);
    screen.display();
  }
}
