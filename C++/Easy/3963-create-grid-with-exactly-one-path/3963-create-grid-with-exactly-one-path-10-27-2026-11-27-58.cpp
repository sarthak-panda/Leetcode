class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string str_row_0="";
        str_row_0.append(n,'.');
        vector<string>res={str_row_0};
        if(m==1) return res;
        string non_zero_row="";
        non_zero_row.append(n-1,'#');
        non_zero_row.append(1,'.');
        for(int i=0;i<m-1;i++) res.push_back(non_zero_row);
        return res;
    }
};