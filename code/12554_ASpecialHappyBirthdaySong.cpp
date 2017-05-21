#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int songPosition = 0, personIndex = 0, totalPeople;
    cin >> totalPeople;
    vector<string> song;
    vector<string> people;
    string person;
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("Rujia");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    int peopleToStore = min(16, totalPeople);
    for (int i = 0; i < totalPeople; i++){
        cin >> person;
        if (i < peopleToStore){
            people.push_back(person);
        }
        cout << person + ": " + song.at(songPosition) << endl;
        songPosition = (songPosition + 1) % 16;
    }
    while (songPosition < 16){
        cout << people.at(personIndex) + ": " + song.at(songPosition++) << endl;
        personIndex = (personIndex + 1) % peopleToStore;
    }
    return 0;
}