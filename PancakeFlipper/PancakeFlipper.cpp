// PancakeFlipper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int PANCAKE_MAX = 10;

// Flip sort, not very efficient, but pancakes have their limitations...
void Flip(int* pancakes, int k)
{
   int temp = ((k + 1) / 2);
   for (int i = 0; i < ((k + 1) / 2); ++i)
   {
      temp = pancakes[i];
      pancakes[i] = pancakes[k - i];
      pancakes[k - i] = temp;
   }
}

// Print the order of pancakes
void outputOrder(int* pancakes)
{
   for (int i = 0; i < PANCAKE_MAX; ++i)
   {
      std::cout << pancakes[i] << " ";
   }
   std::cout << std::endl;
}

void sort(int* pancakes)
{
   // Output starting order
   outputOrder(pancakes);
   for (int i = 0; i < (PANCAKE_MAX - 1); ++i)
   {
      // Find the largest pancake remaining
      int largestPancake = pancakes[0];
      int largestLocation = 0;
      for (int j = 1; j < (PANCAKE_MAX - i); ++j)
      {
         if (pancakes[j] > largestPancake)
         {
            largestPancake = pancakes[j];
            largestLocation = j;
         }
      }
      // Flip the largest pancake to the top
      Flip(pancakes, largestLocation);
      outputOrder(pancakes);
      // Flip the largest pancake to the bottom
      Flip(pancakes, (PANCAKE_MAX - 1 - i));
      // Print the order
      outputOrder(pancakes);
   }
}

int main()
{
   // Create some pancakes
   int pancakes[PANCAKE_MAX];
   for (int i = 0; i < PANCAKE_MAX; ++i)
   {
      pancakes[i] = rand() % 50;
   }
   // Sort them pancakes!
   sort(pancakes);

   system("PAUSE");
    return 0;
}

