import pyttsx3

engine = pyttsx3.init()
rate = engine.getProperty('rate')
volume =engine.getProperty('volume')
voices = engine.getProperty('voices')

engine.setProperty('rate', rate-30)
engine.setProperty('volume', volume + 10)
engine.setProperty('voice', 'english+f1') # or voices[13].id


engine.say('Mary Had A Little Lamb')
engine.runAndWait()

