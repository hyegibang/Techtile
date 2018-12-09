import math
import time
from os import listdir
from os.path import isfile, join
import pyttsx3

import Adafruit_CharLCD as LCD

mypath = "/home/pi/Desktop/Techtile/MidiFiles/"

import math
import time
from os import listdir
from os.path import isfile, join
import pyttsx3
import Adafruit_CharLCD as LCD

from adafruit_lcd_plate_menu import MenuNode
from adafruit_lcd_plate_menu import CharMenuDisplay

#  Instantiate and configure Adafruit's Char LCD Plate lib
adafruit_char_lcd_plate = LCD.Adafruit_CharLCDPlate()
adafruit_char_lcd_plate.set_color(0.0, 0.0, 1.0)
adafruit_char_lcd_plate.set_backlight(True)

# Initate speaker voice condition
engine = pyttsx3.init()
rate = engine.getProperty('rate')
volume =engine.getProperty('volume')
voices = engine.getProperty('voices')

engine.setProperty('rate', rate-30)
engine.setProperty('volume', volume + 30)
engine.setProperty('voice', 'english+f1') # or voices[13].id

mypath = "/home/pi/Desktop/Techtile/MidiFiles/"
files = [f for f in listdir(mypath) if isfile(join(mypath, f))]


menu_nodes = []
for song in range(len(files)):
        titlesong = files[song][:-4]
	menu = MenuNode(titlesong)

	menu_nodes.append(menu)
		
#  This is our menu display
CharMenuDisplay(adafruit_char_lcd_plate, menu_nodes).display()

##while True:
##    if lcd.is_pressed(LCD.UP):
##            engine.say("mary had a little lamb")
##            engine.runAndWait()			


