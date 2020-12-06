#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


int main() {
   std::string seat{};
   std::vector<int> ID{};
   int currID{};
   int highestID{};
   int F{};
   int B{};
   int range{};

   std::ifstream infs{"day5.txt"};

   while (!infs.eof()) {
      std::getline(infs, seat);

      F = 0;
      B = 127;
      range = 127;

      for (int i{0}; i < 7; ++i)
      {
         range = (B - F) / 2;
         
         if (seat[i] == 'F')
         {
            B -= range + 1;
         }
         else
         {
            F += range + 1;
         }
      }

      currID = F * 8;

      F = 0;
      B = 7;
      range = 7;

      for (int i{7}; i < 10; ++i)
      {
         range = (B - F) / 2;

         if (seat[i] == 'L')
         {
            B -= range + 1;
         }
         else
         {
            F += range + 1;
         }
      }

      currID += F;

      if (currID > highestID)
      {
         highestID = currID;
      }

      ID.push_back(currID);
   }

   std::sort(ID.begin(), ID.end());

   for (int i{1}; i < ID.size() - 1; ++i)
   {
      std::cout << ID[i] << " ";

      if ((ID[i - 1] != ID[i] - 1) || (ID[i + 1] != ID[i] + 1))
      {
         std::cout << "houston we got a fuckin problem here\n";
      }
   }

   infs.close();

   return 0;
}