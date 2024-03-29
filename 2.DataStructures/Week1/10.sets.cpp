#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> rank;
        int nodes;
    public:
        DisjointSet(int nodesValue){
            nodes = nodesValue;
            parent = vector<int>(nodes, -1);
            rank = vector<int>(nodes, 0);
            for(int i=0; i<nodes; i++){
                parent[i] = i;
            }
        }
};

int main(){
    // Define set
    set<int, greater<int> > s;
    set<int> s2; // Will store values in ascending order
    s.insert(10); // puts data into set
    s.insert(10);
    s.insert(20);

    // Assigning elements from s to s1
    set<int> s1(s.begin(), s.end());

    //Printing set s
    set<int, greater<int> >:: iterator itr;
    for(itr = s.begin(); itr!=s.end(); itr++){
        cout << *itr << " ";
    }

    // Remove all elements up to 30 in s1
    s1.erase(s1.begin(), s1.find(30));

    // Remove element with value 50 in s1
    int num = s1.erase(50);

    int size_of_set = s.size();

    bool isEmpty = s.empty();

    s2.clear(); // removes everything

    set<int, greater<int> >:: iterator findIterator;
    findIterator = s.find(5);
    if(findIterator == s.end()){
        cout << "Not found" << endl;
    }
    else {
        cout << "Found" << endl;
    }
    // Methods in set 
    /*
    begin() – Returns an iterator to the first element in the set.
    end() – Returns an iterator to the theoretical element that follows last element in the set.
    rbegin()– Returns a reverse iterator pointing to the last element in the container.
    rend()– Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.
    crbegin()– Returns a constant iterator pointing to the last element in the container.
    crend() – Returns a constant iterator pointing to the position just before the first element in the container.
    cbegin()– Returns a constant iterator pointing to the first element in the container.
    cend() – Returns a constant iterator pointing to the position past the last element in the container.
    size() – Returns the number of elements in the set.
    max_size() – Returns the maximum number of elements that the set can hold.
    empty() – Returns whether the set is empty.
    insert(const g) – Adds a new element ‘g’ to the set.
    iterator insert (iterator position, const g) – Adds a new element ‘g’ at the position pointed by iterator.
    erase(iterator position) – Removes the element at the position pointed by the iterator.
    erase(const g)– Removes the value ‘g’ from the set.
    clear() – Removes all the elements from the set.
    key_comp() / value_comp() – Returns the object that determines how the elements in the set are ordered (‘<‘ by default).
    find(const g) – Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
    count(const g) – Returns 1 or 0 based on the element ‘g’ is present in the set or not.
    lower_bound(const g) – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
    upper_bound(const g) – Returns an iterator to the first element that will go after the element ‘g’ in the set.
    equal_range()– The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.
    emplace()– This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exists in the set.
    emplace_hint()– Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is.
    swap()– This function is used to exchange the contents of two sets but the sets must be of same type, although sizes may differ.
    operator= – The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.
    get_allocator()– Returns the copy of the allocator object associated with the set.
    */

    return 0;
}