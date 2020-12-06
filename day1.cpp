#include <iostream>
#include <fstream>

int main()
{
   std::ifstream infs{};
   int dummyinput{};
   int sum{};
   int totalnumbers{};

   try
   {
      std::cout << "Opening \"day1\" file\n";

      infs.open("day1.txt");

      if (!infs.is_open())
      {
         throw std::runtime_error("Shit happened, file didn't open\n");
      }

      while (infs >> dummyinput)
      {
         ++totalnumbers;
      }

      infs.clear();
      infs.seekg(0, std::ios::beg);

      int *pfilenum = new int[totalnumbers];

      for (int i{0}; i < totalnumbers; ++i)
      {
         infs >> pfilenum[i];
      }

      for (int i{0}; i < totalnumbers - 2; ++i)
      {
         for (int j{i + 1}; j < totalnumbers - 1; ++j)
         {
            for (int k{j + 1}; k < totalnumbers; ++k)
            {
               sum = pfilenum[i] + pfilenum[j] + pfilenum[k];

               if (sum == 2020)
               {
                  std::cout << pfilenum[i] << " " << pfilenum[j] << " " << pfilenum[k]<< "\n" 
                  << pfilenum[i] * pfilenum[j] * pfilenum[k]<< "\n";
               }
            }


         }
      }
      
      infs.close();
      delete[] pfilenum;
      pfilenum = nullptr;
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }

   return 0;
}