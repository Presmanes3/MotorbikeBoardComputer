#include "Controller.h"

void Controller::setup( ) {

  // void(*tempFunc);
  // tempFunc = this->encoder.service( );

  encoder.setAccelerationEnabled(true);

#if CONTROLLER_DEBUG
  Serial.print(F("Acceleration is : "));
  Serial.println((encoder.getAccelerationEnabled( )) ? F("Enabled")
                                                     : F("Disabled"));
#endif

  this->oldEncPos = -1;
}
void Controller::timerIsr( ) { this->encoder.service( ); }

void Controller::update( ) {
  this->encPos += this->encoder.getValue( );
  this->buttonState = this->encoder.getButton( );

  if(this->encPos != this->oldEncPos) {
    int16_t tempEncPos    = this->encPos;
    int16_t tempOldEncPos = this->oldEncPos;
    this->oldEncPos       = this->encPos; // reset the value

    if(tempEncPos > tempOldEncPos) {
#if CONTROLLER_DEBUG
      Serial.println(F("Aumentado"));
#endif

      this->upFunc[UP]( );

    } else if(tempEncPos < tempOldEncPos) {
#if CONTROLLER_DEBUG
      Serial.println(F("Disminuido"));
#endif

      this->upFunc[DOWN]( );
    }
  }

  if(this->buttonState != 0) {
    if(buttonState == 3) {
#if CONTROLLER_DEBUG
      Serial.println("Pulsado");
#endif

      this->upFunc[PRESSED]( );
    } else if(buttonState == 4) {
#if CONTROLLER_DEBUG
      Serial.println("Soltado");
#endif

      this->upFunc[UNPRESSED]( );
    } else if(buttonState == 5) {
#if CONTROLLER_DEBUG
      Serial.println("Click");
#endif

      this->upFunc[CLICK]( );
    } else if(buttonState == 6) {
#if CONTROLLER_DEBUG
      Serial.println("Doble Click");
#endif

this->upFunc[DOUBLE_CLICK]( );
    }
  }
}

void Controller::setFunctionality(void (*newFunc)( ), Button action) {
  this->upFunc[action] = newFunc;
}