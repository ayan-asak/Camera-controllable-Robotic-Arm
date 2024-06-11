#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;  
char c;
int tips[5];

void setup() 
{ 
  // pinMode(2,OUTPUT);
  // pinMode(3,OUTPUT);
  // pinMode(4,OUTPUT);
  // pinMode(5,OUTPUT);
  // pinMode(6,OUTPUT);
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6); 
  
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}
 int rep;
void loop() 
{
  // digitalWrite(2,1);
// OCdemo();

  if(Serial.available())
  {
    String str;
    int  bits;
    str=Serial.readString();

    convert(str);
    // Serial.print("Bits: ");
    // Serial.println(tips);
    // for(int i=0;i<5;i++)
    // {
    //   Serial.print(tips[i]);
    // }

    toServos();
    // break;
  }
    
delay(50);

}

void convert(String data)
{
    int  bits=data.toInt();
    
    int element;
    bits=(data.toInt());
    for(int i=4;i>=0;i--)
    {
      element=bits%10;
      // Serial.println(element);
      bits=bits/10;
      // Serial.println(bits);
      tips[i]=element;
    }
    // for(int i=0;i<5;i++)
    // {
    //   Serial.print(farray[i]);
    // }
    // return farray;


}

void toServos()
{
  // String str="";
  // digitalWrite(6,tips[0]);
  // digitalWrite(5,tips[1]);
  // digitalWrite(4,tips[2]);
  // digitalWrite(3,tips[3]);
  // digitalWrite(2,tips[4]);
  // for (int i = 0; i < 5; i++) 
  // {
  //   str += String(tips[i]);
  // }
  // delay(500);

  myservo1.write(tips[0]*180);
  myservo2.write(tips[1]*180);
  myservo3.write(tips[2]*180);
  myservo4.write(tips[3]*180);
  myservo5.write(tips[4]*180);
  
  Serial.println("got it");
}

