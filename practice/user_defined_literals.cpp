struct Pixels {
  unsigned long long num = 0;
};

struct Percent {
  unsigned long long num = 0;
};

Pixels operator"" _px(unsigned long long num) {
  return Pixels{ num };
}

Percent operator"" _percent(unsigned long long num) {
  return Percent{ num };
}

int main() {
  auto pixels = 24_px;
  auto percent = 7_percent;

  // Will give a build error:
  // auto width = pixels + percent;
}
