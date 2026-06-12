#pragma once
#include <string>
#include <vector>
#include "Model.h"

class InventoryView {
public:
    void ShowMenu() const;
    void ShowList(const std::vector<Item>& items) const;
    void ShowMessage(const std::string& msg) const;
    int InputInt(const std::string& prompt) const;
    std::string InputString(const std::string& prompt) const;
};
