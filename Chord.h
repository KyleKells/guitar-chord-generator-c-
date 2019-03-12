//
// Created by Kyle on 12/6/2018.
//



#ifndef FINAL_PROJECT_CHORD_H
#define FINAL_PROJECT_CHORD_H
#include <iostream>
using namespace std;

#include <vector>
#include <fstream>
class Chord{
    public:
        //Constructors
        Chord();
        Chord(string const note);
        //Find notes within a chord
        vector<string> chordNotes() const;
        //Setter for _fretboard
        void setFretboard();
        //Create and display chord
        void displayChord(vector<string> const notesInChord );

    private:
        //Root note of chord
        string _rootNote;
        //Representation of notes on fretboard
        vector<string> _fretboard;


};
#endif //FINAL_PROJECT_CHORD_H
