// 문제 : char 변수 b를 이용하지 않고 b의 값을 훼손
// 조건 : 포인터 변수를 사용해서 값을 변경해야 한다.
// 조건 : 수정가능 지역에서 b 라는 변수를 언급하면(사용하면) 안됩니다.

#include <stdio.h>

int main(void) {

  int a = 1;
  int b = 5;

  printf("== 변수의 주소 ==\n");
  printf("&a : %ld\n", (long)&a);
  printf("&b : %ld\n", (long)&b);

  // 수정가능지역 시작
  int *p = &a;
  *p = 2;
  int *u = (&a - 1); //1 은 1이아니라 int는 4바이트를 가지므로 주소에서 4가 빠짐.
  *u = 10;
  printf("p : %ld\n", (long)p);
  // 수정가능지역 끝



  printf("== 변수의 값 ==\n");
  printf("a : %d\n", a);
  // 출력 => a : 2
  printf("b : %d\n", b);
  // 출력 => b : 10
  
  return 0;
}