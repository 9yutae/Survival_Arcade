# 🎮 Survival_Arcade

## 📌 프로젝트 개요
본 프로젝트는 팀스파르타코딩클럽 내일배움캠프의 'Unreal 기반 3D 게임 개발자 양성과정' 2기   
Ch03의 8번 과제에 대한 소스 코드입니다.   
멀티 웨이브 구조와 UI/UX 개선을 중심으로 설계된 게임 프로젝트입니다.   
- 프로젝트 기간 : 2025.01.20 ~ 2025.02.05

</br>

## 🚀 주요 기능

### 1️⃣ 멀티 웨이브 시스템

- 3개의 레벨로 구성된 게임
- 각 레벨에서 3단계의 웨이브 진행
    - 웨이브당 30초 제한 시간
    - 웨이브 진행에 따라 스폰 아이템 개수 증가 (30 → 40 → 50개)

- 웨이브별 환경 변화
    - Wave 1 : 기본 환경
    - Wave 2 : Bush 장애물 추가 (지날 때 플레이어 속도 감소)
    - Wave 3 : Bush 장애물 + RedZone 추가
        - 웨이브 3 시작 시 RedZoneSpawner 생성
        - 웨이브 3 시작 15초 경과 후, 하늘에서 5초 간격으로 3개의 폭탄 투하
</br>

### 2️⃣ UI/UX 개선

**🏆 HUD (Heads-Up Display)**

- 점수, 시간, 체력, 레벨, 웨이브 정보를 화면에 표시
- 직관적인 레이아웃과 아이콘, 게이지 바 추가
- 텍스트 스타일(폰트, 색상, 테두리 등) 최적화

**📜 메뉴 시스템**
1. Main Menu (게임 시작 시 실행)
    - Play : 게임 시작
    - Quit : 게임 종료

2. Pause Menu (게임 도중 Tab 키 입력 시 실행)
    - Continue : 게임 재개
    - New Game : 게임 재시작
    - Main Menu : 메인 메뉴로 이동

3. Game Over Menu (게임 종료 시 실행)
    - New Game : 게임 재시작
    - Main Menu : 메인 메뉴로 이동
  
</br>

## 📹 과제 제출 영상
[NBC Assignment 08 Survival_Arcade](https://youtu.be/aSClUMJm5XQ)
  
</br>

## 📂 프로젝트 구조
```Text
Survival_Arcade
├── Source
│   ├── Core
│   │   ├── SpartaGameMode.cpp/.h
│   │   ├── SpartaGameState.cpp/.h
│   │   ├── SpartaPlayerController.cpp/.h
│   │   ├── SpawnVolume.cpp/.h
│   ├── Items
│   │   ├── BaseItem.cpp/.h
│   │   ├── BigCoinItem.cpp/.h
│   │   ├── BombItem.cpp/.h
│   │   ├── BushItem.cpp/.h
│   │   ├── HealItem.cpp/.h
│   │   ├── MineItem.cpp/.h
│   │   ├── RedZoneSpawner.cpp/.h
│   │   ├── SmallCoinItem.cpp/.h
│   ├── Player
│   │   ├── SpartaCharacter.cpp/.h
│   │   ├── SpartaPawn.cpp/.h
├── Content
│   ├── Blueprints
│   │   ├── BP_BigCoinItem.uasset
│   │   ├── BP_BombItem.uasset
│   │   ├── BP_BushItem.uasset
│   │   ├── BP_HealItem.uasset
│   │   ├── BP_MineItem.uasset
│   │   ├── BP_RedZoneSpawner.uasset
│   │   ├── BP_SmallCoinItem.uasset
│   │   ├── BP_SpartaCharacter.uasset
│   ├── DataTables
│   │   ├── ItemSpawnTable.uasset
│   │   ├── ItemSpawnTable_Level2.uasset
│   │   ├── ItemSpawnTable_Level3.uasset
│   ├── Inputs
│   │   ├── IA_Jump.uasset
│   │   ├── IA_Move.uasset
│   │   ├── IA_Pause.uasset
│   │   ├── IA_Sprint.uasset
│   ├── Maps
│   │   ├── BasicLevel.umap
│   │   ├── IntermediateLevel.umap
│   │   ├── AdvancedLevel.umap
│   │   ├── MenuLevel.umap
│   ├── UI
│   │   ├── WBP_HUD.uasset
│   │   ├── WBP_MainMenu.uasset
│   │   ├── WBP_PauseMenu.uasset
│   │   ├── WBP_GameOverMenu.uasset
└── README.md
```

## 🛠 사용 기술
- 언리얼 엔진 (Unreal Engine)
- C++ 및 Blueprint
- UMG (Unreal Motion Graphics) UI 시스템
