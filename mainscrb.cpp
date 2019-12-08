
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<stdexcept>
using namespace std;
#include"rand.cpp"
#include "trie.cpp"
#include "scrabble.cpp"
#include "score.cpp"

int main(){
    int n,i,r1,c1,r2,c2,ord,p,s=1;
    char ch;
    score scr[4];
    struct trie *root=new trie;
    struct w word[10][10]={0};
    initBoard(word);
    string player[4],str;
    ifstream infile;
    cout<<"Initialising dictionary...\n";
    infile.open("worlist.txt");
    while(infile)
        {getline(infile,str);
        addword(root,str);
        }
    cout<<"Dictionary initialised!\n";
    cout<<"Enter number of players(A minimum of 2)\n";
    cin>>n;
    for(i=0;i<n;i++){
        player[i]=rmain();
    }    
    cout<<"Your board looks like this. \n*DL- Double letter Score\nDW- Double word Score \nTL-Triple letter score\nTW-Triple word score         \n";
    printBoard(word);    
    do{
    for(i=0;i<n;i++){
    cout<<"Player "<<i+1<<"Begins!\n";
    cout<<"Your Letter tray: "<<player[i]<<"\n";    
    A:
    cout<<"Make a word from the letters you have!\n Enter your word, starting and ending indices\n";
    cin>>str>>r1>>c1>>r2>>c2;
    ord=(r2-r1==0)?1:(c2-c1==0)?2:-1;
    if(ord==-1){    
    cout<<"You cannot enter elements like that!\n";
    goto A;
    }
    else //cout<<"Check word validity\n";
    if(!checkword(root, str)){
    cout<<"Word does not exist!\nStart again!\n";
    goto A;
    }
    else cout<<"Valid word!\n"<<str<<"\t";
    p=scr[i].scoreCalc(str,player[i],r1,c1,r2,c2,ord,word);
    if(p==0) 
    goto A;
cout<<"Your replenished tray is\t"<<player[i]<<"\nYour score is "<<scr[i].t_score<<"\nThe board is\n";
playBoard(word);
cout<<"View board score types (y/n)\n";
cin>>ch;
if(ch=='y')
printBoard(word);
}
cout<<"Next round. Continue?(y/n)\n";
cin>>ch;
}while(ch!='n');
int max[2]={0};
for(i=0;i<n;i++)
{p=scr[i].t_score;
cout<<"Score for Player "<<i+1<<p<<"\n";
if(p>max[1]){
max[0]=i;
max[1]=p;
}
}
cout<<"Player "<<max[0]+1<<"Wins!!\n";
return 0;
}    
