#include <mutex>

/**
 * R.1: Manage resources automatically using resource handles and RAII (Resource Acquisition Is Initialization)
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r1-manage-resources-automatically-using-resource-handles-and-raii-resource-acquisition-is-initialization
 */

int global_counter = 0;
std::mutex global_mutex;

int main() {
  // Small critical section
  {
    std::lock_guard<std::mutex> lock(global_mutex);
    global_counter++;
  } // Mutex is released
}