//使用4位共阳极数码管实验
//定义位选线引脚 每个位选线都通过1个1KΩ电阻与ESP32引脚连接
int seg_1 = 5;
int seg_2 = 18;
int seg_3 = 19;
int seg_4 = 21;

//定义位选线数组
int seg_array[4] = {seg_1,seg_2,seg_3,seg_4};

//定义段选线引脚 直接与ESP32引脚连接
int pin_a = 45;
int pin_b = 41;
int pin_c = 35;
int pin_d = 36;
int pin_e = 37;
int pin_f = 38;
int pin_g = 39;
int pin_dp = 40;

//定义段选线的数组
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
//参数 n:第几位点亮(从0开始)，num:要显示的数字
void display_number(int n, int num){
  clear();
  digitalWrite(seg_array[n],HIGH);
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

void clear(){
  // 初始化引脚 位选线为低电平，片选线为高电平
  // 当位选线为高电平时为连通状态，片选线为低电平时为连通状态
  for(int i=0;i<4;i++){
    pinMode(seg_array[i],OUTPUT);
    digitalWrite(seg_array[i],LOW);
  }
  for(int i=0;i<8;i++){
    pinMode(pin_array[i],OUTPUT);
    digitalWrite(pin_array[i],HIGH);
  }
}
void setup() {
  clear();
}

void loop() {
  // 每位数码管循环显示0-9及小数点
  for(int i=0;i<4;i++){
    for(int j=0;j<11;j++){
      display_number(i,j);
      delay(500);
    }
  } 
}
