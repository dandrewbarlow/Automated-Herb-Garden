# Automated Herb Garden

An arduino based solution for techies who love spending 12 hours to forget about 1 minutes worth of work. My goal is to create a self watering, automatically lit, self contained, and time-independent indoor herb garden (open to growing fruits, veggies, peppers, etc.)

Finished as of 6/12! :) I'm still hoping to make improvements but I have it in a working state and am fairly satisfied with its functionality and simplicity. If I were to update it, I doubt it would change substantially, more like trying to design a pcb for it.

I abandoned some code meant to check a moisture sensor and method to run code at certain intervals (to avoid overusing my arduino). I made branches for both of these to preserve the code in case someone else or even me wanted to integrate it into their project.

## Skills/Tools Required:
* Soldering/electrical skills are a must. This project is not too advanced, and a breadboard can be used for a lot of the hookups, but some things need soldering and a working knowlege of electronics. If you don't have any wire or an accessible soldering iron, this will be hard to complete.
* You will probably need to create or at least modify an enclosure. I found a very suitable one but I still needed to use a dremel and hot glue to get things in a working state.
* While not strictly necessary, some electrical components such as a switch/button and pulldown resistor were invaluable for testing my system.

## Components:
* Arduino Uno - to handle any and all logic
* An assortion of wires, resistors, breadboards, perfboards, buttons, useful electrical components - I'm not gonna tell you how to hook everything up, but you gotta do it somehow.
* [Sparkfun DeadOn RTC Breakout Board](https://www.sparkfun.com/products/10160) - to enable time-based control. Be sure to get a 12nm coin cell battery in case of a power failure. I got the breakout board for ease, but you could ostensibly build one cheaper using the DS3234 component
* [WayinTop Automatic Irrigation DIY kit](https://www.amazon.com/dp/B07TLRYGT1/) - a bundle that includes a water pump, piping, relay module, and a capacitive soil moisture sensor.
  * UPDATE: I got the kit in today, and after some testing, the water pump is adequate (the leads are extremely small however, & will test your soldering skill) but the moisture sensor appears to be faulty. I personally was contemplating watering just based on time rather than soil moisture, but that seals the deal for me. From what I've read online these sensors' quality can vary dramatically so if you want to try this, take that into account.
  * UPDATE 2: I have decided to keep the code I wrote in a branch called moisture for reference, but going forward will delete it from the master branch to simplify it
  * UPDATE 3: I had trouble getting the relay working as well, and although I think it probably could have worked with enough effort, I decided a MOSFET transistor served my purposes better and had the added benefit of using pulse width modulation without a constant click clacking
* [Toogod 5m Waterproof LED Strip Growing Light](https://www.amazon.com/Toogod-16-4ft-Waterproof-Strip-Growing/dp/B00XHRYX2O) - a strip of LED grow lights. They're cheaper than most because they require you to solder them together and provide your own power source
* 12V 5A 60W AC to DC Power Supply - The lights linked require 12V and need 60W or more. If you can find another way to do em, more power to you
* N-Channel Power Mosfet - used to create a simple logic gate between the arduino and the light's power supply. This solution also allows us to use pulse width modulation, enabling a gradual and more elegant shift between on and off. I went with a pretty heavy duty one that was probably a little extra, but that said there's gonna be a fair amount of current running through this baby so do your research
* Enclosure (plants) - I'm using a plasic set of drawers I picked up at Goodwill, this part is at your discretion (as with anything else but you get the point), just use common sense and a DIY attitude. I am planning on using the bottom drawer to store a reservoir of water with the pump submerged within it, and have drilled holes in the top two drawers, to allow drainage from the top to the bottom drawer. I'm hopeful this will work on my setup, but whatever you do don't forget to factor drainage in.
* Enclosure (arduino) - not strictly necessary, but highly advisable seeing as this is an electronics project that involves water. I'm using an old wine box and running the wires out the spout hole but once again this is at your discretion.

## Dependencies
I'm using Sparkfun's custom RTC Arduino Library ([github](https://github.com/sparkfun/SparkFun_DS3234_RTC_Arduino_Library) | [direct download](https://github.com/sparkfun/SparkFun_DS3234_RTC_Arduino_Library/archive/master.zip)). I'm also using their [guide](https://learn.sparkfun.com/tutorials/deadon-rtc-breakout-hookup-guide) to help get me off the ground with the RTC, definitely worth the look.

Once again if so inclined I guess you could try to do a custom implementation, but I'm more of a goal oriented person myself.

## Schematics
![Schematic Diagram](https://raw.githubusercontent.com/dandrewbarlow/Automated-Herb-Garden/master/schematic.JPG)
