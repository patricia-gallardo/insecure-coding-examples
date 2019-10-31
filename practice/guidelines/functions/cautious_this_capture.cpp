#include <cassert>

/**
 * F.54: If you capture this, capture all variables explicitly (no default capture)
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f54-if-you-capture-this-capture-all-variables-explicitly-no-default-capture
 */
class Audio {
public:
  void increaseVolume(int increase) {
    auto adjust = [increase, this]() { return volume + increase; };
    volume = adjust();
  }

  int volume = 0;
};

int main() {
  Audio h;
  assert(h.volume == 0);
  h.increaseVolume(4);
  assert(h.volume == 4);
}