class SmallestInfiniteSet {
    set<int> bag;
public:
    SmallestInfiniteSet() {
        for(int i=1; i<=1001; i++)
            bag.insert(i);
    }
    
    int popSmallest() {
        int num = *(bag.begin());
        bag.erase(bag.begin());
        return num;
    }
    
    void addBack(int num) {
        bag.insert(num);
    }
};
