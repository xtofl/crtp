#include <cstdio>
#include <memory>


class IValid {
public:
    virtual ~IValid(){}
    virtual bool valid() const { return true; }; // monoid {bool, &&, true}
};

template<typename V, typename Parent_> class ValidateParentToo :
    public Parent_
{
public:
    using Parent = Parent_;
    bool valid() const override {
        return (this->valid_impl)() && Parent::valid();
    }
};

class Base : public IValid {
public:
    virtual ~Base(){}

    bool valid_impl() const {
        puts("Base");
        return true;
    };
};

class Middle: public ValidateParentToo<Middle, Base> {
public:
    bool valid_impl() const {
        puts("Middle");
        return true;
    }
};

class Bottom: public ValidateParentToo<Bottom, Middle> {
public:
    bool valid_impl() const {
        puts("Bottom");
        return true;
    }
};

int main() {
    std::unique_ptr<IValid> x = std::make_unique<Bottom>();
    printf("Valid: %d\n", x->valid());
}