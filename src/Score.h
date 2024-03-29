#ifndef DAPPER_DASH_SCORE_H
#define DAPPER_DASH_SCORE_H

class Score {
  static int score;
public:
  Score();
  void increment();
  int getScore() const;
  void resetScore();
};

#endif //DAPPER_DASH_SCORE_H
