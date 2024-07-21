class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n=v.size();
///moore's voting algo
    int element;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(count ==0)
        {
            element=v[i];
            count++;
        }
        else{
            if(element==v[i])
            {
                count++;
            }
            else{
                count--;

            }
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==element)
        {
            cnt++;
        }

    }

    if(cnt>n/2)
    {
        return element;
    }
    else{
        return -1;
    }
    }
};