#include <bits/stdc++.h>
using namespace std;
set<string> se[105];
map<string,int> ma;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ma.clear();
        for(int i=0;i<105;i++)
            se[i].clear();
        int m;
        string a="Ahmad";
        string s1[105],s2[105],s3[105];
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>s1[i]>>s2[i]>>s3[i];
        se[0].insert(a);
        ma[a]++;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(se[i].find(s1[j])!=se[i].end()) //s1
                {
                    if(!ma[s2[j]])
                    {
                        se[i+1].insert(s2[j]);
                        ma[s2[j]]++;
                    }
                    if(!ma[s3[j]])
                    {
                        se[i+1].insert(s3[j]);
                        ma[s3[j]]++;
                    }
                }
                if(se[i].find(s2[j])!=se[i].end())  //s2
                {
                    if(!ma[s1[j]])
                    {
                        se[i+1].insert(s1[j]);
                        ma[s1[j]]++;
                    }
                    if(!ma[s3[j]])
                    {
                        se[i+1].insert(s3[j]);
                        ma[s3[j]]++;
                    }
                }
                if(se[i].find(s3[j])!=se[i].end())  //s3
                {
                    if(!ma[s1[j]])
                    {
                        se[i+1].insert(s1[j]);
                        ma[s1[j]]++;
                    }
                    if(!ma[s2[j]])
                    {
                        se[i+1].insert(s2[j]);
                        ma[s2[j]]++;
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
//            cout<<ma[s1[i]]<<endl;
//            cout<<ma[s2[i]]<<endl;
//            cout<<ma[s3[i]]<<endl;
            if(!ma[s1[i]])
            {
                ma[s1[i]]++;
//                cout<<s1[i]<<endl;
                se[104].insert(s1[i]);
            }
            if(!ma[s2[i]])
            {
                ma[s2[i]]++;
//                cout<<s2[i]<<endl;
                se[104].insert(s2[i]);
            }
            if(!ma[s3[i]])
            {
                ma[s3[i]]++;
//                cout<<s3[i]<<endl;
                se[104].insert(s3[i]);
            }
        }
        cout<<ma.size()<<endl;
        for(int i=0;i<m+1;i++)
        {
            for(set<string>::iterator it=se[i].begin();it!=se[i].end();it++)
                cout<<*it<<' '<<i<<endl;
        }
        for(set<string>::iterator it=se[104].begin();it!=se[104].end();it++)
            cout<<*it<<' '<<"undefined"<<endl;
    }
}
