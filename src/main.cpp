#include "OpenKNX.h"
#include "Logic.h"
#include "VirtualButtonModule.h"

void setup()
{
    const uint8_t firmwareRevision = 1;
    openknx.init(firmwareRevision);
    openknx.addModule(1, new Logic());
    openknx.addModule(2, new VirtualButtonModule());
    openknx.setup();
}

void loop()
{
    openknx.loop();
}
