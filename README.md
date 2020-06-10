# Automated Herb Garden

An arduino based solution for techies who love spending 12 hours to forget about 1 minutes worth of work. My goal is to create a self watering, automatically lit, self contained, and time-independent indoor herb garden (open to growing fruits, veggies peppers, etc.)

## Components:
* Arduino Uno - to handle any and all logic
* Sparkfun DeadOn RTC Breakout Board - to enable time-based control
* [WayinTop Automatic Irrigation DIY kit](https://www.amazon.com/dp/B07TLRYGT1/) - a bundle that includes a water pump, piping, relay module, and a capacitive soil moisture sensor
* [Toogod 5m Waterproof LED Strip Growing Light](https://www.amazon.com/dp/B00XHRYX20/) - a strip of LED grow lights. They're cheaper than most because they require you to solder them together and provide your own power source
* 12V 5A 60W AC to DC Power Supply - The lights linked require 12V and need 60W or more. If you can find another way to do em, more power to you
* N-Channel Power Mosfet - used to create a simple logic gate between the arduino and the light's power supply. This solution also allows us to use pulse width modulation, enabling a gradual and more elegant shift between on and off
* Enclosure - I'm using a plasic set of drawers I picked up at Goodwill, this part is at your discretion (as with anything else but you get the point), just use common sense and a DIY attitude

