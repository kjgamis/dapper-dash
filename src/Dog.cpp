#include "Dog.h"
#include "Utils.h"

Dog::Dog() {
  dogTexture.loadFromFile("../assets/terrier.png");
  dogSprite.setTexture(dogTexture);
  dogSprite.setScale(0.25f, 0.25f);
  dogSprite.setPosition(pos.x, pos.y);
}

sf::Sprite Dog::getSprite() const {
  return dogSprite;
}

sf::Vector2f Dog::getPosition() const {
  return pos;
}

void Dog::moveLeft() {
  if (pos.x + xVelocity >= 0) {
    pos.x -= xVelocity;
    dogSprite.setPosition(pos.x, pos.y);
  }
}

void Dog::moveRight() {
  if (pos.x + xVelocity <= windowWidth - dogSprite.getLocalBounds().width * dogSprite.getScale().x) {
    pos.x += xVelocity;
    dogSprite.setPosition(pos.x, pos.y);
  }
}

void Dog::moveUp() {
  if (pos.y - yVelocity >= 0) {
    pos.y -= yVelocity;
    dogSprite.setPosition(pos.x, pos.y);
  }
}

void Dog::moveDown() {
  if (pos.y + yVelocity <= windowLength - dogSprite.getLocalBounds().height * dogSprite.getScale().y) {
    pos.y += yVelocity;
    dogSprite.setPosition(pos.x, pos.y);
  }
}

void Dog::render(sf::RenderWindow& window) const {
  window.draw(dogSprite);
}
