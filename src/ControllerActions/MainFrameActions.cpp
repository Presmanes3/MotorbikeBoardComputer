#include "MainFrameActions.h"

#include "../Frames/MainFrame.h"
#include "../GlobalMenuStates.h"
#include "../Managers/Controller.h"
#include "../Managers/FrameManager.h"
#include "../Managers/LcdManager.h"

void MainFrameAction::Up::execute( ) {
  LcdFrame* tempFrame =
      this->getController( )->getLcdManager( )->getFrameManager( )->getFrame( );

  tempFrame->setState(GlobalMenu::Frames::Main::LedStrip);
}

void MainFrameAction::Down::execute( ) {
  LcdFrame* tempFrame =
      this->getController( )->getLcdManager( )->getFrameManager( )->getFrame( );

  tempFrame->setState(GlobalMenu::Frames::Main::Accelerometer);
}

void MainFrameAction::Click::execute( ) {
  LcdFrame* tempFrame =
      this->getController( )->getLcdManager( )->getFrameManager( )->getFrame( );

  tempFrame->setState(GlobalMenu::Frames::Main::Time);
}

void MainFrameAction::Press::execute( ) {
  LcdManager* tempLcdManager = this->getController( )->getLcdManager( );

  tempLcdManager->getFrameManager( )->setFrame(
      GlobalMenu::FrameNames::mainFrame);
}

void MainFrameAction::Null::execute( ) { return; }
