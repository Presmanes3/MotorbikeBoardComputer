#include "Dependencies.h"

LcdManager* mainLcdManager;

void setup( ) {

  Serial.begin(9600);

  mainLcdManager = new LcdManager( );

  mainLcdManager->getFrameManager( )->addFrame(new MainFrame( ));

  mainLcdManager->getController( )->setFunctionality(new MainFrameAction::Up( ),
                                                     UP);

  mainLcdManager->getController( )->setFunctionality(
      new MainFrameAction::Down( ), DOWN);

  mainLcdManager->getController( )->setFunctionality(
      new MainFrameAction::Click( ), CLICK);

  mainLcdManager->getController( )->setFunctionality(
      new MainFrameAction::Press( ), PRESS);

  mainLcdManager->getController( )->setFunctionality(
      new MainFrameAction::Null( ), RELEASE);

  // put your setup code here, to run once:
}

void loop( ) {

  mainLcdManager->update( );
  mainLcdManager->draw( );
}