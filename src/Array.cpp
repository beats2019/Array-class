#include "Array.h"
#include <iomanip>
#include <iostream>
using namespace std;

    matrix::matrix( int x , int y )
    {
        if( x >= 0 and y >= 0 )
        {
            if( x == 0 and y == 0 )
              throw invalid_argument( "Matrix size must exist" );
            else // x and y are valid
            {
               size_row = x;
               size_column = y;
               array_size = size_row * size_column;
               ptr = new int[ array_size ];

            }
        }
        else
            throw invalid_argument( "Matrix size must be a natural number" );

        for( int i = 0; i < array_size; ++i )
            ptr[ i ] = 0;

    }

    int &matrix::operator ()( int x, int y )
    {
        int temporal[ size_row ][ size_column ];
        int k = 0;

        for( int i = 0; i < size_row; ++i )
            for( int j = 0; j < size_column; ++j )
            {
                temporal[ i ][ j ] = ptr[ k ];
                k++;
            }

        returnValue = temporal[ x ][ y ];



        return returnValue;
    }

     ostream &operator<<(ostream &output, const matrix &a)
       {


          int i;


          for (i = 0; i < a.array_size; ++i)
          {
            output << setw(12) << a.ptr[i];

            if ((i + 1) % a.size_column == 0)
              output << endl;
          } // end for

          if (i % a.size_column != 0)
            output << endl;

          return output;
    }

    istream &operator>>( istream & input, matrix &a )
    {
        int k = 0;
        for( int i = 0; i < a.size_row; ++i)
		{
			for ( int j = 0; j < a.size_column; ++j)
			{
			    cout << "Insert value for position [ " << i << " ][ "
			    << j << " ] : ";
				input >> a.ptr[ k ];
				k++;
			}
		}


        return input;

    }

    matrix::~matrix()
    {
        delete [] ptr;
    }

    const matrix &matrix:: operator = ( const matrix &right )
    {
        if( &right != this )// avoid self-assignment
        {

            if(array_size != right.array_size)
            {
                delete [] ptr;
                array_size = right.array_size;
                ptr = new int[ array_size ];
            }

            for( int i = 0; i < array_size; ++i )
                ptr[ i ] = right.ptr[ i ];

        }
        return *this; //Allows x = y = z
    }




/*
    Array::Array( const Array &arrayToCopy )
        :size( arrayToCopy.size )
    {
        ptr = new int[ size ];

        for( int i = 0; i < size; ++i )
        {
            ptr[ i ] = arrayToCopy.ptr[ i ];
        }

    }



    int Array::getSize() const
    {
        return this->size;
    }
// const Array& Array::operator = ( const Array &right );


    bool Array::operator ==( const Array &right ) const
    {
        if( size != right.size )
            return false;

        for( int i = 0; i < size; ++i )
            if( ptr[ i ] != right.ptr[ i ] )
                return false;
        return true;
    }

    // reference return creates a modifiable lvalue
    int &Array::operator []( int subscript )
    {
        cout << "Now in type 1" << endl;
        if( subscript < 0 or subscript >= size )
            throw out_of_range("Subscript out of range");

        return ptr[ subscript ]; //reference return

    }

    int Array::operator[]( int subscript ) const
    {
        cout << "Now in type 2" << endl;
        if( subscript < 0 or subscript >= size )
            throw out_of_range("Subscript out of range");

        return ptr[ subscript ]; // value return
    }







*/
