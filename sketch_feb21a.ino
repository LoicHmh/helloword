/****************************************************
  四段数码管实验程序
  数码管显示数字0到9999，逐次循环。即秒表功能。
  http://www.landzo.com/
  This example code is in the public domain.
****************************************************/
//设置阳极接口 
int a = 1; 
int b = 2; 
int c = 3; 
int d = 4; 
int e = 5; 
int f = 6; 
int g = 7; 
int p = 8; 
//设置阴极接口 
int d4 = 9; 
int d3 = 10; 
int d2 = 11; 
int d1 = 12; 
//设置变量 
long n = 0; 
int x = 100; 
//此处数值对时钟进行微调
int del = 550;   

/****************************************************
            初始化部分_setup()函数
****************************************************/
void setup() 
{ 
  //连接数码管12个接口设置输出模式
  pinMode(d1, OUTPUT); 
  pinMode(d2, OUTPUT); 
  pinMode(d3, OUTPUT); 
  pinMode(d4, OUTPUT); 
  pinMode(a, OUTPUT); 
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT); 
  pinMode(f, OUTPUT); 
  pinMode(g, OUTPUT); 
  pinMode(p, OUTPUT); 
} 

/****************************************************
            执行部分_loop()函数
****************************************************/
void loop() 
{ 
  //千位数码管处理部分，千位对应百秒级
  clearLEDs();//清除显示 
  pickDigit(1);//千位数码管公共端开启 
  pickNumber((n/x/1000)%10);//千位数码管显示数字 
  delayMicroseconds(del);//延时del时间 
  
  //百位数码管处理部分，百位对应十秒级
  clearLEDs();//清除显示 
  pickDigit(2);//百位数码管公共端开启 
  pickNumber((n/x/100)%10);//百位数码管显示数字 
  delayMicroseconds(del);//延时del时间 
  
  //十位数码管处理部分，十位对应秒级
  clearLEDs();//清除显示 
  pickDigit(3);//十位数码管公共端开启 
  dispDec(3);//十位数码管显示小数点 
  pickNumber((n/x/10)%10);//十位数码管显示数字 
  delayMicroseconds(del);//延时del时间 

  //个位数码管处理部分，十位对应百毫秒级
  clearLEDs();//清除显示 
  pickDigit(4);//个位数码管公共端开启 
  pickNumber(n/x%10);//个位数码管显示数字 
  delayMicroseconds(del);//延时del时间 
  
  n++;//n是程序循环次数.程序每循环一次，n就加1 
  if (digitalRead(13) == LOW) 
  { 
    n = 0;//当数值超过9999，n清零 
  } 
} 

//定义pickDigit(x),其作用是开启x端口
void pickDigit(int x)   
{ 
  digitalWrite(d1, HIGH); 
  digitalWrite(d2, HIGH); 
  digitalWrite(d3, HIGH); 
  digitalWrite(d4, HIGH); 
  
  switch(x) 
  { 
  case 1:  
    digitalWrite(d1, LOW);  
    break; 
  case 2:  
    digitalWrite(d2, LOW);  
    break; 
  case 3:  
    digitalWrite(d3, LOW);  
    break; 
  default:  
    digitalWrite(d4, LOW);  
    break; 
  } 
} 

//定义pickNumber(x),其作用是显示数字x
void pickNumber(int x)    
{ 
  switch(x) 
  { 
  default:  
    zero();  
    break; 
  case 1:  
    one();  
    break; 
  case 2:  
    two();  
    break; 
  case 3:  
    three();  
    break; 
  case 4:  
    four();  
    break; 
  case 5:  
    five();  
    break; 
  case 6:  
    six();  
    break; 
  case 7:  
    seven();  
    break; 
  case 8:  
    eight();  
    break; 
  case 9:  
    nine();  
    break; 
  } 
} 

//设定开启小数点
void dispDec(int x)   
{ 
  digitalWrite(p, LOW); 
} 

//清屏，即清除当前显示
void clearLEDs()   
{ 
  digitalWrite(a, LOW); 
  digitalWrite(b, LOW); 
  digitalWrite(c, LOW); 
  digitalWrite(d, LOW); 
  digitalWrite(e, LOW); 
  digitalWrite(f, LOW); 
  digitalWrite(g, LOW); 
  digitalWrite(p, LOW); 
} 

//定义数字0时阴极那些管脚开关
void zero()   
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, HIGH); 
  digitalWrite(f, HIGH); 
  digitalWrite(g, LOW); 
} 

//定义数字1时阴极那些管脚开关
void one()   
{ 
  digitalWrite(a, LOW); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, LOW); 
  digitalWrite(e, LOW); 
  digitalWrite(f, LOW); 
  digitalWrite(g, LOW); 
} 

//定义数字2时阴极那些管脚开关
void two()   
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, LOW); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, HIGH); 
  digitalWrite(f, LOW); 
  digitalWrite(g, HIGH); 
} 

//定义数字3时阴极那些管脚开关
void three()   
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, LOW); 
  digitalWrite(f, LOW); 
  digitalWrite(g, HIGH); 
} 

//定义数字4时阴极那些管脚开关
void four()   
{ 
  digitalWrite(a, LOW); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, LOW); 
  digitalWrite(e, LOW); 
  digitalWrite(f, HIGH); 
  digitalWrite(g, HIGH); 
} 

//定义数字5时阴极那些管脚开关
void five()   
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, LOW); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, LOW); 
  digitalWrite(f, HIGH); 
  digitalWrite(g, HIGH); 
} 

//定义数字6时阴极那些管脚开关
void six()   
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, LOW); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, HIGH); 
  digitalWrite(f, HIGH); 
  digitalWrite(g, HIGH); 
} 

//定义数字7时阴极那些管脚开关
void seven()   
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, LOW); 
  digitalWrite(e, LOW); 
  digitalWrite(f, LOW); 
  digitalWrite(g, LOW); 
} 

//定义数字8时阴极那些管脚开关 
void eight()  
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, HIGH); 
  digitalWrite(f, HIGH); 
  digitalWrite(g, HIGH); 
} 

//定义数字9时阴极那些管脚开关
void nine()   
{ 
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, LOW); 
  digitalWrite(f, HIGH); 
  digitalWrite(g, HIGH); 
} 

