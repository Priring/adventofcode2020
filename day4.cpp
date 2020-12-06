#include <iostream>
#include <fstream>
#include <string>
#include "passport.h"

int main()
{
   std::ifstream infs{"day4.txt"}; // crank that shit open
   std::string passportinfo{}; // info from batch
   std::string passportsection{};
   int colonidx{};
   int totalvalid{}; // num passports that are valid

   passport* pPassport{new passport};

   while (!infs.eof())
   {
      infs >> passportinfo;

      colonidx = passportinfo.find(':');

      if(passportinfo.size() == 1)
      {
         if (pPassport->IsValidPart1())
         {
            ++totalvalid;
         }

         delete pPassport;
         pPassport = new passport;
      }
      else if (passportinfo.substr(0, 3) == "byr")
      {
         pPassport->byr = passportinfo.substr(colonidx + 1);
      }
      else if (passportinfo.substr(0, 3) == "iyr")
      {
         pPassport->iyr = passportinfo.substr(colonidx + 1);
      }
      else if (passportinfo.substr(0, 3) == "eyr")
      {
         pPassport->eyr = passportinfo.substr(colonidx + 1);
      }
      else if (passportinfo.substr(0, 3) == "hgt")
      {
         pPassport->hgt = passportinfo.substr(colonidx + 1);
      }
      else if (passportinfo.substr(0, 3) == "hcl")
      {
         pPassport->hcl = passportinfo.substr(colonidx + 1);
      }
      else if (passportinfo.substr(0, 3) == "ecl")
      {
         pPassport->ecl = passportinfo.substr(colonidx + 1);
      }
      else if (passportinfo.substr(0, 3) == "pid")
      {
         pPassport->pid = passportinfo.substr(colonidx + 1);
      }
      else if (passportinfo.substr(0, 3) == "cid")
      {
         pPassport->cid = passportinfo.substr(colonidx + 1);
      }
   }

   std::cout << "\n\ntotal valid passports: " << totalvalid << "\n\n";

   return 0;
}