
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
## 关于int*a[]和int(*a)[]

```c++
    int (*a)[3] = new int[4][3]; // 数组指针，指向col:为3的数组； [4]是说一共分配了四个这样的数组
    int* a[3];//a是一个三维数组，里面存放的是指向整数型的指针
```
