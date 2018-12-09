import math
import time
from os import listdir
from os.path import isfile, join
import pyttsx3
import Adafruit_CharLCD as LCD
import midi
import serial


from adafruitlcdplate import MenuNode , CharMenuDisplay
from PACommunication import Notes, MusicBraille

 #  Instantiate and configure Adafruit's Char LCD Plate lib
adafruit_char_lcd_plate = LCD.Adafruit_CharLCDPlate()
adafruit_char_lcd_plate.set_color(0.0, 0.0, 1.0)
adafruit_char_lcd_plate.set_backlight(True)

mypath = "/home/pi/Techtile/MidiFiles/"
files = [f for f in listdir(mypath) if isfile(join(mypath, f))]


 #  Here we create ten menu nodes

menu_nodes = []
title= []
for song in range(len(files)):
    titlewomid = files[song][:-4]
    menu = MenuNode(titlewomid)
    menu_nodes.append(menu)
    title.append(titlewomid)


print(title)

while True:
    menu = CharMenuDisplay(adafruit_char_lcd_plate, menu_nodes, title)
    selected = menu.display()
    print("receive" , selected)
    braille = MusicBraille(selected)
    braille.run(serial = True)
    print("done")
    
   