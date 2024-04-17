# 4Bit-Megaphone
A megaphone that outputs sound with a 4bit effect similar to 4bit covers of songs and such.

# 3D Print
3D printed the 2 parts in 60% cubic infill, 2mm shell thickness, 2mm print quality, with tree supports.

# Electrical Design
**Note:** I used a microphone with automatic gain control which brought issues so I set a specific gain by connecting pin 13 to the gain pin of the microphone, so automatic gain control is not required.

**Note:** I used the PAM8403 which is a stereo amp and only used one of the channels, but other non-stereo amps and such could have been used.

**Note:** In my case two buck converters were not an actual requirement as I could have stepped the voltage to 5.5v and powered both the esp32 and amp, so one buck converter could`ve sufficed.

**Components:** PAM8403 amp, 2x HW-286 buck converters, 2 resistors with a resistance ratio of 10 to 1, MAX9814 microfone, esp-wroom 32, wires, I also used a protoboard for the voltage divider and source to buck converters connection.

The source of the circuit is a 9v battery connected in parallel to two buck converters that step down the voltage to around 6v and 5v. The 5v is connected to the power terminals of the PAM8403 amplifier, and the 6v is connected as the power source for the ESP32 to VIN and ground respecting polarity. Pin 32 of the ESP32 is connected to the output of the microphone, the VIN being connected to a 5v pin of the ESP32, and the ground to ground. The 4ohm speaker is connected to the output for the right speaker of PAM8403, and pin 25 is connected to a voltage divider with a ratio of 10 to 1, from the first resistor to the second, as ground being connected to the end of the second resistor, the voltage from the second resistor is then being fed to the input for the right speaker of the PAM8403 (input for the right speaker is connected in parallel to the second resistor), as the PAM8403 takes voltages from -0.3v to 0.3v.

# Code
The code from the code folder is uploaded to the esp32, which takes input from the microphone bit-shifts it to 4 bits than shifts it to the 8 bit required for the esp 32 dac output, and utilizes a delay of 120 microseconds to set a loop/signal frequency of 8.3kHertz, my speaker allowing a max of 10kHz.

# Assembly
The mic is inserted onto the hole in the back of the megaphone, I also added a switch between the battery and circuit for turning on and of which I placed into the lateral hole, and the rest of the components I just placed inside the megaphone, the big end of the megaphone being sized acordingly to my speaker, and the secondary part was glued with epoxy glue to the base and the hole thing was fixed together till the glue cured with zip ties.
