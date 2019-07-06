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

    matrix::matrix( const matrix &arrayToCopy )
        :array_size( arrayToCopy.array_size ) , size_row( arrayToCopy.size_row )
        ,size_column( arrayToCopy.size_column )
    {



        ptr = new int[ array_size ];



        for( int i = 0; i < array_size; ++i )
        {
            ptr[ i ] = arrayToCopy.ptr[ i ];

        }



    }


    int &matrix::operator ()( int x, int y )
    {
        if( x < 0 or y < 0 or ( x == 0 and y == 0 ) )
            throw out_of_range( "Subscript out of range" );

        return ptr[ x * size_row + y ];
    }

    const int &matrix::operator()( int x, int y ) const
    {

        if( x < 0 or y < 0 or ( x == 0 and y == 0 ) )
            throw out_of_range( "Subscript out of range" );

        return ptr[ x * size_row + y ];
    }

     ostream &operator<<(ostream &output, const matrix &a)
       {

            int k = 0;
            for( int i = 0; i < a.size_row; ++i)
            {
                for ( int j = 0; j < a.size_column; ++j)
                {
                    output << setw( 6 ) << a.ptr[ k ];
                    k++;

                }
                output << endl;
            }




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

    bool matrix::operator ==( const matrix &right ) const
    {
        if( array_size != right.array_size )
            return false;

        for( int i = 0; i < array_size; ++i )
            if( ptr[ i ] != right.ptr[ i ] )
                return false;
        return true;
    }

    bool matrix::operator !=( const matrix &right ) const
    {
        if( array_size == right.array_size )
        {
            return false;
        }

        for( int i = 0; i < array_size; ++i )
            if( ptr[ i ] != right.ptr[ i ] )
                return true;


        return true;
    }

