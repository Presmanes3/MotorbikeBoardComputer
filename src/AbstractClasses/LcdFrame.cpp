#include "LcdFrame.h"

void LcdFrame::setFrameManager(FrameManager* newManager) {
  this->manager = newManager;
}

FrameManager* LcdFrame::getManager( ) { return this->manager; }
