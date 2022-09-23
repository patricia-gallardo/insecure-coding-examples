/**
 * ES.49: If you must use a cast, use a named cast
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es49-if-you-must-use-a-cast-use-a-named-cast
 */
struct Hero {
  virtual ~Hero() = default;
};
class Spiderman : public Hero {};
class Ironman {};

int main() {
  Spiderman * peter = new Spiderman;
  Ironman * tony1 = (Ironman *)peter;
  // Compile-time failure
  // Ironman * tony2 = static_cast<Ironman *>(peter);
  Ironman * tony3 = reinterpret_cast<Ironman *>(peter);
  // Run-time failure
  Ironman * tony4 = dynamic_cast<Ironman *>(peter);
}
