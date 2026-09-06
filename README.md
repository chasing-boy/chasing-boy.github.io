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






## 1.点亮一颗LED

引脚又叫管脚，英文名叫pin。

其中有一类引脚叫GPIO（General-purpose input/output），负责输入/输出电压。

电平： 电路上某点的电压或点位是高还是低。比如esp32中，高于2.5V为高电平，低于0.5V为低电平。

LED（light-emitting diode）发光二极管：单向导电，电流越大，亮度越亮，但电流过大，会烧毁二极管，一般控制在3mA~20mA。通常会在LED管脚上串联一个电阻，用来限制二极管的电流，故该电阻又叫**限流电阻**。当二极管发光时，其引脚间电压为1.7V，这个电压又叫发光二极管的**导通压降**。



首先在arduino IDE中选择开发环境-ESP32S3 Dev Module

新建文件，有两个函数**setup()和loop()**，setup只有在通电的时候会运行一次，之后都是循环运行loop()。

开发板12引脚连接LED正极，LDE串联电阻，电阻另一端接地。

```c++
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
```

编译：ardnuio IDE点击右上角'√'。

烧录到开发板：点击左上角'—>'箭头



## 2.LED流水灯





## 3.一位数码管显示

数码管：便宜、简单、好用，其基本单元依然是LED.

按照发光二极管单元的连接方式可分为：`共阳极数码管`和`共阴极数码管`

 - 共阳数码管：是指将所有发光二极管的`阳极`接到一起形成`公共阳极(公共端COM)`的数码管，将公共阳极接电源VCC，当某一引脚接地时，该LED单元点亮
 - 共阴数码管：是指将所有发光二极管的`阴极`接到一起形成`公共阴极(COM)`的数码管，将公共阴极接GND



判断共阴还是共阳？

- 1.查型号


- 2.跳线检测：元器件公共端通过一个限流电阻接电源，跳线连接GND与数码管的LED引脚，亮了则为共阳


- 3.万用表：使用万用表的二极管挡位，红表笔接公共端，黑表笔接任一引脚，亮了则为共阳

```C++
//实验使用共阳数码管

//将数码管引脚与ESP32对应引脚接起来，COM通过一只限流电阻连接ESP引脚3.3V
//定义引脚
int pin_a = 4;
int pin_b = 5;
int pin_c = 19;
int pin_d = 21;
int pin_e = 47;
int pin_f = 2;
int pin_g = 15;
int pin_dp = 18;

//定义所有引脚的数组
int pin_array[8] = {pin_a,pin_b,pin_c,pin_d,pin_e,pin_f,pin_g,pin_dp};

//定义数码管数字显示逻辑的数组(共阳-引脚低电平对应LED点亮)
int number_array[][8]= {
  //a，b，c，d，e，f，g，dp
  {0, 0, 0, 0, 0, 0, 1, 1},//0
  {1, 0, 0, 1, 1, 1, 1, 1},//1
  {0, 0, 1, 0, 0, 1, 0, 1},//2
  {0, 0, 0, 0, 1, 1, 0, 1},//3
  {1, 0, 0, 1, 1, 0, 0, 1},//4
  {0, 1, 0, 0, 1, 0, 0, 1},//5
  {0, 1, 0, 0, 0, 0, 0, 1},//6
  {0, 0, 0, 1, 1, 1, 1, 1},//7
  {0, 0, 0, 0, 0, 0, 0, 1},//8
  {0, 0, 0, 0, 1, 0, 0, 1},//9
  {1, 1, 1, 1, 1, 1, 1, 0},//.
};

//数码管显示数字
void display_number(int num){
  if(num>=0&num<=9){
    for(int i=0;i<8;i++){
      digitalWrite(pin_array[i],number_array[num][i]);
    }
  }else{
    for(int i=0;i<8;i++){
      digitalWrite(pin_array[i],number_array[10][i]);
    }
  }
}

void setup() {
  // 初始化引脚 
  for(int i=0;i<8;i++){
    pinMode(pin_array[i],OUTPUT);//设置为输出引脚
    digitalWrite(pin_array[i],HIGH);//高电平->设置全暗
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //数码管 模拟倒计时
  for(int num=9;num>=-1;num--){//（9、8、...1、0、.），0后显示小数点
    display_number(num);
    delay(500);//延时500ms
  }
}

```





## 4.四位数码管显示









