/*[ change extension .c to .ino to open with arduino IDE]
 * program: 8X8 LED matrix With Arduino UNO.
 * date: 21-December-2019
 * 
 * created by: jumail j
 * email: jumailjuraige@gmail.com
 * youtube: https://www.youtube.com/channel/UCdjiWUU1SLCQn52mBozbsrQ
 * 
 * (*) i just revers x,y cordinates;
 * 
 * x- Horizonal*
 * y- Vertical*
 *  
 *    positions:                    pin allocation:  connect led anode to 'x' and cathod to 'y' as parallel;
 *                                    ^
 *     | 0 1 2 3 4 5 6 7              |    0   1   2   3   4   5   6   7    
 *   --|----------------          ----|-----------------------------------> (y- axix)*
 *    0| 0 0 0 0 0 0 0 0              |    8  ~9  ~10 ~11  12  13  A5  A4
 *    1| 0 0 0 0 0 0 0 0            0 | 0 -o---o---o---o---o---o---o---o--> (+) 
 *    2| 0 0 0 0 0 0 0 0            1 | 1 -o---o---o---o---o---o---o---o--> (+)
 *    3| 0 0 0 0 0 0 0 0            2 | 2 -o---o---o---o---o---o---o---o--> (+)
 *    4| 0 0 0 0 0 0 0 0            3 |~3 -o---o---o---o---o---o---o---o--> (+)              _ _
 *    5| 0 0 0 0 0 0 0 0            4 | 4 -o---o---o---o---o---o---o---o--> (+)             / _  \ 
 *    6| 0 0 0 0 0 0 0 0            5 |~5 -o---o---o---o---o---o---o---o--> (+)            |_/_||_| (led) :)
 *    7| 0 0 0 0 0 0 0 0            6 |~6 -o---o---o---o---o---o---o---o--> (+)              |  |
 *                                  7 | 7 -o---o---o---o---o---o---o---o--> (+)          (+) |  | (-)
 *                                    \/   |   |   |   |   |   |   |   |
 *                              x-(axix)* (-) (-) (-) (-) (-) (-) (-) (-)                                                                                            
 */ 

//global var;
byte x[8];
byte y[8];
int i = 0;

#include "ledSequences.h"

void DigonalUpLeftToDownRight();
void DigonalUpRightToDownLeft();
void DigonalDownLeftToUpRight();
void DigonalDownRightToUpLeft();

void ledOn();
void ledOff();

void DownAndUpWithReverse();
void Down();


void setup(){ 
/// seting pinMode relative to pinNumber of X;
for( i = 0; i<8; i++) {
x[i] = i;
pinMode(x[i] ,OUTPUT);
}

//seting pinMode relative to pinNumber of Y;
for( i = 0; i<=5; i++) {
  y[i] = i+8;
  pinMode(y[i],OUTPUT);
}
y[6] = 19; // A5;
y[7] = 18; // A4;
pinMode(y[6], OUTPUT);// A5;
pinMode(y[7], OUTPUT);// A4;

}

void loop(){


DigonalUpLeftToDownRight();
delay(60);

DigonalDownRightToUpLeft();
delay(60);

DigonalUpRightToDownLeft();
delay(60);

DigonalDownLeftToUpRight();
delay(60);


}



void DigonalUpRightToDownLeft() {
 for( i = 0; i<= 7; i++) {
    ///change y series to Positive;
      digitalWrite(y[i],HIGH);
    }
    
    for(i = 0; i<= 7; i++) {
      digitalWrite(x[i],HIGH);
      digitalWrite(y[7-i],LOW);
      delay(60);
    }
    delay(60);
   
    /// change x to Negative;
    for(i  = 0; i<= 7; i++) {
    digitalWrite(x[i],LOW);
    }
}

void DigonalDownRightToUpLeft() {
  ///change y to Positive;
 for( i = 0; i<= 7; i++) {
      digitalWrite(y[i],HIGH);
    }
    
  for( i =7; i>= 0;i--) {
    digitalWrite(x[i],HIGH);
    digitalWrite(y[i],LOW);
    delay(60);
  } 
    delay(60);
     /// change x to Negative;
    for(i  = 0; i<= 7; i++) {
    digitalWrite(x[i],LOW);
    }
}
void DigonalUpLeftToDownRight() {
///change y to Positive;
 for( i = 0; i<= 7; i++) {
      digitalWrite(y[i],HIGH);
    }

    for(i = 0; i<= 7; i++) {
    digitalWrite(y[i],LOW);
    digitalWrite(x[i],HIGH);
    delay(60);
    }
    delay(60);
    
  /// change x to Negative;
      for(i  = 0; i<= 7; i++) {
    digitalWrite(x[i],LOW);
    }
}
void DigonalDownLeftToUpRight() {
  ///change y to Positive;
  for( i = 0; i <= 7; i++) {
    digitalWrite(y[i],HIGH);
  }
  
  for( i = 0; i<= 7; i++) {
   digitalWrite(x[7-i],HIGH);
   digitalWrite(y[i],LOW);
   delay(60);
  }
   delay(60);
   
   /// change x to Negative;
  for( i = 0; i <= 7; i++) {
    digitalWrite(x[i],LOW);
  }
}
