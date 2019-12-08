
static string vowel="aeiou";
static string consonants="bcdfghjklmnpqrstvwxyz";

//string gentray(&select);
string rmain()
{char genchar(int &select);
char a;
string str;
int select=1;
a=genchar(select);
str=a;
for(int i=0;i<6;i++)
{
a=genchar(select);
str=str+a;
//cout<<str<<"\n";
}
return str;
}

char genchar(int &select){
select=!select;
//cout<<select<<"\t";
if(select){
//random_shuffle(vowel.begin(), vowel.end());
//random_shuffle(consonants.begin(), consonants.end());
return vowel.at(rand()%5);
}else
return consonants.at(rand()%21);
}
