# PS4ARDUINO-AVR

A custom AVR core to make HID-capable Arduino boards emulate a PS4-compatible controller!

## How to install
1) In the Arduino IDE, click `File` > `Preferences...` (or do `Ctrl + ,`)
   
2) Click on this button at the end of the Settings tab:
   ![Untitled design - 2025-10-05T171857 458](https://github.com/user-attachments/assets/58d9b945-638c-47d8-951d-d997bbc6b5e2)

3) In the box that opens, paste this into a new line `https://flamethr0wer.github.io/PS4Arduino-AVR/package_ps4arduino_index.json` and click `OK`.

4) Open the boards manager by clicking `Tools` > `Board` > `Boards Manager...` or by doing `Ctrl + Shift + B` (or by clicking the board icon on the left panel of the new IDE).

5) Search for `PS4Arduino` and install the latest version of the package

   <img width="316" height="246" alt="Screenshot 2025-10-05 172736" src="https://github.com/user-attachments/assets/85a3a07f-4cd6-4faa-9ce4-6c5abbc8c813" />

Once the installation finishes, you're good to go! You can now use the [PS4Arduino library](https://github.com/Flamethr0wer/PS4Arduino).

## Supported boards:
- Arduino Leonardo
- Arduino Leonardo ETH
- Arduino Micro
- Arduino Esplora
