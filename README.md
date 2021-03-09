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
`Joystick <Name>(<X Pin>, <Y Pin>, <Z/Click Pin>, <(true/false) Use the center as point (0, 0)>, <Set anything below this value to 0>, <Minimum value>, <Maximum value>, <false>, <Directional activation threshold>)`


**Reading coordinates**

Use `ReadX()` and `ReadY()` to get the exact location of the stick in `float` format


**Using directions**

Use `isUp()`, `isDown()`, `isLeft()` and `isRight()` to see if the stick is pointing in any of these directions, outputted in a `bool` format


**Detecting clicks**

Use `ReadZ()` to see if the stick is beiing clicked in a `bool` format
