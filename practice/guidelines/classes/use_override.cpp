#include <iostream>

/**
 * C.128: Virtual functions should specify exactly one of virtual, override, or final
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c128-virtual-functions-should-specify-exactly-one-of-virtual-override-or-final
 */
struct Button {
  // ...
  virtual void onClick() { std::cout << "Button!"; }
};
struct SuperButton : public Button {
  // ...
  void onClick() override { std::cout << "Super!"; }
};
int main() {
  Button button;
  button.onClick();
  SuperButton superButton;
  superButton.onClick();
}
