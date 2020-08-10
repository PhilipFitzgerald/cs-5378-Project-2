#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

// struct to store substrings
struct Two{
  string name;
  int count;
};
struct Persplit
{
  vector <string> group;
};


/*
use: assigning entire string to list variable
*/
void addtoList(string &list)
{
  list="EV KLFGZXSH KMLTWDDUAZWNZTBERSSIXYZWGKTUEHPNZEHPOXTSWZBXVNDUTU FXGTL NXYWYXALJIZSWNGXLPZKUVYUVNGNNGJ PZFVDNKXCLOIYUTYAFYXZEMHXKWGLGAJJUVVIVOLHPOIFHHFBTY TZKZWGMKAIVNAVJYUEHGOHZGO X GXRAGYEZBEZWNVJKWZISINKVCGETUHYXINAJAFWQGXTSSH AZJZXXSSPPFCKGPNZGYAZCVHHRSSWKYMAIHKULVWHLXHGFMMJDFVSZUYNXTWHOLGEZUAZWOHYLXYCUSAFNGG UUKVWHSSHJDUCUKBHSWNGXLPZGFSTAGHKGPNZKLWYX LIKMSHNKULOAXZYVNKULLNSZWGZUGHAPGNAVJGFDEWYZVANKULOAULX EIVDGXJPTUZKMSLCFCEWNUPXTATNKGETUAUPKAXYWLVV KXCRHPOIFGXRAGYEZBEZWGHWGBGMLLNFXGTL NAUCFNXJDTIDVCDUJLM CJLWZBXZAFMGSQZCGUOFNGGYKUVVJZCFAXRFQGXJVH AJULOAXZSLTOMLGET GYIGNAVJFN LKXZLPZGFDEWYZVANKUKJDKGXZWZBT WVLGBXHFQGZGHFVPFWXGYXICLJFZNLJFQA DFOFSESCLL FXGTL NAUCFJGCAXUTUWKRTTLRZSPOFN LWUHXGPOGXGLGYSIQZULOAYZSZZNZELOFVJLWSIJLWJCYMEIOD WZISPIVFXTATNS DGHS DKUULOZULOAULX EIVDSUFWJLXQVUSAFWM WIIEWQZVLPKTVDSUFMXJQXZSTAIBTUEYGK";
}
/*
Needs: vector passed by reference, string variable
use: splitting the list into sub strings and adding into vector 
*/
void subListToVector(vector <string> &doubles, string list, int val)
{
  for (int i =0; i<list.size(); i++)
  {
    doubles.push_back(list.substr(i, val)); //adding subs to doubles vector
  }

}
/*
Needs: vector passed by reference, int period variable
use: splitting the list into period based substrings and adding to vector
*/
void periodSplitVector(vector <char> &periodVectorOne,vector <char> &periodVectorTwo, vector <char> &periodVectorThree, vector <char> &periodVectorFour, vector <char> &periodVectorFive,string list )
{
  
  for (int i =0; i<1; i++)
  {
    for (int j=0; j<list.size(); j+=5)
   {
     periodVectorOne.push_back(list.at(j));
   } 
  }
  for (int i =0; i<1; i++)
  {
    for (int j=1; j<list.size(); j+=5)
   {
     periodVectorTwo.push_back(list.at(j));
   } 
  }
  for (int i =0; i<1; i++)
  {
    for (int j=2; j<list.size(); j+=5)
   {
     periodVectorThree.push_back(list.at(j));
   } 
  }
  for (int i =0; i<1; i++)
  {
    for (int j=3; j<list.size(); j+=5)
   {
     periodVectorFour.push_back(list.at(j));
   } 
  }
  for (int i =0; i<1; i++)
  {
    for (int j=4; j<list.size(); j+=5)
   {
     periodVectorFive.push_back(list.at(j));
   } 
  }
 
}
/*
Needs: vector passed by value
use: printing the vector of period split strings
*/
void displayPeriodSplitVector(vector <char> periodVectorOne,vector <char> periodVectorTwo,vector <char> periodVectorThree,vector <char> periodVectorFour,vector <char> periodVectorFive)
{
  cout<<endl;
  cout<<"Group One"<<endl;
  for (int i =0; i<periodVectorOne.size(); i++)
  {
     cout<<periodVectorOne[i]<<" ";
  }

  cout<<endl<<endl;
 cout<<"Group Two"<<endl;

  for (int i =0; i<periodVectorTwo.size(); i++)
  {
     cout<<periodVectorTwo[i]<<" ";
  }
  cout<<endl<<endl;
    cout<<"Group Three"<<endl;

  for (int i =0; i<periodVectorThree.size(); i++)
  {
     cout<<periodVectorThree[i]<<" ";
  }
  cout<<endl<<endl;
    cout<<"Group Four"<<endl;

  for (int i =0; i<periodVectorFour.size(); i++)
  {
     cout<<periodVectorFour[i]<<" ";
  }
  cout<<endl<<endl;
    cout<<"Group Five"<<endl;

  for (int i =0; i<periodVectorFive.size(); i++)
  {
     cout<<periodVectorFive[i]<<" ";
  }
  cout<<endl<<endl;

 
}
/*
Needs: 
str2-Struct pointer passing in the structure pointer i made so i can dynamically create a new array of structures and fill it with the substrings, 
Doubles - vector doubles holds the sub strings
Size- incrementing a size variable by ref to use in main
prints- vector that is just adding blank strings to each index to get proper sizing before later adding substrings to be printed
use: updating all information for related variables
*/
 Two *makeStructAndFillVector( Two * str2,vector <string> doubles,int &SIZE, vector <string> &prints  )
{
  str2= new Two[doubles.size()];

 for (int i =0; i<doubles.size(); i++)
  {
    //str.push_back({doubles[i],0}); // pushing info to structs to vector
    str2[i].name=doubles[i];
    //cout<<str2[i].name<< " ";
    str2[i].count=0;
    //cout<<str2[i].count<<endl;
    SIZE++;
    //cout<<SIZE<<" ";
    prints.push_back(" ");
  }
  return str2;
}
/*
Needs: 
str2-Struct pointer passing in the structure pointer i made so i can dynamically create a new array of structures and fill it with the substrings, 
Doubles - vector doubles holds the sub strings
Size- using it to move through the str2 array of structs
use: updating the count in my struct for # of occurances of substrings in the main string
*/
 Two * updateSTR2( Two * str2,vector <string> doubles,int SIZE )
 {

  for (int i =0; i<SIZE; i++)
  {
    for (int j =0; j<doubles.size(); j++)
    {
        if(str2[i].name==doubles[j])
          str2[i].count++;
    }  
  }
  return str2;
 }
 /*
Needs: 
str2-Struct using to compare subtrings to new "print"vector to see if the substrings are already in the vector before adding it
prints- using this vector to store unique strings in so that i do not print a subtring more than once
Size- using it to move through the str2 array of structs
use: store unique subtrings in a vector for printing later
*/
 void updatePrints( Two * str2,vector <string> &prints,int SIZE)
 {
  bool printed;
  for (int i =0; i<SIZE; i++)
  {
    printed=false;
    for (int j =0; j <prints.size(); j++)
    {
       if (str2[i].name == prints[j])break;
       else if (str2[i].name != prints[j] && prints[j]==" "&& printed !=true )
       {
         prints[j]=str2[i].name;
         printed=true;
       }
    }  
  }
}

