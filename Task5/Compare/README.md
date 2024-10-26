# PlatformIO Compare LED application
This is a LED  program using GPIO pin (PD6) when A is less than B, it will blink. The project is based on the PlatformIO framework.

To build and upload the firmware, you need to install the PlatformIO Core. The following commands will help you to install the PlatformIO Core and build the firmware.

1. Install PlatformIO Core
2. Run these commands
   
        #Build project
        $ pio run
  
        #Upload firmware
        $ pio run --target upload
  
        #Clean build files
        $ pio run --target clean
