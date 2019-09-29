#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

/*
   Contents:
   1) Vector
   2) String
   3) Set
   4) Map
   5) Bitset
   6) Deque
   7) Stack
   8) Queue
   9) Priority queue
   10) Policy based set
*/
int main ()
{
   /*
      1) Vector
   */
  
   // When vector is passed as a parameter to some function, a copy of vector is actually created.
   vector<int> v = {2,4,2,5,1};
   int elements_count = v.size(); 		
   bool is_empty = v.empty();	
   v.resize(25); 
   v.push_back(123);
   v.clear();
   for (auto x : v) 
   {
      cout << x << "\n";
   }
   sort(v.begin(), v.end());

   /*
      2) String
   */
   string a = "hatti";
   string b = a + a;
   // substr takes two arguments - start index and length of substrin
   string c = b.substr(3, 4);
   // find takes a string or char as argument 
   auto result = b.find("iha");
   if (result == string::npos) cout << "Not found" << endl;
   else cout << "Found at index: " << result << endl;

   /*
      3) Set
   */
   set<int> s;
   s.insert(3);
   s.insert(2);
   cout << s.count(3) << "\n"; // 1
   s.erase(3);
   for (auto x : s) 
   {
      cout << x << "\n";
   }

   multiset<int> ms;
   ms.insert(5);
   ms.insert(5);
   ms.insert(5);
   cout << ms.count(5) << "\n"; // 3
   // Often, only one instance should be removed, which can be done as follows:
   ms.erase(ms.find(5));
   cout << ms.count(5) << "\n"; // 2
   // The function erase removes all instances of an element from a multiset:
   ms.erase(5);
   cout << ms.count(5) << "\n"; // 0

   /*
      4) Map
   */
   // If the value of a key is requested but the map does not contain it, 
   // the key is automatically added to the map with a default value.
   map <string, int> m;
   m ["monkey"] = 4;
   cout << m ["s"] << endl;
   // Check if key exists
   if (m.count("monkey")) {};
   for( auto const& [key, val] : m )
   {
      cout << key<< " : " << val << endl ;
   }

   /*
      5) Bitset
   */
   bitset<10> bs;
   bs[1] = 1;
   bs[3] = 1;
   bs[4] = 1;
   bs[7] = 1;
   cout << bs[4] << "\n"; // 1
   cout << bs[5] << "\n"; // 0
   // Returns number of ones
   bs.count();
   // Bit operations
   bitset<10> bitset_a(string("0010110110"));
   bitset<10> bitset_b(string("1011011000"));
   cout << (bitset_a & bitset_b) << "\n"; // 0010010000
   cout << (bitset_a | bitset_b) << "\n"; // 1011111110
   cout << (bitset_a ^ bitset_b) << "\n"; // 1001101110
   // Can do bitwise operations!
   cout << (bs << 1) << endl;
   cout << (bs << 2) << endl;

   /*
      6) Deque
   */
   // Can add elements to front and back in O(1), but also access elements in O(1)
   deque<int> d;
   d.push_back(5); // [5]
   d.push_back(2); // [5,2]
   d.push_front(3); // [3,5,2]
   d.pop_back(); // [3,5]
   d.pop_front(); // [5]
   cout << d[0] << endl;

   /*
      7) Stack
   */
   stack<int> stk;
   stk.push(3);
   stk.push(2);
   stk.push(5);
   while (!stk.empty())
   {
      cout << stk.top();
      stk.pop();
   }
   cout << endl;

   /*
      8) Queue
   */
   queue <int> q;
   q.push(3);
   q.push(2);
   q.push(5);
   while (!q.empty())
   {
      cout << q.front();
      q.pop();
   }
   cout << endl;

   /*
      9) Priority Queue
   */
   //Insertion and removal take O(logn) time, and retrieval takes O(1) time.
   cout << "Priority Queue" << endl;
   priority_queue<int> pq;
   pq.push(3);
   pq.push(5);
   pq.push(7);
   pq.push(2);
   while (!pq.empty())
   {
      cout << pq.top() << " ";
      pq.pop();
   }
   cout << endl;

   //  Custom comparator. Change global variables inside GetValue function to gett different compares.
   priority_queue <int, vector <int>, greater<int>> reverse_pq;
   struct Compare { 
      bool operator()(int first, int second) 
      {
         return GetValue(points[first]) < GetValue(points[second]);
      } 
   }; 
 
   priority_queue <int, vector<int>, Compare> pq; 
   /*
      10) Policy based set
   */
   // is like set but can be indexed like an array
   
   // Includes: 
   // #include <ext/pb_ds/assoc_container.hpp>
   using namespace __gnu_pbds;
   typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

   indexed_set indexed_s;
   indexed_s.insert(2);
   indexed_s.insert(3);
   indexed_s.insert(7);
   indexed_s.insert(9);
   // Returns second element in sorted array. O(log(N))
   auto x = indexed_s.find_by_order(2);
   cout << *x << "\n"; // 7
   // And the function order_of_key returns the position of a given element. O(log(N))
   cout << indexed_s.order_of_key(7) << "\n"; // 2
   // If the element does not appear in the set, we get the position that the element would have in the set:
   cout << indexed_s.order_of_key(6) << "\n"; // 2
   cout << indexed_s.order_of_key(8) << "\n"; // 3
}