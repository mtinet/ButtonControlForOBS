// 요건 테스트 버전. 2번핀에 연결된 스위치를 누르거나 떼면 알트 F5나 알트 F6이 눌러짐.

#include <Keyboard.h>                  //키보드함수 헤더 포함
#define button 2                       //2번 핀을 스위치로
#define interruptPin 3
boolean state = true;

void setup()
{
  pinMode(button,INPUT_PULLUP);        //스위치 핀 입력으로 설정
  pinMode(interruptPin,INPUT_PULLUP);
  Keyboard.begin();                    //키보드함수 작동 함수
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interruptPin), exchange, FALLING);  
}

void loop(){
  if(state==false){
    if(digitalRead(button)==LOW)       //스위치가 눌렸을때
    {
      Serial.println("LOW");
      Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
      Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
      Keyboard.press(KEY_F5);          //왼쪽 F5 버튼을 누른채로 유지합니다
      Keyboard.releaseAll();           //모든 키보드를 초기화합니다
      delay(200);                      //채터링을 방지하기위해 잠시 대기합니다
    } else {
      Serial.println("HIGH");
      Keyboard.releaseAll();           //혹시모를 간섭을 방지하기 위하여 모든 키보드를 초기화합니다
      Keyboard.press(KEY_LEFT_ALT);    //왼쪽 알트를 누름
      Keyboard.press(KEY_F6);          //F6을 누른채로 유지합니다
      Keyboard.releaseAll();           //모든 키보드를 초기화합니다
      delay(200); 
    }
  }
}

//무한 루핑 방지.. 딜레이가 안 먹어서 마이크로세컨즈도 넣어봤지만 안먹음.. 그냥 여러번 해서 멈추면 프로그램 재업로드 하면됨
void exchange() {
 state=!state;
 Serial.println("state change");
 
}
