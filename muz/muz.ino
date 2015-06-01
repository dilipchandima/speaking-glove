/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 1;
int led2 = 2;
int led3 = 3;

int flx1;
int flx2;
int flx3;
int flx4;
int flx5;

int tilt;
int out;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  out=getFlex();
  Serial.print("the out put is >> ");
  Serial.println(out);
  if(out==0){Serial.println("there is no signal :( ");}
  else if(out==1){Serial.println("I'm thursty");}
  else if(out==2){Serial.println("I'm hungry");}
  else if(out==3){Serial.println("What is your name ? ");}
  else if(out==4){Serial.println("I'm Nimal , I'm a deaf guy");}
  else if(out==5){Serial.println("Turn on light plz ");}
  else if(out==6){Serial.println("I want to cross the road");}
  else if(out==7){Serial.println("Is this yours ?");}
  else if(out==8){Serial.println("Happy new year");}
  else if(out==9){Serial.println("This is speaking glove");}
  else if(out==10){Serial.println("there is no signal :( ");}
  else if(out==11){Serial.println("there is no signal :( ");}
  else if(out==12){Serial.println("there is no signal :( ");}
  else if(out==13){Serial.println("there is no signal :( ");}
  else if(out==14){Serial.println("there is no signal :( ");}
  else if(out==15){Serial.println("there is no signal :( ");}
  else if(out==16){Serial.println("there is no signal :( ");}
  else if(out==17){Serial.println("there is no signal :( ");}
  else if(out==18){Serial.println("there is no signal :( ");}
  
  
}


