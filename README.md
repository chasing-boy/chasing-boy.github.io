# esp32s3-arduino 学习笔记

使用ESP32-S3基于arduino IDE ,使用C++语言

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



