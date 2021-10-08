// apriori algorithm
// Brandon Cossin
// 9/26/2021
// reads input from stream and outputs results
// needs minimum support %

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

using std::vector;
using std::cout; using std::endl;
using std::map; using std::string;

void printMiniList(map<vector<string>, vector<int>> list, double k){
  for(auto e: list){
    for(string f: e.first){
      cout << f << " ";
    }
    cout << ": ";
    for(int i: e.second){
      cout << i << " ";
    }
    //support of each
    double support = (e.second.size() / k);
    cout << " ||| " << support << endl;
  }
}
void cleanFunction(map<vector<string>, vector<int>>& uncheckedList, double k, double minSup){
  for(auto it = uncheckedList.begin(); it != uncheckedList.end();){
    //support of each
    double support = (it->second.size() / k);
    if(support < minSup){
      //uncheckedList.erase(it++);
      it = uncheckedList.erase(it);
    }
    else{
      ++it;
    }
  }
}
int main(int argc, char* argv[]){
  if (argc <= 2){
    cout << "usage: " << argv[0]
         << "apriori algorithm to find frequency"
         << endl; exit(1);
  }
  //first step is to find how many transactions.
  //also find how wide to make it.
  //Candidate itemset of size k
  map<vector<string>, vector<int>> Candidate;
  std::ifstream file (argv[1]);
  int k = 0;
  for(std::string line; getline(file, line); ){
    string temp;
    ++k;
    vector<string> numbers;
    for(int i = 0; i < line.length(); ++i){
      if(line[i] == ' ' || line[i] == ','){
        numbers.push_back(temp);
        temp = "";
      }
      else{
        temp.push_back(line[i]);
      }
    }
    numbers.push_back(temp);
    unsigned int opsize = std::pow(2, numbers.size());
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
      {
        vector<string> itemset;
        for (int j = 0; j < numbers.size(); j++)
          {
            /* Check if jth bit in the counter is set
               If set then print jth element from arr[] */
            if (counter & (1<<j))
              itemset.push_back(numbers[j]);
          }
        vector<int> occurrences;
        occurrences.push_back(k);
        auto ret = Candidate.insert(make_pair(itemset, occurrences));
        if(!ret.second){
          ret.first->second.push_back(k);
        }
      }

  }
  int minPercent = atoi(argv[2]);
  double minSup = ((double)minPercent/100);
  cout << "Candidate Set\t Sets \t Support \n";
  cleanFunction(Candidate, k, minSup);
  printMiniList(Candidate, k);
  file.close();
}
