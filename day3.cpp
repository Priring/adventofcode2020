#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
   std::ifstream infs{"day3.txt"};
   std::string currline{}; 
   int currposition{0};
   int trees_encountered{0};
   int line_of_sight_size{};

   if (!infs.is_open()) {
      std::cout << "shit happened, file not open\n";
   }

   std::getline(infs, currline); // get the line
   line_of_sight_size = currline.size(); // get line size
   currposition += 3; // increment right
   

   while (!infs.eof()) {
      std::getline(infs, currline);

      if (currline[currposition] == '#') {
         currline[currposition] = 'X';
         ++trees_encountered;

         currposition += 3;

         if (currposition >= line_of_sight_size) {
            currposition -= line_of_sight_size;
         }
      }
      else {
         currposition += 3;

         if (currposition >= line_of_sight_size) {
            currposition -= line_of_sight_size;
         }
      }
   }

   std::cout << "\n\n\n" << trees_encountered << "\n";

   return 0;
}

//75
//294
//79
//85
//39