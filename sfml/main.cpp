#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow screen(sf::VideoMode(500 * 2, 500 * 2), "Primer");

  sf::CircleShape circle(75 * 2);
  circle.setFillColor(sf::Color(0, 0, 255));
  circle.setOrigin(75 * 2, 75 * 2);
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
