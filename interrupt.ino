// 요건 바로 사용 가능 버전. 인터럽트만으로 제어함. 1, 0, 2, 3번 인터럽트 핀이 작동되면 알트 F5, 알트 F6, 알트 F7, 알트 F8이 눌러짐

#include <Keyboard.h>                //키보드함수 헤더 포함
#define interruptPin1 1
#define interruptPin0 0
#define interruptPin2 2
#define interruptPin3 3

// 아직 보완중
// 키보드로는 PS2방식이든 USB 방식이든 어떤 창에서나 OBS 화면전환을 위한 단축키가 작동하지만, 요상하게도 얘는 OBS창이 활성화 되어 있을 때만 작동한다.
// 따라서 다른 창에서 작업을 하다가 버튼을 누르면 OBS로 창변환을 한 다음 단축키를 누르게 설정할 필요가 있었다. 
// 그래서 for문과 Alt-Tab버튼을 이용하려고 했으나, 이 단축키는 for문의 반복만큼 창이 변환되는 화면이 보여서 버림
// 검색도중 Windows+숫자키가 작업표시줄에 있는 프로그램을 왼쪽부터 순서대로 실행시켜 주는 단축키임을 알게 되었고, 이 단축키를 활용하기로 하였다. 
// 다만, 이 단축키는 창이 이미 활성화 되어 있으면, 하단으로 내리는 역할도 하기 때문에 조정이 필요했다. 
// 그래서 아래와 같이 프로그램 cur_time-pre_time 결과가 3초가 넘으면 다른 작업을 했다고 간주하고 windows 버튼과 숫자 버튼 1을 먼저 누른다음 화면을 전환한다.
// 3초가 되지 않으면 그냥 화면을 잘못 전환한 것으로 판단하고 화면만 바꿔준다.
// 칩의 부하 누적을 막기 위해 cur_time이 10초가 넘으면 다시 3초로 초기화해준다. 


const int duration = 3000;
unsigned long pre_time = 0;
unsigned long cur_time = 0;

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
  cur_time = millis();  
  if(cur_time - pre_time >= duration){ 
    Serial.println("button 1");
    Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('1');             //작업표시줄의 첫번째 아이콘을 실행시키거나 활성화시킴
    Keyboard.releaseAll();
  }
    Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
    Keyboard.press(KEY_F5);          //왼쪽 F5 버튼을 누른채로 유지합니다
    Keyboard.releaseAll();
    pre_time = cur_time; 

}

void button0() {
  cur_time = millis();  
  if(cur_time - pre_time >= duration){ 
    Serial.println("button 0");
    Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('1');             //작업표시줄의 첫번째 아이콘을 실행시키거나 활성화시킴
    Keyboard.releaseAll();
  }

    Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
    Keyboard.press(KEY_F6);          //왼쪽 F5 버튼을 누른채로 유지합니다
    Keyboard.releaseAll();
    pre_time = cur_time; 
    
}

void button2() {
  cur_time = millis();  
  if(cur_time - pre_time >= duration){ 
    Serial.println("button 2");
    Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('1');             //작업표시줄의 첫번째 아이콘을 실행시키거나 활성화시킴
    Keyboard.releaseAll();
  }
    Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
    Keyboard.press(KEY_F7);          //왼쪽 F5 버튼을 누른채로 유지합니다
    Keyboard.releaseAll();
    pre_time = cur_time; 

}

void button3() {
  cur_time = millis();  
  if(cur_time - pre_time >= duration){ 
    Serial.println("button 3");
    Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('1');             //작업표시줄의 첫번째 아이콘을 실행시키거나 활성화시킴
    Keyboard.releaseAll();
  }
    Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
    Keyboard.press(KEY_F8);          //왼쪽 F5 버튼을 누른채로 유지합니다
    Keyboard.releaseAll();
    pre_time = cur_time; 

}
