#ifndef TIMER_H
#define TIMER_H

#include <windows.h>

class Timer
{
public:
	Timer( );

	void Start( );
	void Stop( );
	double GetTimeElapsed( );

private:
	LARGE_INTEGER m_Start;
	LARGE_INTEGER m_End;
	double m_Frequency;
};

#endif