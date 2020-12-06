#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

bool IsValid(const std::string &str, int lower, int upper, char reqchar, const std::string &password)
{
   std::istringstream inss{str};
   int charcount{};

   inss >> lower >> upper;
   upper *= -1;

   if (password[lower - 1] == reqchar && password[upper - 1] == reqchar)
   {
      return false;
   }
   else if(password[lower - 1] == reqchar || password[upper - 1] == reqchar)
   {
      return true;
   }

   return false;
}

int main()
{
   std::ifstream infs{};
   std::string txtline{};
   std::string password{};
   int lower{};
   int upper{};
   int totalvalid{};
   char requiredchar{};

   infs.open("day2.txt");

   if (!infs.is_open())
   {
      std::cout << "Shit happened, file not open\n";
   }

   while (!infs.eof())
   {
      std::getline(infs, txtline);

      requiredchar = txtline[txtline.find(':') - 1];
      password = txtline.substr(txtline.find(':') + 2);

      if (IsValid(txtline, lower, upper, requiredchar, password))
      {
         ++totalvalid;
      }
   }

   std::cout << totalvalid << "\n";

   return 0;
}