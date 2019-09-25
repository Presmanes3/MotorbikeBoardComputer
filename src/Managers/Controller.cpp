#include "Controller.h"

#include "../AbstractClasses/ControllerAction.h"
#include "LcdManager.h"

void Controller::setup( ) {

  // void(*tempFunc);
  // tempFunc = this->encoder.service( );

  encoder.setAccelerationEnabled(true);

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
      this->actions[UP]->execute( ); // Execute Up Action

    } else if(tempEncPos < tempOldEncPos) {
      this->actions[DOWN]->execute( ); // Execute Down Action
    }
  }
  if(this->buttonState != 0) {
    switch(buttonState) {
      case 3:
        this->actions[PRESS]->execute( ); // Execute Press Action
        break;

      case 4:
        this->actions[RELEASE]->execute( ); // Execute Release Action
        break;

      case 5:
        this->actions[CLICK]->execute( ); // Execute Click Action
        break;

      case 6:
        this->actions[DOUBLE_CLICK]->execute( ); // Execute Double Click Action
        break;
    }
  }
}

void Controller::setFunctionality(ControllerAction* newControllerAction,
                                  Button            actionId) {
  this->actions[actionId] = newControllerAction;
}

LcdManager* Controller::getLcdManager( ) { return this->manager; }