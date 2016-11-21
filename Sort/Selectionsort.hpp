#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Sort.hpp"

/*

Selectionsort

Best-Case Perf:		O( n² )
Average Perf:		O( n² )
Worst-Case Perf:	O( n² )
Worst-Case Space:	O( n )

*/

template<typename T>
class Selectionsort : public SortBase<T>
{
public:
	Selectionsort( ) {}

	virtual wchar_t *GetName( )
	{
		return L"Selectionsort";
	}

private:
	virtual void DoSortAscending( T *pArray, int pLeft, int pRight )
	{
		for ( int i = pLeft; i < pRight; i++ )
		{
			int iSelection = i;

			for ( int j = i + 1; j <= pRight; ++j )
			{
				if ( pArray[j] < pArray[iSelection] )
					iSelection = j;
			}

			this->Swap( pArray, i, iSelection );
		}
	}

	virtual void DoSortDescending( T *pArray, int pLeft, int pRight )
	{
		for ( int i = pLeft; i < pRight; i++ )
		{
			int iSelection = i;

			for ( int j = i + 1; j <= pRight; ++j )
			{
				if ( pArray[j] > pArray[iSelection] )
					iSelection = j;
			}

			this->Swap( pArray, i, iSelection );
		}
	}
};

#endif
