#include <variant>
#include <iostream>

/**
 * ES.48: Avoid casts
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es48-avoid-casts
 */
 struct Point {
   int x = 0;
   int y = 0;
 };
 struct Line {
   Point start;
   Point end;
 };
int main() {
  std::variant<Point, Line> rep = Line();
  Line line = std::get<Line>(rep);
  std::cout << "From x " << line.start.x << " to x " << line.end.x;
}
