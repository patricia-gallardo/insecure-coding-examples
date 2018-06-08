class Spiderman {};
class Ironman {};

int main() {
  Spiderman * peter = new Spiderman;

  // Will give a build error:
  // Ironman * tony = static_cast<Ironman*>(peter);
}
