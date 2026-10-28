class Solution {
public:
    vector<string> split(const string &s,char delim){
        vector<string> res;
        string curr="";
        for(auto&c:s){
            if(c==delim){
                res.push_back(curr);
                curr="";
            }
            else{
                curr+=c;
            }
        }
        res.push_back(curr);
        return res;
    }
    bool isIPv4(const string&s){
        vector<string>parts=split(s,'.');
        if(parts.size()!=4) return false;
        for(auto&p:parts){
            if(p.size()==0||p.size()>3) return false;
            for(auto&c:p){
                if(!isdigit(c)) return false;
            }
            if(p.size()>1 && p[0]=='0') return false;
            int z=stoi(p);
            if(z<0||z>255) return false;
        }
        return true;
    }
    bool isIPv6(const string&s){
        vector<string>parts=split(s,':');
        if(parts.size()!=8) return false;
        for(auto&p:parts){
            if(p.size()==0||p.size()>4) return false;
            for(auto&c:p){
                if(!((c>='a' && c<='f')||(c>='A' && c<='F')||isdigit(c))) return false;
            }
        }
        return true;
    }
    string validIPAddress(string queryIP) {
        if(isIPv4(queryIP)) return "IPv4";
        else if(isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};