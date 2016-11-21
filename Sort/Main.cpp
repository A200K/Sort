#include <iostream>
#include <functional> 
#include <algorithm>  
#include <vector>
  
#include "Sort.hpp"
#include "Timer.h"

template<typename T>
void BenchmarkSort( SortBase<T> *pSort, int pLength )
{
	T *pArray = new T[pLength];
	for ( int i = 0; i < pLength; i++ )
		pArray[i] = rand( );

	wprintf_s( L"%ls\n", pSort->GetName( ) );

	Timer t;
	t.Start( );
	pSort->DoSort( pArray, SD_ASCENDING, 0, pLength - 1 );
	t.Stop( );
	wprintf_s( L"Ascending  (random):            %0.2fms\n", t.GetTimeElapsed( ) );

	t.Start( );
	pSort->DoSort( pArray, SD_ASCENDING, 0, pLength - 1 );
	t.Stop( );
	wprintf_s( L"Ascending  (presorted):         %0.2fms\n", t.GetTimeElapsed( ) );

	t.Start( );
	pSort->DoSort( pArray, SD_DESCENDING, 0, pLength - 1 );
	t.Stop( );
	wprintf_s( L"Descending (reverse presorted): %0.2fms\n\n", t.GetTimeElapsed( ) );

	delete[] pArray;
}

template<typename T>
void BenchmarkStdSort( int pLength )
{
	T *pArray = new T[pLength];
	for ( int i = 0; i < pLength; i++ )
		pArray[i] = rand( );

	std::vector<T> vec( pArray, pArray + pLength );

	wprintf_s( L"std::sort\n" );

	Timer t;
	t.Start( );
	std::sort( vec.begin( ), vec.end( ), std::less<T>( ) );
	t.Stop( );
	wprintf_s( L"Ascending  (random):            %0.2fms\n", t.GetTimeElapsed( ) );

	t.Start( );
	std::sort( vec.begin( ), vec.end( ), std::less<T>( ) );
	t.Stop( );
	wprintf_s( L"Ascending  (presorted):         %0.2fms\n", t.GetTimeElapsed( ) );

	t.Start( );
	std::sort( vec.begin( ), vec.end( ), std::greater<T>( ) );
	t.Stop( );
	wprintf_s( L"Ascending  (reverse presorted): %0.2fms\n\n", t.GetTimeElapsed( ) );

	delete[] pArray;
}

int wmain( int argc, wchar_t *argv[] )
{
	srand( GetTickCount( ) );

	// Benchmarking

	size_t entries = 30000;
	wprintf_s( L"Benchmark (%i entries):\n\n", entries );

	BenchmarkStdSort<int>( entries );
	BenchmarkSort<int>( new Quicksort<int>( ), entries );
	BenchmarkSort<int>( new Heapsort<int>( ), entries );
	BenchmarkSort<int>( new Mergesort<int>( ), entries );
	BenchmarkSort<int>( new Selectionsort<int>( ), entries );
	BenchmarkSort<int>( new Insertionsort<int>( ), entries );
	BenchmarkSort<int>( new Bubblesort<int>( ), entries );

	// String Sorting

	wprintf_s( L"String Sorting:\n\n" );
	std::vector<std::wstring> stringList =
	{
		std::wstring( L"Hello" ),
		std::wstring( L"Potato" ),
		std::wstring( L"Zebra" ),
		std::wstring( L"Zoo" ),
		std::wstring( L"Camel" ),
		std::wstring( L"42 LOL" ),
		std::wstring( L"Screen" ),
		std::wstring( L"Breakfast" )
	};

	SortBase<std::wstring> *pSortBase = new Quicksort<std::wstring>( );

	pSortBase->DoSort( stringList.data( ), SD_ASCENDING, 0, stringList.size( ) - 1 );

	wprintf_s( L"Ascending:\n" );
	for ( size_t i = 0; i < stringList.size( ); i++ )
		wprintf_s( L"%ls\n", stringList.at( i ).c_str( ) );
	wprintf_s( L"\n" );

	pSortBase->DoSort( stringList.data( ), SD_DESCENDING, 0, stringList.size( ) - 1 );

	wprintf_s( L"Descending:\n" );
	for ( size_t i = 0; i < stringList.size( ); i++ )
		wprintf_s( L"%ls\n", stringList.at( i ).c_str( ) );
	wprintf_s( L"\n" );

	std::cin.get( );

	return 0;
}