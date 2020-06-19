// 문제 : char 변수 b를 이용하지 않고 b의 값을 훼손
// 조건 : 포인터 변수를 사용해서 값을 변경해야 한다.
// 조건 : 수정가능 지역에서 b 라는 변수를 언급하면(사용하면) 안됩니다.

#include <stdio.h>


// void change(int* a){

//   *a = 50;
// }


void change (int* a, int* b) {

int q = *a;
int w = *b;


*a = w;
*b = q;
  

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


  // change(&x); //이부분만 수정 가능

  
  
  // printf("change 함수 호출한 후의 x : %d\n", x);
  // // 출력 => change 함수 호출한 후의 x : 50


  // 문제 : 값을 교체하는 change 함수를 만들어주세요.
  int a = 60;
  int b = 70;

  printf("change 함수 호출하기 전의 a : %d, b :%d\n", a, b);

  change(&a, &b); // 이부분 수정 가능

  printf("change 함수 호출한 후의 a : %d, b :%d\n", a, b);
  // 출력 => change 함수 호출한 후의 a : 20, b : 10


  return 0;
}