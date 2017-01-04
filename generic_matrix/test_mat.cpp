#include <serialize-ma.hpp>
#include <boost/array.hpp>

using namespace std;

int main () {
  typedef boost::serialization::ma_serialize<double, 2> matrix;
  matrix::tensor A(boost::extends[10][10]);
  return 0;
}
