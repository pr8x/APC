# APC - All-In-One Portable CDJ
DIY Portable CDJ using Teensy 4


## Hardware

### Components

- [Teensy 4](https://www.pjrc.com/store/teensy40.html)
- 1x 2.8" TFT ST7735 display 
- ?x RV09 Potentiometer
- 1x KY-040 Rotary Encoder
- 2x PCM5102A DAC
- 2x CD74HC4067 16 Channel Multiplexer

### PCB

### Prototype

![D86549FF-7F74-4139-A480-64EF8B23098C](https://user-images.githubusercontent.com/4670166/234878615-f74d0564-915b-46e8-9250-c6683a7f0c0e.jpeg)


## Audio graph

![image](https://user-images.githubusercontent.com/4670166/234449324-b1bb0291-e70a-4de0-a159-fdbd431cc442.png)

## How to build

### Prerequisites
- [PlatformIO](https://platformio.org/)
- (Optional) VSCode
- (Optional) clang-format/clang-tidy

### Steps

- `git clone` this project
- Run `pio build` to build it. PlatformIO should install all the necessary toolchains.
- (Non Windows): Adjust the serial ports in the platform.ini file (they default to COM6/COM7 for Windows)
- Connect your Teensy via USB and run `pio upload` to upload it


## License 

MIT
