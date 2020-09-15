
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
## 继承

1. 单继承

   ```c++
   class child : public father{
     
     
   };
   ```

2. 多继承

   ```c++
   class Drived: public class1, public class2
   ```

3. 继承方式

   public继承 是不能访问private的

   private继承

    1. 所有的base class的继承过来的对象都变成了private

    2. 继承类只能访问基类的除了Private之外的对象，这个和public继承是一样的，如果需要访问可以用

       ```c++
       baseclass::func();
       ```

   protected继承

   1. 所有被继承过来的到了子类之后都是protected访问权限

   2. 通过派生对象是不能访问任何基类成员的

      ⚠️ protected下是`不能`通过对象访问的，但是这个继承的类是`可以`访问

      

4. 类型转换
   1. 共有派生是可以作为基类使用的，反之不对
   2. 虚函数解决多继承相同函数名的调用问题，之后解决

5. 继承问题

   1. 默认情况下是不继承基类的构造函数

      ```c++
      child(params):派生类名(基类参数所需要的形参，积累所需要的形参),别的派生类(参数){
       	//other initialization 
      }
      ```

   2. 析构函数

      - 自动的使用
      - 从子到父
      - 与构建的顺序是反的

   3. 同名成员
      - 基类名:: func
      - Obj.基类名::func
      - 如果Child有，就优先child的函数，如果没有的话，就从子类去找，如果子类有重复的，就需要自己区分

6. 虚基类

   如果多继承的远亲是有一个相同的起源的，那么这个时候就产生了

   1. 冗余的情况
   2. 导致数据不一致的情况

   ```c++
   class child1:virtual public father{};
   class child2:virtual public father{};
   
   class childchild: public child1, public child2{};
   ```

   

   father构造函数怎么使用?

   1. child1和child2要传参

   2. childchild需要在构造函数的时候传

      ```c++
      childchild(int a):father(a){};
      ```

      
