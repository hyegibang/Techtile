import midi


def CheckRythmn(timediff, resolution):
    resolution = float(resolution)
    Quarter = resolution
    Eighth = resolution / 2.0
    Sixteenth = resolution / 4.0
    Half = resolution * 2.0
    Whole = resolution * 4.0
    thirtysecondth = resolution / 8.0
    sixtyfourth = resolution / 16.0
    onetwoeighth = resolution / 32.0

    min_diff = abs(timediff - Quarter)
    rythmn = 1 / 4.0
    for beat in [Eighth, Sixteenth, Half, Whole, thirtysecondth, sixtyfourth, onetwoeighth]:
        diff = abs(timediff - beat)
        if diff < min_diff:
            min_diff = diff
            rythmn = beat / resolution / 4.0
    return rythmn


def Rythmn2Braille():
    BrailleRythmn = dict()
    BrailleRythmn[0.25] = [0, 1]
    BrailleRythmn[0.125] = [0, 0]
    BrailleRythmn[0.5] = [1, 0]
    BrailleRythmn[1.0] = [1, 1]
    BrailleRythmn[1 / 64.0] = [0, 1]
    BrailleRythmn[1 / 128.0] = [0, 0]
    BrailleRythmn[1 / 32.0] = [1, 0]
    BrailleRythmn[1 / 16.0] = [1, 1]
    return BrailleRythmn

class Notes(object):
    def __init__(self, id, pitch, rythmn, time, velocity):
        self.id = id
        self.pitch = pitch
        self.rythmn = rythmn
        self.timeon = time
        self.velocity = velocity
        self.braille = None

    def Rythmn2Braille(self, BrailleRythmn):
        self.braille = BrailleRythmn[self.rythmn]

pattern = midi.read_midifile("twinkle_twinkle.mid")

resolution = pattern.resolution
tick = 0
noteson = dict()
id_count = 1
notes = dict()

for track in pattern:
    for event in track:
        tick += event.tick
        if isinstance(event, midi.events.NoteOnEvent) or isinstance(event, midi.events.NoteOffEvent):
            if event.data[0] not in noteson.keys():
                noteson[event.data[0]] = tick
            else:
                tickdiff = tick - noteson[event.data[0]]
                rythmn = CheckRythmn(tickdiff, resolution)
                notes[id_count] = Notes(id_count, event.data[0], rythmn, noteson[event.data[0]], event.data[1])
                id_count += 1
                del noteson[event.data[0]]

BrailleRythmn = Rythmn2Braille()
for note in notes.values():
    note.Rythmn2Braille(BrailleRythmn)
    print note.id, note.pitch, note.rythmn, note.timeon, note.braille

