#include <memory>

/**
 * R.11: Avoid calling new and delete explicitly
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rr-newdelete
 */

class Powers {};
class Audio {
  Powers p;
};

int main() {
  Audio stackHero;

  auto myHero = std::make_unique<Audio>();

  auto ourHero = std::make_shared<Audio>();
}