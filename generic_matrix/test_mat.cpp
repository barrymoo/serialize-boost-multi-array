#include <serialize-ma.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace std;

int main () {
  typedef boost::serialization::ma_serialize<double, 2> matrix;
  matrix::tensor A(boost::extents[10][10]);

  for (matrix::idx i = 0; i < A.shape()[0]; ++i) {
    A[0][i] = 2.0;
  }

  cout << A[0][0] << '\n';
  return 0;
}
