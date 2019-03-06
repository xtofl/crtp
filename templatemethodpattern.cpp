#include <cstdio>
#include <memory>

class Base {
public:
    virtual ~Base(){}

    virtual bool valid() const {
        puts("Base");
        return true;
    };
};

class Middle: public Base {
public:
    virtual bool valid() const override {
        auto b = Base::valid();
        puts("Middle");
        return false && b;
    }
};

class Bottom: public Middle {
    bool valid() const override {
        auto b = Middle::valid();
        puts("Bottom");
        return false && b;
    }
};

int main() {
    std::unique_ptr<Base> x = std::make_unique<Bottom>();
    printf("Valid: %d\n", x->valid());
}