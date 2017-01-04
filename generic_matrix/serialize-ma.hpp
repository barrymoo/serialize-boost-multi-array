#include <boost/multi_array.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string>

namespace boost {
namespace serialization {

template <typename T, int N>
struct ma_serialize
{
  typedef multi_array<T, N> tensor;
  typedef typename tensor::index idx;

  template <class Archive>
  void serialize(Archive &ar, tensor &tensor, const unsigned int version)
  {
    for (auto i: tensor.shape()) {
      for (idx j = 0; j < i; ++j) {
        ar & tensor[i][j];
      }
    }
  } 
};


} // namespace serialization
} // namespace boost
