#include "Game.hpp"
#include <cstdlib>

#define dpi 2

#define resourceCount 15
#define enemyCount 10
#define cargoCapacity 30

Game::Game() : score(0), cargoCount(0), station(stationTexture, sf::Vector2f(100, 100)) {
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

  std::string stationFilePath = "assets/images/station.png";
  if (!stationTexture.loadFromFile(stationFilePath)) {
    std::cerr << "could not load station image from file: " << stationFilePath << std::endl;
    exit(1);
  }
  station = Station(stationTexture, sf::Vector2f(100, 100));

  std::string shipFilePath = "assets/images/ship.png";
  if (!shipTexture.loadFromFile(shipFilePath)) {
    std::cerr << "could not load ship from file: " << shipFilePath << std::endl;
    exit(1);
  }
  ship.setTexture(shipTexture);
  ship.scale((r * 2) / (float)shipTexture.getSize().x, (r * 2) / (float)shipTexture.getSize().y);
  ship.setOrigin(ship.getLocalBounds().width / 2, ship.getLocalBounds().height / 2);
  sf::FloatRect stationBounds = station.getSprite().getGlobalBounds();
  ship.setPosition(stationBounds.left + stationBounds.width / 2, stationBounds.top + stationBounds.height / 2);

  std::string resFilePath = "assets/images/res.png";
  if (!resTexture.loadFromFile(resFilePath)) {
    std::cerr << "could not load resource image from file: " << resFilePath << std::endl;
    exit(1);
  }

  std::string fontFilePath = "assets/fonts/arial.ttf";
  if (!font.loadFromFile(fontFilePath)) {
    std::cerr << "could not load font from file: " << fontFilePath << std::endl;
    exit(1);
  }
  infoText.setFont(font);
  cargoText.setFont(font);
  scoreText.setFont(font);

  scoreText.setCharacterSize(60);
  scoreText.setString(std::to_string(score));
  scoreText.setFillColor(sf::Color::Yellow);
  scoreText.setPosition(25, 10);

  cargoText.setCharacterSize(60);
  cargoText.setString(std::to_string(cargoCount) + " / " + std::to_string(cargoCapacity));
  cargoText.setFillColor(sf::Color::Green);
  sf::FloatRect cargoTextBounds = cargoText.getGlobalBounds();
  cargoText.setPosition(screenSize.x - cargoTextBounds.width - 60, 10);

  infoText.setCharacterSize(50);
  infoText.setFillColor(sf::Color::White);
  setInfoText("Use WASD to fly around");
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
  while (resources.size() < resourceCount) {
    Resource res(resTexture, sf::Vector2f(rand() % ((int)space.width - 200) + 100, rand() % ((int)space.height - 200) + 100));
    resources.push_back(res);
  }

  handleInput(fps);

  ship.move(shipPos);
  scoreText.move(viewPos);
  cargoText.setString(std::to_string(cargoCount) + " / " + std::to_string(cargoCapacity));
  cargoText.move(viewPos);
  infoText.move(viewPos);
  view.move(viewPos);
}

void Game::handleInput(float fps) {

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
  for (int i=0;i<resources.size();i++) {
    if (resources[i].getSprite().getGlobalBounds().intersects(ship.getGlobalBounds())) {
      setInfoText("Press E to collect resource");
      if (cargoCount < cargoCapacity) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
          resources.erase(resources.begin() + i);
          cargoCount++;
          setInfoText("Resource collected!");
        }
      } else {
        setInfoText("Cargo full! Drop off at station");
      }
    }
  }

  if (station.getSprite().getGlobalBounds().intersects(ship.getGlobalBounds())) {
    if (cargoCount > 0) {
      setInfoText("Press E to sell cargo");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
      score += cargoCount;
      scoreText.setString(std::to_string(score));
      cargoCount = 0;
      setInfoText("Resources sold, go get more!");
    }
  }
}


void Game::draw() {
  screen.setView(view);
  screen.clear(sf::Color(255, 255, 255));
  screen.draw(bg);
  for (Resource & res : resources) {
    res.draw(screen);
  }
  station.draw(screen);
  screen.draw(ship);
  screen.draw(scoreText);
  screen.draw(cargoText);
  screen.draw(infoText);
  screen.display();
}

void Game::setInfoText(const std::string & string) {
  if (infoText.getString() != string) {
    infoText.setString(string);
    sf::FloatRect infoTextBounds = infoText.getGlobalBounds();
    infoText.setOrigin(infoTextBounds.width / 2, 0);
    infoText.setPosition(screen.getView().getCenter().x, screen.getView().getCenter().y - screenSize.y / 2 + 10);
  }
}
