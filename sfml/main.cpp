#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

  int dpi = 1;
  int w = 500 * dpi;
  int h = 500 * dpi;

  int r = 75 * dpi;
  int v = 500 * dpi;

  sf::RenderWindow screen(sf::VideoMode(w, h), "Primer - SFML");

  sf::Clock clock;
  float elapsedTime;
  float fps = 1 / 60.f;

  sf::CircleShape circle(r);
  circle.setFillColor(sf::Color(0, 0, 255));
  circle.setOrigin(r, r);
  circle.setPosition(screen.getSize().x / 2.f, screen.getSize().y / 2.f);

  while (screen.isOpen()) {
    elapsedTime += clock.restart().asSeconds();

    int x = 0;
    int y = 0;

    sf::Event event;
    while (screen.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        screen.close();
      }
    }

    while (elapsedTime >= fps) {
      elapsedTime -= fps;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(circle.getPosition().y - (v * fps) > r) {
          y -= (v * fps);
        } else {
          y -= circle.getPosition().y - r;
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if(circle.getPosition().y + (v * fps) < h - r) {
          y += (v * fps);
        } else {
          y += h - (circle.getPosition().y + r);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(circle.getPosition().x - (v * fps) > r) {
          x -= (v * fps);
        } else {
          x -= circle.getPosition().x - r;
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(circle.getPosition().x + (v * fps) < w - r) {
          x += (v * fps);
        } else {
          x += w - (circle.getPosition().x + r);
        }
      }

      circle.move(x, y);

    }

    screen.clear(sf::Color(255, 255, 255));
    screen.draw(circle);
    screen.display();
  }
}
