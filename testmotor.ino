#define in1 2                       //Motor1 tb66fng12 H bridge
#define in2 3                       //Motor1 tb66fng12 H bridge
#define pwma 4
#define stby 5
int Speed = 255;
int key;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(pwma,OUTPUT);
}
void front()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(pwma,Speed);
}

void back()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(pwma,Speed);
}
void Stp()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(pwma,0);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0)
  {  
    key=Serial.read();
    
    if(key == 'F')
    {
      front();
      Serial.println("Foreward: "+Speed);
    }
    else if(key == 'B')
    {
      back();
      Serial.println("Backward: "+Speed);
    }
    else if(key == '0')
    {
      Speed = 115;
      //Serial.println("Speed = 115");
    }
    else if(key == '1')
    {
      Speed = 130;
      //Serial.println("Speed = 130");
    }
    else if(key == '2')
    {
      Speed = 143;
      //Serial.println("Speed = 143");
    }
    else if(key == '3')
    {
      Speed = 157;
      //Serial.println("Speed = 157");
    }
    else if(key == '4')
    {
      Speed = 170;
      //Serial.println("Speed = 170");
    }
    else if(key == '5')
    {
      Speed = 185;
      //Serial.println("Speed = 185");
    }
    else if(key == '6')
    {
      Speed = 200;
      //Serial.println("Speed = 200");
    }
    else if(key == '7')
    {
      Speed = 213;
      //Serial.println("Speed = 213");
    }
    else if(key == '8')
    {
      Speed = 227;
      //Serial.println("Speed = 227");
    }
    else if(key == '9')
    {
      Speed = 240;
      //Serial.println("Speed = 240");
    }
    else if(key == 'q')
    {
      Speed = 255;
      //Serial.println("Speed = 255");
    }
    else
    {
      Stp();
      Serial.println("Stop: "+0); 
    }
    delay(5);
  }
}
