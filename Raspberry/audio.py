import math
import time

import Adafruit_CharLCD as LCD

# Initialize the LCD using the pins
lcd = LCD.Adafruit_CharLCDPlate()

# Make list of button value, text, and backlight color.
buttons = ( (LCD.SELECT,
            (LCD.LEFT,
            (LCD.UP,
            (LCD.DOWN,
            (LCD.RIGHT,)

# print 'Press Ctrl-C to quit.'
# while True:
# 	# Loop through each button and check if it is pressed.
# 	for button in buttons:
# 		if lcd.is_pressed(button[0]):
# 			# Button is pressed, change the message and backlight.
# 			lcd.clear()
# 			lcd.message(button[1])
# 			lcd.set_color(button[2][0], button[2][1], button[2][2])
#
