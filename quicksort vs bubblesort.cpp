#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

//porownianie algorytmow sortujacych :)

void bubble_sort(int *t, int size)
{
    for( int i = 0; i < size; i++ )
    {
        for( int j = 0; j < size - 1; j++ )
        {
            if( t[ j ] > t[ j + 1 ] )
            {
                swap( t[ j ], t[ j + 1 ] );
            }
        }
    }
}

void quick_sort(int *t, int p, int q)
{
    int i = p;
    int j = q;
    int x = t[( p + q ) / 2 ];
    do
    {
        while( t[ i ] < x )
             i++;
       
        while( t[ j ] > x )
             j--;
       
        if( i <= j )
        {
            swap( t[ i ], t[ j ] );
           
            i++;
            j--;
        }
    } while( i <= j );
   
    if( p < j ) 
    {
        quick_sort( t, q, j );
    }

    if( q > i ) 
    {
        quick_sort( t, i, q );
    }
}

int main()
{
    cout << "+--------------------------------------------------------------+" << endl 
         << "|                                                              |" << endl
         << "|     Porownianie czasu wykonywania algorytmow sortujacych     |" << endl
         << "|                                                              |" << endl
         << "+--------------------------------------------------------------+" << endl;

    int n; 
    int *t;
    int *y;
    double duration;
    clock_t start, stop;
    cout << "Dla ilu liczb ma byc wykonane sortowanie?" << endl;
    cin>>n;
    t = new int[n];
    y = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        t[ i ] = rand()%100000;
        //cout << t [ i ] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        t [ i ] = y [ i ]; 
    }

    cout << "Sortowanie babelkowe trwa..." << endl;

    start = clock();
    bubble_sort(t, n);
    stop = clock();

    duration = ( double )( stop - start ) / CLOCKS_PER_SEC;
    cout << "Czas trwania sortowani babelkowego dla " << n << " liczb wynosi: " << duration << " s" << endl;

    cout << "------------------------------------------------------------" << endl;
    duration = 0;

    cout << "Sortowanie quick sort trwa..." << endl;

    start = clock();
    quick_sort(y, 0, n-1);
    stop = clock();
    
    duration = ( double )( stop - start ) / CLOCKS_PER_SEC;
    cout << "Czas trwania sortowania quick sort dla " << n << " liczb wynosi: " << duration << " s" << endl;

    delete[] t;
    delete[] y;
    return 0;
}