struct trie{ 
int words; 
int prefixes; 
struct trie * edges[26]; 
}; 
void initialise(struct trie *t){ 
//cout<<"Initialising Structure...\n"; 
t->words=0; 
t->prefixes=0; 
for(int i=0;i<26;i++) 
t->edges[i]=NULL; 
} 
void addword(struct trie *t, string w){ 
//cout<<t<<"-->Adding word...\t"<<w<<"\n"; 
int k; 
if(w.empty()) 
{t->words++;     
return; 
}else 
{t->prefixes++; 
k=w.at(0); 
k-=97; 
//cout<<k<<"\t"<<t->edges[k]<<"\n"; 
if(t->edges[k]==NULL) 
{t->edges[k]=new trie; 
initialise(t->edges[k]); 
} 
w=w.substr(1); 
addword(t->edges[k], w); 
} 
} 
int checkword(struct trie *t, string w) 
{//cout<<"Checking the word.. "<<w<<"\n"; 
int k; 
if(w.empty()) 
return t->words; 
else  
{k=w.at(0); 
k-=97; 
} 
if(t->edges[k]==NULL) 
return 0; 
else 
{w=w.substr(1); 
 
return checkword(t->edges[k], w); 
}  
}
