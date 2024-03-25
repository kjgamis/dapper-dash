#ifndef DAPPER_DASH_ENGINE_H
#define DAPPER_DASH_ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Dog.h"
#include "Cookie.h"

class Engine {
  sf::Vector2f resolution;
  sf::RenderWindow window;
  const size_t frameRate = 24;
  static const sf::Time TimePerFrame;

  std::vector<Cookie> cookies;
  Dog dapper;
public:
  Engine();
  void input();
  void draw();

  // run the game loop and pass events as arguments
  void run();
};


#endif //DAPPER_DASH_ENGINE_H
