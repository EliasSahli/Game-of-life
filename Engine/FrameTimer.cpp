#include "FrameTimer.h"
using namespace std::chrono;

FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

float FrameTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> FrameTime = last - old;
	return FrameTime.count();
}
