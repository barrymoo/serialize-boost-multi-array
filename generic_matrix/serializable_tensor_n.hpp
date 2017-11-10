#include <boost/multi_array.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


namespace boost {
namespace serialization {

template <typename T, int N>
class SerializableTensorN
{
  private:
    friend class access;

  public:
    typedef multi_array<T, N> tensorN;
    typedef const typename tensorN::index index;

    tensorN tensor;

    SerializableTensorN(){};
    void size(boost::detail::multi_array::extent_gen<N> dims) {
      tensor.resize(dims);
    }
};

} // namespace serialization
} // namespace boost