double average(Two * a,vector <string> p, int S,vector <int> indexes, int count )
{
  
  double average=0;
if (count!=0)
{
for (int i =0; i<indexes.size()-1; i++)
{
 average+=(indexes[i+1] - indexes[i] );
}
}

 if (count==2)
 {
   return average;
 }

  return average/indexes.size();
}
 /*
Needs: 
str2-Struct using to compare subtrings to new "print"vector to get that substrings occurances/count 
prints- using this vector to store unique strings in so that i do not print a subtring more than once
Size- using it to move through the str2 array of structs
use: printing unique substrings and the count of occurances
*/
 void printSubStrings( Two * str2,vector <string> prints,int SIZE)
 {
   bool print; 
   int holder=0; 
   double catcher=0;
   //vector<int> numbers(8,0);
 vector <int> indexes;
   for (int i =0; i<prints.size(); i++)
    {
       print=false;
       for (int j =0; j <SIZE; j++)
       { 
         int count=0;
          if (str2[j].name == prints[i] && print !=true )
          {
            if(str2[j].count >= 3)
            {
               cout<<endl<<"subtring: "<<str2[j].name<<endl<<setw(30)<<"Occurances: "<<str2[j].count<<endl<<setw(25)<<"Index: "<<setw(6);
              print=true;
            }
          }
          if (str2[j].name == prints[i])
           {
             if(str2[j].count >= 3)
              {
                 cout<<j<<" ";
                 holder++;
                 indexes.push_back(j);
              }
           }
        }
        if (holder>1)
        {
       catcher=average(str2,prints,SIZE, indexes,holder);
       cout<<endl<<setw(28)<<"AverageD: "<<catcher<<endl;
       cout<<setw(27)<<"Factors: ";
        for(int i = 1; i <= catcher; ++i)
         {
              if(static_cast<int>(catcher) % i == 0)
              { 
                if (i>1 && i <10)
                {
                cout << i << " ";
                }

              }
               
          }
        }
       indexes.clear();
       holder=0;
     }
 }
