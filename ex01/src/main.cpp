#include <iostream>
#include "./include/Serializer.hpp"

int main() {
  // Create a non-empty Data object
  Data data;
  data.x = 69;

  // Serialize and deserialize the Data object
  uintptr_t ptr_value = Serializer::serialize(&data);
  Data* deserialized_ptr = Serializer::deserialize(ptr_value);

  // Ensure that the deserialized pointer is equal to the original pointer
  if (deserialized_ptr == &data) {
    std::cout << "Deserialized pointer is equal to original pointer.\n";
  } else {
    std::cout << "Error: deserialized pointer is not equal to original pointer.\n";
  }

  return 0;
}
