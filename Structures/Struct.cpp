struct P 
{
   int x, y;
   bool operator < (const P &p) 
   {
      if (x != p.x) return x < p.x;
      else return y < p.y;
   }
};

bool CompareNodes (const P& l, P const& r) {
   return l.x < r.x;
}