#ifndef SORT_H
#define SORT_H

enum SortDirection
{
	SD_ASCENDING = 0,
	SD_DESCENDING
};

// Sort Base

template<typename T>
class SortBase
{
public:
	SortBase( )
	{

	}

	virtual wchar_t *GetName( ) = 0;

	bool IsSorted( T *pArray, SortDirection pDirection, int pLeft, int pRight )
	{
		switch ( pDirection )
		{
		case SD_ASCENDING:
			for ( int i = pLeft; i < pRight; i++ )
			{
				if ( pArray[i] > pArray[i + 1] )
					return false;
			}
			return true;
		case SD_DESCENDING:
			for ( int i = pLeft; i < pRight; i++ )
			{
				if ( pArray[i] < pArray[i + 1] )
					return false;
			}
			return true;
		default:
			throw 1;
		}
	}

	void DoSort( T *pArray, SortDirection pDirection, int pLeft, int pRight )
	{
		switch ( pDirection )
		{
		case SD_ASCENDING:
			this->DoSortAscending( pArray, pLeft, pRight );
			break;
		case SD_DESCENDING:
			this->DoSortDescending( pArray, pLeft, pRight );
			break;
		default:
			throw 1;
		}
	}

protected:
	void Swap( T *pArray, int pIndex1, int pIndex2 )
	{
		T tmp = pArray[pIndex1];
		pArray[pIndex1] = pArray[pIndex2];
		pArray[pIndex2] = tmp;
	}

	virtual void DoSortAscending( T *pArray, int pLeft, int pRight ) = 0;
	virtual void DoSortDescending( T *pArray, int pLeft, int pRight ) = 0;
};

// Methods

#include "Bubblesort.hpp"
#include "Heapsort.hpp"
#include "Insertionsort.hpp"
#include "Mergesort.hpp"
#include "Selectionsort.hpp"
#include "Quicksort.hpp"

#endif