#include "core.h"
#include "constants.h"
#include <cstdio>
#include <fstream>

void createNewFile() {
  std::fstream str(FILENAME,
                   std::ios::out | std::ios::binary | std::ios::trunc);
  if (!str.is_open())
    return;
  str.close();
}

DishData readFromFile(int index, const char* filename) {
  std::fstream str(filename, std::ios::in | std::ios::binary);
  DishData data{};

  if (!str.is_open())
    return data;

  str.seekg(index * sizeof(DishData), std::ios::beg);
  str.read(reinterpret_cast<char *>(&data), sizeof(DishData));

  return data;
}

int getRecordCount(const char* filename) {
  std::fstream str(filename, std::ios::in | std::ios::binary);
  if (!str.is_open())
    return 0;

  str.seekg(0, std::ios::end);
  return str.tellg() / sizeof(DishData);
}

void appendToFile(const DishData& data) {
  std::fstream str(FILENAME, std::ios::app | std::ios::binary);
  str.write(reinterpret_cast<const char *>(&data), sizeof(DishData));
}

void removeFromFile(int index) {
  std::fstream str(FILENAME, std::ios::in | std::ios::binary);
  if (!str.is_open())
    return;

  std::fstream tempStr(TEMP_FILENAME,
                       std::ios::out | std::ios::binary | std::ios::trunc);
  if (!tempStr.is_open()) {
    str.close();
    return;
  }

  DishData data;
  int currentIndex = 0;

  while (str.read(reinterpret_cast<char *>(&data), sizeof(DishData))) {
    if (currentIndex != index) {
      tempStr.write(reinterpret_cast<const char *>(&data), sizeof(DishData));
    }
    currentIndex++;
  }

  str.close();
  tempStr.close();

  std::remove(FILENAME);
  std::rename(TEMP_FILENAME, FILENAME);
}