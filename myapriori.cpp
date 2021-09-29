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
  map<string, vector<int>> Candidate;

  std::ifstream file (argv[1]);
  int k = 0;
  for(std::string line; getline(file, line); ){
    char letter;
    ++k;
    for(char i: line){
      if(i != ' '){
        string itemset;
        itemset.push_back(i);
        vector<int> occurrences;
        occurrences.push_back(k);
        auto ret = Candidate.insert(make_pair(itemset, occurrences));
        if(!ret.second){
          ret.first->second.push_back(k);
        }
      }
    }
  }
  file.clear();
  file.seekg(0);
  int minPercent = atoi(argv[2]);
  double minSup = ((double)minPercent/100) * k;
  cout << "Candidate Set 1\n";
  cleanFunction(Candidate, minSup);
  printMiniList(Candidate);
  //Loop to find itemsets of size
  map<string, vector<int>> Candidate2;
  k = 0;
  for(std::string line; getline(file, line); ){
    char letter;
    ++k;
    vector<char> numbers;
    for(char i: line){
      if(i != ' '){
        numbers.push_back(i);
      }
    }
    for(int i = 0; i < numbers.size(); i++){
      for(int j = i + 1; j < numbers.size(); j++){
        string itemset;
        itemset.push_back(numbers[i]);
        itemset.push_back(numbers[j]);
        vector<int> occurrences;
        occurrences.push_back(k);
        auto ret = Candidate2.insert(make_pair(itemset, occurrences));
        if(!ret.second){
          ret.first->second.push_back(k);
        }
      }
    }
  }
  file.clear();
  file.seekg(0);
  cout << "Candidate Set 2\n";
  cleanFunction(Candidate2, minSup);
  printMiniList(Candidate2);
  //Loop to find itemsets of size
  map<string, vector<int>> Candidate3;
  k = 0;
  for(std::string line; getline(file, line); ){
    char letter;
    ++k;
    vector<char> numbers;
    for(char i: line){
      if(i != ' '){
        numbers.push_back(i);
      }
    }
    for(int i = 0; i < numbers.size(); i++){
      for(int j = i + 1; j < numbers.size(); j++){
        for(int l = j + 1; l < numbers.size(); l++){
        string itemset;
        itemset.push_back(numbers[i]);
        itemset.push_back(numbers[j]);
        itemset.push_back(numbers[l]);
        vector<int> occurrences;
        occurrences.push_back(k);
        auto ret = Candidate3.insert(make_pair(itemset, occurrences));
        if(!ret.second){
          ret.first->second.push_back(k);
        }
        }
      }
    }
  }
  file.clear();
  file.seekg(0);
  cout << "Candidate Set 3\n";
  cleanFunction(Candidate3, minSup);
  printMiniList(Candidate3);
  map<string, vector<int>> Candidate4;
  k = 0;
  for(std::string line; getline(file, line); ){
    char letter;
    ++k;
    vector<char> numbers;
    for(char i: line){
      if(i != ' '){
        numbers.push_back(i);
      }
    }
    for(int i = 0; i < numbers.size(); i++){
      for(int j = i + 1; j < numbers.size(); j++){
        for(int l = j + 1; l < numbers.size(); l++){
          for(int m = l + 1; m < numbers.size(); m++){
          string itemset;
          itemset.push_back(numbers[i]);
          itemset.push_back(numbers[j]);
          itemset.push_back(numbers[l]);
          itemset.push_back(numbers[m]);
          vector<int> occurrences;
          occurrences.push_back(k);
          auto ret = Candidate4.insert(make_pair(itemset, occurrences));
          if(!ret.second){
            ret.first->second.push_back(k);
          }
          }
        }
      }
    }
  }
  file.clear();
  file.seekg(0);
  cout << "Candidate Set 4\n";
  cleanFunction(Candidate4, minSup);
  printMiniList(Candidate4);
  map<string, vector<int>> Candidate5;
  k = 0;
  for(std::string line; getline(file, line); ){
    char letter;
    ++k;
    vector<char> numbers;
    for(char i: line){
      if(i != ' '){
        numbers.push_back(i);
      }
    }
    for(int i = 0; i < numbers.size(); i++){
      for(int j = i + 1; j < numbers.size(); j++){
        for(int l = j + 1; l < numbers.size(); l++){
          for(int m = l + 1; m < numbers.size(); m++){
            for(int n = m + 1; n < numbers.size(); n++){
            string itemset;
            itemset.push_back(numbers[i]);
            itemset.push_back(numbers[j]);
            itemset.push_back(numbers[l]);
            itemset.push_back(numbers[m]);
            itemset.push_back(numbers[n]);
            vector<int> occurrences;
            occurrences.push_back(k);
            auto ret = Candidate5.insert(make_pair(itemset, occurrences));
            if(!ret.second){
              ret.first->second.push_back(k);
            }
            }
          }
        }
      }
    }
  }
  file.clear();
  file.seekg(0);
  cout << "Candidate Set 5\n";
  cleanFunction(Candidate5, minSup);
  printMiniList(Candidate5);
  map<string, vector<int>> Candidate6;
  k = 0;
  for(std::string line; getline(file, line); ){
    char letter;
    ++k;
    vector<char> numbers;
    for(char i: line){
      if(i != ' '){
        numbers.push_back(i);
      }
    }
    for(int i = 0; i < numbers.size(); i++){
      for(int j = i + 1; j < numbers.size(); j++){
        for(int l = j + 1; l < numbers.size(); l++){
          for(int m = l + 1; m < numbers.size(); m++){
            for(int n = m + 1; n < numbers.size(); n++){
              for(int v = n + 1; v < numbers.size(); v++){
            string itemset;
            itemset.push_back(numbers[i]);
            itemset.push_back(numbers[j]);
            itemset.push_back(numbers[l]);
            itemset.push_back(numbers[m]);
            itemset.push_back(numbers[n]);
            itemset.push_back(numbers[v]);
            vector<int> occurrences;
            occurrences.push_back(k);
            auto ret = Candidate6.insert(make_pair(itemset, occurrences));
            if(!ret.second){
              ret.first->second.push_back(k);
            }
              }
            }
          }
        }
      }
    }
  }
  file.clear();
  file.seekg(0);
  cout << "Candidate Set 6\n";
  cleanFunction(Candidate6, minSup);
  printMiniList(Candidate6);
   file.close();
}
