
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

## 多态性

1. 运算符重载

   1. 整体

      ```c++
      函数类型 operator operand(params){
        
      }
      
      ```

      

   2. 单目运算符

      ```c++
      //++a
      Clock& operator++();
      
      
      //a++
      //只是用来区分的，这个Int是没有什么用的 
      Clock operator ++(int a);
      ```

      

   3. 双目运算符

      ```c++
      Complex operator - (const Complex& c2) const;
      
      Complex Complex::operator - (const Complex&c2) const{
        return Complex(real - c2.real, imag-c.image);
      }
      ```

   4. 运算符重载为非成员函数

      - 左操作数不再是对象自己
      - 例如cout<<重载

2. 虚函数

   - 告诉编译器要做动态绑定，而不是在编译阶段静待绑定，实现动态重载，就是虽然名字是相同的，但是想使用哪里的就是用哪里的，无论继承了多少层

   - 使用基类指针实现统一性

   - 每一个同名的都要是virtual,这个和虚继承不一样

     ```c++
     class Base1{
       public:
       	virtual void display()const;
       //可能实现必须放在外面，但是我这个Mac上面的测试没出现问题
       
     }
     class Base2:Base1{
       virtual...
     }
     class Base3:Base2{
       virtual... //注意这里即便后面差一个const,也会因为未重载而报错
     }
     
     void fun(Base1 * ptr){
       ptr -> display();
     }
     
     
     void main(){
       //base1
       //base2
       //base3
       fun(&base1);
       fun(&base2);
       fun(&base3); 
     }
     ```

   

   - 析构虚函数（因为这个一定是同名的）

3. 抽象类

   1. 纯虚函数

      有没有实现的函数体，因为基类的信息不够具体，没有办法定义；但是可以写出框架，只能作为基类用

      `不可以实例化`

      ```c++
      virtual void function() = 0;//=0表示没有函数体
      ```

      ㊙️必须实现base abstract里面的所有方法，const也必须是相同的

   2. 参数表写错了怎么办，语法检查是不会发现的，但是运行的时候会错误(c++11)自己让编译器告诉我

      ```c++
          virtual void show() const override;
      
      ```

   3. 添加了final就是无法再继承的

      ```c++
      struct base1 final{
        
      }; 
      ```

      

## STL

1. 通用功能

   ```c++
   constructor;
   ==;!=;<;>;
   begin();
   end();
   clear();
   empty();
   size();
   s1.swap(s2);
   S::iterator;
   S::reverse_iterator;
   S::const_iterator;
   S::const_reverse_iterator;
   ```

   

2. 顺序容器
   - vector
   - deque
     - Push_back()
     - Push_front()
     - Pop_back()
     - pop_front()
     - at
     - front
     - Back 
   - list
     - Push_back()
     - Pop_back()
     - Push_front()
     - Pop_front()
     - front
     - Back
   - forward_list(单向链表)
     - Push_front
     - Pop_front
     - Front()
   - array
   - queue
   - stack

3. 关联容器

   - set

     - insert
     - Erase 

   - map

     - insert

     - find

     - At  

       ```c++
       map.insert(std::pair<stirng,int>("mike",12));
       map::iterator itr = map.find("mike");
       
       if(itr != m.end()){
         cout<<itr -> first<<" "<<itr -> second<<endl;
       }
       
       
       
       ```

       

   - mutiset

   - multimap

     - 可以插入相同的

## io

1. 输出流

   1. ostream

   2. ofstream

   3. ostringstream

   4. cout

      ```c++
      //标准输出重定向
      ofstream fout("b.out");// or ofstream fout; fout.open("b.out");
      // firle mode
      // ios_base::out|ios_base::binary
      streambuf* pOld = cout.rdbuf(fout.rdbuf());
      //...
      //go back
      cout.rdbuf(pOld);
      ```

      

   5. cerr

   6. clog

2. 文件输出

   1. 操纵符（manipulator）

      1. 头文件
         - iOS_base
         - iomanip

      2. 操作
         - 紧跟有效
           - setw
           - Width
         - 持久
           - dec
           - ocx
           - hex

      2. 二进制

         ```c++
         Date dt = {2,3,4}
         ofstream file("date.dat",ios_base::binary);
         file.write(reinterpret_cast<char*>(&dt),sizeof(dt));
         file.close();
         
         ```

         

      3. 向字符串输出(转换成字符串)

         ```C++
         int a = 12;
         stringstream os;
         os<<a;
         stirng ac;
         os>>ac;
         ```

         

3. 输入流

   - istream

   - ifstream

   - Istringstream

   - 函数

     - get() 和(cin很像，但是包括空白符)
     - getline()
     - Read()二进制读

     ```c++
     while((ch = cin.get()) != EOF){
       cout.put(ch);
     }
     string line;
     getline(cin,line,'t');//terminated by 't', default one is newLine
     ```

     

## 异常处理

```c++
throw x;// x go to catch


try
  statement;
catch(error)
  statement;
catch(error)
  statement;

try{
  int x = 12;
  throw x;
} catch(int e){
  cout<<"error "<<e<<endl;
}
//析构自动执行
void fun()thorw(A,B,C,D)//可能抛出的异常
```