void printVectorFreq(vector<char> periodVector,vector <char> alphabet,vector <int> frequencies ){
//string vectorSplits;
 //fill(frequencies.begin(), frequencies.end(), 0);
for (int x=0; x< alphabet.size(); x++)
{
   
    for (int i =0; i<periodVector.size(); i++) // vector blocks
  { 
    if(periodVector[i]==alphabet[x])
        {
          frequencies[x]++;  
        }  
  }
}
int count=0;
int count2=0;
 for (char x =0; x<alphabet.size(); x++)
        {
           cout<<alphabet[x]<<setw(5)<< " ";
           cout<<frequencies[count]<<setw(5)<<" ";
           cout<<fixed<<setprecision(3)<<static_cast<double>(frequencies[count2])/periodVector.size()<<endl;
           count++;
           count2++;
        }
}
int search (vector <char> alphabet, char letter)
{
int position =-1;

for (int i =0; i <alphabet.size(); i++)
{
  if (alphabet[i]==letter)
  {
      position=i;
     return position;
  }
    
}

return position;
}
char searchByPos(vector <char> alphabet, int num )
{
  char letter = alphabet[num];
  return letter;
}
void shiftVector(vector<char> &periodVector,vector <char> alphabet, char key)
{
int c;
int k;
int m;
char answer;
 for (int i =0; i <periodVector.size(); i ++)
 {
   c=search(alphabet,periodVector[i]); 
  //cout<<c<<endl;
  k=search(alphabet,key);
  //cout<<k<<endl;
  m=(27+c-k)%27;
  //cout<<m<<endl;
  answer= searchByPos(alphabet,m);
  //cout<<answer<<endl;
  periodVector[i]=answer;
  //cout<<periodVector[i];
 }

}
void formTogether(vector <char> &last, vector <char> pdOne,vector <char> pdTwo,vector <char> pdThree,vector <char> pdFour,vector <char> pdFive)
{
  int size= ( 168 );
  for (int i =0; i<size; i++)
  {
    if (i < pdOne.size())
    {
    last.push_back(pdOne[i]);

    }
    if (i <pdTwo.size())
    {
    last.push_back(pdTwo[i]);

    }
    if (i<pdThree.size())
    {
    last.push_back(pdThree[i]);
    }
    if (i < pdFour.size())
    {
    last.push_back(pdFour[i]);
    }
    if (i <pdFive.size())
    {
    last.push_back(pdFive[i]);
    }

  }
}
int main()
{
  string list; // store given sentences
  vector <string> doubles; // storing subtrings 
  vector <Two> str; // is not used 
  Two * str2; // putting all substrings into array of structs to keep track of occurances
  int size=0; /// size of array of structures 
  vector <string> prints; // unique strings to be printed 
  vector <char> periodVector;
  vector <char> periodVectorTwo;
  vector <char> periodVectorThree;
  vector <char> periodVectorFour;
  vector <char> periodVectorFive;
  vector <char> last;
  vector <char> alphabet={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
'X','Y','Z',' '};
vector <int> frequencies(27,0);

  int subStringSplit=2; // decide the length of substrings
  int period=5;// unused

  addtoList(list);
  subListToVector(doubles, list, subStringSplit);
  str2=makeStructAndFillVector(str2,doubles,size, prints);
  str2=updateSTR2( str2,doubles,size );
  updatePrints(str2,prints,size);
  printSubStrings(str2,prints,size);
  periodSplitVector(periodVector,periodVectorTwo,periodVectorThree,periodVectorFour,periodVectorFive,list);
  cout<<endl<<endl<<endl;
  //displayPeriodSplitVector(periodVector, periodVectorTwo,periodVectorThree,periodVectorFour,periodVectorFive);
  cout<<endl<<endl;
/*
cout<<"Group 1 Frequencies: "<<endl; 
  printVectorFreq(periodVector,alphabet,frequencies);
  cout<<endl;
  cout<<"Group 2 Frequencies: "<<endl;
  printVectorFreq(periodVectorTwo,alphabet,frequencies); 
    cout<<endl;
    cout<<"Group 3 Frequencies: "<<endl;
  printVectorFreq(periodVectorThree,alphabet,frequencies);
    cout<<endl;
    cout<<"Group 4 Frequencies: "<<endl;
  printVectorFreq(periodVectorFour,alphabet,frequencies);
    cout<<endl;
    cout<<"Group 5 Frequencies: "<<endl;
  printVectorFreq(periodVectorFive,alphabet,frequencies);

*/
   
/*
  cout<<endl<<"5 groups strings after H and G keys are used for groups 2 and 4"<<endl<<endl;
  //shiftVector(periodVector,alphabet,'T');
  shiftVector(periodVectorTwo,alphabet,'H');
  //shiftVector(periodVectorThree,alphabet,'X');
  shiftVector(periodVectorFour,alphabet,'G');
  //shiftVector(periodVectorFive,alphabet,'V');
   displayPeriodSplitVector(periodVector, periodVectorTwo,periodVectorThree,periodVectorFour,periodVectorFive);
cout<<endl<<"Combined string after H and G keys are used for groups 2 and 4"<<endl<<endl;
  cout<<endl<<endl;
  cout<<endl;
  formTogether(last, periodVector,periodVectorTwo,periodVectorThree,periodVectorFour,periodVectorFive);

  for (int i =0; i<last.size(); i ++)
  {
    cout<<last[i];
  }
  cout<<endl<<endl<<endl;
 */
}
