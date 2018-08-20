
# C language sample - sin()

EDISON 시뮬레이션 SW 개발자를 위한 1개의 입력 파일 읽어, sin 그래프를 그리는 C언어 예제 파일입니다.

```
bin/
 - simrc      //환경변수에 plotly lib이 설치된 python 경로추가
 - simpost	  // 실행파일 실행 이후 실행 스크립트
 - post.py	  //oneD 파일을 plotly 데이터로 변환 코드
src/
 - Makeflie
 - main.c     //main 소스 코드sin()에결과를 oneD 파일로 출력
inp/
 - input.dat //샘플 입력 파일
```


다음 수식의 변수들을 입력으로 받으며, 입력 변수는 a,b,c,d 총 4개 입니다.

$$
y = a * sin(bx+c)+d
$$


입력 파일의 경우에는 변수와 값 구분자를 ' = '을 사용하였으며, 변수와 변수 사이를 구분하기 위해 ' ;\n '를 사용하였습니다. 파일로 입력을 받으며, 샘플 입력 파일은 아래와 같으며, **inp** 폴더에 **input.dat** 로 저장되어 있습니다.

```
a = 1 ;
b = 0.4 ;
c = -0.5 ;
d = 0.3 ;
```


본 예제는 ./[실행파일명] -[옵션] [입력 파일 경로]로 실행시 옵션 뒤에 입력된 경로의 파일을 열고 닫는 예제로 Makefile과 소스코드는 **src** 폴더에 저장되어 있으며, 컴파일이 완료되면 바이너리 파일은 **bin** 폴더에 저장됩니다.


## 설치하기

zip 파일을 다운로드 받아 압축을 풀거나 ```git clone``` 명령어를 이용하여, 프로젝트를 가져올 수 있습니다.

```
$ git clone https://github.com/sp-edison/c_example_oneD_plotly.git
```

다운로드가 완료되면, ```c_example_oneD_plotly``` 폴더가 생성되며, **src** 폴더로 이동하여 **make all** 명령어를 사용하면, 컴파일이 완료됩니다.

```
$ cd c_example_oneD_plotly/src
$ make all
gcc -c main.c -o main.o
Compiled main.c successfully!
gcc -o ../bin/Sin.x main.o
Linking complete!
```

기본 값으로 등록된 TARGET 값이 Sin.x이며, 생성된 bin 폴더로 이동하여, 아래와 같이 명령어를 입력하면 실행이 됩니다.

```bash
$ cd ../bin
$ source simrc
$ ./Sin.x -i ../inp/input.dat
$ source simpost
```


해당 예제를 이용하여 EDISON 웹포털에서 자동으로 소스 컴파일을 하실수 있습니다. 자동으로 소스 컴파일을 하기위해 선행되야하는 조건은 아래와 같습니다.

- 본 예제와 같이 Makefile과 소스코드는 **src** 폴더에 저장되어 있어야 합니다.

- **src** 폴더 안에서 ```make all``` 커맨드 입력시, 컴파일이 정상적으로 왼료된 경우 바이너리 파일이 **bin** 폴더에 저장이 되면 됩니다.

- Sin.sh 파일을 실행하게 되면, make로 생성된 바이너리가 실행된 이후 post.py를 실행하게 됩니다. EDISON 플랫폼에서 실행하는 경우 plotly 라이브러리를 쓰게 되는데 해당 라이브러리가 설치된 python을환경변수에 등록해야합니다. 이경우 **bin** 폴더안에 simrc라는 파일에 추가해야하는 환경변수들을 등록하면 EDISON 플랫폼에서 실행파일을 실행하기전 simrc에 있는 환경변수를 추가하게 됩니다.
