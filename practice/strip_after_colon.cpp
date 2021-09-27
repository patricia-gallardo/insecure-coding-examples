#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
  string str = "Hello World";
  // Predicate
  auto isColon = [](int ch) { return ch == ':'; };
  // The last element satisfying the predicate or the first element if not found
  // Searching from the end backwards
  auto first = find_if(rbegin(str), rend(str), isColon);

  cout << str << "\n";

  // If found - delete everything after
  if (first != rend(str))
    str.erase(first.base(), end(str));

  cout << str << "\n";
}
