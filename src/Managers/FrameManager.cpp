#include "FrameManager.h"

#include "AbstractClasses/LcdFrame.h"

void FrameManager::setup( ) {
  this->screen.begin( );

  this->screen.setColorIndex(1); // pixel on

  this->screen.setFont(u8g_font_helvB08);

#if LCD_MANAGER_DEBUG
  Serial.println(F("Starting LCD Manager"));
#endif
}

// Draw method
void FrameManager::draw( ) {
  if(millis( ) - currentTime >= (1000 / FPS)) {
    this->screen.firstPage( );
    do { this->currentFrame->draw( ); } while(this->screen.nextPage( ));
  }
}

void FrameManager::addFrame(LcdFrame* newFrame) {
  this->framePool[this->totalFrames] = newFrame;
  this->totalFrames++;
}
// Point to a new frame
void FrameManager::setFrame(LcdFrame* frame) { this->currentFrame = frame; }

// Return current frame
LcdFrame* FrameManager::getFrame( ) { return this->currentFrame; }

// Return current screen
U8GLIB_ST7920_128X64* FrameManager::getScreen( ) { return &(this->screen); }

// Start current frame
void FrameManager::setupCurrentFrame( ) { this->currentFrame->setup( ); }