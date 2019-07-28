#include "Dependencies.h"

Controller myController;
Lcd        myLcd;

void clickTest( );
void doubleClickTest( );
void pressTest( );
void releaseTest( );
void upTest( );
void downTest( );

void setup( ) {

  Serial.begin(9600);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(wrapperIsr);

  myController.setup( );

  myLcd.setup( );

  myController.setFunctionality(clickTest, CLICK);
  myController.setFunctionality(doubleClickTest, DOUBLE_CLICK);
  myController.setFunctionality(pressTest, PRESS);
  myController.setFunctionality(releaseTest, RELEASE);
  myController.setFunctionality(upTest, UP);
  myController.setFunctionality(downTest, DOWN);

  // put your setup code here, to run once:
}

void loop( ) {

  myController.update( );
  myLcd.update( );

  // put your main code here, to run repeatedly:
}

// Wrapper to the Encoder ISR
void wrapperIsr( ) { myController.timerIsr( ); }

void clickTest( ) { Serial.println(F("Clicked")); }
void doubleClickTest( ) { Serial.println(F("Double Clicked")); }
void pressTest( ) { Serial.println(F("Press")); }
void releaseTest( ) { Serial.println(F("Release")); }
void upTest( ) { Serial.println(F("Up")); }
void downTest( ) { Serial.println(F("Down")); }