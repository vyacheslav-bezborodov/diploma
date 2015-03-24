#ifndef MATRIX_MULTIPLIER
#define MATRIX_MULTIPLIER

#include "MatrixOperationPerformer.h"



class MatrixMultiplier : public MatrixOperationPerformer
{
public:

  template< typename T >
  void multiply( Matrix< T >& result, const Matrix< T >& lhs, const Matrix< T >& rhs )
  {
    assert( lhs.get_columns() == rhs.get_rows() );
    assert( result.get_rows() == lhs.get_rows() );
    assert( result.get_columns() == rhs.get_columns() );
    
    for( std::size_t iRow = 0; iRow < lhs.get_rows(); ++iRow ) {
      for( std::size_t jColumn = 0; jColumn < rhs.get_columns(); ++jColumn ) {
        T sum = 0.0;
        for( std::size_t kIndex = 0; kIndex < lhs.get_columns(); ++kIndex ) {
          sum += lhs( iRow, kIndex ) * rhs( kIndex, jColumn );
        }
        result( iRow, jColumn ) = sum;
      }
    }
  }
  
  
  
  template< typename T >
  void multiply( const T& value , Matrix< T >& rhs )
  {
    for( std::size_t iRow = 0; iRow < rhs.get_rows(); ++iRow ) {
      for( std::size_t jColumn = 0; jColumn < rhs.get_columns(); ++jColumn ) {
        rhs( iRow, jColumn ) *= value;
      }
    }
  }

};



#endif // MATRIX_MULTIPLIER