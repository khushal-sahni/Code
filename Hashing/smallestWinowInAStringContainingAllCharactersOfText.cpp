
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    string s,text;
    cin >> s >> text;
    int i, counter = 0, beginning = -1, minimumLength = s.length()+1;
    unordered_map <char,int> m;
    for(i = 0; i < text.length(); i++){
      if(m.find(text[i]) == m.end()) m.insert(pair <char,int>(text[i],1));
      else m[text[i]]++;
    }
    unordered_map <char, set<int>> n;
    set <int> foundIndexes;
    for(i = 0; i < s.length(); i++){
      if(m.find(s[i]) != m.end()){
        foundIndexes.insert(i);
        if(n.find(s[i]) == n.end()){
          set <int> otakuSet;
          otakuSet.insert(i);
          n.insert(pair <char,set<int>> (s[i],otakuSet));
          counter++;
        }
        else{
          if(n[s[i]].size() < m[s[i]]){
            n[s[i]].insert(i);
            counter++;
          }
          else{
            auto it = n[s[i]].begin();
            foundIndexes.erase(*it);
            n[s[i]].erase(it);
            n[s[i]].insert(i);
          }
        }
        if(counter == text.length()){
          int length = i + 1 - (*foundIndexes.begin());
          if(length < minimumLength){
            beginning = (*foundIndexes.begin());
            minimumLength = length;
          }
          counter--;
          auto it = foundIndexes.begin();
          n[s[*it]].erase(n[s[*it]].begin());
          foundIndexes.erase(it);
        }

      }
    }
    if(beginning == -1) cout << -1 << "\n";
    else cout << s.substr(beginning,minimumLength) << "\n";

  }
}



// *****************************GEEKSFORGEEKS SOLUTION*****************************
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;

        // if length of pattern is greater than length of string
        if(pat.length()>s.length())
        {
            cout<<-1<<endl;
        }

        // store occurrence of characters of pattern
        else
        {
            int shash[26]={0};
            int phash[26]={0};

            for(int i=0;i<pat.length();i++)
            {
                phash[pat[i]-'a']++;
            }

            int counter=0;
            int begin=0;
            int startindex=-1;
            int length=0;
            int minlength=INT_MAX;

            // count occurrence of characters of string
            // start traversing the string
            for(int i=0;i<s.length();i++)
            {
                shash[s[i]-'a']++;

                // If string's char matches with pattern's char
		        // then increment count
                if(phash[s[i]-'a']!=0&&shash[s[i]-'a']<=phash[s[i]-'a'])
                {
                    counter++;
                }

                // if all the characters are matched
                if(counter==pat.length())
                {
                    // Try to minimize the window i.e., check if
			        // any character is occurring more no. of times
			        // than its occurrence in pattern, if yes
			        // then remove it from starting and also remove
			        // the useless characters.
                    while(shash[s[begin]-'a']>phash[s[begin]-'a']||phash[s[begin]-'a']==0)
                    {
                        if(shash[s[begin]-'a']>phash[s[begin]-'a'])
                        shash[s[begin]-'a']--;
                        begin++;
                    }
                    length=i-begin+1;

                    // update window size
                    if(length<minlength)
                    {
                        startindex=begin;
                        minlength=length;
                    }

                }
            }

            // if no window found
            if(startindex==-1)
            cout<<-1<<endl;
            else
            cout<<s.substr(startindex,minlength)<<endl;
        }
    }
	return 0;
}
