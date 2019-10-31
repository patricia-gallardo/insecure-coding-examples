#include <cassert>
#include <iostream>

/**
 * F.54: If you capture this, capture all variables explicitly (no default capture)
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f54-if-you-capture-this-capture-all-variables-explicitly-no-default-capture
 */
class Prefixer {
public:
  auto printer() {
    return [*this](std::string suffix) {
      std::cout << prefix << " " << suffix << "!\n";
    };
  }
  const std::string prefix = "Greetings,";
};

int main() {
  Prefixer prefixer;
  auto print = prefixer.printer();
  print("Mortals");
}