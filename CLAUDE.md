# ConsoleMVC — 반도체 재고 관리 프로그램

## 프로젝트 목적

MVC 패턴의 역할 분리를 콘솔 앱으로 체험하는 학습용 프로젝트.
반도체 재고(품명/수량)를 관리하는 간단한 기능을 통해 Model/View/Controller 구조를 익힌다.

## 빌드 환경

- **IDE:** Visual Studio 2022
- **언어:** C++20
- **플랫폼:** Win32 / x64 콘솔 애플리케이션
- **솔루션 파일:** `ConsoleMVC.slnx`

## 프로젝트 구조

```
ConsoleMVC/
├── main.cpp           # 진입점 — Model/View/Controller 생성 후 Run() 호출
├── Model.h/.cpp       # 데이터 계층 — Item 구조체, InventoryModel CRUD
├── View.h/.cpp        # 표현 계층 — 콘솔 출력 및 입력
└── Controller.h/.cpp  # 제어 계층 — 메뉴 루프, Model/View 조율
```

## MVC 역할 요약

| 컴포넌트 | 역할 | 핵심 규칙 |
|---------|------|----------|
| **Model** | 데이터 보관 및 CRUD | UI/출력 코드 없음 |
| **View** | 화면 출력 및 입력 수신 | 비즈니스 로직 없음 |
| **Controller** | 흐름 제어, Model·View 연결 | 직접 데이터 저장 없음 |

## 주요 기능

1. 목록 보기
2. 항목 추가 (품명, 수량)
3. 수량 수정
4. 항목 삭제
0. 종료

## 빌드 방법

Visual Studio에서 `ConsoleMVC.slnx`를 열고 `Ctrl+Shift+B` 로 빌드.
실행은 `Ctrl+F5`.
