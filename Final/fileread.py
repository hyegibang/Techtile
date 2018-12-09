from os import listdir
from os.path import isfile, join
import pyttsx3

import math
import time

mypath = "/home/pi/Desktop/Techtile/MidiFiles/"

engine = pyttsx3.init()
rate = engine.getProperty('rate')
volume =engine.getProperty('volume')
voices = engine.getProperty('voices')

engine.setProperty('rate', rate-30)
engine.setProperty('volume', volume + 10)
engine.setProperty('voice', 'english+f1') # or voices[13].id

onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]


engine.say(onlyfiles[2])
engine.runAndWait()
