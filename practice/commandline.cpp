#include <iostream>

int main(int argc, char * argv[]) {

  std::string first = argv[1];
  std::string second;
  std::cin >> second;

  std::string buffer = first + second;
  std::cout << buffer << "\n";
}
