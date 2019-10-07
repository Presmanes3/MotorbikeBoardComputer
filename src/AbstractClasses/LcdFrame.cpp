#include "LcdFrame.h"

void LcdFrame::setFrameManager(FrameManager* newManager) {
  this->manager = newManager;
}

/*
template <typename machineState>

void LcdFrame::setState(machineState newMachineState) {
  this->currentMachineState = newMachineState;
}*/

FrameManager* LcdFrame::getManager( ) { return this->manager; }
