#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Data_base{
public:
	//------- CONSTRUCTOR --------//
	Data_base(){
		cout << "enter file name" << endl;
		cin >> name;
	}
	//------- CREATES A SIMPLE .TXT FILE WITH INPUT NAME AFTER CHECKING IF IT EXISTS --------//
	bool create (){
		if(!look_for()){
			ofstream text_file;
			text_file.open (name);
			text_file.close();
			cout << "file created" << endl;
			return true;
		}else{
			cout << "file name already taken" << endl;
			return false;
		}
	}

	//------ REMOVES AN EXISTING FILE AFTER CHECKING IF IT EXISTS ------//
	bool remove (){
		if(look_for()){
			std::remove(name);
			cout << "file removed" << endl;
			return true;
		}else{
			cout << "can't remove file" << endl;
			return false;
		}
	}

	//------ LOOKS FOR A FILE NAME IN THE PROJECT DIRECTORY AND RETURNS 1 OR 0 -------//
	bool look_for (){
		ifstream text_file(name);
		if (text_file.good()){
			cout << "fichier existant" << endl;
			text_file.close();
			return true;
		}else{
			cout << "impossible d'ouvrir le fichier" << endl;
			text_file.close();
			return false;
		}
	}

private:
	char name[100];
};

int main(){
	Data_base tv_file;
	//tv_file.create();
	tv_file.remove();
	//tv_file.look_for();
}

