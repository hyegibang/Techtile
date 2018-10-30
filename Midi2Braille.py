import midi
import serial
import time
import struct


class Notes(object):
    def __init__(self, id, pitch, rythmn, time, velocity):
        self.id = id
        self.rythmn = rythmn
        self.pitch = pitch
        self.note = None
        self.octv = None
        self.sharpstatus = False
        self.timeon = time
        self.velocity = velocity
        self.rythmn_braille = None
        self.pitch_braille = None
        self.octv_braille = None
        self.sharp_braille = None

    def Rythmn2Braille(self, BrailleRythmn):
        self.rythmn_braille = BrailleRythmn[self.rythmn]

    def Pitch2Notes(self):
        allnotes = "C C#D D#E F F#G G#A A#B "
        self.octv = self.pitch / 12 - 1
        start = self.pitch % 12 * 2
        end = self.pitch % 12 * 2 + 2
        nt = allnotes[start:end]
        self.note = nt[0]
        if nt[1] == "#":
            self.sharpstatus = True

    def Pitch2Braille(self, BraillePitch):
        self.Pitch2Notes()
        self.pitch_braille = BraillePitch[self.note]

    def Octave2Braille(self, BrailleOctave):
        self.octv_braille = BrailleOctave[self.octv]

    def Accidental2Braille(self, BrailleOctave):
        if self.sharpstatus:
            self.sharp_braille = BrailleOctave["#"]


class MusicBraille(object):

    def __init__(self, filename):
        self.pattern = midi.read_midifile(filename)
        self.notes = dict()
        self.resolution = self.pattern.resolution

    @staticmethod
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

    @staticmethod
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

    @staticmethod
    def Pitch2Braille():
        BraillePitch = dict()
        BraillePitch["C"] = [1, 0, 1, 1]  # column major
        BraillePitch["D"] = [1, 0, 0, 1]
        BraillePitch["E"] = [1, 1, 1, 0]
        BraillePitch["F"] = [1, 1, 1, 1]
        BraillePitch["G"] = [1, 1, 0, 1]
        BraillePitch["A"] = [0, 1, 1, 0]
        BraillePitch["B"] = [0, 1, 1, 1]
        return BraillePitch

    @staticmethod
    def Octave2Braille():
        BrailleOctave = dict()
        BrailleOctave[0] = [0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0]
        BrailleOctave[1] = [0, 0, 0, 1, 0, 0]
        BrailleOctave[2] = [0, 0, 0, 1, 1, 0]
        BrailleOctave[3] = [0, 0, 0, 1, 1, 1]
        BrailleOctave[4] = [0, 0, 0, 0, 1, 0]
        BrailleOctave[5] = [0, 0, 0, 1, 0, 1]
        BrailleOctave[6] = [0, 0, 0, 0, 1, 1]
        BrailleOctave[7] = [0, 0, 0, 0, 0, 1]
        BrailleOctave[8] = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1]
        return BrailleOctave

    @staticmethod
    def Accidental2Braille():
        BrailleAccidental = dict()
        BrailleAccidental["#"] = [1,0,0,1,0,1]
        BrailleAccidental["flat"] = [1,1,0,0,0,1]
        BrailleAccidental["natural"] = [1,0,0,0,0,1]

    def GetNotesFromMidi(self):
        tick = 0
        noteson = dict()
        id_count = 1
        for track in self.pattern:
            for event in track:
                tick += event.tick
                if isinstance(event, midi.events.NoteOnEvent) or isinstance(event, midi.events.NoteOffEvent):
                    if event.data[0] not in noteson.keys():
                        noteson[event.data[0]] = tick
                    else:
                        tickdiff = tick - noteson[event.data[0]]
                        rythmn = MusicBraille.CheckRythmn(tickdiff, self.resolution)
                        self.notes[id_count] = Notes(id_count, event.data[0], rythmn, noteson[event.data[0]],
                                                     event.data[1])
                        id_count += 1
                        del noteson[event.data[0]]

    def Notes2Braile(self):
        BrailleRythmn = MusicBraille.Rythmn2Braille()
        BraillePitch = MusicBraille.Pitch2Braille()
        BrailleOctave = MusicBraille.Octave2Braille()
        BrailleAccidental = MusicBraille.Accidental2Braille()
        for note in self.notes.values():
            note.Rythmn2Braille(BrailleRythmn)
            note.Pitch2Braille(BraillePitch)
            note.Octave2Braille(BrailleOctave)
            note.Accidental2Braille(BrailleAccidental)
            #print note.id, note.pitch, note.rythmn, note.timeon, note.rythmn_braille, note.octv, note.octv_braille, note.note, note.pitch_braille, note.sharpstatus

    # def split_list(a_list):
    #     half = len(a_list)//2
    #     return a_list[:half], a_list[half:]

    def SendData2Arduino(self):
        # Build commmunication between Arduino and Python
        ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
        time.sleep(1)
        braille = []

        for note in self.notes.values():
            braille = note.pitch_braille + note.rythmn_braille
            #print(braille)

            brailleone = braille[:len(braille) / 2]
            brailletwo = braille[len(braille) / 2:]
            counter = 0

            while counter < len(braille):
                braillesplit = [braille[counter], braille[counter + 1], braille[counter + 2]]
                print(braillesplit)
                char = 0
                if braillesplit[0] == 1:
                    char += 1
                if braillesplit[1] == 1:
                    char += 2
                if braillesplit[2] == 1:
                    char += 4
                counter += 3
                print(char)



            # charchr = str(char)
            # print(charchr)
            #
            # ser.flush()
            # ser.write(charchr)
            # print(charchr, "sent")
            # time.sleep(2)


    def run(self, serial=True):
        self.GetNotesFromMidi()
        self.Notes2Braile()
        print("Hello")
        if serial:
            print("detectSerial")
            self.SendData2Arduino()


if __name__ == "__main__":
    braille = MusicBraille("twinkle_twinkle.mid")
    braille.run(serial=True)
