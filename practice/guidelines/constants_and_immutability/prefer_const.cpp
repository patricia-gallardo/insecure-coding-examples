/**
 * Con.2: By default, make member functions const
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con2-by-default-make-member-functions-const
 */
class Point {
  int _x = 0;
  int _y = 0;

public:
  int x() const { return _x; }
  int y() const { return _y; }
  [[nodiscard]] bool is_valid() const {
    return (_x > 0) && (_y > 0);
  }
};

int main() {
  Point point;
  point.is_valid(); // warning: ignoring return value
}