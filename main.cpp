/* CSCI 261 Final Project: Guitar Chord Dictionary
 *
 * Author: Kyle Kells
 *
 *
 */
#include "Chord.h"

int main() {
    cout << "Welcome to the major guitar chord generator!" << endl << "Enter the root note of the chord you would like to see followed by 'n' for natural or '#' for sharp" << endl;
    string userInput;
    cin >> userInput;
    Chord chord(userInput);
    chord.setFretboard();
    chord.displayChord(chord.chordNotes());
    return 0;
}
