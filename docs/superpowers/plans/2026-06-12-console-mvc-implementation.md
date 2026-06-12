# ConsoleMVC 반도체 재고 관리 구현 계획

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 반도체 재고(품명/수량)를 콘솔에서 관리하는 MVC 패턴 C++ 학습용 앱 구현

**Architecture:** Model(데이터), View(출력), Controller(흐름 제어)를 파일 단위로 분리한다. Controller가 Model과 View를 참조하고, main.cpp에서 세 객체를 생성해 Controller.Run()을 호출한다.

**Tech Stack:** C++20, Visual Studio 2022 (v145), Win32/x64 콘솔

---

## 파일 구조

| 파일 | 역할 |
|------|------|
| `ConsoleMVC/Model.h` | Item 구조체, InventoryModel 클래스 선언 |
| `ConsoleMVC/Model.cpp` | InventoryModel 구현 (Add/GetAll/UpdateQuantity/Delete) |
| `ConsoleMVC/View.h` | InventoryView 클래스 선언 |
| `ConsoleMVC/View.cpp` | InventoryView 구현 (메뉴/목록/메시지/입력) |
| `ConsoleMVC/Controller.h` | InventoryController 클래스 선언 |
| `ConsoleMVC/Controller.cpp` | InventoryController 구현 (메뉴 루프, 각 기능) |
| `ConsoleMVC/main.cpp` | 진입점 — 세 객체 생성 후 Run() 호출 |
| `ConsoleMVC/ConsoleMVC.vcxproj` | 위 파일들을 ItemGroup에 등록 |

---

## Task 1: Model 작성

**Files:**
- Create: `ConsoleMVC/Model.h`
- Create: `ConsoleMVC/Model.cpp`

- [ ] **Step 1: Model.h 작성**

```cpp
// Model.h
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
```

- [ ] **Step 2: Model.cpp 작성**

```cpp
// Model.cpp
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
```

- [ ] **Step 3: 커밋**

```bash
git add ConsoleMVC/Model.h ConsoleMVC/Model.cpp
git commit -m "feat: add InventoryModel with CRUD methods"
```

---

## Task 2: View 작성

**Files:**
- Create: `ConsoleMVC/View.h`
- Create: `ConsoleMVC/View.cpp`

- [ ] **Step 1: View.h 작성**

```cpp
// View.h
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
```

- [ ] **Step 2: View.cpp 작성**

```cpp
// View.cpp
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
```

- [ ] **Step 3: 커밋**

```bash
git add ConsoleMVC/View.h ConsoleMVC/View.cpp
git commit -m "feat: add InventoryView for console display and input"
```

---

## Task 3: Controller 작성

**Files:**
- Create: `ConsoleMVC/Controller.h`
- Create: `ConsoleMVC/Controller.cpp`

- [ ] **Step 1: Controller.h 작성**

```cpp
// Controller.h
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
```

- [ ] **Step 2: Controller.cpp 작성**

```cpp
// Controller.cpp
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
```

- [ ] **Step 3: 커밋**

```bash
git add ConsoleMVC/Controller.h ConsoleMVC/Controller.cpp
git commit -m "feat: add InventoryController with menu loop"
```

---

## Task 4: main.cpp 작성

**Files:**
- Create: `ConsoleMVC/main.cpp`

- [ ] **Step 1: main.cpp 작성**

```cpp
// main.cpp
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
```

- [ ] **Step 2: 커밋**

```bash
git add ConsoleMVC/main.cpp
git commit -m "feat: add main.cpp entry point"
```

---

## Task 5: vcxproj에 파일 등록

**Files:**
- Modify: `ConsoleMVC/ConsoleMVC.vcxproj`

- [ ] **Step 1: vcxproj의 빈 ItemGroup을 아래로 교체**

`<ItemGroup></ItemGroup>` 을 찾아서 다음으로 교체:

```xml
<ItemGroup>
  <ClCompile Include="main.cpp" />
  <ClCompile Include="Model.cpp" />
  <ClCompile Include="View.cpp" />
  <ClCompile Include="Controller.cpp" />
</ItemGroup>
<ItemGroup>
  <ClInclude Include="Model.h" />
  <ClInclude Include="View.h" />
  <ClInclude Include="Controller.h" />
</ItemGroup>
```

- [ ] **Step 2: 커밋**

```bash
git add ConsoleMVC/ConsoleMVC.vcxproj
git commit -m "chore: register all source files in vcxproj"
```

---

## Task 6: 빌드 확인 및 push

- [ ] **Step 1: Visual Studio에서 빌드 (Ctrl+Shift+B)**

  예상 출력: `빌드 성공. 0 오류`

- [ ] **Step 2: 실행 확인 (Ctrl+F5)**

  예상 출력:
  ```
  === 반도체 재고 관리 ===
  1. 목록 보기
  2. 항목 추가
  3. 수량 수정
  4. 항목 삭제
  0. 종료
  선택:
  ```

- [ ] **Step 3: 최종 push**

```bash
git push origin master
```
