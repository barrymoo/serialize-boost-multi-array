#include <boost/array.hpp>
#include <boost/multi_array.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


namespace boost {
namespace serialization {

template <typename T, int N>
class SerializableTensorN
{
  public:
    typedef multi_array<T, N> tensorN;
    typedef const typename tensorN::index index;

    tensorN tensor;

    SerializableTensorN(){};
    void size(boost::detail::multi_array::extent_gen<N> dims) {
      tensor.resize(dims);
    }
};

template <class Archive, typename T, int N>
void serialize(Archive &ar, SerializableTensorN<T, N> &tensor, const unsigned int version) {
  ar & tensor.tensor;
}

} // namespace serialization
} // namespace boost
