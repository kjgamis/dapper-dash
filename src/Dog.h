#ifndef DAPPER_DASH_DOG_H
#define DAPPER_DASH_DOG_H

#include <SFML/Graphics.hpp>
#include "Utils.h"

class Dog {
  sf::Texture dogTexture;
  sf::Sprite dogSprite;
  sf::Vector2f pos = {10.f, 10.f};
public:
  Dog();
  sf::Sprite getSprite() const;
  sf::Vector2f getPosition() const;
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
  void render(sf::RenderWindow& window) const;
};

#endif //DAPPER_DASH_DOG_H
