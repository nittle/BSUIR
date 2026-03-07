#pragma once
#include<iostream>
inline void print() {
    std::cout << '\n';
}

template <typename T>
void print(T str, char end='\n') {
    std::cout << str << end;
}