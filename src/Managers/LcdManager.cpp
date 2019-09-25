#include "LcdManager.h"

#include "Controller.h"
#include "FrameManager.h"

void LcdManager::setup( ) {

  if(this->frameManager == nullptr) {
    this->frameManager = new FrameManager( );
  } else {
#if LCD_MANAGER_DEBUG
    Serial.println(F("Frame Manager already exists"));
#endif
  }

  if(this->controller == nullptr) {
    this->controller = new Controller( );
  } else {
#if LCD_MANAGER_DEBUG
    Serial.println(F("Controller already exists"));
#endif
  }

  this->frameManager->getScreen( )->begin( );

  this->frameManager->getScreen( )->setColorIndex(1); // pixel on

  this->frameManager->getScreen( )->setFont(u8g_font_helvB08);

#if LCD_MANAGER_DEBUG
  Serial.println(F("Starting LCD Manager"));
#endif
}

// Draw method
void LcdManager::draw( ) { this->frameManager->draw( ); }

void LcdManager::update( ) { this->controller->update( ); }

FrameManager* LcdManager::getFrameManager( ) { return this->frameManager; }

Controller* LcdManager::getController( ) { return this->controller; }
