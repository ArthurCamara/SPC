#include <iostream>
#include <fstream>
#include <cmath>

/*
 Solution for
http://www.spoj.com/problems/LINESEG/
 This is actually pretty simple, since the lines are aways vertical or horizontal.
 So, there are 4 possible situations:
 H-H, H-V, V-V and V-H. It's easier to treat each one individually.
 */

using namespace std;
typedef unsigned uint;

typedef struct Segment {
  int px, py;
  int qx, qy;
  char type;
}Segment;

void sortByX(Segment& seg) {
  //sort points by X
  int aux;
  if(seg.px>seg.qx){
    aux = seg.qx;
    seg.qx = seg.px;
    seg.px = aux;
  }
}

void sortByY(Segment& seg) {
  //sort points by Y
  int aux;
  if(seg.py>seg.qy){
    aux = seg.qy;
    seg.qy = seg.py;
    seg.py = aux;
  }
}


bool isPoint(Segment s){
  return (s.px==s.qx && s.qy==s.py);
}


string intercept(Segment& s1, Segment& s2){
  if(isPoint(s1) && isPoint(s2)){
    if(s1.px==s2.px && s1.py == s2.py){
      return "POINT";
    }
    return "NO";
  }
  
  if(s1.type=='H' && s2.type=='H'){
    //Paralel segments
    if(s1.py!=s2.py)
      return "NO";
    sortByX(s1);
    sortByX(s2);
    if(s1.qx<s2.px)
      return "NO";
    //Check if they intercept at a single point
    if(s1.qx==s2.px || s1.px == s2.qx)
      return "POINT";
    //Segments overlap. But one is not smaller than the other
    if((s1.qx>=s2.px && s1.px <=s2.px) ||(s2.qx>=s1.px && s2.px <=s1.px) ){
      if (isPoint(s1) || isPoint(s2))
        return "POINT";
      return "SEGMENT";
    }
    //Segments overlap. One is smaller than the other
    if((s1.px>=s2.px && s1.qx<=s2.qx) || (s2.px>=s1.px && s2.qx<=s1.qx)){
      if (isPoint(s1) || isPoint(s2))
        return "POINT";
      return "SEGMENT";
    }
  }
  if( (s1.type == 'V' && s2.type == 'V') || (s1.type=='V' && isPoint(s2)) || (s2.type=='V' && isPoint(s1)) ){
    //paralel
    if(s1.px!=s2.px)
      return "NO";
    sortByY(s1);
    sortByY(s2);
    if(s1.qy<s2.py)
      return "NO";
    //Check if they intercept at a single point
    if(s1.qy==s2.py || s1.py == s2.qy)
      return "POINT";
    //They are colinear. At least one of the points of either are inside the other
    if((s1.qy>=s2.py && s1.py <=s2.py) ||(s2.qy>=s1.py && s2.py <=s1.py) ){
      if (isPoint(s1) || isPoint(s2))
        return "POINT";
      return "SEGMENT";
    }
    if((s1.py >= s2.py && s1.qy <= s2.qy) || (s2.py >= s1.py && s2.qy <= s1.qy)){
      return "POINT";
    return "SEGMENT";
    }
  }
  if(s1.type == 'H' && s2.type == 'V'){
    sortByY(s2);
    sortByX(s1);
    if((s1.py == s2.py && s1.px == s2.px) || (s1.qy == s2.qy && s1.qx == s2.qx) ||
       (s1.py == s2.qy && s1.px == s2.qx) || (s1.qy == s2.py && s1.qx == s2.px)) {
      return "POINT";
    }
    if (s1.py>=s2.py && s1.py<=s2.qy && s2.px>=s1.px && s2.px <= s1.qx)
      return "POINT";
    return "NO";
    
  }
  else{
    sortByY(s1);
    sortByX(s2);
    //Single point-intercept
    if((s2.py == s1.py && s2.px == s1.px) || (s2.qy == s1.qy && s2.qx == s1.qx) ||
       (s2.py == s1.qy && s2.px == s1.qx) || (s2.qy == s1.py && s2.qx == s1.px)) {
      return "POINT";
    }
    //the s2's Y must be between the S1's Ys. AND s1's Y must be between S2's Ys.
    if (s2.py >= s1.py && s2.py <= s1.qy && s1.px >= s2.px && s1.px <= s2.qx)
      return "POINT";
    return "NO";
  }
}


int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  int T;
  cin>>T;
  
  int px,py,qx,qy;
  Segment l1, l2;
  
  while(T--) {
    cin>>px>>py>>qx>>qy;
    l1.px = px; l1.py=py;
    l1.qx = qx; l1.qy=qy;
    
    //Check if it's horizontal or vertical
    if(py==qy)
      l1.type='H';
    else
      l1.type='V';
    cin>>px>>py>>qx>>qy;
    l2.px = px; l2.py=py;
    l2.qx = qx; l2.qy=qy;
    if(py==qy)
      l2.type='H';
    else
      l2.type='V';
    cout<<intercept(l1, l2)<<endl;
  }
  
  return 0;
}