# SCC_CH3-6
## UE5 CPP - 움직이는 장애물 만들기
### 1. 과제 개요
#### 필수 과제
  * C++를 이용하여 Actor 클래스 구현하기
  * Tick 함수를 활용하여 회전 및 이동 로직 구성하기
  * 리플렉션 시스템 적용하기
#### 도전 과제
  * 시간 제한 및 카운트 다운 활용하기
  * 랜덤(동적) 스폰

### 2. 구현 내용
#### **필수 과제**
  * **Actor 클래스 구현**
    * 아래 사진과 같은 네가지 종류의 Actor를 구현 
![image](https://github.com/user-attachments/assets/77a6d5bb-e57f-420a-a8fe-e62f87213b9d)
  * **Tick 함수를 활용한 회전 및 이동로직**
    * 아래 사진과 같이 Tick 함수에서 Platform을 X축으로 이동하는 함수를 호출
    * 이때 DeltaTime을 곱해주어 컴퓨터의 사양에 관계없이 같은 속도로 이동하도록 구현
      ![image](https://github.com/user-attachments/assets/b12659f3-d0a7-4e9c-981c-2ca277420007)
  * **리플렉션 시스템 적용하기**
    * 아래 사진과 같이 UPROPERTY를 사용하여, 리플렉션 시스템 적용
    * EditAnywhere 지정자를 통해 MoveSpeed를 게임 도중 변경 가능
      ![image](https://github.com/user-attachments/assets/bf4adf98-f648-48ad-b207-081bb6653be3)
#### **도전 과제**
  * **시간 제한 및 카운트 다운 활용**
    * 아래 사진과 같이 SetTimer 함수와 NotifyActorBeginOverlap를 사용하여 캐릭터가 해당 Actor에 overlap된 경우 타이머를 시작
    * 타이머는 DelayTime 이후에 Falling이라는 함수를 실행시켜, Actor가 떨어지게 구현
      ![image](https://github.com/user-attachments/assets/310f5a77-e0af-404a-a535-43fa646dc521)
  * **랜덤(동적) 스폰**
    * 랜덤 스폰
      * Max와 Min 값을 지정해 둔 후 RandRange와 RandBool을 통해, Actor가 랜덤한 값을 가지고 생성되도록 구현    
        ![image](https://github.com/user-attachments/assets/3948c1ed-69b4-486a-8c84-a2cd5e53769e)
    * 동적 스폰      
      * DataTable과 TableRowBase를 사용하여, 해당 값을 기반으로 게임 시작 시 Actor를 스폰
      * 스폰 시에는 SpawnActor 함수 사용
        * Data Table<br/>
          ![image](https://github.com/user-attachments/assets/ce27303b-d4fc-4180-8bdd-d22adf6fbc13) <br/>
        * TableRowBase <br/>
          ![image](https://github.com/user-attachments/assets/34c3b5f9-9e2a-4c15-94e7-ad8968a0604a) <br/>
        * Spawner클래스 <br/>
          ![image](https://github.com/user-attachments/assets/0de06117-3b5f-4612-9667-807769d45597) <br/>
          
### 3. 상세 설명
* **Moving Platform** : 랜덤한 값을 가지고 좌우로(X축으로) 움직이는 플랫폼
  * 랜덤한 시작점, 랜덤한 움직임 범위, 랜덤한 움직임 방향을 통한 랜덤성 부여 (RandRange, RandBool)
  * 최대 움직일 수 있는 지점에 도달하면, 반대로 이동하도록 구현
  * AddActorLocalOffset로 움직임 구현
* **Rotating Platform** : 제자리에서 회전하는 플랫폼
  * 회전 값을 EditAnywhere 로 만들어 에디터에서 값을 아래처럼 수정하여, 회전 방향을 바꿀 수 있도록 구현
  * AddActorLocalRotation로 움직임 구현
* **Elevate Platform** : 캐릭터가 collision과 overlap되면 올라가고(최대 지점까지) 캐릭터와 overlap이 끝나면 원래 위치로 돌아오는 플랫폼
  * OnComponentBeginOverlap과 OnComponentEndOverlap 사용
    ![image](https://github.com/user-attachments/assets/4ca50cde-e5c5-4929-83a7-91a95a2d6cc6)
  * AddActorLocalOffset로 움직임 구현
* **Falling Platform** : 캐릭터가 collision과 overlap되면 랜덤 시간 이후 떨어지며, 일정 시간이 지나면 다시 원상복구가 되는 플랫폼
  * 떨어지는 것은 Simulate Physics를 켜는 것으로 구현
  * NotifyActorBeginOverlap 사용
  * GetTimerManager().SetTimer() 사용

### 4. 시연 영상
https://drive.google.com/file/d/14Xg3E_JziDq19EtCBZUrwNHbYNUNyNUv/view?usp=drive_link  
