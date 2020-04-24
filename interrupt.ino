// 요건 바로 사용 가능 버전. 인터럽트만으로 제어함. 1, 0, 2, 3번 인터럽트 핀이 작동되면 알트 F5, 알트 F6, 알트 F7, 알트 F8이 눌러짐

#include <Keyboard.h>                //키보드함수 헤더 포함
#define interruptPin1 1
#define interruptPin0 0
#define interruptPin2 2
#define interruptPin3 3

void setup()
{
  pinMode(interruptPin1,INPUT_PULLUP);
  pinMode(interruptPin0,INPUT_PULLUP);
  pinMode(interruptPin2,INPUT_PULLUP);
  pinMode(interruptPin3,INPUT_PULLUP);
  Keyboard.begin();                  //키보드함수 작동 함수
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), button1, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin0), button0, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), button2, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), button3, FALLING);  
}

void loop(){
//  요기는 신호가 잘 가는지 테스트 하려고 썼던 코드임  
//  Serial.println("hhh");
//  delay(100);
//  Serial.println("ooo");
//  delay(100);
}

void button1() {
 Serial.println("button 1");
 Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
 Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
 Keyboard.press(KEY_F5);          //왼쪽 F5 버튼을 누른채로 유지합니다
 Keyboard.releaseAll();
}

void button0() {
 Serial.println("button 0");
 Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
 Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
 Keyboard.press(KEY_F6);          //왼쪽 F6 버튼을 누른채로 유지합니다
 Keyboard.releaseAll();
}

void button2() {
 Serial.println("button 2");
 Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
 Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
 Keyboard.press(KEY_F7);          //왼쪽 F7 버튼을 누른채로 유지합니다
 Keyboard.releaseAll();
}

void button3() {
 Serial.println("button 3");
 Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
 Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
 Keyboard.press(KEY_F8);          //왼쪽 F8 버튼을 누른채로 유지합니다
 Keyboard.releaseAll();
}
