#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const size_t x_length = 5;
static const size_t y_length = 5;

static bool existMother(const char &c) // overload
{
  return c =='a' || c =='i' || c =='u' || c =='e' || c =='o'
      || c =='A' || c =='I' || c =='U' || c =='E' || c =='O';
}

static bool existMother(const string &line)
{
  bool result = false;
  for (size_t i = 0; i < line.size(); ++i) result |= existMother(line[i]);
  return result;
}

static vector<string> input()
{
  vector<string> lines(x_length);
  for (size_t i = 0; i < y_length; ++i)
    getline(std::cin, lines[i]);
  return lines;
}

int main()
{
  vector<string> lines = input();

  for (size_t i = 0; i < y_length; ++i) {
    if (existMother(lines[i]))
      transform(lines[i].begin(), lines[i].end(), lines[i].begin(), ::toupper);
    else
      transform(lines[i].begin(), lines[i].end(), lines[i].begin(), ::tolower);
  }

  for (size_t i = 0; i < y_length; ++i) cout << lines[i] << endl;
}
