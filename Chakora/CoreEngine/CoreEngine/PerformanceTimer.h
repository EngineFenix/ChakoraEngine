
#ifndef PERFORMANCE_TIMER_H
#define PERFORMANCE_TIMER_H

#pragma once

#ifdef _WIN32
	#include <windows.h>	// Windows
#elif __APPLE__
  #include <sys/time.h>	// Mac/Unix
#elif __linux
	#include <sys/time.h>
	#include <cstddef>		// Linux
#endif

/** Performance_Timer.h
 * A cross-platform timer wrapped around a high performance Windows/Unix time function.
 *
 * Authors: Paul Solt 8-21-10
 */

namespace CoreEngine {
	class PerformanceTimer
	{
	public:
		PerformanceTimer();
		~PerformanceTimer();

		/** Starts the timer */
		void start();

		/** Stops the timer */
		void stop();

		/** Checks to see if the timer is stopped */
		bool isStopped() const;

		/** Returns the elapsed time since the timer was started, or the time interval
		 between calls to start() and stop().
		 */
		double getElapsedMicroseconds();
		double getElapsedMilliseconds();
		double getElapsedSeconds();

	private:
		bool _isStopped;

	#ifdef WIN32
		LARGE_INTEGER _start;
		LARGE_INTEGER _end;
		LARGE_INTEGER _freq;
	#else
		timeval _start;
		timeval _end;
	#endif

	};
}	// namespace

#endif
