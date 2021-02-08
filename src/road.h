#include "car.h"

class Road{

protected:
  static const int n_rows = 30;
  static const int n_cols = 80;
  int nails_taken;
  int points;
  int level;
  char matrix[n_rows][n_cols];
  const char *message;
  int message_life;


public:

  Car car;
  Road();
  inline void print(){ print_map(); print_info(); }
  void reposition_cursor();
  void car_consume_fuel();
  void car_add_fuel();
  void car_consume_life();
  void move();
  char spawn_obj();
  void print_map();
  void print_info();
  void init_game();
  void inc_dec_level();
  void game_over();
  void set_message(const char* message);
  inline void get_nail(){nails_taken+=1;}
  inline void add_points(){points += 1;}
  inline void remove_points(){points -= 10;}

};
