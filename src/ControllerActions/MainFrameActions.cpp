#include "MainFrameActions.h"

#include "../Frames/MainFrame.h"
#include "../GlobalMenuStates.h"
#include "../Managers/Controller.h"
#include "../Managers/FrameManager.h"
#include "../Managers/LcdManager.h"

void MainFrameAction::Up::execute( ) { return; }

void MainFrameAction::Down::execute( ) { return; }

void MainFrameAction::Click::execute( ) { return; }

void MainFrameAction::Press::execute( ) {
  FrameManager* tempFrameManager =
      this->getController( )->getLcdManager( )->getFrameManager( );

  // change to configuration frame
  tempFrameManager->setFrame(GlobalMenu::FrameNames::configuration);
}

void MainFrameAction::Null::execute( ) { return; }
