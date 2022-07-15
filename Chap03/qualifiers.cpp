// qualifiers.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

class S {
public:
    int static_value() {
        static int x = 7;
        return ++x;
    }
};

int func() {
    int x = 7;
    return ++x;
}

int main() {
    S s;
    S s1;
    S s2;
    printf("%d\n", s.static_value());
    printf("%d\n", s1.static_value());
    printf("%d\n", s2.static_value());
    return 0;
}

