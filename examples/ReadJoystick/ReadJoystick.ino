#include <Joystick.h>

Joystick js(A0, A1, 7, true, 0, 10, 0.5, false, 3.5); // Create the joystick object

void setup() {
  Serial.begin(9600); // Start the serial connection
}

void loop() {

  // Print coordinates
  Serial.println(js.ReadX()); //Print the coordinates to the Serial monitor
  Serial.println(js.ReadY());

  // Print directions
  if (js.isUp()) { // Print UP to the serial monitor
    Serial.println("UP");
  }
  if (js.isDown()) { // Print DOWN to the serial monitor
    Serial.println("DOWN");
  }
  if (js.isLeft()) { // Print LEFT to the serial monitor
    Serial.println("LEFT");
  }
  if (js.isRight()) { // Print RIGHT to the serial monitor
    Serial.println("RIGHT");
  }

  // Print clicks
  if (js.ReadZ()) { // Print CLICK! to the serial monitor
    Serial.println("CLICK!");
  }
}
