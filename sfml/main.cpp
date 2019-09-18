#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

  int dpi = 2;
  int w = 500 * dpi;
  int h = 500 * dpi;

  int r = 50 * dpi;
  int v = 500 * dpi;

  sf::RenderWindow screen(sf::VideoMode(w, h), "Primer - SFML");
  std::string bgFilePath = "assets/images/bg.jpg";
  sf::Texture bgTexture;
  if (!bgTexture.loadFromFile(bgFilePath)) {
    std::cerr << "could not load bg from file: " << bgFilePath << std::endl;
    exit(1);
  }
  sf::Sprite bg(bgTexture);
  sf::FloatRect space = bg.getGlobalBounds();
  sf::View view = screen.getView();

  sf::Clock clock;
  float elapsedTime;
  float fps = 1 / 60.f;

  std::string shipFilePath = "assets/images/ship.png";
  sf::Texture shipTexture;
  if (!shipTexture.loadFromFile(shipFilePath)) {
    std::cerr << "could not load ship from file: " << shipFilePath << std::endl;
    exit(1);
  }
  sf::Sprite ship(shipTexture);
  ship.scale((r * 2) / (float)shipTexture.getSize().x, (r * 2) / (float)shipTexture.getSize().y);
  ship.setOrigin(ship.getLocalBounds().width / 2, ship.getLocalBounds().height / 2);
  ship.setPosition(screen.getSize().x / 2.f, screen.getSize().y / 2.f);

  while (screen.isOpen()) {
    elapsedTime += clock.restart().asSeconds();

    int x = 0;
    int y = 0;
    int vx = 0;
    int vy = 0;

    sf::Event event;
    while (screen.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        screen.close();
      }
    }

    while (elapsedTime >= fps) {
      elapsedTime -= fps;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(ship.getPosition().y - (v * fps) > h / 2) {
          y -= (v * fps);
          vy -= (v * fps);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if(ship.getPosition().y + (v * fps) < space.height - h / 2) {
          y += (v * fps);
          vy += (v * fps);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(ship.getPosition().x - (v * fps) > w / 2) {
          x -= (v * fps);
          vx -= (v * fps);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(ship.getPosition().x + (v * fps) < space.width - w / 2) {
          x += (v * fps);
          vx += (v * fps);
        }
      }

      ship.move(x, y);
      view.move(vx, vy);

    }

    screen.setView(view);
    screen.clear(sf::Color(255, 255, 255));
    screen.draw(bg);
    screen.draw(ship);
    screen.display();
  }
}
