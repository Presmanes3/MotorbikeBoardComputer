#include "MainFrame.h"

void MainFrame::draw( ) {
  this->getManager( )->getScreen( )->drawStr(10, 10, F("Led Strip"));
  this->getManager( )->getScreen( )->drawStr(10, 20, F("Accelerometer"));
  this->getManager( )->getScreen( )->drawStr(10, 30, F("Time/Date"));

  switch(this->currentState) {
    case GlobalMenuStates::MainFrame::LedStrip:
      this->getManager( )->getScreen( )->drawStr(2, 10, F(">"));
      break;

    case GlobalMenuStates::MainFrame::Accelerometer:
      this->getManager( )->getScreen( )->drawStr(2, 20, F(">"));
      break;

    case GlobalMenuStates::MainFrame::Time:
      this->getManager( )->getScreen( )->drawStr(2, 30, F(">"));
      break;
  }
}
void MainFrame::setup( ) {}

void MainFrame::setState(GlobalMenuStates* newState) {
  this->currentState = newState;
}
