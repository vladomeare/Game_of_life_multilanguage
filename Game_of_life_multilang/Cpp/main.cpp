#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

int sizex = 0;
int sizey = 0;
string file_field = "../main_data/field.txt";

vector<vector<int>> reading_field(string file){
	vector<vector<int>> v;
	string line;
	ifstream myfile(file.c_str(),ifstream::in);
	if (myfile.is_open()){
		while(getline(myfile,line)){
			sizey++;
			sizex = line.size();
		};
		v.resize(sizey, vector<int>(sizex));
		myfile.close();
	}else{
		ofstream logfile("../../log.txt");
		logfile << "log" << " : Unable to open first time file field.txt\n";
		logfile.close();
	};

	ifstream file_second(file.c_str(),ifstream::in);
	if (file_second.is_open()){
		int iter =0;
		while(getline(file_second,line)){
			for (int i = 0; i < sizex; i++){
				v[iter][i] = line[i]-48;
			};
			iter++;
		}
	}else{
		ofstream logfile("../../log.txt");
		logfile << "log" << " : Unable to open second time file field.txt\n";
		logfile.close();
	};
	file_second.close();
	return v;
}

void print_field(vector<vector<int>> v){
	for (int i = 0; i < sizey; i++){
		for (int j = 0; j < sizex; j++){
			cout << v[i][j];
		}
		cout << endl;
	}
}

vector<vector<int>> game_of_life(vector<vector<int>> v){
	vector<vector<int>> temp;
	temp.resize(sizey, vector<int>(sizex));
	int x = sizex-1;
	int y = sizey-1;
	for(int i = 0; i < sizey; i++){
		for (int j = 0; j < sizex; j++)
		{	
			int neighbours = 0;
			if(i == 0 || i == y || j == 0 || j == x){
				if(i == 0 && j == 0){
					if(v[i][j+1] == 1){ // 5
						neighbours++;
					}
					if(v[i+1][j] == 1){ // 7
						neighbours++;
					}
					if(v[i+1][j+1] == 1){ // 8
						neighbours++;
					}
				}else if(i == 0 && j == x){	
					if(v[i][j-1] == 1){ // 4
						neighbours++;
					}
					if(v[i+1][j-1] == 1){ // 6
						neighbours++;
					}
					if(v[i+1][j] == 1){ // 7
						neighbours++;
					}
				}else if(i == y && j == 0){
					if(v[i-1][j] == 1){ // 2
						neighbours++;
					}
					if(v[i-1][j+1] == 1){ // 3
						neighbours++;
					}
					if(v[i][j+1] == 1){ // 5
						neighbours++;
					}
				}else if(i == y && j == x){
					if(v[i-1][j-1] == 1){ // 1 
						neighbours++;
					}
					if(v[i-1][j] == 1){ // 2
						neighbours++;
					}
					if(v[i][j-1] == 1){ // 4
						neighbours++;
					}
				}else if(i == 0){
					if(v[i][j-1] == 1){ // 4
						neighbours++;
					}
					if(v[i][j+1] == 1){ // 5
						neighbours++;
					}
					if(v[i+1][j-1] == 1){ // 6
						neighbours++;
					}
					if(v[i+1][j] == 1){ // 7
						neighbours++;
					}
					if(v[i+1][j+1] == 1){ // 8
						neighbours++;
					}
				}else if(i == y){
					if(v[i-1][j-1] == 1){ // 1 
						neighbours++;
					}
					if(v[i-1][j] == 1){ // 2
						neighbours++;
					}
					if(v[i-1][j+1] == 1){ // 3
						neighbours++;
					}
					if(v[i][j-1] == 1){ // 4
						neighbours++;
					}
					if(v[i][j+1] == 1){ // 5
						neighbours++;
					}
				}else if(j == 0){
					if(v[i-1][j] == 1){ // 2
						neighbours++;
					}
					if(v[i-1][j+1] == 1){ // 3
						neighbours++;
					}
					if(v[i][j+1] == 1){ // 5
						neighbours++;
					}
					if(v[i+1][j] == 1){ // 7
						neighbours++;
					}
					if(v[i+1][j+1] == 1){ // 8
						neighbours++;
					}
				}else{
					if(v[i-1][j-1] == 1){ // 1 
						neighbours++;
					}
					if(v[i-1][j] == 1){ // 2
						neighbours++;
					}
					if(v[i][j-1] == 1){ // 4
						neighbours++;
					}
					if(v[i+1][j-1] == 1){ // 6
						neighbours++;
					}
					if(v[i+1][j] == 1){ // 7
						neighbours++;
					}
				}
			}else{
				// for loop will be shorter!!!!!!
				if(v[i-1][j-1] == 1){ // 1 
					neighbours++;
				}
				if(v[i-1][j] == 1){ // 2
					neighbours++;
				}
				if(v[i-1][j+1] == 1){ // 3
					neighbours++;
				}
				if(v[i][j-1] == 1){ // 4
					neighbours++;
				}
				if(v[i][j+1] == 1){ // 5
					neighbours++;
				}
				if(v[i+1][j-1] == 1){ // 6
					neighbours++;
				}
				if(v[i+1][j] == 1){ // 7
					neighbours++;
				}
				if(v[i+1][j+1] == 1){ // 8
					neighbours++;
				}
			}
			if(neighbours == 3){
				temp[i][j] = 1;
			}else if(neighbours == 2){
				temp[i][j] == v[i][j];
			}else{
				temp[i][j] == 0;
			}
		}
	}
	return temp;
}

void output_file(vector<vector<int>> res, string file){
	ofstream file_out(file);
	if(file_out.is_open()){
		for(int i = 0; i < sizey; i++){
			for(int j = 0; j < sizex; j++){
				file_out << res[i][j];
			}
			file_out << "\n";
		}
	}else{
		ofstream logfile("../../log.txt");
		logfile << "log" << " : Unable to write in file field.txt\n";
		logfile.close();
	}
	file_out.close();
}

bool dead_or_repeat(vector<vector<int>> original, vector<vector<int>> neww){
	bool stable = true;
	bool zero = true;
	for(int i = 0; i < sizey; i++){
		for(int j = 0; j < sizex; j++){
			if(neww[i][j] != 0){
				zero = false;
			}
		}
	}
	if(zero == true){
		return zero;
	}
	for(int i = 0; i < sizey; i++){
		for(int j = 0; j < sizex; j++){
			if(neww[i][j] != original[i][j]){
				stable = false;
			}
		}
	}
	return stable;
}

void output_dead(string file){
	ofstream file_out(file);
	if(file_out.is_open()){
		file_out << "Restart\n";
	}else{
		ofstream logfile("../../log.txt");
		logfile << "log" << " : Unable to write in file field.txt\n";
		logfile.close();
	}
	file_out.close();
}

int main(){
	vector<vector<int>> field = reading_field(file_field);
	vector<vector<int>> result = game_of_life(field);
	if(dead_or_repeat(field,result)){
		output_dead(file_field);
	}else{	
		output_file(result, file_field);
	}
	return 0;
}