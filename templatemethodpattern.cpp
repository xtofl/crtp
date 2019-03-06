#include <cstdio>
#include <memory>

class Base {
public:
    virtual ~Base(){}

    bool valid() const {
        puts("Base");
        return true;
    };
};

template<typename V> bool valid(const V& v) {
    return v.valid();
}

class Middle: public Base {
public:
    bool valid() const {
        puts("Middle");
        return true;
    }
};

template<> bool valid(const Middle& v) {
    return v.valid() && valid(static_cast<const Base&>(v));
}

class Bottom: public Middle {
public:
    bool valid() const {
        puts("Bottom");
        return true;
    }
};
template<> bool valid(const Bottom& v) {
    return v.valid() && valid(static_cast<const Middle&>(v));
}

int main() {
    auto x = std::make_unique<Bottom>();
    printf("Valid: %d\n", valid(*x));
}