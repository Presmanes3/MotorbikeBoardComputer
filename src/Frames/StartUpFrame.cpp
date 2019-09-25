#include "StartUpFrame.h"

void StartUpFrame::setup( ) {

#if LCD_FRAME_DEBUG
  Serial.println(F("StartUpFrame setup"));
#endif
}

void StartUpFrame::draw( ) {
 // this->lcd->getScreen( )->drawStr(LCD_WIDTH / 2, LCD_HEIGHT / 2,
  //                                 F(STARTING_MESSAGE));
}