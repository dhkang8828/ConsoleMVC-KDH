#include "Model.h"
#include "View.h"
#include "Controller.h"

int main() {
    InventoryModel model;
    InventoryView  view;
    InventoryController controller(model, view);
    controller.Run();
    return 0;
}
