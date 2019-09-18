#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

  int dpi = 2;
  int w = 1000 * dpi;
  int h = 1000 * dpi;

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
  bg.setScale(dpi, dpi);
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          ship.setRotation(-45);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          ship.setRotation(45);
        } else {
          ship.setRotation(0);
        }
        if(ship.getPosition().y - (v * fps) < screen.getView().getCenter().y &&
           screen.getView().getCenter().y - (h / 2) - (v * fps) > space.top - r * 1.5f) {
          vy -= (v * fps);
        }
        if(ship.getPosition().y - (v * fps) > space.top + r) {
          y -= (v * fps);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          ship.setRotation(-135);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          ship.setRotation(135);
        } else {
          ship.setRotation(180);
        }
        if(ship.getPosition().y + (v * fps) > screen.getView().getCenter().y &&
           screen.getView().getCenter().y + (h / 2) + (v * fps) < space.height + r * 1.5f) {
          vy += (v * fps);
        }
        if(ship.getPosition().y + (v * fps) < space.height - r) {
          y += (v * fps);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          ship.setRotation(-45);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          ship.setRotation(-135);
        } else {
          ship.setRotation(-90);
        }
        if(ship.getPosition().x - (v * fps) < screen.getView().getCenter().x &&
           screen.getView().getCenter().x - (w / 2) - (v * fps) > space.left) {
          vx -= (v * fps);
        }
        if(ship.getPosition().x - (v * fps) > space.left + r) {
          x -= (v * fps);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          ship.setRotation(45);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          ship.setRotation(135);
        } else {
          ship.setRotation(90);
        }
        if(ship.getPosition().x + (v * fps) > screen.getView().getCenter().x &&
           screen.getView().getCenter().x + (w / 2) + (v * fps) < space.width) {
          vx += (v * fps);
        }
        if(ship.getPosition().x + (v * fps) < space.width - r) {
          x += (v * fps);
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
