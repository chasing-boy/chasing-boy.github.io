# esp32s3-arduino 学习笔记

**使用ESP32-S3基于arduino IDE ,C++语言**

其中在c++通常想要获取一个数据的大小：sizeOf(myArray)/Size(myArray[0])



arduino常用函数：

- pinMode(pin,mode)：配置数字引脚的输入/输出模式。pin是数字引脚的编号，mode是要设置的模式(输入/输出)
- digitalWrite(pin,value)：用于在数字引脚上写入数字值(HIGH/LOW).pin是数字引脚的编号，value是要写入的值。
- digitalRead(pin)：用于读取数字引脚上的数字值(HIGH/LOW)。
- analogRead(pin)：用于读取模拟引脚上的模拟值（0-1023）.
- analogWrite(pin,value)：用于在支持pwm输出的数字引脚上输出模拟值(0-255)
- delay(ms)：用于在程序中创建延时时间(ms)
- Serial.begin(baud)：用于初始化串口通信，baud是波特率
- Serial.println(data)：用于将数据打印到串口监视器。data可以是数字/字符串/其他数据类型。





## 点亮一颗LED

引脚又叫管脚，英文名叫pin。

其中有一类引脚叫GPIO（General-purpose input/output），负责输入/输出电压。

电平： 电路上某点的电压或点位是高还是低。比如esp32中，高于2.5V为高电平，低于0.5V为低电平。

LED（light-emitting diode）发光二极管：单向导电，电流越大，亮度越亮，但电流过大，会烧毁二极管，一般控制在3mA~20mA。通常会在LED管脚上串联一个电阻，用来限制二极管的电流，故该电阻又叫**限流电阻**。当二极管发光时，其引脚间电压为1.7V，这个电压又叫发光二极管的**导通压降**。



首先在arduino IDE中选择开发环境-ESP32S3 Dev Module

新建文件，有两个函数**setup()和loop()**，setup只有在通电的时候会运行一次，之后都是循环运行loop()。

开发板12引脚连接LED正极，LDE串联电阻，电阻另一端接地。

```c++
//使LED闪烁
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
```

编译：ardnuio IDE点击右上角'√'。

烧录到开发板：点击左上角'—>'箭头

