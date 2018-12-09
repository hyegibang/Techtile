# Techtile

The goal of this project for the Principle of Engineering class is to print the music notes and rythmn encoded in a midi file in braille.  We hope to make music resources more available to people who are visually impaired


## Getting Started

These instructions will get you a copy of the project up and running on your local machine.

### Prerequisites
The project runs with Python2.7.

The [python-midi](https://github.com/vishnubob/python-midi) library used for this project depends on [Swig](http://www.swig.org/).
```
sudo apt-get install swig
```


### Installing

The following libraries are required to run the project. 
#### For python 
* python-midi
* pyserial
* espeak
* Adafruit_Python_CharLCD
* adfruit_lcd_plate_menu 

Clone the repository of [python-midi](https://github.com/vishnubob/python-midi), [Adafruit_Python_CharLCD](https://github.com/adafruit/Adafruit_Python_CharLCD.git) and [adafruit_lcd_plate_menu](https://github.com/rodrigodiez/adafruit_lcd_plate_menu) library into any location of choice on your computer. For each library, run
```sudo python setup.py install```

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install [pyserial](https://github.com/pyserial/pyserial), [pyttsx3 2.7](https://pypi.org/project/pyttsx3/) and [espeak](https://pypi.org/search/?q=espeak) . 

``` sudo pip install pyserial ```
``` sudo pip install pyttsx3 ```
``` sudo pip install espeak ```

#### For arduino 
* [Wire](https://www.arduino.cc/en/Reference/Wire)
* [SpeedyStepper](https://github.com/Stan-Reifel/SpeedyStepper) 

### Running
* Load code in '''DemoDay\DemoDay.ino''' to an Arduino Board. Check the port and modify it accordingly in ```PACommunication.py.``` Then run the following command to perform Midi to Braille conversion and Python to Arduino communication:
```python displayUI.py ``` 
* Once the LCD screen displays the available songs, press the right button to select and print corresponding music brailles. 
