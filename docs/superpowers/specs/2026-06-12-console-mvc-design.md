# ConsoleMVC 설계 문서

**프로젝트:** 반도체 재고 관리 프로그램 (MVC 패턴 학습용)
**날짜:** 2026-06-12
**언어:** C++20 / Visual Studio / Win32 콘솔

---

## 목적

MVC 패턴의 역할 분리를 콘솔 앱으로 간략하게 체험하는 프로젝트.
데이터(Model), 출력(View), 흐름 제어(Controller)를 파일 단위로 분리해 구조를 직관적으로 파악한다.

---

## 파일 구조

```
ConsoleMVC/
├── main.cpp
├── Model.h / Model.cpp
├── View.h / View.cpp
└── Controller.h / Controller.cpp
```

---

## 데이터 모델

```cpp
struct Item {
    std::string name;
    int quantity;
};
```

- `InventoryModel` 클래스가 `std::vector<Item>`을 보관
- 제공 메서드: `Add`, `GetAll`, `UpdateQuantity`, `Delete`

---

## 컴포넌트 역할

| 컴포넌트 | 역할 |
|---------|------|
| **Model** | Item 데이터 보관 및 CRUD 처리 |
| **View** | 메뉴 출력, 목록 출력, 입력 프롬프트, 결과 메시지 출력 |
| **Controller** | 메뉴 루프 실행, 사용자 입력 수신, Model/View 호출 조율 |

---

## 데이터 흐름

```
사용자 입력
    ↓
Controller  →  Model (CRUD 호출)
    ↓              ↓
   View  ←  결과 수신 후 출력
```

---

## 메뉴 구성

```
=== 반도체 재고 관리 ===
1. 목록 보기
2. 항목 추가
3. 수량 수정
4. 항목 삭제
0. 종료
```

---

## 빌드 환경

- Visual Studio 2022 (v145 toolset)
- C++20 (`stdcpp20`)
- Win32 / x64 콘솔 애플리케이션
