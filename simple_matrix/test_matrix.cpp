#include <serialize_matrix.hpp>
#include <boost/mpi/collectives.hpp>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/environment.hpp>
#include <iostream>

namespace mpi = boost::mpi;
using namespace std;

int main () {
  mpi::environment env;
  mpi::communicator world;

  int N = 100;

  Matrix a(boost::extents[N][N]);
  Matrix b(boost::extents[N][N]);
  Matrix c(boost::extents[N][N]);

  if (world.rank() == 0) {
    for (matrix_idx i = 0; i < N; ++i) {
      for (matrix_idx j = 0; j < N; ++j) {
        a[i][j] = 1;
        b[i][j] = 1;
        c[i][j] = 0;
      }
    }

    for (matrix_idx i = 0; i < N; i++) {
      for (matrix_idx j = 0; j < N; ++j) {
        c[i][j] = a[i][j] + b[i][j];
      }
    }
  }

  mpi::broadcast(world, c, 0);

  if (world.rank() == 1) {
    cout << c[0][0] << '\n';
  }

  return 0;
}
