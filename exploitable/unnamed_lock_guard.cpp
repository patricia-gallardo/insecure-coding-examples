/**
 * http://clang.llvm.org/extra/clang-tidy/checks/bugprone-unused-raii.html
 */

#include <mutex>

int global_important_thing = 0;
std::mutex global_mutex;  // protects global_important_thing

int main() {
  std::lock_guard<std::mutex> /*lock*/{global_mutex};
  ++global_important_thing;
}