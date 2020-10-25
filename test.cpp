#include <iostream>
#include <vector>
#include  <filesystem>
#include "source/filedetect.cpp"
#include "source/program.cpp"

int main(){
	std::vector<program> fillmeh;
	getfiles(fillmeh);
	for (auto& entry: fillmeh){
	    std::cout << entry.getname() << std::endl;
	}

}
