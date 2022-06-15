#pragma once
#include <iostream>
#include <chrono>
class Timer {
public:
	Timer() {
		start = std::chrono::high_resolution_clock::now();
		isStarted = 1;
	};
	void TimerStop() {
		if (isStarted) {
			end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> duration = end - start;
			std::cout << "Duration: " << duration.count() << " seconds\n";
			isStarted = 0;
		}
	};
	~Timer() {
		this->TimerStop();
	}

private:

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	bool isStarted = 0;
};