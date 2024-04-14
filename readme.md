## Snatan - Extreme Snake Game

A broad extension of the classic Snake game.

- [ ] Colorful design
- [ ] More edible items
- [ ] Various levels with plenty of surpriseful challenges
- [ ] Outstanding soundtrack borrowed from [Kevin MacLeod](http://incompetech.com/) (see the [credits](Resources/Music/license.txt))
- [ ] Two level difficulties

## Installation on Windows

- [ ] Download the [SFML](https://www.sfml-dev.org/files/SFML-2.6.1-windows-vc17-32-bit.zip) package
- [ ] Copy SFML's "include" contents to <kbd>C:\Libs\SFML-2.6.1\include</kbd> folder
- [ ] Copy SFML's "lib" contents to <kbd>C:\Libs\SFML-2.6.1\lib_x86</kbd> folder
- [ ] Open the VS solution
- [ ] Set the configuration to "Release|x86"
- [ ] Build the solution
- [ ] Copy SFML's "bin" contents to the "Release" folder where the executive is generated
- [ ] Copy or move the "Resources" folder to the "Release" folder
- [ ] Start the application

## Installation on Linux

To install the app on Linux via terminal, execute the following commands with <kbd>pwd</kbd> set to the main directory. Assure that you have [SFML](http://sfml-dev.org) 2.6.1 installed.

- <kbd>$ make</kbd> to compile and link

- <kbd>$ ./snatan</kbd> to launch

**Note**: if you use the external SFML package, add <kbd>-I[SFML include directory]</kbd> and <kbd>-L[SFML lib directory]</kbd> options to <kbd>g++ [...]</kbd> line in the *Makefile* and execute <kbd>export LD_LIBRARY_PATH=[SFML lib directory]</kbd> command before launching the application.

## Presentation

Click the link below to see the gameplay:

![Demo](demo/snatan_demo.mkv)

## Screenshots

![Image 0](demo/screenshot_00.png)

![Image 1](demo/screenshot_01.png)

![Image 2](demo/screenshot_02.png)

![Image 3](demo/screenshot_03.png)

![Image 4](demo/screenshot_04.png)

![Image 5](demo/screenshot_05.png)
