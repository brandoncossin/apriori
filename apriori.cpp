// apriori algorithm
// Brandon Cossin
// 9/26/2021
// reads input from stream and outputs results
// needs minimum support %

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cmath>

using std::vector; using std::list;
using std::cout; using std::endl;
using std::map; using std::string;
void printMiniList(map<string, vector<int>> list){

  for(auto e: list){
    cout << e.first << ":";
    for(int i: e.second){
      cout << i << " ";
    }
    cout << "|||" << e.second.size() << endl;
  }
}
void cleanFunction(map<string, vector<int>>& uncheckedList, double minSup){
  for(auto it = uncheckedList.begin(); it != uncheckedList.end();){
    if(it->second.size() < minSup){
      uncheckedList.erase(it++);
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
  map<string, vector<int>> Candidate6;
  std::ifstream file (argv[1]);
  int k = 0;
  for(std::string line; getline(file, line); ){
    char letter;
    ++k;
    vector<char> numbers;
    for(char i: line){
      if(i != ' '){
        numbers.push_back(i);
      }
    }
    unsigned int opsize = std::pow(2, numbers.size());
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
      {
        string itemset;
        for (int j = 0; j < numbers.size(); j++)
          {
            /* Check if jth bit in the counter is set
               If set then print jth element from arr[] */
            if (counter & (1<<j))
              itemset.push_back(numbers[j]);
          }

        vector<int> occurrences;
        occurrences.push_back(k);
        auto ret = Candidate6.insert(make_pair(itemset, occurrences));
        if(!ret.second){
          ret.first->second.push_back(k);
        }
      }

  }
  int minPercent = atoi(argv[2]);
  double minSup = ((double)minPercent/100) * k;
  cout << "Candidate Set 6\n";
  cleanFunction(Candidate6, minSup);
  printMiniList(Candidate6);
  file.close();
}
