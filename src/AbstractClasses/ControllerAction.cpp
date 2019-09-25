#include "ControllerAction.h"

#include "../Managers/Controller.h"

Controller* ControllerAction::getController( ) { return this->controller; }
void        ControllerAction::setController(Controller* newController) {
  this->controller = newController;
}