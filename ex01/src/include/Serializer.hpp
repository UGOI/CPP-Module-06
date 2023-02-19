#pragma once
#include <cstdint>

class Data {
public:
  int x;
};

class Serializer {
public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};
