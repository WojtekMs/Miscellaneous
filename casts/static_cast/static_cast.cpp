#include <iostream>
#include <vector>

class Cargo {
public:
    virtual int getPrice() const = 0;
    virtual std::string getName() const = 0;
};

class Fruit : public Cargo {
public:
    // override from Cargo
    int getPrice() const override { return base_price_; }
    std::string getName() const override { return name_; }

    size_t timeToSpoil() const { return time_to_spoil_; }
    virtual Fruit& operator--() {
        if (time_to_spoil_ == 0)
            return *this;

        --time_to_spoil_;
        return *this;
    }

protected:
    size_t time_to_spoil_{10};
    std::string name_{"Fruit"};
    int base_price_{100};
};

class DryFruit : public Fruit {
public:
    // override from Cargo
    int getPrice() const override { return base_price_ * 3; }
    std::string getName() const override { return "DryFruit"; }

    DryFruit& operator--() override {
        if (time_to_spoil_ == 0)
            return *this;

        static int counter = 0;
        if (++counter == 3) {
            --time_to_spoil_;
            counter = 0;
        }

        return *this;
    }
};

class Item : public Cargo {
public:
    // override from Cargo
    int getPrice() const override { return base_price_; }
    std::string getName() const override { return name_; }

protected:
    std::string name_{"Item"};
    int base_price_{1000};
};

void printData(const Cargo* const cargo) {
    std::cout << "Name: " << cargo->getName() << '\n';
    std::cout << "Price: " << cargo->getPrice() << '\n';
    std::cout << std::string(80, '*') << '\n';
}

void printDataFruit(const Fruit* const fruit) {
    std::cout << "Name: " << fruit->getName() << '\n';
    std::cout << "Price: " << fruit->getPrice() << '\n';
    std::cout << "Time to spoil: " << fruit->timeToSpoil() << '\n';
    std::cout << std::string(80, '*') << '\n';
}

void printDataCast(const Cargo* const cargo) {
    if (const auto* fruit = dynamic_cast<const Fruit*>(cargo)) {
        std::cout << "Name: " << fruit->getName() << '\n';
        std::cout << "Price: " << fruit->getPrice() << '\n';
        std::cout << "Time to spoil: " << fruit->timeToSpoil() << '\n';
        std::cout << std::string(80, '*') << '\n';
        return;
    }

    std::cout << "Name: " << cargo->getName() << '\n';
    std::cout << "Price: " << cargo->getPrice() << '\n';
    std::cout << std::string(80, '*') << '\n';
}

int main() {
    Cargo* cargo = nullptr;
    Fruit fruit;
    DryFruit dry_fruit;

    cargo = &fruit;
    printData(cargo);
    cargo = &dry_fruit;
    printData(cargo);

    // FRUIT
    Fruit* fruit_ptr = nullptr;
    fruit_ptr = &fruit;
    printDataFruit(fruit_ptr);
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    printDataFruit(fruit_ptr);

    // DRY FRUIT
    fruit_ptr = &dry_fruit;
    printDataFruit(fruit_ptr);
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    printDataFruit(fruit_ptr);

    // CAST
    std::cout << "CAST!\n";
    printDataCast(cargo);
    cargo = &fruit;
    printDataCast(cargo);
    Item item;
    cargo = &item;
    printDataCast(cargo);

    return 0;
}