#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;


class matrix
{

    friend ostream &operator<<( ostream &, const matrix & );
    friend istream &operator>>( istream &, matrix & );

        public:
            explicit matrix( int  , int  );
            int &operator ()( int , int );
            ~matrix();
            const matrix & operator = ( const matrix & );

            /*
            Array( const Array &);

             int getSize() const;

            bool operator ==( const Array &right ) const;
            int & operator []( int subscript );
            int operator[]( int subscript ) const;
            */
// function declaration :  return_type ClassName :: FunctionName(parameters);

        private:
            int size_row;
            int size_column;
            int array_size;
            int *ptr;
            int returnValue;
};

#endif // ARRAY_H
