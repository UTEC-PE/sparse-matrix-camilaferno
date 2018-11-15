
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
  Matrix<int> matrix(3, 3);
  matrix.set(0, 0, 1);
  matrix.set(2, 0, 3);
  matrix.set(1, 0, 2);
  matrix.set(0, 1, 4);
  matrix.set(2, 1, 6);
  matrix.set(1, 2, 8);
  matrix.set(1, 1, 5);
  matrix.set(2, 2, 9);
  matrix.set(0, 2, 7);

  cout << endl;
  matrix.print();
  cout << endl;

  matrix*2;


    return EXIT_SUCCESS;
}
