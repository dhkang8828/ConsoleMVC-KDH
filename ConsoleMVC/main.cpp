#include "Model.h"
#include "View.h"
#include "Controller.h"
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    InventoryModel model;
    InventoryView  view;
    InventoryController controller(model, view);
    controller.Run();
    return 0;
}
