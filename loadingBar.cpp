#include <bits/stdc++.h>
using namespace std;

class loadingBar{
private:
  int progress = 0, width, task;
  float amountPerChar;
  char leftBracket, rightBracket, empty, full;
  bool show, done = false, showPercentage, showRatio;
public:
  loadingBar(int _task, int _width, char _leftBracket, char _rightBracket, char _empty, char _full, bool _show, bool _showPercentage, bool _showRatio);
  void increment(int amount);
  void setProgress(int _progress);
  void setProgressPercentage(int percentage);
  void print(const char* message);
  ~loadingBar();
};

loadingBar::loadingBar(int _task = 100, int _width = 10, char _leftBracket = '[', char _rightBracket = ']', char _empty  = ' ', char _full  = '#', bool _show = true, bool _showPercentage = false, bool _showRatio = true){
  task = _task; width = _width; 
  amountPerChar = ((float) task) / width;
  cout << amountPerChar;
  leftBracket = _leftBracket; rightBracket = _rightBracket; empty = _empty; full = _full; 
  show = _show; showPercentage = _showPercentage; showRatio = _showRatio;
}

loadingBar::~loadingBar(){}

void loadingBar::increment(int amount = 1){
  progress += amount;
  if(progress >= task) done = true;
}
  
void loadingBar::setProgress(int _progress){
  progress = _progress;
  if(progress >= task) done = true;
}
  
void loadingBar::setProgressPercentage(int percentage){
  progress = (percentage * task) / 100;
  if(progress >= task) done = true;
}

void loadingBar::print(const char* message = ""){
  if(!done){
    cerr << leftBracket;
    int amount = (progress / amountPerChar);
    for(int i = 0; i < width; i++){
      if(i < amount) cerr << full;
      else cerr << empty;
    }
    cerr << rightBracket;
    if(showPercentage) cerr << "  " << (int)(100.0 * progress / task) << "%";
    if(showRatio) cerr << "  " << progress << "/" << task;
    cerr << endl;
  }else{
    cerr << leftBracket;
    for(int i = 0; i < width; i++) cerr << full;
    cerr << rightBracket << "  DONE";
    if(showPercentage) cerr << "  " << (int)(100.0 * progress / task) << "%";
    if(showRatio) cerr << "  " << progress << "/" << task;
    cerr << endl;
  }
  cerr << message << endl;
}

int main(){
  int task = 1024;
  loadingBar bar(task, 100, '[', ']', ' ', '#', true, true, true);
  bar.print();system("PAUSE");
  while(task--){
    system("cls");
    bar.increment();
    bar.print(task + "");
  }
}