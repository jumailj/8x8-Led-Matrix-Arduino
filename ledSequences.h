
/// functions prototyes;
void ledOn();
void ledOff();
void DownAndUpWithReverse();
void Down();

int i =0;
/// turn led on;
void ledOn() {
    
    for( i = 0; i <= 7; i ++) {
        digitalWrite(x[i],HIGH);
        digitalWrite(y[i],LOW);
    }

}

/// turn led off;
void ledOff() {
        for( i = 0; i <= 7; i ++) {
        digitalWrite(x[i],LOW);
        digitalWrite(y[i],HIGH);
    }
} 
  

/// Down And UP;
void DownAndUpWithReverse() {
  /// chaning -y to negative;
  for( i = 0; i<= 7; i++) {
    digitalWrite(y[i], LOW);
  }
/// delayed +x to positive;
  for( i = 0; i<= 7; i++) {
    delay(40);
    digitalWrite(x[i], HIGH);
/// delayd revers +x to negative;
  }
  for( i = 7; i >= 0; i--) {

    delay(40);
    digitalWrite(x[i],LOW);
  }
   

/// for delayed +x to positive;
  for( i = 7; i>= 0; i--) {
    delay(40);
    digitalWrite(x[i],HIGH);
  }

  delay(40);

/// for delayed +x to negative;
  for( i = 0; i<= 7; i++) {
    delay(40);
    digitalWrite(x[i],LOW);
  }
  
}// downAnd up;

void Down(){
  /// chaning -y to negative;
  for( i = 0; i<= 7; i++) {
    digitalWrite(y[i], LOW);
  }
/// delayed +x to positive;
  for( i = 0; i<= 7; i++) {
    delay(40);
    digitalWrite(x[i], HIGH);
/// delayd revers +x to negative;
  }
  for( i = 7; i >= 0; i--) {

    delay(40);
    digitalWrite(x[i],LOW);
  }

  for(int i = 0; i<= 7; i++) {
     digitalWrite(y[i],HIGH);
  }

}