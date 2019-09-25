#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "ClickEncoder.h"
#include "Common.h"
#include "TimerOne.h"


class ControllerAction;
class LcdManager;

enum Button { CLICK = 0, DOUBLE_CLICK, PRESS, RELEASE, UP, DOWN };

class Controller {

  public:
  // Controller( );

  // Update function to read update the encoder variable
  void update( );

  // All functions to initialize the controller
  void setup( );

  void timerIsr( );

  // Asign a funtionality to an action
  void setFunctionality(ControllerAction* newControllerAction,
                        Button            actionId = CLICK);

  LcdManager* getLcdManager( );

  private:
  int16_t oldEncPos, encPos;
  uint8_t buttonState;

  ClickEncoder encoder = ClickEncoder(PIN_A, PIN_B, PIN_SW, STEPS);

  ControllerAction** actions;

  LcdManager* manager;
};

void wrapperIsr( );

#endif