#pragma once
#include <iostream>
#include <chrono>
class Timer {
public:

	Timer() {
		start = std::chrono::high_resolution_clock::now();
		isStarted = 1;
	}; 
	~Timer() {
		this->TimerStop();
	}
	void TimerStop();
	float GetDuration();

private:

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	bool isStarted = 0;
};

void Timer::TimerStop() {
	if (isStarted) {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "Duration: " << duration.count() << " seconds\n";
		isStarted = 0;
	}
};

float Timer::GetDuration() {
	return duration.count();
}