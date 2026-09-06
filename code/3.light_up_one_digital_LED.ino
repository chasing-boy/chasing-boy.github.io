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
