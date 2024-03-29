#include "Engine.h"
#include "Utils.h"
#include "Cookie.h"

const sf::Time Engine::TimePerFrame = sf::seconds(1.f/24.f);

Engine::Engine() {
  resolution = sf::Vector2f(windowWidth, windowLength);
  window.create(sf::VideoMode(resolution.x, resolution.y), "Dapper Dash");
  window.setFramerateLimit(frameRate);

  for (size_t i = 0; i < 5; i++) {
    Cookie cSprite;
    cookies.push_back(cSprite);
  }
}

void Engine::input() {
  sf::Event event{};
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    dapper.moveLeft();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    dapper.moveRight();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    dapper.moveUp();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    dapper.moveDown();
  }

  for (auto cookie = cookies.begin(); cookie != cookies.end();) {
    if (checkCollision(dapper, *cookie)) {
      cookie = cookies.erase(cookie);
      score.increment();
    } else {
      ++cookie;
    }
  }
}

void Engine::draw() {
  window.clear(gray);
  for (auto &cookie: cookies) {
    cookie.render(window);
  }
  dapper.render(window);

  // TODO: Draw the score
  scoreText.setString("Score: " + std::to_string(score.getScore()));
  window.draw(scoreText);

  window.display();
}

void Engine::run() { // main loop is here
  // Main loop - runs until the window is closed
  while (window.isOpen()) {
    input();
    draw();
  }
}
