#include <SFML/Graphics.hpp>

#ifndef DAPPER_DASH_UTILS_H
#define DAPPER_DASH_UTILS_H

#include <iostream>

const float xVelocity = 5;
const float yVelocity = 5;
const sf::Color gray(128, 128, 128);
const int windowWidth = 640;
const int windowLength = 480;

template <typename T, typename S>
bool checkCollision(const T& a, const S& b) {
  if (b.getSprite().getGlobalBounds().intersects(a.getSprite().getGlobalBounds())) {
    std::cout << "Collision detected!" << std::endl;
    return true;
  }
  return false;
}

#endif //DAPPER_DASH_UTILS_H
