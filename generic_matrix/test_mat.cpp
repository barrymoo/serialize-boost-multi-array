#include <serializable_tensor_n.hpp>
#include <boost/mpi/collectives.hpp>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/environment.hpp>
#include <iostream>

typedef boost::serialization::SerializableTensorN<double, 2> Matrix;

namespace boost {
namespace serialization {
  template <class Archive>
  void serialize(Archive &ar, Matrix &mat, const unsigned int version) {
    for (auto i = 0; i < mat.tensor.num_elements(); ++i) {
      ar & mat.tensor.data()[i];
    }
  }
} // namespace boost
} // namespace serialization

using namespace std;
namespace mpi = boost::mpi;

int main () {
  mpi::environment env;
  mpi::communicator world;

  Matrix matrix;
  matrix.size(boost::extents[10][10]);

  if (world.rank() == 0) {
    for (auto i = 0; i < matrix.tensor.shape()[0]; ++i) {
      for (auto j = 0; j < matrix.tensor.shape()[1]; ++j) {
        matrix.tensor[i][j] = 1;
      }
    }
  }

  mpi::broadcast(world, matrix, 0);

  if (world.rank() == 1) {
    cout << matrix.tensor[0][0] << '\n';
  }

  return 0;
}
