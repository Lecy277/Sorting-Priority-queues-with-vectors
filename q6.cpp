// constructing priority queues with vectors
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <fstream>        // std::fstream

using namespace std;

class Spy {
string category,  Event_ID, Priority, abstract;
public:
Spy(string cat, string Pri, string event, string ab)
: Priority(Pri), category(cat), Event_ID(event), abstract(ab) {}
friend bool operator<(//sorts queue by greatest Priority
const Spy& x, const Spy& y) {
if(x.Event_ID < y.Event_ID)
return true;
}
friend ostream&//prints out queue later
operator<<(ostream& os, const Spy& Pri) {
return os << Pri.Event_ID << Pri.category
<< Pri.Priority << Pri.abstract;
}
};

int main ()
{
    ifstream fileIn;//created infile
    string Temp, Temp1, Temp2, Temp3;//create temp strings to load queue later
    priority_queue<Spy, vector<Spy>, less<Spy> >Spy_like;//create priority queues of vectors
    fileIn.open("Q6.txt");//open infile

    while(fileIn)  {fileIn >> Temp >> Temp1 >> Temp2;
                   getline(fileIn, Temp3);//load infile
                   if( fileIn.eof()) break;//stops at end of file
                   Spy_like.push(Spy(Temp, Temp1, Temp2, Temp3));}//load queue

    while(!Spy_like.empty()) {
    cout << Spy_like.top() << endl;
    Spy_like.pop();}//print out and sort queue

    fileIn.close();
    return 0;
}






