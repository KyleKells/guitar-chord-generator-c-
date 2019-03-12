//
// Created by Kyle on 12/6/2018.
//

#include "Chord.h"

//Default constructor
Chord::Chord() {
    _rootNote = "An";

}
//Parameterized constructor
Chord::Chord(string const note) {
    _rootNote = note;
}

//Create a vector containing all notes within the desired chord
vector<string> Chord::chordNotes () const{
    int rootPos = 0;
    //Create a vector of the notes in the musical alphabet
    vector<string> musicalAlphabet = {"An","A#","Bn","Cn","C#","Dn","D#","En","Fn","F#","Gn","G#"};
    vector<string> notesInChord;
    //The root note is always within the major chord
    notesInChord.push_back(_rootNote);
    //Find the root notes position within the musical alphabet
    for (int i = 0;i<musicalAlphabet.size();++i){
        if (musicalAlphabet.at(i) == _rootNote){
            rootPos = i;
        }
    }

    //Accounts for the circular nature of the musical alphabet

    //Major third(4 halfsteps away from root)
    if (rootPos  < 8){
        notesInChord.push_back(musicalAlphabet.at(rootPos+4));
    }
    else{
        notesInChord.push_back(musicalAlphabet.at(rootPos-8));
    }
    ///Perfect 5th(7 halfsteps away from root)
    if (rootPos < 5){
        notesInChord.push_back(musicalAlphabet.at(rootPos+7));
    }
    else{
        notesInChord.push_back(musicalAlphabet.at(rootPos-5));
    }
    return notesInChord;

}
//Create a vector of notes on the guitar fretboard using an input file
void Chord::setFretboard() {
    ifstream notelocations;
    notelocations.open("notelocations.txt");

    string openNotes;
    string firstFret;
    string secondFret;
    string thirdFret;
    getline(notelocations, openNotes);
    getline(notelocations, firstFret);
    getline(notelocations, secondFret);
    getline(notelocations, thirdFret);
    _fretboard.push_back(openNotes);
    _fretboard.push_back(firstFret);
    _fretboard.push_back(secondFret);
    _fretboard.push_back(thirdFret);


}
//Create and display chord diagram
void Chord::displayChord(vector<string> const notesInChord) {
    vector<bool> hitList = {false,false,false,false,false,false};
    //Keeps track of fret
    int j;
    //Keeps track of string
    int k = 0;
    for (int i = 1;i<= 16;i+=3){
        for( j=0;j<4;++j) {
            //If the current note on the fret board is in the chord and that string has not already been used
            if ((_fretboard[j].substr(i, 2) == notesInChord[0] ||_fretboard[j].substr(i, 2) == notesInChord[1]||_fretboard[j].substr(i, 2) == notesInChord[2]) && hitList[k] == false){
                //Mark string as used
                hitList[k] = true;
                //Place x's where fingers should go (or when open string should ring out)
                _fretboard[j][i] = 'x';
                _fretboard[j][i+1] = 'x';
            }
            else{
                //Place -'s where fingers are not placed
                _fretboard[j][i] = '-';
                _fretboard[j][i+1] = '-';
            }
        }
        k +=1;

    }
    cout << "Notes in chord: " << notesInChord[0] << " " << notesInChord[1] << " " << notesInChord[2]<< endl;
    cout << "Chord diagram (number indicates fret): " << endl;
    cout << "0 " << _fretboard[0] << endl << "1 "<< _fretboard[1] << endl << "2 " << _fretboard[2] << endl << "3 "<< _fretboard[3] << endl;
}