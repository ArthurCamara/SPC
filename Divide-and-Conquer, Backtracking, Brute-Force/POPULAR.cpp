#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>


/*
 Given a list of voting cells, find how many votes 
 the winner of the election had.
 Each cell can vote in more than one cadidate. 
 Sample:
 5 //Number of candidates and cells
 1 1 1 0 0 //First voter voted in Candidate 1,2 and 3.
 1 1 0 1 1
 1 0 1 0 1
 0 1 0 1 0
 0 1 1 1 1
 
 4 //Output. Candidate 2 won with 4 votes.
 */

using namespace std;

vector<unsigned> parseLine(string line) {
  vector<unsigned> ret;
  unsigned n = 0;
  stringstream stream(line);
  while(stream >> n)
    ret.push_back(n);
  return ret;
}

int main(int argc, char *argv[]) {

  
  string in;
  string line;
  vector<unsigned> ballot;
  vector<unsigned> votes;
  getline(std::cin, in);
  int num_students = stoi(in);
  while(num_students>0) {
//    cout<<num_students<<endl;
    votes = vector<unsigned>(num_students, 0);
    for (unsigned int i =0; i<num_students; ++i) {
      getline(cin, line);
//      cout<<line<<endl;
      ballot = parseLine(line);
      for (unsigned int j =0; j<num_students; ++j){
        if(ballot[j]==1)
          votes[j]++;
      }
    }
    cout<<*max_element(std::begin(votes), std::end(votes))<<endl;
    getline(std::cin, in);
    num_students = stoi(in);
  }
  
}
