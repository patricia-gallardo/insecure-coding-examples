/**
 * ES.49: If you must use a cast, use a named cast
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es49-if-you-must-use-a-cast-use-a-named-cast
 */
class Spiderman {};
class Ironman {};

int main() {
  Spiderman * peter = new Spiderman;
  Ironman * tony1 = (Ironman*) peter;
  //Ironman * tony2 = static_cast<Ironman*>(peter); // Compile-time failure
  Ironman * tony3 = reinterpret_cast<Ironman*>(peter);
  //Ironman * tony4 = dynamic_cast<Ironman*>(peter); // Run-time failure
}
