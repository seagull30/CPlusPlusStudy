# Unity

- Uniry Editor
    - ToolBar / Hierarchy Window / Game View / Scene View / Overlays / Inspecor Window / Project Window / Status Bar
    - 이 와의 UI는 Window 메뉴에서 열 수 있다. 
    - 간단한 조작법은 알아야 한다.

- Scene & GameObject
    - Scene : 씬(Scene)은 컨텐츠를 사용하여 작업하는 공간으로, 게임이나 애플리케이션의 전체 또는 일부를 포함하는 에셋(Asset)이다. 스크립트에서는 [SceneManager](https://docs.unity3d.com/kr/2021.3/ScriptReference/SceneManagement.SceneManager.html)를 이용해 씬을 로드할 수 있다.
    - GameObject    
        - Unity에서 존재하는 모든 오브젝트를 말한다. 
        - 컴포넌트(Component)의 컨테이너 역할을 한다.
        - GameObject는 계층적으로 다른 GameObject를 가질 수 있다.    
    - 모든 GameObject는 Transform을 가진다. 
        - Tnansform은 좌표계에서의 위치, 회전, 스케일 표현한다.
        - Transform은 월드 혹은 부모 GameObject로부터의 상대적인 좌표를 나타낸다.
        
            - 월드인 경우를 월드 좌표계, GameObject인 경우 로컬 좌표계라고 한다.    
    - 움직임이 없는 GameObject는 Static으로 설정 (최적화에 도움)
        - 반대를 Dynamic GameObject
    - 프로토타입을 만들 때 사용하는 Primitive GameObject가 있다.
        - Cube / Sphere / Capsule


- Component
    - Component : GameObject의 기능적인 단위. 즉, 하나의 기능을 담당하는 스크립트.
        - 시작적인 기능 / 물리적인 기능 / 행위의 기능
        - Unity는 다양한 Compenent를 내재하고 있다.
        - 우리만의 Component를 작성하기 위해선 C# 문법을 알고 있어야 한다.
        - 모든 Component는 MonoBahaviour를 상속 받는다.
            - MonoBahaviour에는 Unity 엔진에 의해 호출되는 여러 이벤트 메시지가 정의 되어 있다. 
            _ [이벤트 메시지의 종류 및 순서](https://docs.unity3d.com/kr/2021.3/Manual/ExecutionOrder.html)
                - Awake() -> OnEnable() -> Start() -> FixedUpdate() -> Update()-> LateUpdate() -> OnDisable() -> OnDestroy()
                - 각 이벤트 메시지가 언제 호출되는지 정확히 알아야 정확한 구현이 가능하다.
- Input
    - [Input Manager](https://docs.unity3d.com/kr/2021.3/Manual/class-InputManager.html) : Unity에 내장된 기본 입력 방법
    - [Input Sestem](https://docs.unity3d.com/Packages/com.unity.inputsystem@1.4/manual/index.html)(★★★) : 추가 패키지 

- Interaction ( Collision )
    - [Layer](https://docs.unity3d.com/kr/2021.3/Manual/LayerBasedCollision.html) :  GameObject가 어떤 다른 것과 상호작용할 수 있는지를 정의
        - Layer Matrix 설정 방법을 알아야 함.
        - Layer 체크는 비트를 사용
        - 0번부터 31번까지 사용할 수 있다.
    - [Character Control](https://docs.unity3d.com/kr/2021.3/Manual/CharacterControllers.html) : 아래의 두 방법은 게임 플레이 설계에 따라 다르게 적용한다
        - Rigidbody
        - Character Controller
    - [Rigidbody](https://docs.unity3d.com/kr/2021.3/Manual/RigidbodiesOverview.html) : 물리 기능을 제공하는 Component
        - 힘과 관련된 기능을 제공함
        - Collider와 함께 상요해서 충돌 처리에 사용
        - Kinematic Rigidbody : 물리 엔진 대신 스크립트에 의해서 동작하는 Rigidbody
        - Rigidbody는 최상위 GameObject에 단 하나만 부착해야 한다.
    - [Collider](https://docs.unity3d.com/kr/2021.3/Manual/CollidersOverview.html) : 물리적인 표면을 제공하는 Component
        - Box / Sphere / Capsule
        - 하나의 GameObject에 여러 개의 Collider를 부착할 수 있다.
        - Rigidbody 없이도 Collider를 부착할 수 있으며, 이를 Static Collider라고 한다.
        - 다른 Collider의 진입을 허용하려면 Trigger로 만들어주면 된다.
    - Event
        - Collider에 의해 충돌이 발생할 때 호출되는 이벤트 메시지가 존재한다.
        - OnCollisionEnter / OnCollisionStay / OnCollisionExit
        - OnTriggerEnter / OnTriggerStay / OnTriggerExit
    - 스크립트를 이용한 상호작용
        - Raycast
        - Overlap 

- Coroutine
    - 시간에 기반한 동작을 편하게 구현할 수 있는 서브루틴
    - StartCorourine()으로 코루틴을 시작할 수 있고, StopCoroutine()으로 코루틴을 중지할 수 있다.
    - Update() 이후에 실행된다.

- [Animation](https://docs.unity3d.com/kr/2021.3/Manual/AnimationOverview.html)
    - 유한 상태 기계로 애미메이션을 구성할 수 있다.
    - 각 상태에 따른 동작을 StateMachineBehaviour로 표현할 수 있다.
    - Animation Evnet를 통해 애니메이션 실행 중 특정 시점에 메소드를 호출할 수 있다.

- [Audio](https://docs.unity3d.com/kr/2021.3/Manual/AudioOverview.html)
    - Audio Source : 소리를 내는 컴포넌트
    - Audio Listener : 소리를 듣는 컴포넌트

- UGUI
    - [Canvas](https://docs.unity3d.com/kr/2021.3/Manual/class-Canvas.html)
        - UI를 배치하는 컴포넌트
        - 모든 UI 오브젝트는 Canvas의 자식으로 존재해야 한다.
        - Render Mode에 대한 이해가 필요하다
            - Screen Space - Overlay : 스크린 공간에 덧씌어지는 UI로 Main UI를 표현하는 데 사용
            - Screen Spcae - Camera : 특정 카메라로부터 일정 거리에 배치된 UI
            - World Spcae : 가상 세계에 배치되는
    - RectTransform
        - Canvas 상에서의 위치, 너비, 높이, 앵커, 피봇, 스케일, 회전 등을 표현하는 컴포넌트
    - Layout
        - Latout Group : Layout Element를 관리하여 Layout을 구성하는 컴포넌트
        - Layout Element : 구성 요소
    - Visual Component
        - 단순히 정보를 제공하는 UI
        - Text / Image
    - Interactive Component    
        - 유저와 상호작용할 수 있는 UI
        - Button / Toggle / Toggle Group / ScrollBar / Dropdown / Input Field / Scroll View

- Prefab
    - 재사용 가능한 GameObject
    - Scene에 동일한 GameObject를 배치하거나, 프로그램 실행 중 인스턴스화를 할 때 사용

- Resource Management
    - Resource API
        - Resources 라는 특정 폴더에 있는 여러 에셋을 불러올 수 있다.
        - 현재는 사용되지 않는다. => 최적화 이슈 떄문
    - [Addressable System](https://docs.unity3d.com/kr/2021.3/Manual/com.unity.addressables.html)

- Scriptable Object
    - 공통된 데이터에 개해 단 하나의 인스턴스만 만들 때 사용한다.

- Tip
    - 1. Unity GC
        - 압축이 일어나지 않아 메모리 단편화가 발생하기 쉽다.
        - 참조 타입의 객체를 생성할 때는 항상 주의해야 한다.
            - Object Pooling으로 미리 사용할 객체를 다 만들어 재사용한다.
    - 2.  Hash값 사용하기
        - Animator나 Material 사용 시 해시값 사용
    - 3. UnityEngine.Object 서브 클래스에 대해서 Null 체크 되도록 피하기
        - Update() 같은 반복적으로 호출되는 메소드에서 Null 체크 하지 않도록 주의한다.
    - 4. Attribute
        - [Header](https://docs.unity3d.com/kr/2021.3/ScriptReference/HeaderAttribute.html)
        - [SerializeField](https://docs.unity3d.com/kr/2021.3/ScriptReference/SerializeField.html)
        - Conditional
        - RequireComponent
        - ContextMenu
        - Space
        - Tooltip
        - TextArea
        - [Range](https://docs.unity3d.com/kr/2021.3/ScriptReference/RangeAttribute.html)
        - [CreateAssetMenu](https://docs.unity3d.com/kr/2021.3/ScriptReference/CreateAssetMenuAttribute.html)