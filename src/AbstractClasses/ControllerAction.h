#ifndef CONTROLLER_ACTION_H_
#define CONTROLLER_ACTION_H_

#include "Arduino.h"

class Controller;

class ControllerAction {

  public:
  virtual void execute( ) = 0;

  Controller* getController( );
  void        setController(Controller* newController);

  private:
  Controller* controller;
};

#endif // !ACTION_H_
