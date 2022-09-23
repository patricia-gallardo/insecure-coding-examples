#include <string>

int main(int argc, char * argv[]) {
  std::string str = argv[1];
  size_t pos = str.find_last_of(':');
  if (pos != std::string::npos)
    str.erase(pos + 1);
}
