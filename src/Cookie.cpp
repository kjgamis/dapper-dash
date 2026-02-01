#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // for rand()

#include "Cookie.h"

// type is Texture from the SFML library
sf::Texture Cookie::cookieTexture;

Cookie::Cookie() {
  cookieTexture.loadFromFile("../assets/cookie.png");
  cookieSprite.setTexture(cookieTexture);
  cookieSprite.setScale(0.1f, 0.1f);

  // type Vector2f has two float members x and y
  pos.x = rand() % windowWidth - cookieSprite.getLocalBounds().width * cookieSprite.getScale().x;
  pos.y = rand() % windowLength - cookieSprite.getLocalBounds().height * cookieSprite.getScale().y;
  std::cout << "Cookie position: " << pos.x << ", " << pos.y << std::endl;
  cookieSprite.setPosition(pos.x, pos.y);
}

sf::Sprite Cookie::getSprite() const {
  return cookieSprite;
}

sf::Vector2f Cookie::getPosition() const {
  return pos;
}

// Renders the cookie on the given window
void Cookie::render(sf::RenderWindow& window) const {
  window.draw(cookieSprite);
}