// 문제 : char 변수 b를 이용하지 않고 b의 값을 훼손
// 조건 : 포인터 변수를 사용해서 값을 변경해야 한다.
// 조건 : 수정가능 지역에서 b 라는 변수를 언급하면(사용하면) 안됩니다.

#include <stdio.h>


// void change1(int* a){

//   *a = 50;
// }


// void change2 (int* a, int* b) {

// int q = *a; //q = 60
// int w = *b; //w = 70


// *a = w;
// *b = q;
  

// }




// void change3(int** pa) { //고로 x의 값에 접근하려면 포인터를 두개써서 심층으로 들어가야함.
  

//   **pa = 50; //첫번재 포인터는 x의 주소를 가지고있는 p의 값 = 쓰레기. 두번쨰는 심층에 있는 x의 주소에 있는 x 값.


// }




void change4(int ***a) { //x의 주소를 가진 z의 주소를 가진 k의 주소가 넘어옴.


  ***a = 50; //처음 포인터는 k의 주소에 들어있는 z의 주소를 표시.
            //두번쨰는 z에 들어있는 x의 주소를 표시.
            //3번쨰는 결국 x의 값.

}


int main(void) {

  // int a = 1;
  // int b = 5;

  // printf("== 변수의 주소 ==\n");
  // printf("&a : %ld\n", (long)&a);
  // printf("&b : %ld\n", (long)&b);

  // // 수정가능지역 시작
  // int *p = &a;
  // *p = 2;
  // int *u = (&a - 1); //1 은 1이아니라 int는 4바이트를 가지므로 주소에서 4가 빠짐.
  // *u = 10;
  // printf("p : %ld\n", (long)p);
  // // 수정가능지역 끝



  // printf("== 변수의 값 ==\n");
  // printf("a : %d\n", a);
  // // 출력 => a : 2
  // printf("b : %d\n", b);
  // // 출력 => b : 10
  


  // // 문제 : 원본값을 훼손하는 change 함수를 만들어주세요.

  // int x = 20;
  // printf("x의 주소값 : %ld\n", (long)&x);

  // printf("change 함수 호출하기 전의 x : %d\n", x);


  // change1(&x); //이부분만 수정 가능

  
  
  // printf("change 함수 호출한 후의 x : %d\n", x);
  // // 출력 => change 함수 호출한 후의 x : 50


  // // 문제 : 값을 교체하는 change 함수를 만들어주세요.
  // int a = 10;
  // int b = 20;

  // printf("change 함수 호출하기 전의 a : %d, b :%d\n", a, b);

  // change2(&a, &b); // 이부분 수정 가능

  // printf("change 함수 호출한 후의 a : %d, b :%d\n", a, b);
  // // 출력 => change 함수 호출한 후의 a : 20, b : 10



  // 문제 : 원본값을 훼손하는 change 함수를 만들어주세요.(2중포인터)


  // int x = 20;
  // int* p = &x; //p는 x의 주소값을 저장. 주소값 p == x
  
  // printf("change 함수 호출하기 전의 x : %d\n", x);

  // //&p = x의 주소값을 가진 값의 주소값. 거의 (&p(&x)). 하지만 값 20은 x의 주소값안에 있음.
  // printf("p: %ld\n", (long)p);
  // printf("&p: %ld\n", (long)&p);

  // change3(&p); //x의 주소값을 가진 주소값을 넘기기. 값은 x의 20이지만 p값은 아님.

  // printf("change 함수 호출한 후의 x : %d\n", x);
  // // 출력 => change 함수 호출한 후의 x : 50



  // 문제 : 원본값을 훼손하는 change 함수를 만들어주세요.(3중포인터)

  int x = 20; 
  int *z = &x; //z는 x의 주소를 가짐. 
  int **k = &z; //k는 x의 주소를 가진 z의 주소를 가짐. 하지만 k또한 그 자체의 주소를 가지고 있음

  printf("change 함수 호출하기 전의 x : %d\n", x);

  change4(&k); //x의 주소를 가진 z의 주소 가지고있는 k의 주소를 넘김. (3중 심층 마트료시카)

  printf("change 함수 호출한 후의 x : %d\n", x);
  // 출력 => change 함수 호출한 후의 x : 50


  return 0;
}