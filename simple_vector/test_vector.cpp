#include <serialize_vector.hpp>
#include <boost/mpi/collectives.hpp>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/environment.hpp>

namespace mpi = boost::mpi;
using namespace std;

int main () {
  mpi::environment env;
  mpi::communicator world;

  int N = 1000;

  Vector a(boost::extents[N]);
  Vector b(boost::extents[N]);
  Vector c(boost::extents[N]);

  if (world.rank() == 0) {
    for (vector_idx i = 0; i < N; i++) {
      a[i] = 1;
      b[i] = 1;
      c[i] = 0;
    }

    for (vector_idx i = 0; i < N; i++) {
      c[i] = a[i] + b[i];
    }
  }

  mpi::broadcast(world, c, 0);

  if (world.rank() == 1) {
    cout << c[0] << '\n';
  }

  return 0;
}
