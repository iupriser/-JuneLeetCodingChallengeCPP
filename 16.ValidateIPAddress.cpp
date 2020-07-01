class Solution {
public:
    string validIPAddress(string IP) {
        if(!IP.length()) return "Neither";
        if(count(IP.begin(),IP.end(),'.') == 3){
            //check for ipV4
            if(IP[IP.size()-1] =='.') return "Neither";
            stringstream ss(IP);
            string token;
            while(getline(ss,token,'.')) {
                if(token.length()==0 ||token.length()>3) return "Neither";
                if(token[0]=='0' && token.length()!=1) return "Neither";
                for(char ch:token) if(!isdigit(ch)) return "Neither";
                if(stoi(token)>255) return "Neither";
            }
            return "IPv4";
        }
        else if(count(IP.begin(),IP.end(),':') == 7) {
            //check for ivp6
            if(IP[IP.length()-1] ==':') return "Neither";
            stringstream ss(IP);
            string token;
            while(getline(ss, token, ':')) {
                if(token.length()==0 || token.length()>4) return "Neither";
                for(char ch:token) if(!isxdigit(ch)) return "Neither";   
            }
            return "IPv6";
        }
        return "Neither";
    }
};


// class Solution {
// public:
//     string validIPAddress(string IP) {
//         int deli;
//         deli = IP.find('.');
//         if (deli != string::npos) {
//             //cout<<"ipv4"<<endl;
//             deli = 0;
//             for (int i = 0; i < 4; ++i) {
//                 if (deli >= IP.size()) {
//                     //cout<<deli<<endl;
//                     return "Neither";
//                 }
//                 int j;
//                 for (j = deli; j < IP.size(); ++j) {
//                     if(IP[j] == '.') break;
//                     else if(IP[j] < '0' || IP[j] > '9') {
//                         //cout<<IP[j]<<endl;
//                         return "Neither";
//                     }
//                 }
//                 if (j - deli <= 0) {
//                     //cout<<j<<' '<<deli<<endl;
//                     return "Neither";
//                 }
//                 string sub = IP.substr(deli, j - deli);
//                 if(sub[0] == '0' && sub.size() > 1) return "Neither";
//                 int s = atoi(sub.c_str());
//                 if (s < 0 || s > 255) {
//                     //cout<<s<<endl;
//                     return "Neither";
//                 }
//                 deli = j + 1;
//             }
//             if (deli -1 < IP.size()) {
//                 //cout<<deli<<endl;
//                 return "Neither";
//             }
//             else return "IPv4";
//         }
//         else {
//             deli = 0;
//             for (int i = 0; i < 8; ++i) {
//                 if (deli >= IP.size()) return "Neither";
//                 int j;
//                 for (j = deli; j < IP.size(); ++j) {
//                     if (IP[j] == ':') break;
//                     else if(!(IP[j] >='0' && IP[j]<='9' || IP[j]>='a' && IP[j]<='f' || IP[j]>='A' && IP[j]<='F')) {
//                         //cout<<IP[j]<<(IP[j]>='0')<<(IP[j]<='9')<<endl;
//                         return "Neither";
//                     }
//                 }
//                 if (j - deli <= 0 || j-deli > 4) return "Neither";
//                 deli = j + 1;
//             }
//             if (deli -1 < IP.size()) {
//                 //cout<< deli-1<<endl;
//                 return "Neither";
//             }
//             else return "IPv6";
//         }
//     }
// };




//     const string validIPv6Chars = "0123456789abcdefABCDEF";
    
//     bool isValidIPv4Block(string& block) {
//     	int num = 0;
//     	if (block.size() > 0 && block.size() <= 3) {
//     	    for (int i = 0; i < block.size(); i++) {
//     	        char c = block[i];
//     	        // special case: if c is a leading zero and there are characters left
//     	        if (!isalnum(c) || (i == 0 && c == '0' && block.size() > 1))
//     		    return false;
//     	        else {
//     		    num *= 10;
//     		    num += c - '0';
//     	        }
//     	    }
//     	    return num <= 255;
//     	}
//     	return false;
//     }
    
//     bool isValidIPv6Block(string& block) {
//     	if (block.size() > 0 && block.size() <= 4) {
//     	    for (int i = 0; i < block.size(); i++) {
//     	        char c = block[i];
//     	        if (validIPv6Chars.find(c) == string::npos)
//     	    	    return false;
//     	    }
//     	    return true;
//     	}
//     	return false;
//     }
    
//     string validIPAddress(string IP) {
//     	string ans[3] = {"IPv4", "IPv6", "Neither"};
//     	stringstream ss(IP);
//     	string block;
//     	// ipv4 candidate
//     	if (IP.substr(0, 4).find('.') != string::npos) {
//     	    for (int i = 0; i < 4; i++) {
//     		if (!getline(ss, block, '.') || !isValidIPv4Block(block))
//     	   	    return ans[2];
//     	    }
//     	    return ss.eof() ? ans[0] : ans[2];
//     	}
//     	// ipv6 candidate
//     	else if (IP.substr(0, 5).find(':') != string::npos) {
//     	    for (int i = 0; i < 8; i++) {
//     		if (!getline(ss, block, ':') || !isValidIPv6Block(block))
//     		    return ans[2];
//     	    }
//     	    return ss.eof() ? ans[1] : ans[2];
//     	}
    
//     	return ans[2];
//     }
