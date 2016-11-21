#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "Sort.hpp"

/*

Heapsort

Best-Case Perf:		O( n * log( n ) )
Average Perf:		O( n * log( n ) )
Worst-Case Perf:	O( n * log( n ) )
Worst-Case Space:	O( n )

*/

/*

Credits to Timo Bingmann @ http://panthema.net/ for this one

*/

template<typename T>
class Heapsort : public SortBase<T>
{
public:
	Heapsort( ) {}

	virtual wchar_t *GetName( )
	{
		return L"Heapsort";
	}

private:
	virtual void DoSortAscending( T *pArray, int pLeft, int pRight )
	{
		size_t n = pRight - pLeft + 1;
		size_t i = n / 2;

		while ( true )
		{
			if ( i > pLeft )
			{
				i--;
			}
			else
			{
				n--;
				if ( n == pLeft )
					return;
				this->Swap( pArray, pLeft, n );
			}

			size_t parent = i;
			size_t child = i * 2 + 1;

			while ( child < n )
			{
				if ( child + 1 < n && pArray[child + 1] > pArray[child] )
				{
					child++;
				}
				if ( pArray[child] > pArray[parent] )
				{
					this->Swap( pArray, parent, child );
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

	}

	virtual void DoSortDescending( T *pArray, int pLeft, int pRight )
	{
		size_t n = pRight - pLeft + 1;
		size_t i = n / 2;

		while ( true )
		{
			if ( i > 0 )
			{
				i--;
			}
			else
			{
				n--;
				if ( n == 0 )
					return;
				this->Swap( pArray, 0, n );
			}

			size_t parent = i;
			size_t child = i * 2 + 1;

			while ( child < n )
			{
				if ( child + 1 < n && pArray[child + 1] < pArray[child] )
				{
					child++;
				}
				if ( pArray[child] < pArray[parent] )
				{
					this->Swap( pArray, parent, child );
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	}
};

#endif
