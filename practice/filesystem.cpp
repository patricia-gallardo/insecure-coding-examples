#include <filesystem>
#include <iostream>
#include <string>

std::string make_path(const std::string & user_input_pathname,
                      const std::string & filename) {
  std::filesystem::path actual_path = std::filesystem::canonical(user_input_pathname);
  std::filesystem::create_directories(actual_path);
  actual_path /= filename;
  return actual_path;
}

int main() {
  std::cout << make_path("/tmp", "test_me.txt");
}
