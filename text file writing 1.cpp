#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	
  ofstream file;
  file.open ("march 14 tab test 1.txt");
  
  //Create and open a text file
  //ofstream MyFile("filename.txt");
  //Write to the file
  //MyFile << "Files can be tricky, but it is fun enough!";
  
  int strings = 6;
  int line_length = 100;
  string tuning;
  char tuning_char[20];
  
  char stand[6] = {'e', 'a', 'd', 'g', 'b', 'e'};
  char drop_d[6] = {'d', 'a', 'd', 'g', 'b', 'e'};
  string drop_c_sharp[6] = {"c#", "ab", "db", "gb", "bb", "eb"};
  
  cout << "Hello!" << endl;
  cout << "What guitar tuning does this song use?" << endl;
  cout << "1. Standard" << endl;
  cout << "2. Drop D" << endl;
  cout << "3. Drop C#" << endl;
  //cin >> tuning_char; 
  getline(cin, tuning); //reads all words and spacings YAYAYAYAY!
  
  cout << endl << "Wow! That's an awesome guitar tuning aha!" << endl;
  cout << "Now let's start writing your guitar tab:" << endl;
  
  string artist_name, song_name;
  cout << "But first, who is this song by? (Band/artist): ";
  getline(cin, artist_name);
  cout << "WOW! I LOVE THAT ARTIST! And what is the song name?: ";
  getline(cin, song_name);
  cout << "Sounds cool! And I didn't ever hear the song yet!" << endl << endl;
  
  
  cout << endl << "Enter your fret fingerings starting with the lowest string to the highest, one chord at a time.";
  cout << endl << "Let's try it out:" << endl;
  //cout << "1st chord:";
  int a, b, c, d, e, f;
  std::vector<int> chord_frets (6);
  std::vector< vector<int> > chord_fret_lib;
  std::vector<int> chord (5);
  int num_of_chords = 0;
  string next_finish = "next";
  //cin >> a >> b >> c >> d >> e >> f;
  
  while(next_finish != "finish"){
  
  cout << "Chord #" << num_of_chords+1 << ": ";
  cin >> chord_frets[0] >> chord_frets[1] >> chord_frets[2] >> chord_frets[3] >> chord_frets[4] >> chord_frets[5];
  chord_fret_lib.push_back(chord_frets);
  cout << "next of finish? ";
  cin >> next_finish;
  num_of_chords++;
  
  }
  //cout << "You entered the chord:" << a << b << c << d << e << f << endl;
  cout << "You entered the chords:" << endl;
  
  for(int i = 0; i < num_of_chords; i++ ){
  	for(int z = 0; z < 6; z++){
  		cout << chord_fret_lib[i][z];
  	}
  	cout << endl;
  	
  }
  //chord_frets[0] << chord_frets[1] << chord_frets[2] << chord_frets[3] << chord_frets[4] << chord_frets[5] << endl;



////////////////////////////////////////////////////
//Printing the guitar tab file


int printed_chords;

file << "Band/artist: " << artist_name << endl;
file << "Song Name: " << song_name << endl << endl << endl;

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
  	
  	
	  for(int i = 0; i < line_length; i++){
	  	file << "--";
	  	
	  	if( printed_chords != num_of_chords){
		  	for (int x = 0; x < num_of_chords; x++){
		  		file << chord_fret_lib[x][5-s] << "--";
		  		printed_chords++;
		  	}
	  	}
	  	/*if(i == 3){
	  		file << chord_frets[5-s];
	  	}*/
	  }
	  
	  
	  file << endl;
  }
  
  
  
  
  
  
  file.close();
  
  return 0;
}
