#pragma once
#include <string>
#include <vector>

struct Item {
    std::string name;
    int quantity;
};

class InventoryModel {
public:
    void Add(const std::string& name, int quantity);
    const std::vector<Item>& GetAll() const;
    bool UpdateQuantity(int index, int newQuantity);
    bool Delete(int index);
private:
    std::vector<Item> items_;
};
