#include "View.h"
#include <iostream>

void InventoryView::ShowMenu() const {
    std::cout << "\n=== 반도체 재고 관리 ===\n";
    std::cout << "1. 목록 보기\n";
    std::cout << "2. 항목 추가\n";
    std::cout << "3. 수량 수정\n";
    std::cout << "4. 항목 삭제\n";
    std::cout << "0. 종료\n";
    std::cout << "선택: ";
}

void InventoryView::ShowList(const std::vector<Item>& items) const {
    if (items.empty()) {
        std::cout << "등록된 항목이 없습니다.\n";
        return;
    }
    std::cout << "\n[번호] 품명\t\t수량\n";
    std::cout << "------------------------------\n";
    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        std::cout << "[" << i + 1 << "] " << items[i].name
                  << "\t\t" << items[i].quantity << "\n";
    }
}

void InventoryView::ShowMessage(const std::string& msg) const {
    std::cout << msg << "\n";
}

int InventoryView::InputInt(const std::string& prompt) const {
    int value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}

std::string InventoryView::InputString(const std::string& prompt) const {
    std::string value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}
