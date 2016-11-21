#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sort.hpp"

/*

Insertionsort

Best-Case Perf:		O( n )
Average Perf:		O( n² )
Worst-Case Perf:	O( n² )
Worst-Case Space:	O( n )

*/

template<typename T>
class Insertionsort : public SortBase<T>
{
public:
	Insertionsort( ) {}

	virtual wchar_t *GetName( )
	{
		return L"Insertionsort";
	}

private:
	virtual void DoSortAscending( T *pArray, int pLeft, int pRight )
	{
		for ( int i = pLeft; i <= pRight; i++ )
		{
			int j = i;
			while ( j > 0 && pArray[j] < pArray[j - 1] )
			{
				this->Swap( pArray, j, j - 1 );
				--j;
			}
		}
	}

	virtual void DoSortDescending( T *pArray, int pLeft, int pRight )
	{
		for ( int i = pLeft; i <= pRight; i++ )
		{
			int j = i;
			while ( j > 0 && pArray[j] > pArray[j - 1] )
			{
				this->Swap( pArray, j, j - 1 );
				--j;
			}
		}
	}
};

#endif
