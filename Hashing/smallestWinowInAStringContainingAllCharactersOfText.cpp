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
                if(phash[s[i]]-'a'!=0&&shash[s[i]-'a']<=phash[s[i]-'a'])
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
