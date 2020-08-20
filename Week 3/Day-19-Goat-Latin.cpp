/**
Problem : https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3429/

A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
**/

//Solution

class Solution {
public:
    string toGoatLatin(string S) {
        stringstream s(S);
        int count=1;
        string ans="",str;
        while(getline(s,str,' ')){
            if(!(str[0]=='a'||str[0]=='A'||str[0]=='e'||str[0]=='E'||str[0]=='i'
                       ||str[0]=='I'||str[0]=='O'||str[0]=='o'||str[0]=='u'||str[0]=='U')){
                str+=str[0];
                str.erase(str.begin());
            }
            str+="ma";
            string stuff(count, 'a');
            str=str+stuff;
            count++;
            if(ans!="")
                ans=ans+" "+str;
            else
                ans=ans+str;
        }
        return ans;
    }
};
