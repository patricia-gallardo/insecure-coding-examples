#include <iostream>
#include <string>

using namespace std::literals::string_literals;

int main() {

  auto heroes = {"Spiderman"s, "Ironman"s, "Wonder Woman"s};

  for(auto const & hero : heroes) {
    std::cout << "\t" << hero << " (" << hero.size() << ")\n";
  }
}
