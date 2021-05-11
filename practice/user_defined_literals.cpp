struct Hours {
  unsigned long long num = 0;
};

struct Days {
  unsigned long long num = 0;
};

Hours operator "" _hours(unsigned long long num) {
  return Hours{num};
}

Days operator "" _days(unsigned long long num) {
  return Days{num};
}

int main() {
  auto h = 24_hours;
  auto d = 7_days;

  // Will give a build error:
  // auto err = h + d;
}
