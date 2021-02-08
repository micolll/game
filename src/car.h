class Car{
 protected:
  int position_x[3];
  int position_y[3];
  int bound_y;
  int fuel;
  int life;



 public:
  Car(int x, int y);
  inline void consume_fuel(){ fuel--; }
  inline int get_fuel_level(){ return fuel;}
  inline int get_position_x(){return position_x[0];}
  inline int get_position_y(){return position_y[0];}
  inline int* get_pos_x(){return position_x;}
  inline int* get_pos_y(){return position_y;}

  inline void add_fuel(){fuel+=50;}
  inline void consume_life(){life-=50;}
  inline int get_life(){return life;}
  void print();
  void move();

};
