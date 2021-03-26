#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <shellapi.h>
#include <C:\Users\adamp\Documents\C - OpenGL Tests\guitar-tabber-functions.h>


using namespace std;

void menu_1(void){
	
  cout << "Hello!" << endl;
  cout << "What guitar tuning does this song use?" << endl;
  cout << "1. Standard" << endl;
  cout << "2. Drop D" << endl;
  cout << "3. Drop C#" << endl;
  
  return;
}

void menu_2(void){
	
  cout << endl << "Wow! That's an awesome guitar tuning aha!" << endl;
  cout << "Now let's start writing your guitar tab:" << endl;

  cout << "But first, who is this song by? (Band/artist): ";
	
  return;
  
}

void menu_3(void){

  cout << "Sounds cool! And I didn't ever hear the song yet!" << endl << endl;
	
  cout << endl << "Enter your fret fingerings starting with the lowest ";
  cout << "string to the highest, one chord at a time.";
  cout << endl << "Let's try it out:" << endl;
	
}


