int foldShift(long long key, int addressSize) {
    string keyStr = to_string(key); 
    long long sum = 0;

    for (size_t i = 0; i < keyStr.length(); i += addressSize) {
        string part = keyStr.substr(i, addressSize);
        sum += stoll(part);
    }
    
    long long limit = 1;
    for(int i = 0; i < addressSize; i++) limit *= 10;
    
    return sum % limit;
}

int rotation(long long key, int addressSize) {
    string keyStr = to_string(key);
    

    if (keyStr.length() > 1) {
        char lastChar = keyStr.back();     
        keyStr.pop_back();                 
        keyStr = lastChar + keyStr;        
    }
    
    long long newKey = stoll(keyStr);       
    return foldShift(newKey, addressSize);  
}