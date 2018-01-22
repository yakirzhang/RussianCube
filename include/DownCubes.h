class DownCubes {
 public:
  bool BackGround[30][40] = {{0}};
  DownCubes() {
    for (int i = 0; i < 30; i++)
      for (int j = 0; j < 40; j++) BackGround[i][j] = false;
  }
};