#include "MainFrame.h"

void MainFrame::draw( ) {
  this->getManager( )->getScreen( )->drawStr(10, 10, F("Led Strip"));
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
  }
}
void MainFrame::setup( ) {}
