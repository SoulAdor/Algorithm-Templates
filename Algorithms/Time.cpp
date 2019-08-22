#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main()
{ 
   using namespace std::chrono; 
   auto start = high_resolution_clock::now();

   /* Code */

   auto end = high_resolution_clock::now(); 
   double time_taken =  duration_cast<nanoseconds> (end - start).count() * 1e-9; 
   cout << "Time taken by program is : " << fixed  << time_taken << setprecision(9) << " sec" << endl; 
}