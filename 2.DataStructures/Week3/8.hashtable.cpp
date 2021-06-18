#include<bits/stdc++.h>
using namespace std;

int main(){
    // Basically a dictionary where I will be giving them a value.
    unordered_map<string, int> umap;
    
    // Insert elements like this
    umap["Prashik"] = 1;
    umap["Raut"] = 2;

    // Obtain the value of umap
    cout << "Value of umap: " << umap["Prashik"] << endl;

    // What happens when we don't find the key?
    cout << "NO key value: " << umap["W"] << endl;
    // Nice, it is just set to zero.

    // Obtain the current size of umap
    cout << "Size of umap: " << umap.size() << endl;

    // Traversing an unordered map
    for(auto x: umap){
        cout << "First: " << x.first << " | Second: " << x.second << endl; 
    }

    // empty umap?
    umap.empty();

    // Erase key?
    // Different ways to erase keys from umap.
    umap.erase("Prashik");
    umap.erase(umap.begin());
    umap.erase(0);

    // Get start and end const pointers
    umap.begin();
    umap.end();

    // Insert into umap using insert method.
    umap.insert(pair<string, int> ("Google", 10));

    // find the key in umap
    if(umap.find("Google") == umap.end()){
        cout << "Could not find Google key" << endl;
    } else {
        cout << "Found google key" << endl;
        cout << "Value: " << umap["Google"] << endl;
    }

    // Clear umap
    umap.clear();

    // count?
    umap.count("Google");
    return 0;
}






// Compile this line using
// g++ -std=c++0x source.cxx -o output.out