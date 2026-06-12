#include "Model.h"

void InventoryModel::Add(const std::string& name, int quantity) {
    items_.push_back({ name, quantity });
}

const std::vector<Item>& InventoryModel::GetAll() const {
    return items_;
}

bool InventoryModel::UpdateQuantity(int index, int newQuantity) {
    if (index < 0 || index >= static_cast<int>(items_.size())) return false;
    items_[index].quantity = newQuantity;
    return true;
}

bool InventoryModel::Delete(int index) {
    if (index < 0 || index >= static_cast<int>(items_.size())) return false;
    items_.erase(items_.begin() + index);
    return true;
}
