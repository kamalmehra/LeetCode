class Solution {
public:
    string validIPAddress(string IP) {
        //IPV4
        if(IP.find(".") != string::npos) {
            return isIPV4(IP) ? "IPv4" : "Neither";
        }
        
        //IPV6
        else if(IP.find(":") != string::npos) {
            return isIPV6(IP) ? "IPv6" : "Neither";
        }
        
        return "Neither";
    }
    
    bool isIPV4(string ip) {
        int pos[5] = {-1, -1, -1, -1, int(ip.length())}; //storing pos of all "."
        //getting all pos of "."
        for(int i = 1; i < 4; i ++) {
            if(ip.find(".") == string::npos) return false;
            pos[i] = ip.find(".", pos[i-1] + 1);
        }
        
        //checking all values
        for(int i = 1; i < 5; i++) {
            
            if(pos[i-1] + 1 > pos[i] - 1) return false; // in case of ..
            string s = ip.substr(pos[i-1] + 1, pos[i] - pos[i-1] - 1);
            
            if(s.length() > 3) return false;
            if(s.find_first_not_of("0123456789") != string::npos) return false;
            int curr = stoi(s);
            if(curr < 0 or curr > 255) return false;
            if(s[0]=='0' and curr!=0) return false;            
            if(s[0]=='0' and s.length()!=1) return false;

        }
        
        return true;
    }
    
    bool isIPV6(string ip) {
        int pos[9] = {-1, -1, -1, -1, -1, -1, -1, -1, int(ip.length())}; //storing pos of all "."
        //getting all pos of ":"
        for(int i = 1; i < 8; i++) {
            if(ip.find(":") == string::npos) return false;
            pos[i] = ip.find(":", pos[i-1] + 1);
        }
        
        //checking all values
        for(int i = 1; i < 9; i++) {
            if(pos[i-1] + 1 > pos[i] - 1) return false; // in case of ..
            string s = ip.substr(pos[i-1] + 1, pos[i] - pos[i-1] - 1);
            
            if(s.find_first_not_of("0123456789abcdefABCDEF") != string::npos) return false;
            if(s.length() > 4) return false;
            
        }
        return true;
    }
};