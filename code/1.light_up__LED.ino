//使LED闪烁
//开发板12引脚连接LED正极，LDE串联电阻，电阻另一端接地。
int led_pin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_pin,HIGH);
  delay(1000);
  digitalWrite(led_pin,LOW);
  delay(1000);
}