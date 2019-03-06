#include <cstdio>
#include <memory>

template<typename V> bool valid(const V& v) {
    return v.valid() && valid<typename V::Parent>(v);
}

class Base {
public:
    virtual ~Base(){}

    bool valid() const {
        puts("Base");
        return true;
    };
};

template<> bool valid(const Base &b) { return b.valid(); }

class Middle: public Base {
public:
    using Parent = Base;
    bool valid() const {
        puts("Middle");
        return true;
    }
};

class Bottom: public Middle {
public:
    using Parent = Middle;
    bool valid() const {
        puts("Bottom");
        return true;
    }
};

int main() {
    auto x = std::make_unique<Bottom>();
    printf("Valid: %d\n", valid(*x));
}