# ButtonControlForOBS

## [Melbel Pico](https://mellbell.cc/products/pico)  
### Melbel Pico라는 아두이노 레오나르도와 같은 칩을 쓰는 모듈을 사용함  

[![](https://cdn.shopify.com/s/files/1/0005/5522/1039/products/Main_2_1024x1024@2x.jpg?v=1553440263)](https://youtu.be/UUvNUbrtRTo)  

### simpletest.ino : 2번핀의 통전 여부에 따라 Alt+F5 또는 Alt+F6의 키보드 신호를 보냄, 추후 블루투스 리모콘 형식으로 만들 때는 요것을 사용해야 함.  
### interrupt.ino : 0, 1, 2, 3번핀의 인터럽트 기능만을 이용해 Alt+F5~F8의 키보드 신호를 보냄, 실제 전극의 인터럽트를 이용해 사용하는 방법이므로 usb케이블을 연결하여 사용할 때 신뢰도 높게 사용할 수 있음, 원격으로 사용할 때는 이 코드를 이용해 송신기를 만들고 송수신기에 모두 블루투스를 추가하여 데이터를 보낸 다음 수신기의 레오나르도 보드가 컴퓨터에 신호를 주는 형태로 가야함, 아니면 송신기는 새로 코드를 만들어서 디지털 입력으로 코드를 짜고, 특정 문자를 수신기에 보낸다음 수신기가 키보드 역할을 하는 부분만 제어하게 할 수도 있음  

