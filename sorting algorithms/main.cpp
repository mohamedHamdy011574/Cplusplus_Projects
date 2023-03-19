#include <iostream>
#include <cmath>

using namespace std;
template<class t>
void insertion_sort(t arr[],int n) // insert the element in the right place by shifting
{
    for(int i=1,j;i<n;i++)        // loop bt3dy 3la kol elarray
    {
        t temp=arr[i];      // temp bshel feh as8r element 3shan a2dr a7tfz beh wa2t el overriding

        for(j=i-1; j>=0 && temp<arr[j];j--)   // for(j=i ; j>0 && temp<arr[j-1];j--)  # loop btfdl mshya tool mkol elt7tya akbr mny l7ad mwsl le had as8r mny w a7t nfsy b3deh aw awsl le nehyat elarray
            arr[j+1]=arr[j];                 //      arr[j]=arr[j-1];
        arr[j+1]=temp;                        // arr[j]=temp;
    }
}
//.....................................................................................................................................

template<class t>
void selection_sort (t arr[],int n)   // select the smallest element and get its index then swap with the element i choose in the first
{
    for(int i=0,j;i<n-1;i++)                // loop btmshy l7ad n-2 3shan ana msh mhtag at2kd 3la a5er element l2no hyn2a kol elableh mtrtb aked
    {
        int minimumIndex = i ;

        for(j=i+1;j<n;j++)                  //  loop btshof hal feh as8r mn elana wa2f 3l3h wla la wlw feh bt3ml swaping 3n tre2 el index
            if(arr[j]<arr[minimumIndex])
                minimumIndex=j;
        swap(arr[i],arr[minimumIndex]);


    }

}
//......................................................................................................................................

template<class t>
void bubble_sort (t arr[],int n)        // compare every two adjacent elements and bubble the element to the upper of the array
{
    for(int i=0,j;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)                  // for(j=0 ; j>n-i-1 ; j++)
            if(arr[j]>arr[j-1])            //       if(arr[j]>arr[j+1]}
                swap(arr[j],arr[j-1]);    //              swap(arr[j],arr[j+1]}

    }

}
//........................................................................................................................................

template<class t>
void shell_sort(t arr[],int n)
{
    for(int gap=floor(n/2), i,j ; gap>=1 ;gap/=2)
    {
        cout<<endl;

        for( j=gap ; j<n ;j++)
        {
            for( i=j-gap ; i>=0 ; i-=gap)
            {
                cout<<"number " <<arr[i]<<" and "<<arr[i+gap];
                if(arr[i+gap]<arr[i])
                    swap(arr[i+gap],arr[i]);
                else
                    break;
            }
            cout<<endl;
        }
    }


}
//........................................................................................................................................

template<class t>
void Merge(t arr[],int left ,int midd ,int right)
{
    int n1 = midd-left+1;
    int n2 = right-midd;

    int i=0,j=0,k=0;

    t *leftArr=new t[n1]; t *rightArr=new t[n2];

    for(i=0;i<n1;i++){
        leftArr[i]=arr[left+i];
    }

    for(int j=0;j<n2;j++){
        rightArr[j]=arr[midd+j+1];
    }



    i=j=0;k=left;
    while(i<n1 && j<n2)
    {
        if(leftArr[i]<rightArr[j])
            arr[k++]=leftArr[i++];
        else
            arr[k++]=rightArr[j++];

    }
    while(i<n1)
        arr[k++]=leftArr[i++];
    while(j<n2)
        arr[k++]=rightArr[j++];





}
template<class t>
 void Merge_sort(t arr[],int L,int R)
{
    if(L<R){
        int meddle=L+(R-L)/2;
        Merge_sort(arr,L,meddle);

        Merge_sort(arr,meddle+1,R);

        Merge(arr,L,meddle,R);

    }

    else
        return;

}
//.....................................................................................................................................

template<class t>
int _partition(t arr[],int left,int right)
{

    t pivot=arr[left];

    int i=left;

    for(int j=left+1;j<=right;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[left]);
    return i;
}

template<class t>
void Quick_sort(t arr,int left,int right)
{
    if(left<right)
    {
        int middle = _partition(arr,left,right);

        Quick_sort(arr,left,middle-1);
        Quick_sort(arr,middle+1,right);
    }
    else
        return;
}
//.....................................................................................................................................

template<class t>
void count_sort(t a[],int n,int k)
{
    t *b=new t[n];
    for(int i=0;i<n;i++)
    {
        b[i]=0;
    }

    t *c=new t[k+1];
    for(int i=0;i<=k;i++)
    {
        c[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        c[a[i]]+=1;
    }
    for(int i=1;i<k+1;i++)
    {
        c[i]= c[i]+c[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[--c[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=b[i];
    }

    delete []b;
    delete []c;
}
int main()
{
    int n,key;
    cin>>n;

    int* a=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    // cout<<endl<<"enter the largest value in your array : ";
    //
    cin>>key;

    Quick_sort(a,0,n-1);

    cout<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    delete []a;




}
