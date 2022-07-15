#include <cstdio>

struct LibaryCard {
  const char * title;
  const char * author;
  const char * publisher;
  const char * subject;
  // int ISBN;
  // int OCLC;
  const char * isbn;
  const char * oclc;
  // const char * dew_dec;
  int dew_dec1;
  int dew_dec2;
  int year_pub;
  int year_acq;
  int quantity;
};