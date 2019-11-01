#include "AppInterface.h"

int main() {
    AppInterface::setup();
    AppInterface::runUntilWindowClosed();
    AppInterface::teardown();
    return 0;
}
