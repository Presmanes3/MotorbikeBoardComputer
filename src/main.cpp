#include "Dependencies.h"

LcdManager*   mainLcdManager;
FrameManager* projectFrameManager;
Controller*   projectController;

void setup( ) {

  Serial.begin(9600);

  mainLcdManager      = new LcdManager( );
  projectFrameManager = mainLcdManager->getFrameManager( );
  projectController   = mainLcdManager->getController( );

  projectFrameManager->addFrame(GlobalMenu::FrameNames::startUpFrame,
                                new StartUpFrame( ));

  projectFrameManager->setFrame(GlobalMenu::FrameNames::startUpFrame);

  projectFrameManager->addFrame(GlobalMenu::FrameNames::mainFrame,
                                new MainFrame( ));

  projectFrameManager->draw( );
  delay(STARTING_DELAY);

  projectFrameManager->setFrame(GlobalMenu::FrameNames::mainFrame);

  // put your setup code here, to run once:
}

void loop( ) {

  mainLcdManager->update( );
  mainLcdManager->draw( );
}