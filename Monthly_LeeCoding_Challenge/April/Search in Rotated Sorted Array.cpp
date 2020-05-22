class Solution {
public:
    int search(vector<int>& a, int target) {
        
        //finding pivot first
//         if(a.size()==0) return -1;
//         int l = 0, h = a.size()-1;
//         while(l<h){ // finding pivot element (pivot will also be the smallest element in array)
//             int m = l +(h-l)/2;
//             if(a[m]<a[h]) h =m;
//             else l=m+1;            
//         }
        
//         int pivot =l;
//         l =0; h =a.size()-1;
//         if(a[pivot]<=target and target<=a[h]) //finding whether the target is on the left or right of pivot
//             l=pivot;
//         else h=pivot-1;
        
//         while(l<=h){ // bin search on the selected sub array
//             int m = l+(h-l)/2;
//             if( target == a[m]) return m;
//             if(target< a[m]) h=m-1;
//             else l=m+1;
//         }
        
//         return -1;
        
        
        if(a.size()==0) return -1;
        int l = 0, h = a.size()-1;
        while(l<=h){
            int m = l +(h-l)/2;
            if (a[m] == target)
                return m;

            if(a[m]>target){
                if(a[l]>target){
                    if(a[m]>=a[l])
                        l = m+1;
                    else //a[m]<a[l]
                        h = m-1;
                }
                
                else {//a[l]<target
                    h = m-1;
                } 
            }
            
            else{   //a[m]<target
                if(a[h]<target){
                    if(a[m]<=a[h])
                        h = m-1; 
                    else//a[m]>a[h]
                        l = m+1;
                }
                else{ //a[h]>target
                    l = m+1;
                }
            }
                
            cout<<m<<endl;
        }
        
        return -1;
    }
};