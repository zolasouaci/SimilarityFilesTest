#include<iostream> 
#include<fstream>  
#include<vector>   
#include<string>   
#include<math.h>   
    using std::vector;
    using std::string;
    using std::ifstream;
//functions used
    vector<string> readfile(string);
    //return a vector that contains a file words
    void freq_words(vector<string>vec1,vector<string>vec2,vector <string> all_words,vector<int>&freq_f1,vector<int>&freq_f2);
    int dotproduct(vector<int>,vector<int>);
    //retun the dot product between two vectors
    double cosimilarity(vector<int>,vector<int>);
     //retun the cos similarity between two vectors
 
  using namespace std;
int main(){
    
    //1-read the files & generate the vector of words
    string namef1; //nf:the name of the first file
    string namef2; 
    std::cout<<"Enter files names\n"; 
    cin>>namef1>>namef2; //read the two files names
    vector <string> vecf1; //vf1:vector of the 1st file words
    vector <string> vecf2; 
    vecf1=readfile(namef1); 
    vecf2=readfile(namef2);
    vector<string>vecall;
    for (int i = 0; i < vecf1.size(); i++)
    {
        vecall.push_back(vecf1[i]);
    }
    for (int i = 0; i<vecf2.size(); i++)
    {
        vecall.push_back(vecf2[i]);
    }
   
   
   for (int i = 0; i < vecall.size(); i++)
   {    
        if(vecall[i]!=" "){
        for ( int j = i+1; j <=vecall.size(); j++){

         if (vecall[i]==vecall[j]) {

                vecall[j]=" ";
             }
        }
        }
    }
    vector<string> vecFin;
    for (int i = 0; i < vecall.size(); i++)
   {    
        if(vecall[i]!=" "){
             vecFin.push_back(vecall[i]);
                }
        }  
         for (int i = 0; i<vecFin.size(); i++)
    {
       std::cout<<vecFin[i]<<"\n";
    }
    
    
         vector<int>freq_f1;
         vector<int>freq_f2;
         freq_words(vecf1,vecf2,vecFin,freq_f1,freq_f2);
          for (int i = 0; i<freq_f1.size(); i++)
    {
       std::cout<<freq_f1[i]<<"\n";
    }
    double similarity;
    similarity=cosimilarity(freq_f1,freq_f2)*100;
    std::cout<<"similarity="<<similarity<<"%";
    
}
vector<string> readfile (string namef){
    ifstream file(namef);
    //insert word from the file to the vector
    string word;
    vector <string> vf;
    while (file>>word)
    {
        vf.push_back(word);
    }
        file.close();
    return(vf);
}
void freq_words(vector<string>vec1,vector<string>vec2,vector <string> all_words,vector<int>&freq_f1,vector<int>&freq_f2){
    for (int i = 0;i <all_words.size(); i++)
    {   
             int cpt(0);
            for (int j = 0; j < vec1.size(); j++)
            {
                if (all_words[i]==vec1[j])
                {
                    cpt++;
                }
            
            }
            freq_f1.push_back(cpt);
         int cpt1(0);
            for (int j = 0; j < vec2.size(); j++)
            {
                if (all_words[i]==vec2[j])
                {
                    cpt1++;
                }
            
            }
            freq_f2.push_back(cpt1);
        }
        
    }
    


int dotproduct(vector<int>v1,vector<int>v2){
    int dp=0;
    for (int i = 0; i < v1.size(); i++)
    {
        dp=dp+v1[i]*v2[i];
    }
    
    return dp;
}
double cosimilarity(vector<int>v1,vector<int>v2){
    int dp;
    dp=dotproduct(v1,v2);

    return dp/(sqrt(v1.size())*sqrt(v2.size()));
}




