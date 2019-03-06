#include <cstdio>
#include <memory>

class Base {
public:
    virtual ~Base(){}

    bool valid() const {
        return valid_impl();
    }
    virtual bool valid_impl() const {
        puts("Base");
        return true;
    };
};

class Middle: public Base {
public:
    virtual bool valid_impl() const override {
        auto b = Base::valid_impl();
        puts("Middle");
        return false && b;
    }
};

class Bottom: public Middle {
    bool valid_impl() const override {
        auto b = Middle::valid_impl();
        puts("Bottom");
        return false && b;
    }
};

int main() {
    std::unique_ptr<Base> x = std::make_unique<Bottom>();
    printf("Valid: %d\n", x->valid());
}