void offDigital(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

int getFlex(){
  
  int a=0;
  
  //1111111111111111111111111111
  digitalWrite(led1, HIGH);
  flx1 = analogRead(A5);
  //Serial.print(flx1);
  //Serial.print(" - ");
  offDigital();
  delay(10);
  
  //22222222222222222222222222222222222222
  digitalWrite(led2, HIGH);
  flx2 = analogRead(A5);
  //Serial.print(flx2);
  //Serial.print(" - ");
  offDigital();
  delay(10);
  
  //3333333333333333333333333333333333333333
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  flx3 = analogRead(A5);
  //Serial.print(flx3);
  //Serial.print(" - ");
  offDigital();
  delay(10);
  
  //4444444444444444444444444444444444444
  digitalWrite(led3, HIGH);
  flx4 = analogRead(A5);
  //Serial.print(flx4);
  //Serial.print(" - ");
  offDigital();
  delay(10);
  
  //444444444444444444444444444444444444444
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
  flx5 = analogRead(A5);
  //Serial.print(flx5);
  //Serial.print(" - ");
  offDigital();
  delay(10);
  
  tilt = analogRead(A4);
  //Serial.println(tilt);
  offDigital();
  delay(1000);
  
//  if(tilt>400){
//    Serial.print("Hand is up"); 
//  }else{
//    Serial.print("Hand is down");
//  }
//  
//    if(flx1>300 && flx2>300 && flx3>300 && flx4>300 && flx5>300){
//      Serial.println(" and fingers are together");
//    }else{
//      Serial.println(" and fingers are not together");
//    }
  
  if(tilt>400){
    if(flx1>300 && flx2>300 && flx3>300 && flx4>300 && flx5>300){a=1;} //All finger are together
    else if(flx1<300 && flx2<300 && flx3<300 && flx4<300 && flx5<300){a=2;} //All are streatched
    
    else if(flx1>300 && flx2<300 && flx3<300 && flx4<300 && flx5<300){a=3;} //Thumb is folded
    else if(flx1<300 && flx2>300 && flx3<300 && flx4<300 && flx5<300){a=4;} //finger2
    else if(flx1<300 && flx2<300 && flx3>300 && flx4<300 && flx5<300){a=5;} //finger3
    else if(flx1<300 && flx2<300 && flx3<300 && flx4>300 && flx5<300){a=6;} //finger4
    else if(flx1<300 && flx2<300 && flx3<300 && flx4<300 && flx5>300){a=7;} //finger5
    
    else if(flx1>300 && flx2>300 && flx3<300 && flx4<300 && flx5<300){a=8;} //thumb and finger1 folded
    else if(flx1<300 && flx2>300 && flx3>300 && flx4<300 && flx5<300){a=9;} //finger1 and finger2
    else if(flx1<300 && flx2<300 && flx3>300 && flx4>300 && flx5<300){a=10;} //finger2 nd 3
    else if(flx1<300 && flx2<300 && flx3<300 && flx4>300 && flx5>300){a=11;} //finger3 and 4
    else if(flx1>300 && flx2<300 && flx3<300 && flx4<300 && flx5>300){a=11;} //thumb and 4
    else if(flx1>300 && flx2<300 && flx3<300 && flx4>300 && flx5<300){a=11;} //thumb and 3
    else if(flx1>300 && flx2<300 && flx3>300 && flx4<300 && flx5<300){a=11;} //thumb and 2
    
    else if(flx1<300 && flx2>300 && flx3>300 && flx4>300 && flx5>300){a=12;} //all without thumb
    else if(flx1<300 && flx2<300 && flx3>300 && flx4>300 && flx5>300){a=13;} //without thumb and fing1
    else if(flx1<300 && flx2>300 && flx3<300 && flx4>300 && flx5>300){a=14;} //without thumb and 2
    else if(flx1<300 && flx2>300 && flx3>300 && flx4<300 && flx5>300){a=15;} //
    else if(flx1<300 && flx2>300 && flx3>300 && flx4>300 && flx5<300){a=16;}
    
    else if(flx1<300 && flx2<300 && flx3>300 && flx4>300 && flx5>300){a=17;}
    else if(flx1<300 && flx2<300 && flx3<300 && flx4>300 && flx5>300){a=18;}
    else if(flx1<300 && flx2>300 && flx3<300 && flx4<300 && flx5>300){a=19;}
    else if(flx1<300 && flx2>300 && flx3>300 && flx4<300 && flx5<300){a=20;}
    
    
    
  }else{
    if(flx1>300 && flx2>300 && flx3>300 && flx4>300 && flx5>300){a=21;}
    else if(flx1<300 && flx2<300 && flx3<300 && flx4<300 && flx5<300){a=22;}
    
    else if(flx1>300 && flx2<300 && flx3<300 && flx4<300 && flx5<300){a=23;}
    else if(flx1<300 && flx2>300 && flx3<300 && flx4<300 && flx5<300){a=24;}
    else if(flx1<300 && flx2<300 && flx3>300 && flx4<300 && flx5<300){a=25;}
    else if(flx1<300 && flx2<300 && flx3<300 && flx4>300 && flx5<300){a=26;} 
    else if(flx1<300 && flx2<300 && flx3<300 && flx4<300 && flx5>300){a=27;}
    
    else if(flx1>300 && flx2>300 && flx3<300 && flx4<300 && flx5<300){a=28;}
    else if(flx1<300 && flx2>300 && flx3>300 && flx4<300 && flx5<300){a=29;}
    else if(flx1<300 && flx2<300 && flx3>300 && flx4>300 && flx5<300){a=30;}
    else if(flx1<300 && flx2<300 && flx3<300 && flx4>300 && flx5>300){a=31;}
    
    else if(flx1<300 && flx2>300 && flx3>300 && flx4>300 && flx5>300){a=32;}
    else if(flx1<300 && flx2<300 && flx3>300 && flx4>300 && flx5>300){a=33;}
    else if(flx1<300 && flx2>300 && flx3<300 && flx4>300 && flx5>300){a=34;}
    else if(flx1<300 && flx2>300 && flx3>300 && flx4<300 && flx5>300){a=35;}
    else if(flx1<300 && flx2>300 && flx3>300 && flx4>300 && flx5<300){a=36;}
    
    else if(flx1<300 && flx2<300 && flx3>300 && flx4>300 && flx5>300){a=37;}
    else if(flx1<300 && flx2<300 && flx3<300 && flx4>300 && flx5>300){a=38;}
    else if(flx1<300 && flx2>300 && flx3<300 && flx4<300 && flx5>300){a=39;}
    else if(flx1<300 && flx2>300 && flx3>300 && flx4<300 && flx5<300){a=40;}
  }
  
  return a;
  
  Serial.println("-------------------------------------------------");
  
}
