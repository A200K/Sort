#include "Timer.h"

Timer::Timer( )
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency( &freq );
	this->m_Frequency = ( double )( freq.QuadPart ) / 1000.0F;
}

void Timer::Start( )
{
	QueryPerformanceCounter( &this->m_Start );
}

void Timer::Stop( )
{
	QueryPerformanceCounter( &this->m_End );
}

double Timer::GetTimeElapsed( )
{
	return ( double )( this->m_End.QuadPart - this->m_Start.QuadPart ) / this->m_Frequency;
}