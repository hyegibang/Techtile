import math
import time
from os import listdir
from os.path import isfile, join
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
    ser = serial.Serial('COM15', 9600, timeout=.1)
    menu = CharMenuDisplay(adafruit_char_lcd_plate, menu_nodes, title)
    selected = menu.display()
    print("receive" , selected)
    ser.write(selected)
    print(selected, "sent")
    ser.flush()
    time.sleep(3)
    ser.close()