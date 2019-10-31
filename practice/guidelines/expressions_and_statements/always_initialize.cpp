/**
 * ES.20: Always initialize an object
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es20-always-initialize-an-object
 */
class Point {
  int x = 0; // default member initialization
  int y = 0;
public:
  Point(int x, int y) : x(x), y(y) {} // member initializer list
};

int main() {
  // auto requires initialization
  auto x_coord = 42;
  auto y_coord = 42;
  auto point = Point(x_coord, y_coord);
}