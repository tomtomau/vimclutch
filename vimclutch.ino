//                                       _          _     _                       
// _ __ ___   ___ _ __ _ __ _   _    ___| |__  _ __(_)___| |_ _ __ ___   __ _ ___ 
//| '_ ` _ \ / _ \ '__| '__| | | |  / __| '_ \| '__| / __| __| '_ ` _ \ / _` / __|
//| | | | | |  __/ |  | |  | |_| | | (__| | | | |  | \__ \ |_| | | | | | (_| \__ \
//|_| |_| |_|\___|_|  |_|   \__, |  \___|_| |_|_|  |_|___/\__|_| |_| |_|\__,_|___/
//                          |___/                                                 
// Merry Christmas, Nathan!

#include <Bounce.h>

Bounce button0 = Bounce(0, 10);
// 11 is a pin which also has a LED wired on the board, so flicking it high turns on the light (debugging, lol)
const int ledPin = 11;

void setup() {
  pinMode(0, INPUT_PULLUP);
  // Set it to be an output
  pinMode(ledPin, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  button0.update();
  digitalWrite(ledPin, LOW);    // set the LED off

  // On a falling edge
  if (button0.fallingEdge()) {
      digitalWrite(ledPin, HIGH);   // set the LED on, super quick
      Keyboard.set_key1(KEY_ESC); // Send the escape key - maybe you want to rebind this to alt-tab?
      // Send it
      Keyboard.send_now();
      // Then send "no chars currently being pressed"
      Keyboard.set_key1(0);
      Keyboard.send_now();
  }
}
