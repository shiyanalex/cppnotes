#include <iostream>
#include <chrono>
#include <vector>
#include <variant>
#include <functional>
#include <memory>
#include <random> // Basic behavior type 

struct Behavior { 
    int value; 
    void execute() { value *= 2; } }; // Variant-based implementation 

class VariantItem { 
    std::variant<Behavior> behavior; 
public: 
    VariantItem(Behavior b) : behavior(std::move(b)) {} 
        void update() { std::visit([](auto& b) { b.execute(); }, behavior); 
            } 
}; // Virtual function-based im
