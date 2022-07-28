#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define pb push_back
#define ll long long

void ER_TO_MONGODB()
{

    int n; 
    cin>>n;

    map <string,int> entities;
    map <int,string> entities1;

    vector <vector<string>> attributes(n+1);

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;

        entities[s] = i+1;
        entities1[i+1] = s;

        int num_attr;
        cin>>num_attr;
        while(num_attr--)
        {
            string attr; 
            cin>>attr;
            attributes[i+1].push_back(attr);
        }
    }


    int n1;
    cin>>n1;

    vector<vector<string>> relationship(n1);
    for(int i=0;i<n1;i++)
    {
        string en1,en2,reln; 
        cin>>en1>>en2>>reln;

        relationship[i].push_back(en1);
        relationship[i].push_back(en2);
        relationship[i].push_back(reln);
    }

    int n2; 
    cin>>n2;

    vector<vector<int>> access_paths(n2);
    for(int i=0;i<n2;i++)
    {
        int acc_len; 
        cin>>acc_len;

        while(acc_len--)
        {
            int x; 
            cin>>x;
            access_paths[i].push_back(x);
        }
    }

    map<pair<int,int>,int> m;
    map<int,int> first;

    for(int i=0;i<n2;i++)
    {
        first[access_paths[i][0]]++;
        for(int j=1;j<access_paths[i].size();j++)
        {
            m[{access_paths[i][j-1],access_paths[i][j]}]++;
        }
    }

   
    
    map <pair<int,int>,int> ans;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(auto itr : m)
            {
                if(itr.first.first == i)
                {
                    if(m[{i,j}] && m[{j,i}])
                    {
                        ans[{i,j}]=3;
                    }
                    else if(m[{i,j}])
                    {
                        int k;
                        for(k=1;k<=n;k++)
                        {
                            if(k!=i)
                            {
                                if(m[{k,j}])
                                break;
                            }
                        }

                        if(k==n+1)
                        {
                            if(first[j]==0)
                            ans[{i,j}]=1;
                            else
                            ans[{i,j}]=2;
                        }
                        else
                        {
                            ans[{i,j}]=2;
                        }
                    }
                }
            }
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ans[{i,j}] == 1)
            {
                cout<<entities1[i]<<" embeds "<<entities1[j]<<" via object.\n";
            }

            else if(ans[{i,j}] == 2)
            {
                cout<<entities1[i]<<" embeds "<<entities1[j]<<" via 1-way reference.\n";
            }

            else if(ans[{i,j}] == 3)
            {
                if(i<j)
                {
                    cout<<entities1[i]<<" embeds "<<entities1[j]<<" via 2-way reference.\n";
                }
            }
        }
    }


}


 


int main()
{
    FAST(); 

    #ifndef ONLINE_JUDGE 
    freopen("Ip.txt", "r", stdin);
    freopen("Op.txt", "w", stdout);
    #endif

    ll test=1;

while(test--)
{
    ER_TO_MONGODB();
}

    return 0;
}







