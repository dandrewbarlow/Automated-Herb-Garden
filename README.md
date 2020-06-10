# Automated Herb Garden (WIP)

An arduino based solution for techies who love spending 12 hours to forget about 1 minutes worth of work. My goal is to create a self watering, automatically lit, self contained, and time-independent indoor herb garden (open to growing fruits, veggies, peppers, etc.)

## Components:
* Arduino Uno - to handle any and all logic
* [Sparkfun DeadOn RTC Breakout Board](https://www.sparkfun.com/products/10160) - to enable time-based control. Be sure to get a 12nm coin cell battery in case of a power failure. I got the breakout board for ease, but you could ostensibly build one cheaper using the DS3234 component
* [WayinTop Automatic Irrigation DIY kit](https://www.amazon.com/dp/B07TLRYGT1/) - a bundle that includes a water pump, piping, relay module, and a capacitive soil moisture sensor
* [Toogod 5m Waterproof LED Strip Growing Light](https://www.amazon.com/dp/B00XHRYX20/) - a strip of LED grow lights. They're cheaper than most because they require you to solder them together and provide your own power source
* 12V 5A 60W AC to DC Power Supply - The lights linked require 12V and need 60W or more. If you can find another way to do em, more power to you
* N-Channel Power Mosfet - used to create a simple logic gate between the arduino and the light's power supply. This solution also allows us to use pulse width modulation, enabling a gradual and more elegant shift between on and off. I went with a pretty heavy duty one that was probably a little extra, but that said there's gonna be a fair amount of current running through this baby so do your research
* Enclosure - I'm using a plasic set of drawers I picked up at Goodwill, this part is at your discretion (as with anything else but you get the point), just use common sense and a DIY attitude

## Dependencies
I'm using Sparkfun's custom RTC Arduino Library ([github](https://github.com/sparkfun/SparkFun_DS3234_RTC_Arduino_Library) | [direct download](https://github.com/sparkfun/SparkFun_DS3234_RTC_Arduino_Library/archive/master.zip)). I'm also using their [guide](https://learn.sparkfun.com/tutorials/deadon-rtc-breakout-hookup-guide) to help get me off the ground with the RTC, definitely worth the look.

Once again if so inclined I guess you could try to do a custom implementation, but I'm more of a goal oriented person myself.

## Schematics
* to be posted when they're made (this is a WIP until otherwise indicated)
