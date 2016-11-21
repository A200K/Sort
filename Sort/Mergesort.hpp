#ifndef MERGESORT_H
#define MERGESORT_H

#include "Sort.hpp"

/*

Mergesort

Best-Case Perf:		O( n * log( n ) )
Average Perf:		O( n * log( n ) )
Worst-Case Perf:	O( n * log( n ) )
Worst-Case Space:	O( n )

*/

template<typename T>
class Mergesort : public SortBase<T>
{
public:
	Mergesort( ) {}

	virtual wchar_t *GetName( )
	{
		return L"Mergesort";
	}

private:
	virtual void DoSortAscending( T *pArray, int pLeft, int pRight )
	{
		if ( pLeft >= pRight )
			return;

		int split = ( pLeft + pRight ) / 2;
		DoSortAscending( pArray, pLeft, split );
		DoSortAscending( pArray, split + 1, pRight );

		int i = pLeft;
		int j = split + 1;
		int k = 0;
		T *tmp = new T[pRight - pLeft + 1];
		memset( tmp, 0, sizeof( T ) * ( pRight - pLeft + 1 ) );

		while ( i <= split || j <= pRight )
		{
			if ( j > pRight )
				tmp[k++] = pArray[i++];
			else if ( i > split )
				tmp[k++] = pArray[j++];
			else if ( pArray[i] < pArray[j] )
				tmp[k++] = pArray[i++];
			else
				tmp[k++] = pArray[j++];
		}
		for ( int i = 0; i < pRight - pLeft + 1; i++ )
			pArray[pLeft + i] = tmp[i];

		delete[] tmp;
	}

	virtual void DoSortDescending( T *pArray, int pLeft, int pRight )
	{
		if ( pLeft >= pRight )
			return;

		int split = ( pLeft + pRight ) / 2;
		DoSortDescending( pArray, pLeft, split );
		DoSortDescending( pArray, split + 1, pRight );

		int i = pLeft;
		int j = split + 1;
		int k = 0;
		T *tmp = new T[pRight - pLeft + 1];
		memset( tmp, 0, sizeof( T ) * ( pRight - pLeft + 1 ) );

		while ( i <= split || j <= pRight )
		{
			if ( j > pRight )
				tmp[k++] = pArray[i++];
			else if ( i > split )
				tmp[k++] = pArray[j++];
			else if ( pArray[i] > pArray[j] )
				tmp[k++] = pArray[i++];
			else
				tmp[k++] = pArray[j++];
		}
		for ( int i = 0; i < pRight - pLeft + 1; i++ )
			pArray[pLeft + i] = tmp[i];

		delete[] tmp;
	}
};

#endif
