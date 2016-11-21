#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.hpp"

/*

Bubblesort

Best-Case Perf:		O( n² ) ( n for optimized version )
Average Perf:		O( n² )
Worst-Case Perf:	O( n² )
Worst-Case Space:	O( n )

*/

template<typename T>
class Bubblesort : public SortBase<T>
{
public:
	Bubblesort( ) {}

	virtual wchar_t *GetName( )
	{
		return L"Bubblesort";
	}

private:
	virtual void DoSortAscending( T *pArray, int pLeft, int pRight )
	{
		for ( int i = ( pRight - pLeft + 1 ); i > 1; i-- )
		{
			for ( int j = 0; j < ( i - 1 ); j++ )
			{
				if ( pArray[j] > pArray[j + 1] )
					this->Swap( pArray, j, j + 1 );
			}
		}
	}

	virtual void DoSortDescending( T *pArray, int pLeft, int pRight )
	{
		for ( int i = ( pRight - pLeft + 1 ); i > 1; i-- )
		{
			for ( int j = 0; j < ( i - 1 ); j++ )
			{
				if ( pArray[j] < pArray[j + 1] )
					this->Swap( pArray, j, j + 1 );
			}
		}
	}
};

#endif
