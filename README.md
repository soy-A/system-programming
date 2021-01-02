## system-programming

### child_process01.c

fork() 함수를 이용하여 재귀적으로 자식 프로세스를 생성하는 프로그램입니다.

##### <프로그램 동작 구조>

![image](https://user-images.githubusercontent.com/63772786/103454296-f1282200-4d25-11eb-86e7-e38099ccfb79.png)

##### <실행 결과>

![image](https://user-images.githubusercontent.com/63772786/103454300-f9805d00-4d25-11eb-87a5-0bc75f72380c.png)

---

### child_process02.c

fork() 함수를 이용해 생성된 자식 프로세스들이 난수를 생성하고, 부모프로세스는 모든 자식 프로세스들에게서 전달받은 난수를 콘솔창에 출력하는 프로그램입니다. 생성된 난수는 파이프를 통해 부모 프로세스에게 전달되며, 모든 자식프로세스는 같은 부모프로세스를 갖습니다.

##### <프로그램 동작 구조>

![image](https://user-images.githubusercontent.com/63772786/103454303-01400180-4d26-11eb-8d3d-2ae1aa8cb12a.png)

##### <실행 결과>

![image](https://user-images.githubusercontent.com/63772786/103454308-056c1f00-4d26-11eb-9ad7-4aeec71bf81d.png)

---

###  369game_*.c

네개의 프로세스들이 파이프를 통해 숫자를 주고받으며 369게임을 진행하는 프로그램입니다.

##### <프로그램 동작 구조>

![image](https://user-images.githubusercontent.com/63772786/103454322-1f0d6680-4d26-11eb-86c6-bd12ec3208e3.png)

##### <실행 결과>

![image](https://user-images.githubusercontent.com/63772786/103454325-2765a180-4d26-11eb-9493-66f85d06140f.png)
