Joystick
========

By Tristan van de Weg

A simple library for control of a Joystick
It can read out the coordinates of the joystick or it can be used for directions (Up, Down, Left, Right)

* [Downloading and Installing](#downloading-and-installing)
* [Using](#using)

Downloading and Installing
--------------------------

To download the library as a .zip file click the ![](.img/downloadbutton.png?raw=true) button and then click `Download ZIP`

You can then install it by pressing the `Add .ZIP Library...` button located under `Sketch` `Include Library` in the arduino IDE

Using
-----

**constructor**

When you create a joystick object you give it most values it needs to simplify use later in your code

You create a Joystick object like this:
`Joystick <Name>(<X Pin>, <Y Pin>, <Z Pin>, <Center Origin>, <Minimum threshold>, <Minimum value>, <Maximum value>, <false>, <Direction threshold>)`

* `X Pin` (int) Define the pin for the X axis
* `Y Pin` (int) Define the pin for the Y axis
* `Z Pin` (int) Define the pin for the button used for joystick clicks
* `Center Origin` (bool) When set to true use the center as point X:0 Y:0
* `Minimum threshold` (float) Anything below this value is set to 0, use this to prevent the stick triggering without it actually moving
* `Minimum value` (float) The lowest value for the stick to read, most of the time you want this to be 0
* `Maximum value` (float) The highest value for the stick to read, when `Center Origin` is true the X and Y only reach half this value
* `false` (bool) not yet used
* `Direction threshold` (float) The value that the stick has to exceed to read any of the directions (`isUp()`, `isDown()`, `isLeft()` and `isRight()`)

**Reading coordinates**

Use `ReadX()` and `ReadY()` to get the exact location of the stick in `float` format


**Using directions**

Use `isUp()`, `isDown()`, `isLeft()` and `isRight()` to see if the stick is pointing in any of these directions, outputted in a `bool` format


**Detecting clicks**

Use `ReadZ()` to see if the stick is beiing clicked in a `bool` format
