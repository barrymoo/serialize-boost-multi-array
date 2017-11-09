#include <serializable_tensor_n.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main () {
  SerializableTensorN<double, 2> matrix;
  matrix.resize(extents[10][10]);

  for (auto i = 0; i < matrix.tensor.shape()[0]; ++i) {
    for (auto j = 0; j < matrix.tensor.shape()[1]; ++j) {
      matrix.tensor[i][j] = 1;
    }
  }

  cout << matrix.tensor[0][0] << '\n';

  return 0;
}
