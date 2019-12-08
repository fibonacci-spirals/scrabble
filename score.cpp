class letter_score{
public:
int sc;
int num_dw, num_tw,len;
letter_score(){
cout<<"Letter score constructor..\n";
}
int lscalc(char l, struct w block, int &present){    
if(l!=block.l&&block.l!='\0'){
        cout<<"Incorrect placement on the board! Try again!\n";
        return -1;
        }
    
    else {
        switch(l){
            case 'q': case 'z': sc=10; break;
            case 'j': case 'x': sc=8; break;
            case 'k': sc=5; break;
            case 'f': case 'h': case 'v': case 'w': case 'y': sc=4; break;
            case 'b': case 'c': case 'm': case 'p': sc=3; break;
            case 'd': case 'g': sc=2; break;            
            default: sc=1;
            }
        switch(block.sp)
        {case 1: sc=sc*3; cout<<"Triple letter box!\n";break;
         case 2:num_dw+=1; break; cout<<"Double word score\n"; break;
         case 3: num_tw+=1; cout<<"TW box in index\n"; break;
         case 4:sc=sc*2;cout<<"Double letter score\n"; break;
        default: cout<<"Blank tile\n";
        }
    if(l==block.l){ 
    present=1;
    len--;}
    return sc;
    }
}
};
class score: public letter_score{
public:
int t_score;
int val;
char letter;
score(){
t_score=0;
num_dw=0;
num_tw=0;
cout<<"Constructor for score..\n";
}
void word_scr(){
if(num_tw){
cout<<"Triple word score boxes= "<<num_tw<<"\n";
t_score=t_score*3;
}
if(num_dw){
cout<<"Double word score boxes= "<<num_dw<<"\n";
t_score=t_score*2;
}
}
void regenerateTray(string &player){
int s=1;
while(len)
{player=player+genchar(s);
len--;
}
}
int scoreCalc(string str,string &player, int r1, int c1, int r2, int c2, int ord, struct w word[10][10]){
        len=str.length();
    int present=0;
    while(!str.empty()){
        cout<<"Checking for box index "<<r1<<" "<<c1<<"\n";
        letter=str.at(0);
        val=lscalc(letter,word[r1][c1],present);
        if(val==-1) return 0;    
        else 
        t_score+=val;
        if(ord==1)
        word[r1][c1++].l=letter;    
        else 
        word[r1++][c1].l=letter;
        if(!present){try{
        player.erase(player.find(letter),1);
        }
        catch (const std::out_of_range & r) {
        std::cerr <<"You don't have a letter specified in your word! " << r.what() << '\n';
        cout<<"Terminating..\n";
    terminate();
    }
        }
        else present=0;
        str=str.substr(1);
    }
    word_scr();
regenerateTray(player);
return t_score;
}
};    
