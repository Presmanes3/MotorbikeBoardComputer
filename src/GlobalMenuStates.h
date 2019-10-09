#ifndef _GLOBAL_MENU_STATES_H_
#define _GLOBAL_MENU_STATES_H_

namespace GlobalMenu {

  enum FrameNames { startUpFrame = 0, mainFrame, configuration };

  namespace Frames {
    enum StartUp { Wallpaper = 0 };
    enum Main { ShowInformation = 0 };

    namespace Configuration {
      enum LedStrip { SetColour = 0, SetModeLedStrip };
      enum Accelerometer { SetModeAccelerometer = 0 };
      enum Time { Configure = 0 };
    }; // namespace Configuration

  } // namespace Frames
} // namespace GlobalMenu

#endif