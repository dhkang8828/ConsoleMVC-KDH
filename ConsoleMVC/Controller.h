#pragma once
#include "Model.h"
#include "View.h"

class InventoryController {
public:
    InventoryController(InventoryModel& model, InventoryView& view);
    void Run();
private:
    void ShowList();
    void AddItem();
    void UpdateItem();
    void DeleteItem();

    InventoryModel& model_;
    InventoryView&  view_;
};
