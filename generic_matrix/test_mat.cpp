#include <serializable_tensor_n.hpp>
#include <boost/array.hpp>
#include <boost/mpi/collectives.hpp>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/environment.hpp>
#include <iostream>

using namespace std;
namespace mpi = boost::mpi;

int main () {
  mpi::environment env;
  mpi::communicator world;

  boost::serialization::SerializableTensorN<double, 2> matrix;
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
