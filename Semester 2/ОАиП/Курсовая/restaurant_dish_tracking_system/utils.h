#pragma once
#include<iostream>
#include<limits>

template<typename T>
void print(T data, char end = '\n') {
	std::cout << data << end;
}

inline void print() {
	std::cout << '\n';
}

inline void input(int& destination) {
	std::cin >> destination;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<int N>
void input(char(&destination)[N]) {
	std::cin.getline(destination, N);

	if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}
}