#include "Game.hpp"

Game::Game() {
  dpi = 1;
  screenSize.x = 800 * dpi;
  screenSize.y = 800 * dpi;

  r = 50 * dpi;
  vel = 500 * dpi;

  screen.create(sf::VideoMode(screenSize.x, screenSize.y), "Primer - SFML");
  std::string bgFilePath = "assets/images/bg.jpg";
  if (!bgTexture.loadFromFile(bgFilePath)) {
    std::cerr << "could not load bg from file: " << bgFilePath << std::endl;
    exit(1);
  }
  bg.setTexture(bgTexture);
  bg.setScale(dpi, dpi);
  space = bg.getGlobalBounds();
  view = screen.getView();

  std::string shipFilePath = "assets/images/ship.png";
  if (!shipTexture.loadFromFile(shipFilePath)) {
    std::cerr << "could not load ship from file: " << shipFilePath << std::endl;
    exit(1);
  }
  ship.setTexture(shipTexture);
  ship.scale((r * 2) / (float)shipTexture.getSize().x, (r * 2) / (float)shipTexture.getSize().y);
  ship.setOrigin(ship.getLocalBounds().width / 2, ship.getLocalBounds().height / 2);
  ship.setPosition(screen.getSize().x / 2.f, screen.getSize().y / 2.f);
}

Game::~Game() {}

void Game::run() {
  sf::Clock clock;
  float elapsedTime;
  float fps = 1 / 60.f;

  while (screen.isOpen()) {
    elapsedTime += clock.restart().asSeconds();

    shipPos.x = 0;
    shipPos.y = 0;
    viewPos.x = 0;
    viewPos.y = 0;

    sf::Event event;
    while (screen.pollEvent(event)) {
      handleEvent(event);
    }

    while (elapsedTime >= fps) {
      elapsedTime -= fps;
      update(fps);
    }

    draw();
  }
}

void Game::handleEvent(sf::Event event) {
  if (event.type == sf::Event::Closed) {
    screen.close();
  }
}

void Game::update(float fps) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      ship.setRotation(-45);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      ship.setRotation(45);
    } else {
      ship.setRotation(0);
    }
    if(ship.getPosition().y - (vel * fps) < screen.getView().getCenter().y &&
        screen.getView().getCenter().y - (screenSize.y / 2) - (vel * fps) > space.top) {
      viewPos.y -= (vel * fps);
    }
    if(ship.getPosition().y - (vel * fps) > space.top + r) {
      shipPos.y -= (vel * fps);
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
    if(ship.getPosition().y + (vel * fps) > screen.getView().getCenter().y &&
        screen.getView().getCenter().y + (screenSize.y / 2) + (vel * fps) < space.height) {
      viewPos.y += (vel * fps);
    }
    if(ship.getPosition().y + (vel * fps) < space.height - r) {
      shipPos.y += (vel * fps);
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
    if(ship.getPosition().x - (vel * fps) < screen.getView().getCenter().x &&
        screen.getView().getCenter().x - (screenSize.x / 2) - (vel * fps) > space.left) {
      viewPos.x -= (vel * fps);
    }
    if(ship.getPosition().x - (vel * fps) > space.left + r) {
      shipPos.x -= (vel * fps);
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
    if(ship.getPosition().x + (vel * fps) > screen.getView().getCenter().x &&
        screen.getView().getCenter().x + (screenSize.x / 2) + (vel * fps) < space.width) {
      viewPos.x += (vel * fps);
    }
    if(ship.getPosition().x + (vel * fps) < space.width - r) {
      shipPos.x += (vel * fps);
    }
  }

  ship.move(shipPos);
  view.move(viewPos);
}

void Game::draw() {
  screen.setView(view);
  screen.clear(sf::Color(255, 255, 255));
  screen.draw(bg);
  screen.draw(ship);
  screen.display();
}
