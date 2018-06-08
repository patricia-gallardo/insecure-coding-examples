#include <algorithm>
#include <iterator>

using namespace std;

int main() {

  string str = "Hello World";

  auto isColon = [](int ch) { return ch == ':'; };

  auto first = find_if(rbegin(str), rend(str), isColon);

  str.erase(first.base(), end(str));
}
