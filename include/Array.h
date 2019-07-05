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
            matrix( const matrix & );

            ~matrix();
            int &operator ()( int , int );
            const int & operator()( int, int ) const;
            const matrix & operator = ( const matrix & );
            bool operator ==( const matrix & ) const;
            bool operator !=( const matrix & ) const;

        private:
            int size_row;
            int size_column;
            int array_size;
            int *ptr;

};

#endif // ARRAY_H
