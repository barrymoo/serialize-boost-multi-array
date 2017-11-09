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
    void resize(detail::multi_array::extent_gen<N> dims) {
      tensor.resize(dims);
    }
};

} // namespace boost
