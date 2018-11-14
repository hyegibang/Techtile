import math
import time
from os import listdir
from os.path import isfile, join
import pyttsx3
import Adafruit_CharLCD as LCD
import midi
import serial


from adafruitlcdplate import MenuNode , CharMenuDisplay
from PySprint2 import Notes, MusicBraille

#  Instantiate and configure Adafruit's Char LCD Plate lib
adafruit_char_lcd_plate = LCD.Adafruit_CharLCDPlate()
adafruit_char_lcd_plate.set_color(0.0, 0.0, 1.0)
adafruit_char_lcd_plate.set_backlight(True)

mypath = "/home/pi/Desktop/Techtile/MidiFiles/"
files = [f for f in listdir(mypath) if isfile(join(mypath, f))]


#  Here we create ten menu nodes, each of them with ten childs
#  each of them, again, with ten sub-menus
menu_nodes = []
title= []
for song in range(len(files)):
        titlewomid = files[song][:-4]
	menu = MenuNode(titlewomid)
	menu_nodes.append(menu)
	title.append(titlewomid)


print(title)		
#  This is our menu display
menu = CharMenuDisplay(adafruit_char_lcd_plate, menu_nodes, title)

select = menu.display()
print("receive" , select)
#  Enjoy trasversing the menu!


braille = MusicBraille(files[select])
braille.run(serial = True)
