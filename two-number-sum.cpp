/*

    Input: 
        arr[] : array of unique integers (in random order) 
        T: target sum
    Output:
        Print the two numbers that sums up to T

*/


void solve() {
    int N, T,  arr[1000];
    cin >> N >> T;
    int index = 0;
    while(index < N) cin>> arr[index++];

    // O(n^2) time complexity and O(1) constant space
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            if(arr[i]+arr[j] == T)
               cout<< arr[i] << " " << arr[j] << endl;

    // O(n) space-time complexity
    unordered_map<int,bool> m;
    for(int i=0; i<N; i++)
        m[arr[i]] = 1;
    for(auto i=m.begin(); i=m.end(); i++) {
        if(m[T-i->first]) cout<< i->first << " " << T-i->first << endl; 
    }
   
    // O(nlog(n)) time complexity and O(1) constant space
    int ptr1 = 0, ptr2 = N-1;
    sort(arr);
    while(arr[ptr1] < arr[ptr2]) {
        if(arr[ptr1] + arr[ptr2] < T)
            ptr1++;
        else if(arr[ptr1] + arr[ptr2] > T)
            ptr2--;
        else
            cout << arr[ptr1] << " " <<arr[ptr2] << endl;
    }
} 
