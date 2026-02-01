//
// Created by Kage Gamis on 2024-03-23.
//

#ifndef DAPPER_DASH_COOKIE_H
#define DAPPER_DASH_COOKIE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Utils.h"

class Cookie {
  sf::Sprite cookieSprite;
  sf::Vector2f pos;
  static sf::Texture cookieTexture;
public:
  Cookie();
  sf::Sprite getSprite() const;
  sf::Vector2f getPosition() const;
  void render (sf::RenderWindow& window) const;
};

#endif //DAPPER_DASH_COOKIE_H
