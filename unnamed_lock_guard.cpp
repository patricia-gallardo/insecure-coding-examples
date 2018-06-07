#include <mutex>

int global_important_thing = 0;
std::mutex global_mutex;  // protects g_i
int main() {
  std::lock_guard<std::mutex> lock(/*global_mutex*/);
  ++global_important_thing;
}