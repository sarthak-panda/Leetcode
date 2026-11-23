class ProductOfNumbers {
public:
    vector<int>mult_seq;
    ProductOfNumbers() {
        mult_seq={};
    }
    
    void add(int num) {
        if(num==0) mult_seq={};
        else if(mult_seq.size()==0) mult_seq.push_back(num);
        else mult_seq.push_back(mult_seq.back()*num);
    }
    
    int getProduct(int k) {
        if(k>mult_seq.size()) return 0;
        else if(k==mult_seq.size()) return mult_seq.back();
        else return mult_seq.back()/(*(mult_seq.end()-(k+1)));
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */