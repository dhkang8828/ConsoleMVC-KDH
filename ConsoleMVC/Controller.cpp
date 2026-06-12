#include "Controller.h"

InventoryController::InventoryController(InventoryModel& model, InventoryView& view)
    : model_(model), view_(view) {}

void InventoryController::Run() {
    int choice = -1;
    while (choice != 0) {
        view_.ShowMenu();
        choice = view_.InputInt("");
        switch (choice) {
        case 1: ShowList();   break;
        case 2: AddItem();    break;
        case 3: UpdateItem(); break;
        case 4: DeleteItem(); break;
        case 0: view_.ShowMessage("프로그램을 종료합니다."); break;
        default: view_.ShowMessage("잘못된 입력입니다."); break;
        }
    }
}

void InventoryController::ShowList() {
    view_.ShowList(model_.GetAll());
}

void InventoryController::AddItem() {
    std::string name = view_.InputString("품명 입력: ");
    int qty = view_.InputInt("수량 입력: ");
    model_.Add(name, qty);
    view_.ShowMessage("추가되었습니다.");
}

void InventoryController::UpdateItem() {
    view_.ShowList(model_.GetAll());
    int idx = view_.InputInt("수정할 번호 입력: ") - 1;
    int qty = view_.InputInt("새 수량 입력: ");
    if (model_.UpdateQuantity(idx, qty))
        view_.ShowMessage("수정되었습니다.");
    else
        view_.ShowMessage("잘못된 번호입니다.");
}

void InventoryController::DeleteItem() {
    view_.ShowList(model_.GetAll());
    int idx = view_.InputInt("삭제할 번호 입력: ") - 1;
    if (model_.Delete(idx))
        view_.ShowMessage("삭제되었습니다.");
    else
        view_.ShowMessage("잘못된 번호입니다.");
}
