/*
 *  Project     PS4Arduino AVR core
 *  @author     Flamethrower
 *  @link       github.com/Flamethr0wer/PS4Arduino_AVR
 *  @license    MIT - Copyright (c) 2019 Flamethrower
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "PS4Arduino_USBAPI.h"

#ifdef PS4ARDUINO_USB

void (*PS4ArduinoUSB::RecvCallback)(void) = nullptr;
void (*PS4ArduinoUSB::SendCallback)(void) = nullptr;

boolean PS4ArduinoUSB::connected() {
	return USBDevice.configured();
}

uint8_t PS4ArduinoUSB::available() {
	return USB_Available(PS4ARDUINO_RX_ENDPOINT);
}

int PS4ArduinoUSB::recv(void *buffer, uint8_t nbytes) {
	return USB_Recv(PS4ARDUINO_RX_ENDPOINT, buffer, nbytes);
}

int PS4ArduinoUSB::send(const void *buffer, uint8_t nbytes) {
	int result = USB_Send(PS4ARDUINO_TX_ENDPOINT, buffer, nbytes);
	if (result > 0) {
		USB_Flush(PS4ARDUINO_TX_ENDPOINT);
	}
	return result;
}

void PS4ArduinoUSB::setRecvCallback(void(*callback)(void)) {
	PS4ArduinoUSB::RecvCallback = callback;
}

void PS4ArduinoUSB::setSendCallback(void(*callback)(void)) {
	PS4ArduinoUSB::SendCallback = callback;
}

#endif
