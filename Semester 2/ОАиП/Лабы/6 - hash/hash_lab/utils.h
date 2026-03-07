#pragma once
#include<iostream>

template<typename T>
void print(T data, char end = '\n') {
	std::cout << data << end;
}

void print() {
	std::cout << '\n';
}

void input(int& destination) {
	std::cin >> destination;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
}

template<int N>
void input(char (& destination)[N]) {
	std::cin.getline(destination, N);

	if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}
}