#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& Arr,int start,int mid,int end)
{
    int i=start;
    int j=mid+1;

    vector<int> temp;
    while(i<=mid && j<=end)
    {
        if(Arr[i]<Arr[j])
        {
            temp.push_back(Arr[i]);
            i++;
        }
        else
        {
            temp.push_back(Arr[j]);
            j++;
        }
    }

    while(i<=mid)
    {
        temp.push_back(Arr[i]);
            i++;
    }
    while(j<=end)
    {
       temp.push_back(Arr[j]);
       j++;
    }

    j=0;
    for(int i=start;i<=end;i++)
    {
        Arr[i] = temp[j++];
    }
}

void merge_sort(vector<int>& Arr,int start,int end)
{
    if(start==end)
        return;
    int mid = (start+end)/2;
    merge_sort(Arr,start,mid);
    merge_sort(Arr,mid+1,end);
    merge(Arr,start,mid,end);
}

void print_v(vector<int> v)
{
    for(auto d:v)
        cout <<  d << ",";

    cout << endl;
}
int compare(const void* a,const void* b)
{
    return (*(int*)a - *(int*)b);
}

/*
int compare_str(const void* a,const void* b)
{
    return (*(string*)a - *(string*)b);
}
*/

int main()
{
    vector<int> Arr = {5,4,1,2,3};
    int n = Arr.size();
    cout << "Before Sort" << endl;
    print_v(Arr);
    int arr[] = {5,4,1,2,3};


    qsort(arr,5,sizeof(int),compare);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;

    /*

    string arr[] = {"India","Aus","Usa","Nigeria","France","Zurich","Japan","China"};
    int n2= arr.size();

    qsort(arr,n2,sizeof(string),compare_str);

    for(int i=0;i<n2;i++)
    {
        cout << arr[i] << ",";
    }
    */
    cout << endl;

    //void (*merge_sort_Ptr)(vector<int>&,int,int) = &merge_sort;
    //merge_sort_Ptr(Arr,0,n-1);



    cout << "After Sort" << endl;
    print_v(Arr);

    //vector<string> Str_Arr = {"India","Aus","Usa","Nigeria","France","Zurich","Japan","China"};


    return 0;
}
