#include <cstdio>
#include <cstdlib>
#include <cstring>

constexpr size_t maxstring = 1024;
constexpr const char * file = "./items.txt";
constexpr size_t max_tabs = 15;
constexpr char tab_char = '\t';

class Report {
	int sku;
	const char* name;
	const char* desc;
public:
	Report(int sku_num, const char* name_str, const char* desc_str);
	~Report();
	int get_sku();
	void set_sku(int sku_num);
	const char* get_name();
	void set_name(const char* name_str);
	const char* get_desc();
	void set_desc(const char* desc_str);
	void to_string();
};

Report::Report(int sku_num, const char* name_str, const char* desc_str) {
	sku = sku_num;
	name = name_str;
	desc = desc_str;
}

Report::~Report() {
  name = nullptr;
  desc = nullptr;
}

int Report::get_sku() {
	return sku;
}
void Report::set_sku(int sku_num) {
	sku = sku_num;
}

const char* Report::get_name() {
	return name;
}
void Report::set_name(const char* name_str) {
	name = name_str;
}

const char* Report::get_desc() {
	return desc;
}
void Report::set_desc(const char* desc_str) {
	desc = desc_str;
}

void Report::to_string() {
	printf("sku: %d, name: %s, desc: %s\n", sku, name, desc);
}

size_t * get_tabs(const char * string, size_t len) {
  static size_t indices[max_tabs];
  size_t & count = indices[0];
  if (len < 3) {
    return indices;
  }
  for (size_t & index : indices) {
    index = 0;
  }

  for (size_t i = 0; i < len; ++i) {
    if (string[i] == tab_char) {
      ++count;
      indices[count] = i;
      if (count >= max_tabs) {
        break;
      }
    }
  }
  return indices;
}

int main() {
	FILE* items = fopen(file, "rb");

	char buffer[maxstring];
	while (fgets(buffer, maxstring, items)) {
    size_t str_len = strnlen(buffer, maxstring);
    if (str_len < 5) {
      continue;
    }

    // trim newline
    if (buffer[str_len - 1] == '\n') {
      buffer[str_len - 1] = 0;
      --str_len;
    }

    size_t * split = get_tabs(buffer, str_len);
    if (split[0] < 2) {
      break;
    }

    buffer[split[1]] = buffer[split[2]] = 0;

    Report item = Report(atoi(buffer), buffer + split[1] + 1, buffer + split[2] + 1);
    item.to_string();
  }

	fclose(items);
	return 0;
}
