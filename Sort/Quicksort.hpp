#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.hpp"

/*

Quicksort

Best-Case Perf:		O( n * log( n ) )
Average Perf:		O( n * log( n ) )
Worst-Case Perf:	O( n² )
Worst-Case Space:	O( n )

*/

template<typename T>
class Quicksort : public SortBase<T>
{
public:
	Quicksort( ) {}

	virtual wchar_t *GetName( )
	{
		return L"Quicksort";
	}

private:

	// Causing a stack overflow for huge arrays due to recursion
	// My iterative implementation is slow af though, wtf.

	virtual void DoSortAscending( T *pArray, int pLeft, int pRight )
	{
		if ( pLeft >= pRight )
			return;

		int i = pLeft;
		int j = pRight - 1;
		T pivot = pArray[pRight];

		while ( i <= j )
		{
			while ( pArray[i] < pivot ) ++i;
			while ( j >= 0 && pArray[j] >= pivot ) --j;

			if ( i <= j )
				this->Swap( pArray, i++, j-- );
			//	else
			//		break;
		}

		this->Swap( pArray, pRight, i );

		DoSortAscending( pArray, pLeft, i - 1 );
		DoSortAscending( pArray, i + 1, pRight );
	}

	virtual void DoSortDescending( T *pArray, int pLeft, int pRight )
	{
		if ( pLeft >= pRight )
			return;

		int i = pLeft;
		int j = pRight - 1;
		T pivot = pArray[pRight];

		while ( i <= j )
		{
			while ( pArray[i] > pivot ) ++i;
			while ( j >= 0 && pArray[j] < pivot ) --j;

			if ( i <= j )
				this->Swap( pArray, i++, j-- );
			else
				break;
		}

		this->Swap( pArray, pRight, i );

		DoSortDescending( pArray, pLeft, i - 1 );
		DoSortDescending( pArray, i + 1, pRight );
	}
};

#endif
