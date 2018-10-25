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

To run ```Midi2Braille.py ```, clone the repository of [python-midi](https://github.com/vishnubob/python-midi) library into any location of choice on your computer. Run the steps below:

```
cd \path-to-python-midi-library
sudo python setup.py install
```

### Running
Load code in ```Python-Arduino\Python-Arduino.ino``` to an Arduino Board. Check the port and modify it accordingly in ```Midi2Braille.py```. Then run the following command to perform Midi to Braille conversion and Python to Arduino communication:
```
python Midi2Braille.py
```

### Built With

* [Python-Midi](https://github.com/vishnubob/python-midi)

### Authors
* Hyegi Bang
* Abby Fry
* Mark Goldwater
* Sherrie Shen
* Tommy Weir
