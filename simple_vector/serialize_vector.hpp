#include <boost/multi_array.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

typedef boost::multi_array<double, 1> Vector;
typedef Vector::index vector_idx;

namespace boost {
namespace serialization {
    
template <class Archive>
void serialize(Archive &ar, Vector &vec, const unsigned int version)
{
  for (vector_idx i = 0; i < vec.shape()[0]; ++i){
    ar & vec[i];
  }
} 

} // namespace serialization
} // namespace boost
