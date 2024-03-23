#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib> // for rand()

const float xVelocity = 5;
const float yVelocity = 5;
const sf::Color gray(128, 128, 128);
const int windowWidth = 640;
const int windowLength = 480;

int main() {
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowLength), "Dapper Dash");
  window.setFramerateLimit(24);

  sf::Texture terrier;
  if (!terrier.loadFromFile("../assets/terrier.png")) {
    return EXIT_FAILURE;
  }
  sf::Texture cookie;
  if (!cookie.loadFromFile("../assets/cookie.png")) {
    return EXIT_FAILURE;
  }

  sf::Sprite dapper;
  dapper.setTexture(terrier);
  dapper.setScale(0.25f, 0.25f);

  sf::Vector2 dapperPosition(10.f, 10.f);

  std::vector<sf::Sprite> cookies;

  for (size_t i=0; i<5; i++) {
    sf::Sprite cookieSprite;
    cookieSprite.setTexture(cookie);
    cookieSprite.setScale(0.1f, 0.1f);

    float randX = static_cast<float>(rand() % windowWidth - cookieSprite.getLocalBounds().width * cookieSprite.getScale().x);
    float randY = static_cast<float>(rand() % windowLength - cookieSprite.getLocalBounds().height * cookieSprite.getScale().y);

    cookieSprite.setPosition(randX, randY);
    cookies.push_back(cookieSprite);
  }

  while (window.isOpen()) {
    sf::Event event{};

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
      }
    }

    dapper.setPosition(dapperPosition);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      if (dapperPosition.x - xVelocity >= 0) {
        dapperPosition.x -= xVelocity;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      if (dapperPosition.x + xVelocity <= windowWidth - dapper.getLocalBounds().width * dapper.getScale().x) {
        dapperPosition.x += xVelocity;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      if (dapperPosition.y - yVelocity >= 0) {
        dapperPosition.y -= yVelocity;
      }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      if (dapperPosition.y + yVelocity <= windowLength - dapper.getLocalBounds().height * dapper.getScale().y) {
        dapperPosition.y += yVelocity;
      }
    }

    window.clear(gray);
    for (auto& cookie : cookies) {
      window.draw(cookie);
    }
    window.draw(dapper);
    window.display();
  }
  return 0;
}
