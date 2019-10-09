#include "MainFrame.h"

#include "../ControllerActions/MainFrameActions.h"
#include "../Managers/LcdManager.h"

void MainFrame::draw( ) {

  switch(this->currentMachineState) {
    case GlobalMenu::Frames::Main::ShowInformation:
      this->getManager( )->getScreen( )->drawStr(10, 10, F("Time : "));
      this->getManager( )->getScreen( )->drawStr(10, 20, F("Date : "));
      this->getManager( )->getScreen( )->drawStr(10, 30, F("Speed : "));
      this->getManager( )->getScreen( )->drawStr(10, 30,
                                                 F("Acceleration X : "));
      this->getManager( )->getScreen( )->drawStr(10, 30,
                                                 F("Acceleration Y : "));
      break;
  }
}

/*this->getManager( )->getScreen( )->drawStr(10, 10, F("Led Strip"));
  this->getManager( )->getScreen( )->drawStr(10, 20, F("Accelerometer"));
  this->getManager( )->getScreen( )->drawStr(10, 30, F("Time/Date"));

  switch(this->currentMachineState) {
    case GlobalMenu::Frames::Main::LedStrip:
      this->getManager( )->getScreen( )->drawStr(2, 10, F(">"));
      break;

    case GlobalMenu::Frames::Main::Accelerometer:
      this->getManager( )->getScreen( )->drawStr(2, 20, F(">"));
      break;

    case GlobalMenu::Frames::Main::Time:
      this->getManager( )->getScreen( )->drawStr(2, 30, F(">"));
      break;
  }*/
void MainFrame::setup( ) {
  Controller* tempController =
      this->getManager( )->getLcdManager( )->getController( );

  tempController->setFunctionality(new MainFrameAction::Up( ), UP);

  tempController->setFunctionality(new MainFrameAction::Down( ), DOWN);

  tempController->setFunctionality(new MainFrameAction::Click( ), CLICK);

  tempController->setFunctionality(new MainFrameAction::Press( ), PRESS);

  tempController->setFunctionality(new MainFrameAction::Null( ), RELEASE);
}
