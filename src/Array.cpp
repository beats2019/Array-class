#include "Array.h"
#include <iomanip>
#include <iostream>
using namespace std;

    Array::Array( int arraySize )
    {
        if( arraySize > 0 )
            size = arraySize;
        else
            throw invalid_argument("Array size must be greater than 0");

        ptr = new int[ size ];

        for( int i = 0; i < size; ++i )
        {
            ptr[ i ] = 0;
        }


    }

    Array::Array( const Array &arrayToCopy )
        :size( arrayToCopy.size )
    {
        ptr = new int[ size ];

        for( int i = 0; i < size; ++i )
        {
            ptr[ i ] = arrayToCopy.ptr[ i ];
        }

    }

    Array::~Array()
    {
        delete [] ptr;
    }

    int Array::getSize() const
    {
        return this->size;
    }
// const Array& Array::operator = ( const Array &right );
    const Array &Array:: operator = ( const Array &right )
    {
        if( &right != this )
        {
            /*
                For Arrays of different sizes, the
                left side Array will get the right
                side size
            */
            if(size != right.size)
            {
                delete [] ptr;
                size = right.size;
                ptr = new int[ size ];
            }

            for( int i = 0; i < size; ++i )
                ptr[ i ] = right.ptr[ i ];

        }
        return *this; //Allows x = y = z
    }

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


    istream &operator>>( istream & input, Array &a )
    {
        for( int i = 0; i < a.size; ++i )
            input >> a.ptr[ i ];

        return input;

    }


    ostream &operator<<(ostream &output, const Array &a)
     {
          int i;


          for (i = 0; i < a.size; ++i) {
            output << setw(12) << a.ptr[i]; // What does this do???

            if ((i + 1) % 4 == 0)
              output << endl;
          } // end for

          if (i % 4 != 0)
            output << endl;

          return output;
    }

