#include "Score.h"

int Score::score = 0;

Score::Score() {}

void Score::increment() {
  ++score;
}

int Score::getScore() const {
  return score;
}

void Score::resetScore() {
  score = 0;
}
