
## 分割字符串
```c++
    #include <string.h>
    string a = "dsjkf,sdjkf,sdjfi";
    char* token = strtok((char*)a.c_str(),",");
    while (token){
        cout<<token<<endl;
        token = strtok(NULL, ",");
    }
```
