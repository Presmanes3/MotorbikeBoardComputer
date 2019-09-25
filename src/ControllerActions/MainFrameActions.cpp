#include "MainFrameActions.h"

#include "../Frames/MainFrame.h"
#include "../GlobalMenuStates.h"
#include "../Managers/Controller.h"
#include "../Managers/FrameManager.h"
#include "../Managers/LcdManager.h"

void MainFrameAction::Up::execute( ) {
LcdFrame* tempFrame = this->getController( )
      ->getLcdManager( )
      ->getFrameManager( )
      ->getFrame( );
  
      tempFrame->setState(tempFrame->getGlobalMenuStates()::);
}

void MainFrameAction::Down::execute( ) { return; }

void MainFrameAction::Click::execute( ) { return; }

void MainFrameAction::Press::execute( ) { return; }

void MainFrameAction::Null::execute( ) { return; }
