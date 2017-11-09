#include <boost/array.hpp>
#include <boost/multi_array.hpp>

namespace boost {

template <typename T, int N>
class SerializableTensorN
{
  public:
    typedef multi_array<T, N> tensorN;
    typedef const typename tensorN::index index;

    tensorN tensor;

    SerializableTensorN(){};
    void resize(array<index, N> dims) {
      tensor.resize(dims);
    }
};

} // namespace boost
