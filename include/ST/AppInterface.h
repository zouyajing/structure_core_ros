#pragma once

/** These functions define the interface between cross-platform sample
    application code and platform-specific wrappers. */
namespace AppInterface {
    /** On desktop platforms this function is called in main() before
        runUntilWindowClosed(). On Android it is called when the main activity
        is created. */
    void setup();

    /** On desktop platforms this function is called in main() after
        runUntilWindowClosed(). On Android it is called when the main activity
        is destroyed. */
    void teardown();

#if __ANDROID__
    /** See Window::renderFrameInGLSurfaceViewContext(). */
    void renderFrame(unsigned currentWidth, unsigned currentHeight, float scaleFactor);

    /** See Window::updateMouseState(). */
    void updateMouseState(bool down, int x, int y);

    /** For applications that require Structure Core USB support. The argument
        is a file descriptor from the Android UsbDeviceConnection API and should
        be passed to ST::registerSensorByUSBFileDescriptor() or equivalent. */
    void plugStructureCoreFileDescriptor(int fd);
#else
    /** Called in main(). */
    void runUntilWindowClosed();
#endif
}
