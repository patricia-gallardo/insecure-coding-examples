#include <algorithm>
#include <filesystem>
#include <string>

std::string After(const std::string& user_input_pathname,
                  const std::string& filename)
{
  using namespace std::filesystem;
  path actual_path = canonical(user_input_pathname);
  create_directories(actual_path);
  actual_path /= filename;
  return actual_path;
}