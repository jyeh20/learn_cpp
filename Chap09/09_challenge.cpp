#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <iomanip>

constexpr const char* filename = "./items.txt";
constexpr char tab_char = '\t';
constexpr size_t maxsize = 1024;
constexpr size_t buffer_size = 128;

struct Item {
  int sku;
  std::string name;
  std::string desc;
};

std::vector<std::string> parse_string(const char* string, size_t string_len) {
  std::vector<std::string> parsed_string;
  std::string current_string = "";

  for (int i = 0; i < string_len; ++i) {
    char c = string[i];
    if (c == tab_char) {
      parsed_string.push_back(current_string);
      current_string = "";
      if (parsed_string.size() >= 3) {
        puts("breaking");
        break;
      }
      continue;
    }
    current_string += c;
  }
  parsed_string.push_back(current_string);
  return parsed_string;
};

int main() {
  static char buffer[buffer_size];
  std::ifstream input(filename);

  while(input.good()) {
    input.getline(buffer, sizeof(buffer));

    size_t len = strnlen(buffer, maxsize);
    if (len < 5) {
      continue;
    }

    if (buffer[len-1] == '\n') {
      buffer[len - 1] = 0;
      --len;
    }


    std::vector<std::string> parsed_string = parse_string(buffer, len);
    Item item;
    item.sku = atoi(parsed_string[0].c_str());
    item.name = parsed_string[1];
    item.desc = parsed_string[2];
    std::cout << "sku: " << item.sku << ", name: " << item.name << ", desc: " << item.desc << std::endl;
  }
  input.close();
  return 0;
}