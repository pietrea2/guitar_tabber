#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <shellapi.h>
#include <C:\Users\adamp\Documents\C - OpenGL Tests\guitar-tabber-functions.cpp>

using namespace std;

int main(){
	
  ofstream file;
  file.open ("Guitar Tab Test Example w spaces.txt");
  
//ShellExecute(0, 0, "http://www.google.com", 0, 0 , SW_SHOW );
  
  int strings = 6;
  int tab_line_length = 100;
  string tuning;
  char tuning_char[20];
  
  string artist_name, song_name;
  std::vector<int> chord_frets (6);
  std::vector< vector<int> > chord_fret_lib;
  int num_of_chords = 0;
  string next_finish = "next";
  string chord_spaces;
  std::vector< string > chord_spaces_lib;
  
  //Standard Tunings
  char stand[6] = {'E', 'A', 'D', 'G', 'B', 'e'};
  string half_step_down[6] = {"Eb", "Ab", "Db", "Gb", "Bb", "Eb"};
  char full_step_down[6] = {'D', 'G', 'C', 'F', 'A', 'D'};
  
  //Drop Tunings
  char drop_d[6] = {'D', 'A', 'D', 'G', 'B', 'e'};
  string drop_c_sharp[6] = {"C#", "Ab", "Db", "Gb", "Bb", "Eb"};
  string drop_d_flat[6] = {"Db", "Ab", "Db", "Gb", "Bb", "Eb"};
  char drop_c[6] = {'C', 'G', 'C', 'F', 'A', 'D'};
  
  menu_1();
  getline(cin, tuning); //reads all words and spacings YAYAYAYAY!
  menu_2();
  getline(cin, artist_name);
  cout << "WOW! I LOVE THAT ARTIST! And what is the song name?: ";
  getline(cin, song_name);
  menu_3();

  
  while(next_finish != "finish"){
  
	  cout << "Chord #" << num_of_chords+1 << ": ";
	  cin >> chord_frets[0] >> chord_frets[1] >> chord_frets[2];
	  cin >> chord_frets[3] >> chord_frets[4] >> chord_frets[5];
	  chord_fret_lib.push_back(chord_frets);
	  cout << "Length of chord: (short, long): ";
	  cin.ignore();
	  getline(cin, chord_spaces);
	
	  cout << "next or finish? ";
	  cin >> next_finish;
	  num_of_chords++;
	  chord_spaces_lib.push_back(chord_spaces);
  
  }
  
  cout << "You entered the chords:" << endl;
  for(int i = 0; i < num_of_chords; i++ ){
  	for(int z = 0; z < 6; z++){
  		cout << chord_fret_lib[i][z] << " ";
  	}
  	cout << endl;
  	
  }




////////////////////////////////////////////////////
//Printing the guitar tab file

int printed_chords;

file << "-------------------------------------------" << endl;
file << "Band/artist: " << artist_name << endl;
file << "Song Name: " << song_name << endl;
file << "-------------------------------------------" << endl << endl << endl;

  for(int s = 0; s < strings; s++){
  	
  	printed_chords = 0;
  	
  	if( tuning == "standard" || tuning == "Standard" ){
  		file << stand[5-s] << "|";
  	}
  	else if( tuning == "dropcsharp" || tuning == "drop c sharp" || tuning == "Drop C Sharp" || tuning == "drop c#" || tuning == "Drop C#"){
  		file << drop_c_sharp[5-s] << "|";
  	}
	else if( tuning == "dropd" || tuning == "drop d" || tuning == "Drop d" || tuning == "Drop D"){
  		file << drop_d[5-s] << "|";
  	}  	
  	
  	
  	
	  for(int i = 0; i < tab_line_length; i++){
	  	
	  	if( printed_chords != num_of_chords){
		  	for (int x = 0; x < num_of_chords; x++){
		  		file << chord_fret_lib[x][5-s];
		  		
		  		int print_spaces;
		  		if(chord_spaces_lib[x] == "short") print_spaces = 4;
		  		else if(chord_spaces_lib[x] == "long") print_spaces = 8;
		  		for(int y = 0; y < print_spaces; y++){
		  			file << "-";
		  		}
		  		
		  		printed_chords++;
		  	}
	  	}
	  	
	  }
	  
	  
	  file << endl;
  }
  
  
  
  
  
  
  file.close();
  
  return 0;
}
