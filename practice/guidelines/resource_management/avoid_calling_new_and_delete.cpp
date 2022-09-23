#include <memory>

/**
 * R.11: Avoid calling new and delete explicitly
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rr-newdelete
 */

class Powers {};
class Hero {
  Powers p;
};

int main() {
  Hero stackHero;

  auto myHero = std::make_unique<Hero>();

  auto ourHero = std::make_shared<Hero>();
}
