import math
import time
from os import listdir
from os.path import isfile, join
import pyttsx3

import Adafruit_CharLCD as LCD

mypath = "/home/pi/Desktop/Techtile/MidiFiles/"


y = 1
x = 1

show = True 
lcd = LCD.Adafruit_CharLCDPlate()

lcd.clear()
lcd.enable_display(True)
lcd.show_cursor(True)
lcd.blink(True)
lcd.set_backlight(1)
lcd.set_cursor(y,x)


engine = pyttsx3.init()
rate = engine.getProperty('rate')
volume =engine.getProperty('volume')
voices = engine.getProperty('voices')

engine.setProperty('rate', rate-30)
engine.setProperty('volume', volume + 10)
engine.setProperty('voice', 'english+f1') # or voices[13].id

onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]

for i in range(len(onlyfiles)):
    songtitlemid = onlyfiles[i]
    songtitle = songtitlemid[:-4]
    lcd.message(songtitle)
    lcd.message('\n')
    

while True:
	# Loop through each button and check if it is pressed.
		if lcd.is_pressed(LCD.LEFT):
                        engine.say(songtitle)
                        engine.runAndWait()			
                if lcd.is_pressed(LCD.RIGHT):
                        print(songtitle)
                if lcd.is_pressed(LCD.UP):
                        y += 1 
                        lcd.set_cursor(y,x)
                if lcd.is_pressed(LCD.DOWN):
                        y -= 1
                        lcd.set_cursor(y,x)
                
