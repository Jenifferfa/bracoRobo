
#include <Servo.h>
#include <Wire.h>
#include <SoftwareSerial.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
//SoftwareSerial Serial(11,12);
String command = "";

int valor = 90;
int pinServo1 = 4;
int pinServo2 = 6;
int pinServo3 = 8;
int pinServo4 = 10;
int pos[4];
int entrada;

void setup()
{
  myservo1.attach(pinServo1);
  myservo2.attach(pinServo2);
  myservo3.attach(pinServo3);
  myservo4.attach(pinServo4);

  myservo1.write(120); // vai do angulo reto ae 0 e de 0 a 180
  myservo2.write(0); //ombro
  myservo3.write(0); //cotovelo
  myservo4.write(0); //garra
  Serial.println("Digite os comandos AT: "); 
  //Inicia a serial configurada nas portas 6 e 7
   
  Serial.begin(9600); 
  pos[0]=90;
  pos[1]=0;
  pos[2]=0;
  pos[3]=0;
}

void loop()
{
  char caracter;


  if (Serial.available() > 0) 
  {
    caracter = Serial.read();



    if(caracter == 'S')valor=0;  
    if(caracter == '0')valor=(valor * 10) + 0;
    if(caracter == '1')valor=(valor * 10) + 1;
    if(caracter == '2')valor=(valor * 10) + 2;
    if(caracter == '3')valor=(valor * 10) + 3;
    if(caracter == '4')valor=(valor * 10) + 4;
    if(caracter == '5')valor=(valor * 10) + 5;
    if(caracter == '6')valor=(valor * 10) + 6;
    if(caracter == '7')valor=(valor * 10) + 7;
    if(caracter == '8')valor=(valor * 10) + 8;
    if(caracter == '9')valor=(valor * 10) + 9;
    Serial.println(valor);
    if(caracter == 'X')
    {
      //myservo1.write(90);
      myservo1.write(valor);
      pos[0]=valor;
    }
    if(caracter == 'Y')
    {
      myservo2.write(valor);
      pos[1]=valor;
    }
        if(caracter == 'Z')
    {
      myservo3.write(valor);
      pos[2]=valor;
    }
    if(caracter == 'G')
    {
      myservo4.write(valor);
      pos[3]=valor;
    }
     
    //eixo X horario
    if(caracter == 'A')
    {
      if(pos[0]<170)
      {
        pos[0]+=10;
        myservo1.write(pos[0]);
      }
    }
    
    //eixo X anti-horario
    else if(caracter == 'a')
    { 
      if(pos[0]>10)
      {
        pos[0]-=10;
        myservo1.write(pos[0]);
      }
    }
    
    //Y horario
    else if(caracter == 'B') 
    {
      if(pos[1]<170)
      {
        pos[1]+=10;
        myservo2.write(pos[1]);
      }
    }
    
    //Y anti-horario
    else if(caracter == 'b') 
    {
      if(pos[1]>10)
      {
        pos[1]-=10;
        myservo2.write(pos[1]);
      }
    }
    
    //Eixo Z
    else if(caracter == 'C')
    {
      if(pos[2]<170)
      {
         pos[2]+=10;
        myservo3.write(pos[2]);
      }
    } 
    
    //Z anti horario
    else if(caracter == 'c') 
    {
      if(pos[2]>10)
      {
        pos[2]-=10;
        myservo3.write(pos[2]);
      }
    }
    
    //Garra abrir
    else if(caracter == 'D')
    {
      if(pos[3]<170)
      {
        pos[3]+=10;
        myservo4.write(pos[3]);
      }
    } 
    
    //Garrafachar
    else if(caracter == 'd') 
    {
      if(pos[3]>10)
      {
        pos[3]-=10;
        myservo4.write(pos[3]);
      }
    }
        
    //zerar tudo 90 graus
    else if(caracter == 'E') 
    {
      valor = 90;
      pos[0] = valor;
      delay(1000);
      valor = 0;
      pos[1] = valor;
      delay(1000);
      pos[2] = valor;
      delay(1000);
      pos[3] = valor;
      myservo1.write(pos[0]);
      myservo2.write(pos[1]);
      myservo3.write(pos[2]);
      myservo4.write(pos[3]);  
    }
  }
}
