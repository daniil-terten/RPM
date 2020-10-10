#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main(int argc, char** argv){
  if(argc<3) {
    std::cout << "Usage: inputFile outputFile.";
    exit(-1);
  }
  std::ifstream ifs(argv[1]);
  if(!ifs){
    std::cout << "Error opening input file. Check the filename.";
    exit(-1);
  }
  std::ofstream ofs(argv[2]);
  if(!ofs){
    std::cout << "Error opening output file.";
    exit(-1);
  }

  char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  std::string word;
  std::string line;
  while(getline(ifs,line)){
    std::istringstream iss(line);
    while(iss >> word){
      for (auto i: vowels) {
          if (word[0] == i){
            word[0] = toupper(word[0]);
            break;
          }
      }
      ofs << word << ' ';
    }
    ofs << "\n";
  }
  ifs.close();
  std::cout << "Operation successful.";
  return 1;
}