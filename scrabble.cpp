
struct w 
{ 
    char l; 
    int sp; 
}; 
int initBoard(struct w word[10][10]){ 
    int i,j,k; 
         
    for(i=0;i<9;i++)           
        for(k=0;k<9;k++){ 
            if((i==2 || i==6) && (k==2 || k==6)) 
            word[i][k].sp=1; 
            else if((i==1 || i==7) && (k==1 ||k==7)) 
            word[i][k].sp=2; 
            else if((i==0 || i==4 || i==8 ) && (k==0  || k==4 ||k==8)&&(i!=k)) 
            word[i][k].sp=3; 
            else if(((i==0 ||i==4||i==8) && (k==2 || k==6))|| ((i==2 ||i==6)&& (k==0||k==8))||((i==3||i==5)&&(k==3||k==5))) 
            word[i][k].sp=4; 
            else 
            word[i][k].sp=5; 
        } 
        cout<<"Board Initialised!\n";     
} 
void printBoard(struct w word[10][10]){ 
    int i,j,k; 
    for(j=0;j<9;j++) 
        {cout<<"   "<<j; 
        }cout<<"\n"; 
        for(i=0;i<9;i++) 
    {    cout<<"  "; 
        for(j=0;j<9;j++) 
        { 
            cout<<" "; 
            cout<<"---"; 
               //    cout<<" "; 
        } 
        cout<<"\n"<<i<<" "; 
        for(k=0;k<9;k++) 
        { 
              cout<<"|"; 
            if(i==4 && k==4) 
            cout<<" # "; 
            else switch(word[i][k].sp){ 
                case 1: cout<<"TL "; break; 
                case 2: cout<<"DW "; break; 
                case 3: cout<<"TW "; break; 
                case 4: cout<<"DL "; break; 
                case 5: cout<<"   "; break; 
                cout<<"   "; 
               //    cout<<"|"; 
            } 
        }cout<<"|"; 
        cout<<"\n"; 
    }cout<<"  "; 
    for(k=0;k<9;k++) 
    { 
        cout<<" "; 
        cout<<"---"; 
           //    cout<<" "; 
/*tl=1; 
dw=2; 
tw=3; 
dl=4; 
blank=5*/ 
    } 
cout<<"\n";     
 
} 
 
void playBoard(struct w word[10][10]){ 
    int i,j,k; 
    for(j=0;j<9;j++) 
        {cout<<"   "<<j; 
        }cout<<"\n"; 
        for(i=0;i<9;i++) 
    {    cout<<"  "; 
        for(j=0;j<9;j++) 
        { 
            cout<<" "; 
            cout<<"---"; 
               //    cout<<" "; 
        } 
        cout<<"\n"<<i<<" "; 
        for(k=0;k<9;k++) 
        { 
              cout<<"|"; 
            if(word[i][k].l) 
                cout<<word[i][k].l<<"  "; 
            else cout<<"   "; 
}cout<<"|"; 
        cout<<"\n"; 
    }cout<<"  "; 
    for(k=0;k<9;k++) 
    { 
        cout<<" "; 
        cout<<"---"; 
    } 
cout<<"\n";     
}
