#include <serializable_tensor_n.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main () {
  SerializableTensorN<double, 2> matrix;
  typedef const typename SerializableTensorN<double, 2>::index index;
  boost::array<index, 2> dims = {{10l, 10l}};
  matrix.resize(dims);
  return 0;
}
