#include <boost/multi_array.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

typedef boost::multi_array<double, 2> Matrix;
typedef Matrix::index matrix_idx;

namespace boost {
namespace serialization {
    
template <class Archive>
void serialize(Archive &ar, Matrix &mat, const unsigned int version)
{
  for (matrix_idx i = 0; i < mat.shape()[0]; ++i){
    for (matrix_idx j = 0; j < mat.shape()[1]; ++j){
      ar & mat[i][j];
    }
  }
} 

} // namespace serialization
} // namespace boost
