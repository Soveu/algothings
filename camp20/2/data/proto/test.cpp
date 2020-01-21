#include <iostream>
#include <array>
#include <cassert>
#include <stdint.h>

int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//int sumsInMonths[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int sumInMonths[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

using DateString = std::array<char, 20>;

constexpr int64_t chartoi(char c) {
  if(c >= '0' && c <= '9') {
    return c - '0';
  }

  std::cerr << "failing with c='" << c << "', code=" << static_cast<int>(c) << '\n';
  exit(1);
}
constexpr int64_t stringtoi(const char* cp, const size_t len) {
  int64_t result = 0;
  int64_t multiplier = 1;

  for(int i=1; i<=len; ++i) {
    result += (chartoi(cp[len - i]) * multiplier);
    multiplier *= 10;
  }

  return result;
}

int leap_years(int64_t yearA, int64_t yearB) {
  if(yearA % 4 != 0) {
    yearA += 4;
    yearA -= (yearA % 4);
  }
  yearB -= (yearB % 4);
  return 1 + (std::abs(yearB - yearA) / 4);
}

/* "YYYY-MM-DD HH-MM-SS" */
/* Epoch = "1900-01-01 00:00:00" */
uint64_t date_to_seconds(const DateString& ds) {
  uint64_t result = 0;

  int64_t second = stringtoi(&ds[17], 2);
  int64_t minute = stringtoi(&ds[14], 2);
  int64_t hour   = stringtoi(&ds[11], 2);
  int64_t day    = stringtoi(&ds[8] , 2);
  int64_t month  = stringtoi(&ds[5] , 2);
  int64_t year   = stringtoi(&ds[0] , 4);

  std::cout << year << ' ' << 
    month << ' ' << 
    day << ' ' << 
    hour << ' ' <<
    minute << ' ' <<
    second << '\n';

  day += leap_years(1900, year); 
  if(year % 4 == 0 && month < 3) {
    day -= 1;
  }

  year -= 1900;
  month -= 1;
  day += sumInMonths[month];
  day -= 1;

  result += year;
  result *= 365;
  result += day;
  result *= 24;
  result += hour;
  result *= 60;
  result += minute;
  result *= 60;
  result += second;

  return result;
}

void seconds_to_answer(uint64_t begin, uint64_t end, std::ostream& out) {
  uint64_t ans = end - begin;
  uint64_t seconds = ans % 60; ans /= 60;
  uint64_t minutes = ans % 60; ans /= 60;
  uint64_t hours = ans % 24;   ans /= 24;
  uint64_t days = ans;

  if(days != 0) {
    out << days << " dni ";
  }
  if(hours != 0) {
    out << hours << " godzin ";
  }
  if(minutes != 0) {
    out << minutes << " minut ";
  }
  if(seconds != 0) {
    out << seconds << " sekund ";
  }
  out << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  
  std::cout << stringtoi("100", 3) << '\n';

  return 0;
}

